#include "Common.h"

std::map<int, SDNode *> SDNode::nodes;
const std::map<int, SDNode *> &SDNode::Nodes (SDNode::nodes);

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

	LinkCondition(0, NodeExists);
	LinkCondition(1, NodeExistsByID);
	LinkCondition(2, IntExists);
	LinkCondition(3, FloatExists);
	LinkCondition(4, StringExists);

	LinkExpression(0, NodeID);
	LinkExpression(1, Int);
	LinkExpression(2, Float);
	LinkExpression(3, String);

	root = new SDNode();
	cur = root;
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
	bool OK = false;
#ifndef VITALIZE
	//
	OK = true;
#endif
	return OK;
}

bool Extension::Load(HANDLE File)
{
	bool OK = false;
#ifndef VITALIZE
	//
	OK = true;
#endif
	return OK;
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
	return long("");
}
