#include "Common.h"

void Extension::ReturnToRoot()
{
	cur = root;
}
void Extension::EnterSubnode(const char *Name)
{
	CreateSubnode(Name);
	cur = cur->nm[Name];
}
void Extension::GotoNodeByID(int ID)
{
	if(SDNode::Nodes.find(ID) != SDNode::Nodes.end())
	{
		cur = SDNode::Nodes.find(ID)->second;
	}
}
void Extension::CreateSubnode(const char *Name)
{
	if(cur->nm.find(Name) == cur->nm.end())
	{
		cur->nm[Name] = new SDNode();
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
void Extension::IterateNodes()
{
	SDNode::Nodes_t::const_iterator it = SDNode::Nodes.begin();
	for(Nit = &it; it != SDNode::Nodes.end(); ++it)
	{
		Runtime.GenerateEvent(TOnNode);
	}
	Nit = 0;
}
void Extension::IterateSubnodes()
{
	SDNode *c = cur;
	SDNode::nmt::iterator it = c->nm.begin();
	nit.push_back(&it);
	for(; it != c->nm.end(); ++it)
	{
		Runtime.GenerateEvent(TOnSubnode);
	}
	nit.pop_back();
}
void Extension::IterateInts()
{
	SDNode *c = cur;
	SDNode::imt::iterator it = c->im.begin();
	for(iit = &it; it != c->im.end(); ++it)
	{
		Runtime.GenerateEvent(TOnInt);
	}
	iit = 0;
}
void Extension::IterateFloats()
{
	SDNode *c = cur;
	SDNode::fmt::iterator it = c->fm.begin();
	for(fit = &it; it != c->fm.end(); ++it)
	{
		Runtime.GenerateEvent(TOnFloat);
	}
	fit = 0;
}
void Extension::IterateStrings()
{
	SDNode *c = cur;
	SDNode::smt::iterator it = c->sm.begin();
	for(sit = &it; it != c->sm.end(); ++it)
	{
		Runtime.GenerateEvent(TOnString);
	}
	sit = 0;
}
void Extension::RemoveSubnode(const char *Name)
{
	cur->nm.erase(Name);
}
void Extension::RemoveNodeByID(int ID)
{
	if(ID == 0) return;
	if(ID == cur->ID) ReturnToRoot();
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
