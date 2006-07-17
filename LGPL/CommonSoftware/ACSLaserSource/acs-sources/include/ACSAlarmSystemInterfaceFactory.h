#ifndef ACS_ALARM_SYSTEM_INTERFACE_FACTORY_H
#define ACS_ALARM_SYSTEM_INTERFACE_FACTORY_H
/*******************************************************************************
* ALMA - Atacama Large Millimiter Array
* (c) European Southern Observatory, 2006 
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
* "@(#) $Id$"
*
* who       when      what
* --------  --------  ----------------------------------------------
* acaproni  2006-07-12  created
*/

/************************************************************************
 *
 *----------------------------------------------------------------------
 */

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <AlarmSystemInterfaceFactory.h>
#include <AlarmSystemInterface.h>
#include "ACSAlarmSystemInterfaceFactory.h"
#include "ACSAlarmSystemInterfaceProxy.h"
#include "ConfigPropertyGetter.h"
#include "maciS.h"

/**
 * The class to create sources and fault states.
 * It extends the laser source but it returns different implementations of the
 * sources depending of a value of a property of the CDB
 * 
 * The ACS implementation of the source logs a message for each alarm
 */
class ACSAlarmSystemInterfaceFactory: public laserSource::AlarmSystemInterfaceFactory {
	private:
		// It is true if ACS implementation for sources must be used and
		// null if it has not yet been initialized
		// false means CERN implementation
		static bool* m_useACSAlarmSystem;
		
		// The manager
		maci::Manager_ptr m_manager;
		
	private:
		/** Default constructor.
		*/
		ACSAlarmSystemInterfaceFactory();
		virtual ~ACSAlarmSystemInterfaceFactory();
	
	public:
	
		static void init(maci::Manager_ptr manager);
	
	/**
 	 * Create a new instance of an alarm system interface.
	 * @param sourceName the source name.
	 * @return the interface instance.
	 * @throws ASIException if the AlarmSystemInterface instance can not be created.
	 */
	static auto_ptr<laserSource::AlarmSystemInterface> createSource(string sourceName);
		
	static bool cernImplementationRequested();

	/**
	 * Create a new instance of an alarm system interface without binding it to any source.
	 * @return the interface instance.
	 * @throws ASIException if the AlarmSystemInterface instance can not be created.
	 */
	static auto_ptr<laserSource::AlarmSystemInterface> createSource();

};

#endif /*!ACS_ALARM_SYSTEM_INTERFACE_FACTORY_H*/
