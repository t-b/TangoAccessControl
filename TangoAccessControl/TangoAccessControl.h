/*----- PROTECTED REGION ID(TangoAccessControl.h) ENABLED START -----*/
//=============================================================================
//
// file :        TangoAccessControl.h
//
// description : Include for the TangoAccessControl class.
//
// project :     Tango Access Control Management.
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
// Revision 1.12  2011/02/11 14:21:42  pascal_verdier
// GetAccessForMutiIP  command added.
//
// Revision 1.11  2011/02/11 13:28:43  pascal_verdier
// Pogo-7 compatibility.
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef TANGOACCESSCONTROL_H
#define TANGOACCESSCONTROL_H


#include <tango.h>
#include <AccessControl.h>
#include <mysql.h>


#define	CONTROL_SYSTEM				"CtrlSystem"
#define SERVICE_PROP_NAME			"Services"
#define ServiceName					"AccessControl"
#define InatanceName				"tango"
 
#define AC_SQLError 				"AC_SQLError"
#define AC_IncorrectArguments		"AC_IncorrectArguments"
#define AC_AlreadyExists			"AC_AlreadyExists"

#define	STARTER_DEVNAME_HEADER	"tango/admin/"

typedef struct {
	string	user;
	string	device;
	string	address;
	string	rights;
}
AccessStruct;

//	Define time measuremnt type (depends on OS)
#ifndef WIN32

#	define	TimeVal	struct timeval
#	define	GetTime(t)	gettimeofday(&t, NULL);
#	define	Elapsed(before, after)	\
		1000.0*(after.tv_sec-before.tv_sec) + \
		((double)after.tv_usec-before.tv_usec) / 1000

#else

static LARGE_INTEGER	cpu_freq;
#	define	TimeVal	LARGE_INTEGER
#	define	GetTime(t)	w_gettimeofday(&t);
#	define	Elapsed(before, after)		\
		(cpu_freq.QuadPart==0) ? 0.0 :	\
			(double) (after.QuadPart - before.QuadPart)/cpu_freq.QuadPart * 1000;

#endif	/*	WIN32		*/




/*----- PROTECTED REGION END -----*/


/**
 *	TangoAccessControl class Description:
 *	This class is a conceate class inherited from AccessControl abstract class.<Br>
 *	<Br>
 *	This class defines how to manage the TANGO access control.<Br>
 *	It implements commands for tool to defines access for users, devices and IP addresses.<Br>
 *	It implements also commands used by client API to check access for specified user, device and address.<Br>
 *	And it implements register and unregister it as TANGO service.
 */

namespace TangoAccessControl_ns
{
	/*----- PROTECTED REGION ID(TangoAccessControl::Additional Class Declarations) ENABLED START -----*/

		//		Additional Class Declarations
class DummyDev: public Tango::Connection
{
public:
	DummyDev():Tango::Connection(true) {};

	virtual string get_corba_name(bool) {string str;return str;}
	virtual string build_corba_name() {string str;return str;}
	virtual int get_lock_ctr() {return 0;}
	virtual void set_lock_ctr(int) {};

	virtual string dev_name() {string str;return str;}

	int get_env_var(const char *cc,string &str_ref) {return Tango::Connection::get_env_var(cc,str_ref);}
};

	/*----- PROTECTED REGION END -----*/	//	TangoAccessControl::Additional Class Declarations


class TangoAccessControl : public AccessControl_ns::AccessControl
{


	/*----- PROTECTED REGION ID(TangoAccessControl::Data Members) ENABLED START -----*/

	//		Add your own data members
public:



	/*----- PROTECTED REGION END -----*/	//	TangoAccessControl::Data Members


//	Device property data members
public:	

//	Attribute data members
public:



//	Constructors and destructors
public:
	/**
	 * Constructs a newly allocated Command object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	TangoAccessControl(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly allocated Command object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	TangoAccessControl(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly allocated Command object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	TangoAccessControl(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The object destructor.
	 */	
	~TangoAccessControl() {delete_device();};



//	Miscellaneous methods
public:
	/**
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/**
	 *	Initialize the device
	 */
	virtual void init_device();
	/**
	 *	Read the device properties from database
	 */
	 void get_device_property();
	/**
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


	/**
	 *	Method      : TangoAccessControl::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
		void add_dynamic_attributes();

//	Command related methods
public: 


	/**
	 *	Command AddAddressForUser related methods.
	 */
	void add_address_for_user(const Tango::DevVarStringArray *argin);
	virtual bool is_AddAddressForUser_allowed(const CORBA::Any &any);

