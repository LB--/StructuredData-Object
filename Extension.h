#include "StructuredData.hpp"

class Extension
{
public:
	LPRDATA rdPtr;
	LPRH	rhPtr;

	Edif::Runtime Runtime;

	static const int MinimumBuild = 255;
	static const int Version = 2;

	static const int OEFLAGS = OEFLAG_VALUES|OEFLAG_RUNBEFOREFADEIN|OEFLAG_NEVERKILL;
	static const int OEPREFS = 0;
	
	static const int WindowProcPriority = 0;

	Extension(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr);
	~Extension();


	SDNode *root, *cur;


	//Actions
	void ReturnToRoot();
	void EnterSubnode(const char *Name);
	void GotoNodeByID(int ID);
	void CreateSubnode(const char *Name);
	void AddNodeByID(int ID, const char *Name);
	void SetInt(const char *Name, int Value);
	void SetFloat(const char *Name, float Value);
	void SetString(const char *Name, const char *String);
	void RemoveSubnode(const char *Name);
	void RemoveNodeByID(int ID);
	void RemoveInt(const char *Name);
	void RemoveFloat(const char *Name);
	void RemoveString(const char *Name);

	//Conditions
	bool NodeExists(const char *Name);
	bool NodeExistsByID(int ID);
	bool IntExists(const char *Name);
	bool FloatExists(const char *Name);
	bool StringExists(const char *Name);

	//Expressions
	int NodeID();
	int Int(const char *Name);
	float Float(const char *Name);
	const char *String(const char *Name);


	void Action(int ID, LPRDATA rdPtr, long param1, long param2);
	long Condition(int ID, LPRDATA rdPtr, long param1, long param2);
	long Expression(int ID, LPRDATA rdPtr, long param);


	short Handle();
	short Display();

	short Pause();
	short Continue();

	bool Save(HANDLE File);
	bool Load(HANDLE File);
};
