#include "Common.h"

int Extension::NodeID()
{
	return cur->ID;
}
int Extension::Int(const char *Name)
{
	return cur->im[Name];
}
float Extension::Float(const char *Name)
{
	return cur->fm[Name];
}
const char *Extension::String(const char *Name)
{
	return Runtime.CopyString(cur->sm[Name].c_str());
}
const char *Extension::SubnodeName()
{
	return Runtime.CopyString(nit.back()->operator->()->first.c_str());
}
const char *Extension::IntName()
{
	if(iit)
	{
		return Runtime.CopyString(iit->operator->()->first.c_str());
	}
	return"";
}
const char *Extension::FloatName()
{
	if(fit)
	{
		return Runtime.CopyString(fit->operator->()->first.c_str());
	}
	return"";
}
const char *Extension::StringName()
{
	if(sit)
	{
		return Runtime.CopyString(sit->operator->()->first.c_str());
	}
	return"";
}
