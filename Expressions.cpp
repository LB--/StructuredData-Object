#include "Common.h"

int Extension::NodeID()
{
	return cur->ID;
}
int Extension::Int(const TCHAR *Name)
{
	return cur->im[Name];
}
float Extension::Float(const TCHAR *Name)
{
	return cur->fm[Name];
}
const TCHAR *Extension::String(const TCHAR *Name)
{
	return Runtime.CopyString(cur->sm[Name].c_str());
}
const TCHAR *Extension::SubnodeName()
{
	return Runtime.CopyString(nit.back()->operator->()->first.c_str());
}
const TCHAR *Extension::IntName()
{
	if(iit)
	{
		return Runtime.CopyString(iit->operator->()->first.c_str());
	}
	return _T("");
}
const TCHAR *Extension::FloatName()
{
	if(fit)
	{
		return Runtime.CopyString(fit->operator->()->first.c_str());
	}
	return _T("");
}
const TCHAR *Extension::StringName()
{
	if(sit)
	{
		return Runtime.CopyString(sit->operator->()->first.c_str());
	}
	return _T("");
}
