#ifndef LOGGING_ACSREMOTEAPPENDER_H_
#define LOGGING_ACSREMOTEAPPENDER_H_

/*******************************************************************************
* ALMA - Atacama Large Millimiter Array
* (c) UNSPECIFIED - FILL IN, 2005
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*
* "@(#) $Id: loggingACSRemoteAppender.h,v 1.1 2011/02/14 21:15:08 javarias Exp $"
*
*/


#define LOG4CPP_FIX_ERROR_COLLISION 1
#include <log4cpp/LayoutAppender.hh>

#include <iostream>
#include <deque>

#include <ace/Synch.h>

#include "loggingLogThrottle.h"
#include "logging_idlC.h"

namespace logging {

class ACSRemoteAppender: public virtual log4cpp::LayoutAppender{
public:
	ACSRemoteAppender(const std::string& name,
			unsigned long cacheSize,
			unsigned int autoFlushTimeoutSec,
			Logging::AcsLogService_ptr centralizedLogger,
			int maxLogsPerSecond);
	virtual ~ACSRemoteAppender();
	void close();

protected:
	void _append(const log4cpp::LoggingEvent& event);

private:
	unsigned int _cacheSize;
	unsigned int _flushTimeout;
	logging::LogThrottle* _logThrottle;
	Logging::AcsLogService_ptr _logger;
	std::deque<Logging::XmlLogRecord>* _cache;
	log4cpp::Priority::Value _threshold;
	log4cpp::Filter* _filter;

	void flushCache();
	void sendLog(Logging::XmlLogRecord& log);
	void sendLog(Logging::XmlLogRecordSeq& logs);

	//worker entry thread function, it flush the thread at regular intervals or
	//when the cache reaches the max size
	static void* worker(void* arg);
	void svc();
	ACE_SYNCH_MUTEX _workCondThreadMutex;
	ACE_SYNCH_CONDITION _workCond;
	bool _stopThread;
};

};

#endif
