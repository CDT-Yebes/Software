#! /usr/bin/env python
#*******************************************************************************
# ALMA - Atacama Large Millimiter Array
# (c) Associated Universities Inc., 2005 
# 
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
# 
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
#
# "@(#) $Id: SimServer.py,v 1.1 2007/04/04 20:24:34 agrimstrup Exp $"
#
# who       when        what
# --------  ----------  ----------------------------------------------
# rhiriart  2006-12-06  created
#

import sys

import ACSSim__POA
from Acspy.Servants.ACSComponent       import ACSComponent
from Acspy.Servants.ComponentLifecycle import ComponentLifecycle
from Acspy.Servants.ContainerServices  import ContainerServices
from Acssim.Goodies import setGlobalData
from Acssim.Goodies import removeGlobalData
from Acssim.Goodies import getGlobalData
from ACSSim import MethodInfo
from ACSSim import NoSuchMethodEx
from ACSSim import NoSuchDataEx
from ACSSim import DataErrorEx

class SimServer(ACSSim__POA.Simulator,
                ACSComponent,
                ContainerServices,
                ComponentLifecycle):
    """Simulator component implementation.
    """
    
    #------------------------------------------------------------------------------
    #--Constructor-----------------------------------------------------------------
    #------------------------------------------------------------------------------
    def __init__(self):
        '''Constructor.
        '''
        ACSComponent.__init__(self)
        ContainerServices.__init__(self)

        self.logger = self.getLogger()

        self.methods = {}

    #------------------------------------------------------------------------------
    #--Override ComponentLifecycle methods-----------------------------------------
    #------------------------------------------------------------------------------
    def initialize(self):
        '''
        Override this method inherited from ComponentLifecycle
        '''
        self.getLogger().logInfo("called...")
        
    #------------------------------------------------------------------------------
    def cleanUp(self):
        '''
        Override this method inherited from ComponentLifecycle
        '''
        self.getLogger().logInfo("called...")
            
    #------------------------------------------------------------------------------
    def getName(self):
        return "SimServer"
    
    #------------------------------------------------------------------------------
    #--Implementation of IDL methods-----------------------------------------------
    #------------------------------------------------------------------------------

    #------------------------------------------------------------------------------
    def setMethod(self, comp_name, method_name, method_code, timeout):
        if not comp_name in self.methods.keys():
            self.methods[comp_name] = {}
        self.methods[comp_name][method_name] = MethodInfo(method_code.split('\n'),
                                                          timeout)

    #------------------------------------------------------------------------------
    def getMethod(self, comp_name, method_name):
        try:
            return self.methods[comp_name][method_name]
        except KeyError:
            raise NoSuchMethodEx()

    #------------------------------------------------------------------------------
    def setGlobalData(self, name, value):
        try:
            setGlobalData(name, value)
        except:
            # setGlobalData() raises a string exception.
            ex_info = sys.exc_info()
            raise DataErrorEx(ex_info[0])
        
    #------------------------------------------------------------------------------
    def removeGlobalData(self, name):
        try:
            removeGlobalData(name)
        except KeyError, ex:
            raise NoSuchDataEx()
        except:
            ex_info = sys.exc_info()
            raise DataErrorEx(ex_info[0])            

    #------------------------------------------------------------------------------
    def getGlobalData(self, name):
        value = getGlobalData(name)
        if value == None:
            raise NoSuchDataEx()
        else:
            return str(value)

#----------------------------------------------------------------------------------
#--Main defined only for generic testing-------------------------------------------
#----------------------------------------------------------------------------------
if __name__ == "__main__":
    print "Creating an object"
    s = SimServer()
    print "Done..."

#
# ___oOo___