	/**
	 *	Command AddDeviceForUser related methods.
	 */
	void add_device_for_user(const Tango::DevVarStringArray *argin);
	virtual bool is_AddDeviceForUser_allowed(const CORBA::Any &any);

	/**
	 *	Command CloneUser related methods.
	 */
	void clone_user(const Tango::DevVarStringArray *argin);
	virtual bool is_CloneUser_allowed(const CORBA::Any &any);

	/**
	 *	Command GetAccess related methods.
	 */
	Tango::DevString get_access(const Tango::DevVarStringArray *argin);
	virtual bool is_GetAccess_allowed(const CORBA::Any &any);

	/**
	 *	Command GetAccessForMultiIP related methods.
	 */
	Tango::DevString get_access_for_multi_ip(const Tango::DevVarStringArray *argin);
	virtual bool is_GetAccessForMultiIP_allowed(const CORBA::Any &any);

	/**
	 *	Command GetAddressByUser related methods.
	 */
	Tango::DevVarStringArray *get_address_by_user(Tango::DevString argin);
	virtual bool is_GetAddressByUser_allowed(const CORBA::Any &any);

	/**
	 *	Command GetAllowedCommandClassList related methods.
	 */
	Tango::DevVarStringArray *get_allowed_command_class_list();
	virtual bool is_GetAllowedCommandClassList_allowed(const CORBA::Any &any);

	/**
	 *	Command GetAllowedCommands related methods.
	 */
	Tango::DevVarStringArray *get_allowed_commands(Tango::DevString argin);
	virtual bool is_GetAllowedCommands_allowed(const CORBA::Any &any);

	/**
	 *	Command GetDeviceByUser related methods.
	 */
	Tango::DevVarStringArray *get_device_by_user(Tango::DevString argin);
	virtual bool is_GetDeviceByUser_allowed(const CORBA::Any &any);

	/**
	 *	Command GetDeviceClass related methods.
	 */
	Tango::DevString get_device_class(Tango::DevString argin);
	virtual bool is_GetDeviceClass_allowed(const CORBA::Any &any);

	/**
	 *	Command GetUsers related methods.
	 */
	Tango::DevVarStringArray *get_users();
	virtual bool is_GetUsers_allowed(const CORBA::Any &any);

	/**
	 *	Command RegisterService related methods.
	 */
	void register_service();
	virtual bool is_RegisterService_allowed(const CORBA::Any &any);

	/**
	 *	Command RemoveAddressForUser related methods.
	 */
	void remove_address_for_user(const Tango::DevVarStringArray *argin);
	virtual bool is_RemoveAddressForUser_allowed(const CORBA::Any &any);

	/**
	 *	Command RemoveDeviceForUser related methods.
	 */
	void remove_device_for_user(const Tango::DevVarStringArray *argin);
	virtual bool is_RemoveDeviceForUser_allowed(const CORBA::Any &any);

	/**
	 *	Command RemoveUser related methods.
	 */
	void remove_user(Tango::DevString argin);
	virtual bool is_RemoveUser_allowed(const CORBA::Any &any);

	/**
	 *	Command UnregisterService related methods.
	 */
	void unregister_service();
	virtual bool is_UnregisterService_allowed(const CORBA::Any &any);



	/*----- PROTECTED REGION ID(TangoAccessControl::Additional Method prototypes) ENABLED START -----*/

	//	Additional Method prototypes
protected :	
	MYSQL mysql;

	string         removeFQDN(string s);
	void           mysql_connection();
	void           simple_query(string sql_query,const char *method);
	MYSQL_RES     *query(string sql_query,const char *method);
	vector<string> get_dev_members(string &devname);
	vector<string> get_ip_add_members(string &devname);

	vector<AccessStruct>
		get_access_for_user_address(string &user, string &ip_add);
	string get_access_for_user_device(string &user, string &device);
	int    nb_chars(string s, char c);
	int    mini_nb_stars(vector<AccessStruct> v);

	void register_service(string servicename, string instname, string devname);
	void unregister_service(string servicename, string instname, string devname);

	/*----- PROTECTED REGION END -----*/	//	TangoAccessControl::Additional Method prototypes

};

	/*----- PROTECTED REGION ID(TangoAccessControl::Additional Classes Definitions) ENABLED START -----*/

	//	Additional Classes definitions

	/*----- PROTECTED REGION END -----*/	//	TangoAccessControl::Additional Classes Definitions

} //	namespace

#endif	//	TANGOACCESSCONTROL_H
