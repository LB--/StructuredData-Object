#include "Common.h"

void Extension::ReturnToRoot()
{
	cur = root;
}
void Extension::EnterSubnode(const char *Name)
{
	if(cur->nm.find(Name) == cur->nm.end())
	{
		cur->nm[Name] = new SDNode();
	}
	cur = cur->nm[Name];
}
void Extension::GotoNodeByID(int ID)
{
	if(SDNode::Nodes.find(ID) != SDNode::Nodes.end())
	{
		cur = SDNode::Nodes.find(ID)->second;
	}
}
void Extension::AddNodeByID(int ID, const char *Name)
{
	if(SDNode::Nodes.find(ID) != SDNode::Nodes.end())
	{
		cur->nm[Name] = SDNode::Nodes.find(ID)->second;
	}
}
void Extension::SetInt(const char *Name, int Value)
{
	cur->im[Name] = Value;
}
void Extension::SetFloat(const char *Name, float Value)
{
	cur->fm[Name] = Value;
}
void Extension::SetString(const char *Name, const char *String)
{
	cur->sm[Name] = String;
}
void Extension::RemoveSubnode(const char *Name)
{
	cur->nm.erase(Name);
}
void Extension::RemoveNodeByID(int ID)
{
	for(std::map<int, SDNode *>::const_iterator it = SDNode::Nodes.begin(); it != SDNode::Nodes.end(); ++it)
	{
		for(SDNode::nmt::iterator jt = it->second->nm.begin(); jt != it->second->nm.end();)
		{
			if(jt->second->ID == ID)
			{
				jt = it->second->nm.erase(jt);
			}
			else ++jt;
		}
	}
	delete SDNode::Nodes.find(ID)->second;
}
void Extension::RemoveInt(const char *Name)
{
	cur->im.erase(Name);
}
void Extension::RemoveFloat(const char *Name)
{
	cur->fm.erase(Name);
}
void Extension::RemoveString(const char *Name)
{
	cur->sm.erase(Name);
}
