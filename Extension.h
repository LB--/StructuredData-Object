#include <typeinfo>
#include "StructuredData.hpp"

class Extension
{
public:

	LPRDATA rdPtr;
	LPRH	rhPtr;

	Edif::Runtime Runtime;

	static const int MinimumBuild = 255;
	static const int Version = 1;

	static const int OEFLAGS = OEFLAG_VALUES|OEFLAG_RUNBEFOREFADEIN|OEFLAG_NEVERKILL;
	static const int OEPREFS = 0;
	
	static const int WindowProcPriority = 100;

	Extension(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr);
	~Extension();


	/*  Add any data you want to store in your extension to this class
		(eg. what you'd normally store in rdPtr)

		Unlike rdPtr, you can store real C++ objects with constructors
		and destructors, without having to call them manually or store
		a pointer.
	*/

	// int MyVariable;

	SDNode *root, *cur;


	/*  Add your actions, conditions and expressions as real class member
		functions here. The arguments (and return type for expressions) must
		match EXACTLY what you defined in the JSON.

		Remember to link the actions, conditions and expressions to their
		numeric IDs in the class constructor (Extension.cpp)
	*/

	/// Actions
	void ReturnToRoot();
	void EnterSubnode(const char *Name);
	void GotoNodeByID(int ID);
	void AddNodeByID(int ID, const char *Name);
	void SetInt(const char *Name, int Value);
	void SetFloat(const char *Name, float Value);
	void SetString(const char *Name, const char *String);
	void RemoveSubnode(const char *Name);
	void RemoveNodeByID(int ID);
	void RemoveInt(const char *Name);
	void RemoveFloat(const char *Name);
	void RemoveString(const char *Name);

	/// Conditions
	bool NodeExists(const char *Name);
	bool NodeExistsByID(int ID);
	bool IntExists(const char *Name);
	bool FloatExists(const char *Name);
	bool StringExists(const char *Name);

	/// Expressions
	int NodeID();
	int Int(const char *Name);
	float Float(const char *Name);
	const char *String(const char *Name);



	/* These are called if there's no function linked to an ID */

	void Action(int ID, LPRDATA rdPtr, long param1, long param2);
	long Condition(int ID, LPRDATA rdPtr, long param1, long param2);
	long Expression(int ID, LPRDATA rdPtr, long param);




	/*  These replace the functions like HandleRunObject that used to be
		implemented in Runtime.cpp. They work exactly the same, but they're
		inside the extension class.
	*/

	short Handle();
	short Display();

	short Pause();
	short Continue();

	bool Save(HANDLE File);
	bool Load(HANDLE File);

};