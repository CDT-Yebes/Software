/*******************************************************************************
* ALMA - Atacama Large Millimiter Array
* (c) European Southern Observatory, 2011
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
* "@(#) $Id: bulkDataNTReceiverFlow.cpp,v 1.3 2011/07/27 13:28:31 bjeram Exp $"
*
* who       when      what
* --------  --------  ----------------------------------------------
* bjeram  2011-04-19  created
*/

#include "bulkDataNTReceiverFlow.h"
#include <iostream>

#include <AV/FlowSpec_Entry.h>  // we need it for TAO_Tokenizer ??
#include <ACSBulkDataError.h>   // error definition  ??


static char *rcsId="@(#) $Id: bulkDataNTReceiverFlow.cpp,v 1.3 2011/07/27 13:28:31 bjeram Exp $";
static void *use_rcsId = ((void)&use_rcsId,(void *) &rcsId);

using namespace AcsBulkdata;
using namespace std;

BulkDataNTReceiverFlow::BulkDataNTReceiverFlow(BulkDataNTStream *receiverStream, const char* flowName, BulkDataCallback *cb) :
		receiverStream_m(receiverStream)
{
	AUTO_TRACE(__PRETTY_FUNCTION__);

	std::string topicName;

	flowName_m = flowName;

	// should be refactor to have just one object for comunication !! DDSDataWriter or similar
	ddsSubscriber_m = new BulkDataNTDDSSubscriber(receiverStream_m->getDDSParticipant());

	topicName = receiverStream_m->getName() + "#" + flowName_m;
	ddsTopic_m = ddsSubscriber_m->createDDSTopic(topicName.c_str());

	callback_m = cb;

	callback_m->setFlowName(topicName.c_str());

	dataReaderListener_m = new BulkDataNTReaderListener(topicName.c_str(), callback_m);

	ddsDataReader_m= ddsSubscriber_m->createDDSReader(ddsTopic_m, dataReaderListener_m);
}//BulkDataNTReceiverFlow


BulkDataNTReceiverFlow::~BulkDataNTReceiverFlow()
{
	AUTO_TRACE(__PRETTY_FUNCTION__);
	receiverStream_m->removeFlowFromMap(flowName_m.c_str());
	// this part can go to BulkDataNTDDSPublisher, anyway we need to refactor
	DDS::DomainParticipant *participant = receiverStream_m->getDDSParticipant();
	if (participant!=0)
	{
		participant->delete_datareader(ddsDataReader_m);
		delete dataReaderListener_m;
		participant->delete_topic(ddsTopic_m);
	}
	else
	{
		//TBD: error handling
	}
	delete ddsSubscriber_m;
	// delete callback_m
}//~BulkDataNTReceiverFlow


/*___oOo___*/
