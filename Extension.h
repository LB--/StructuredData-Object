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
	
	static const int WindowProcPriority = 0;

	Extension(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr);
	~Extension();


	SDNode *root, *cur;
	SDNode::Nodes_t::const_iterator *Nit; //All Nodes iterator
	std::vector<SDNode::nmt::iterator *> nit; //Subnodes iterator
	SDNode::imt::iterator *iit; //Ints iterator
	SDNode::fmt::iterator *fit; //Floats iterator
	SDNode::smt::iterator *sit; //Strings iterator


	//Actions
	void ReturnToRoot();
	void EnterSubnode(const TCHAR *Name);
	void GotoNodeByID(int ID);
	void CreateSubnode(const TCHAR *Name);
	void AddNodeByID(int ID, const TCHAR *Name);
	void SetInt(const TCHAR *Name, int Value);
	void SetFloat(const TCHAR *Name, float Value);
	void SetString(const TCHAR *Name, const TCHAR *String);
	void IterateNodes();
	void IterateSubnodes();
	void IterateInts();
	void IterateFloats();
	void IterateStrings();
	void RemoveSubnode(const TCHAR *Name);
	void RemoveNodeByID(int ID);
	void RemoveInt(const TCHAR *Name);
	void RemoveFloat(const TCHAR *Name);
	void RemoveString(const TCHAR *Name);
	void ClearAll();

	//Conditions
	bool NodeExists(const TCHAR *Name);
	bool NodeExistsByID(int ID);
	bool IntExists(const TCHAR *Name);
	bool FloatExists(const TCHAR *Name);
	bool StringExists(const TCHAR *Name);
	bool OnNode();						const static unsigned TOnNode	= 5;
	bool OnSubnode();					const static unsigned TOnSubnode= 6;
	bool OnInt();						const static unsigned TOnInt	= 7;
	bool OnFloat();						const static unsigned TOnFloat	= 8;
	bool OnString();					const static unsigned TOnString	= 9;

	//Expressions
	int NodeID();
	int Int(const TCHAR *Name);
	float Float(const TCHAR *Name);
	const TCHAR *String(const TCHAR *Name);
	const TCHAR *SubnodeName();
	const TCHAR *IntName();
	const TCHAR *FloatName();
	const TCHAR *StringName();


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
