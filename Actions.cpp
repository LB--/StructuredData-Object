#include "Common.h"

void Extension::ReturnToRoot()
{
	cur = root;
}
void Extension::EnterSubnode(const TCHAR *Name)
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
void Extension::CreateSubnode(const TCHAR *Name)
{
	if(cur->nm.find(Name) == cur->nm.end())
	{
		cur->nm[Name] = new SDNode();
	}
}
void Extension::AddNodeByID(int ID, const TCHAR *Name)
{
	if(SDNode::Nodes.find(ID) != SDNode::Nodes.end())
	{
		cur->nm[Name] = SDNode::Nodes.find(ID)->second;
	}
}
void Extension::SetInt(const TCHAR *Name, int Value)
{
	cur->im[Name] = Value;
}
void Extension::SetFloat(const TCHAR *Name, float Value)
{
	cur->fm[Name] = Value;
}
void Extension::SetString(const TCHAR *Name, const TCHAR *String)
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
void Extension::RemoveSubnode(const TCHAR *Name)
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
void Extension::RemoveInt(const TCHAR *Name)
{
	cur->im.erase(Name);
}
void Extension::RemoveFloat(const TCHAR *Name)
{
	cur->fm.erase(Name);
}
void Extension::RemoveString(const TCHAR *Name)
{
	cur->sm.erase(Name);
}

void Extension::ClearAll()
{
	while(SDNode::Nodes.size())
	{
		delete SDNode::Nodes.begin()->second;
	}
	root = new SDNode();
	cur = root;
}
