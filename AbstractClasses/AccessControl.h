/*----- PROTECTED REGION ID(AccessControl.h) ENABLED START -----*/
//=============================================================================
//
// file :        AccessControl.h
//
// description : Include for the AccessControl class.
//
// project :     Access Control abstract class.
//
//
// Copyright (C) :      2004,2005,2006,2007,2008,2009,2010,2011
//						European Synchrotron Radiation Facility
//                      BP 220, Grenoble 38043
//                      FRANCE
//
// This file is part of Tango.
//
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
//
//
//
// $Author$
//
// $Revision$
// $Date$
//
// SVN only:
// $HeadURL:  $
//
// CVS only:
// $Source$
// $Log$
// Revision 1.5  2011/02/11 14:20:27  pascal_verdier
// GetAccessForMutiIP  command added.
//
// Revision 1.4  2011/02/11 13:43:12  pascal_verdier
// Pogo-7 compatibility.
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef ACCESSCONTROL_H
#define ACCESSCONTROL_H


#include <tango.h>

#ifndef TANGO_UNUSED
	#ifdef _TG_WINDOWS_
		#define TANGO_UNUSED(var) var
	#else
		#if __GNUC__ == 3 && __GNUC_MINOR__ >= 4
			#define TANGO_UNUSED(var) var __attribute__ ((unused))
		#elif __GNUC__ > 3
			#define TANGO_UNUSED(var) var __attribute__ ((unused))
		#else
			#define TANGO_UNUSED(var) var
		#endif
	#endif
#endif

/*----- PROTECTED REGION END -----*/	//	AccessControl.h

/**
 *  AccessControl class description:
 *    This class defines how to manage the TANGO access control.
 *    It interfaces commands for tool to defines access for users, devices and IP addresses.
 *    It interfaces also commands used by client API to check access for specified user, device and address.
 *    And it insterfaces to register and unregister it as TANGO service.
 */

namespace AccessControl_ns
{
/*----- PROTECTED REGION ID(AccessControl::Additional Class Declarations) ENABLED START -----*/

		//		Additional Class Declarations

	/*----- PROTECTED REGION END -----*/	//	AccessControl::Additional Class Declarations

class AccessControl : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(AccessControl::Data Members) ENABLED START -----*/

	//		Add your own data members

	/*----- PROTECTED REGION END -----*/	//	AccessControl::Data Members



//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	AccessControl(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	AccessControl(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	AccessControl(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~AccessControl() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : AccessControl::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);


