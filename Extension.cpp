#include "Common.h"

SDNode::nodes_t SDNode::nodes;
const SDNode::Nodes_t &SDNode::Nodes (SDNode::nodes);

Extension::Extension(LPRDATA _rdPtr, LPEDATA edPtr, fpcob cobPtr)
	: rdPtr(_rdPtr), rhPtr(_rdPtr->rHo.hoAdRunHeader), Runtime(_rdPtr)
{
	LinkAction(0, ReturnToRoot);
	LinkAction(1, EnterSubnode);
	LinkAction(2, GotoNodeByID);
	LinkAction(3, AddNodeByID);
	LinkAction(4, SetInt);
	LinkAction(5, SetFloat);
	LinkAction(6, SetString);
	LinkAction(7, RemoveSubnode);
	LinkAction(8, RemoveNodeByID);
	LinkAction(9, RemoveInt);
	LinkAction(10,RemoveFloat);
	LinkAction(11,RemoveString);
	LinkAction(12,CreateSubnode);
	LinkAction(13,IterateNodes);
	LinkAction(14,IterateSubnodes);
	LinkAction(15,IterateInts);
	LinkAction(16,IterateFloats);
	LinkAction(17,IterateStrings);
	LinkAction(18,ClearAll);

	LinkCondition(0,			NodeExists);
	LinkCondition(1,			NodeExistsByID);
	LinkCondition(2,			IntExists);
	LinkCondition(3,			FloatExists);
	LinkCondition(4,			StringExists);
	LinkCondition(TOnNode,		OnNode);
	LinkCondition(TOnSubnode,	OnSubnode);
	LinkCondition(TOnInt,		OnInt);
	LinkCondition(TOnFloat,		OnFloat);
	LinkCondition(TOnString,	OnString);

	LinkExpression(0, NodeID);
	LinkExpression(1, Int);
	LinkExpression(2, Float);
	LinkExpression(3, String);
	LinkExpression(4, SubnodeName);
	LinkExpression(5, IntName);
	LinkExpression(6, FloatName);
	LinkExpression(7, StringName);

	root = new SDNode();
	cur = root;
	Nit = 0;
}

Extension::~Extension()
{
	while(SDNode::Nodes.size())
	{
		delete SDNode::Nodes.begin()->second;
	}
	root = cur = 0;
}


short Extension::Handle()
{
	return REFLAG_ONESHOT;
}


short Extension::Display()
{
	return 0;
}

short Extension::Pause()
{
	return 0;
}

short Extension::Continue()
{
	return 0;
}

bool Extension::Save(HANDLE File)
{
	return false;
}

bool Extension::Load(HANDLE File)
{
	return false;
}


void Extension::Action(int ID, LPRDATA rdPtr, long param1, long param2)
{
}

long Extension::Condition(int ID, LPRDATA rdPtr, long param1, long param2)
{
	return false;
}

long Extension::Expression(int ID, LPRDATA rdPtr, long param)
{
	return long(_T(""));
}
