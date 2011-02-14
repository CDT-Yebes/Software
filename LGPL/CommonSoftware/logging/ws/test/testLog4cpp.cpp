/*******************************************************************************
 *    ALMA - Atacama Large Millimiter Array
 *    (c) European Southern Observatory, 2002
 *    Copyright by ESO (in the framework of the ALMA collaboration)
 *    and Cosylab 2002, All rights reserved
 *
 *    This library is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 2.1 of the License, or (at your option) any later version.
 *
 *    This library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with this library; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 *
 * "@(#) "
 *
 * who       when        what
 * --------  ----------  ----------------------------------------------
 * javarias  May 7, 2010  	 created
 */

#include "loggingLog4cpp.h"
#include "loggingLog4cppMACROS.h"

int main (int argc, char * argv[])
{
	LOG4CPP_LOG(log4cpp::Priority::TRACE, __PRETTY_FUNCTION__, "LOG");
	LOG4CPP_LOG_FULL(log4cpp::Priority::INFO, __PRETTY_FUNCTION__, "LOG_FULL", "Engineering", "Array00X", "DVXX");
	LOG4CPP_LOG_RECORD(log4cpp::Priority::INFO, "LOG_RECORD", __FILE__, __LINE__, __PRETTY_FUNCTION__, "newLogger");
	return 0;
}