	//--------------------------------------------------------
	/**
	 *	Method      : AccessControl::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command AddAddressForUser related method
	 *	Description: Add an address for the specified user..
	 *
	 *	@param argin user name, address
	 */
	virtual void add_address_for_user(const Tango::DevVarStringArray *argin) = 0;
	virtual bool is_AddAddressForUser_allowed(const CORBA::Any &any);
	/**
	 *	Command AddDeviceForUser related method
	 *	Description: Add a device and rights for the specified user..
	 *
	 *	@param argin user name, device adn value
	 */
	virtual void add_device_for_user(const Tango::DevVarStringArray *argin) = 0;
	virtual bool is_AddDeviceForUser_allowed(const CORBA::Any &any);
	/**
	 *	Command CloneUser related method
	 *	Description: Copy addresses and devices from source user to target user.
	 *
	 *	@param argin [0] - source user name.\n[1] - target user name.
	 */
	virtual void clone_user(const Tango::DevVarStringArray *argin) = 0;
	virtual bool is_CloneUser_allowed(const CORBA::Any &any);
	/**
	 *	Command GetAccess related method
	 *	Description: Check access for specified user, device, address
	 *                    and returns access (read or write).
	 *
	 *	@param argin [0] - User name
	 *               [1] - IP Address
	 *               [2] - Device
	 *	@returns access for specified inputs  read/write.
	 */
	virtual Tango::DevString get_access(const Tango::DevVarStringArray *argin) = 0;
	virtual bool is_GetAccess_allowed(const CORBA::Any &any);
	/**
	 *	Command GetAccessForMultiIP related method
	 *	Description: Check access for specified user, device and addresses
	 *                    and returns access (read or write).
	 *
	 *	@param argin [0] - User name
	 *               [1] - Device
	 *               [2] - IP Address #1
	 *               [3] - IP Address #2
	 *               [4] - IP Address #3
	 *               [5] - IP Address #4
	 *               ......
	 *	@returns access for specified inputs  read/write.
	 */
	virtual Tango::DevString get_access_for_multi_ip(const Tango::DevVarStringArray *argin) = 0;
	virtual bool is_GetAccessForMultiIP_allowed(const CORBA::Any &any);
	/**
	 *	Command GetAddressByUser related method
	 *	Description: Returns address list  found for the specified user.
	 *
	 *	@param argin user name.
	 *	@returns Addresses found for the specified user.
	 */
	virtual Tango::DevVarStringArray *get_address_by_user(Tango::DevString argin) = 0;
	virtual bool is_GetAddressByUser_allowed(const CORBA::Any &any);
	/**
	 *	Command GetAllowedCommands related method
	 *	Description: Returns allowed command list found in database for specified device
	 *               It search the class of the specified device and then uses the class property <b>AllowedAccessCmd</b>
	 *
	 *	@param argin Device name
	 *	@returns Allowed commands found in database for specified device
	 */
	virtual Tango::DevVarStringArray *get_allowed_commands(Tango::DevString argin) = 0;
	virtual bool is_GetAllowedCommands_allowed(const CORBA::Any &any);
	/**
	 *	Command GetDeviceByUser related method
	 *	Description: Returns devices and rights found for the specified user.
	 *
	 *	@param argin user name.
	 *	@returns devices and rights found for the specified user.
	 */
	virtual Tango::DevVarStringArray *get_device_by_user(Tango::DevString argin) = 0;
	virtual bool is_GetDeviceByUser_allowed(const CORBA::Any &any);
	/**
	 *	Command GetDeviceClass related method
	 *	Description: Returns class for specified device.
	 *
	 *	@param argin Device name
	 *	@returns Class found in database for specified device
	 */
	virtual Tango::DevString get_device_class(Tango::DevString argin) = 0;
	virtual bool is_GetDeviceClass_allowed(const CORBA::Any &any);
	/**
	 *	Command GetUsers related method
	 *	Description: Returns user list found in table access_address.
	 *
	 *	@returns Users find in table access_address.
	 */
	virtual Tango::DevVarStringArray *get_users() = 0;
	virtual bool is_GetUsers_allowed(const CORBA::Any &any);
	/**
	 *	Command RegisterService related method
	 *	Description: Register device as a TANGO service.
	 *
	 */
	virtual void register_service() = 0;
	virtual bool is_RegisterService_allowed(const CORBA::Any &any);
	/**
	 *	Command RemoveAddressForUser related method
	 *	Description: Remove an address for the specified user..
	 *
	 *	@param argin user name, address
	 */
	virtual void remove_address_for_user(const Tango::DevVarStringArray *argin) = 0;
	virtual bool is_RemoveAddressForUser_allowed(const CORBA::Any &any);
	/**
	 *	Command RemoveDeviceForUser related method
	 *	Description: Remove a device and its rights for the specified user..
	 *
	 *	@param argin user name, device and value
	 */
	virtual void remove_device_for_user(const Tango::DevVarStringArray *argin) = 0;
	virtual bool is_RemoveDeviceForUser_allowed(const CORBA::Any &any);
	/**
	 *	Command RemoveUser related method
	 *	Description: Remove all records for specified user.
	 *
	 *	@param argin user name
	 */
	virtual void remove_user(Tango::DevString argin) = 0;
	virtual bool is_RemoveUser_allowed(const CORBA::Any &any);
	/**
	 *	Command UnregisterService related method
	 *	Description: Unregister device as a TANGO service.
	 *
	 */
	virtual void unregister_service() = 0;
	virtual bool is_UnregisterService_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : AccessControl::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(AccessControl::Additional Method prototypes) ENABLED START -----*/

	//	Additional Method prototypes

	/*----- PROTECTED REGION END -----*/	//	AccessControl::Additional Method prototypes
};

/*----- PROTECTED REGION ID(AccessControl::Additional Classes Definitions) ENABLED START -----*/

	//	Additional Classes definitions

	/*----- PROTECTED REGION END -----*/	//	AccessControl::Additional Classes Definitions

}	//	End of namespace

#endif   //	AccessControl_H
