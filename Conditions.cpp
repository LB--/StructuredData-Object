#include "Common.h"

bool Extension::NodeExists(const TCHAR *Name)
{
	return cur->nm.find(Name) != cur->nm.end();
}
bool Extension::NodeExistsByID(int ID)
{
	return SDNode::Nodes.find(ID) != SDNode::Nodes.end();
}
bool Extension::IntExists(const TCHAR *Name)
{
	return cur->im.find(Name) != cur->im.end();
}
bool Extension::FloatExists(const TCHAR *Name)
{
	return cur->fm.find(Name) != cur->fm.end();
}
bool Extension::StringExists(const TCHAR *Name)
{
	return cur->sm.find(Name) != cur->sm.end();
}
bool Extension::OnNode()
{
	if(Nit)
	{
		cur = Nit->operator->()->second;
		return true;
	}
	return false;
}
bool Extension::OnSubnode()
{
	if(nit.size())
	{
		cur = nit.back()->operator->()->second;
		return true;
	}
	return false;
}
bool Extension::OnInt()
{
	return iit != 0;
}
bool Extension::OnFloat()
{
	return fit != 0;
}
bool Extension::OnString()
{
	return sit != 0;
}
