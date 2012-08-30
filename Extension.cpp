
#include "Common.h"

std::map<int, SDNode *> SDNode::nodes;
const std::map<int, SDNode *> &SDNode::Nodes (SDNode::nodes);


///
/// EXTENSION CONSTRUCTOR/DESTRUCTOR
///

Extension::Extension(LPRDATA _rdPtr, LPEDATA edPtr, fpcob cobPtr)
	: rdPtr(_rdPtr), rhPtr(_rdPtr->rHo.hoAdRunHeader), Runtime(_rdPtr)
{
	/*
		Link all your action/condition/expression functions to their IDs to match the
		IDs in the JSON here
	*/

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
	/*
	   If your extension will draw to the MMF window you should first 
	   check if anything about its display has changed :

		   if (rdPtr->roc.rcChanged)
			  return REFLAG_DISPLAY;
		   else
			  return 0;

	   You will also need to make sure you change this flag yourself 
	   to 1 whenever you want to redraw your object
	 
	   If your extension won't draw to the window, but it still needs 
	   to do something every MMF loop use :

			return 0;

	   If you don't need to do something every loop, use :

			return REFLAG_ONESHOT;

	   This doesn't mean this function can never run again. If you want MMF
	   to handle your object again (causing this code to run) use this function:

			Runtime.Rehandle();

	   At the end of the loop this code will run

	*/

	// Will not be called next loop	
	return REFLAG_ONESHOT;
}


short Extension::Display()
{
	/*
	   If you return REFLAG_DISPLAY in Handle() this routine will run.
	*/

	// Ok
	return 0;
}

short Extension::Pause()
{

	// Ok
	return 0;
}

short Extension::Continue()
{

	// Ok
	return 0;
}

bool Extension::Save(HANDLE File)
{
	bool OK = false;

	#ifndef VITALIZE

		// Save the object's data here

		OK = true;

	#endif

	return OK;
}

bool Extension::Load(HANDLE File)
{
	bool OK = false;

	#ifndef VITALIZE

		// Load the object's data here

		OK = true;

	#endif

	return OK;
}


// These are called if there's no function linked to an ID

void Extension::Action(int ID, LPRDATA rdPtr, long param1, long param2)
{

}

long Extension::Condition(int ID, LPRDATA rdPtr, long param1, long param2)
{

	return false;
}

long Extension::Expression(int ID, LPRDATA rdPtr, long param)
{

	return 0;
}

