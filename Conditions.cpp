#include "Common.h"

bool Extension::NodeExists(const char *Name)
{
	return cur->nm.find(Name) != cur->nm.end();
}
bool Extension::NodeExistsByID(int ID)
{
	return SDNode::Nodes.find(ID) != SDNode::Nodes.end();
}
bool Extension::IntExists(const char *Name)
{
	return cur->im.find(Name) != cur->im.end();
}
bool Extension::FloatExists(const char *Name)
{
	return cur->fm.find(Name) != cur->fm.end();
}
bool Extension::StringExists(const char *Name)
{
	return cur->sm.find(Name) != cur->sm.end();
}
