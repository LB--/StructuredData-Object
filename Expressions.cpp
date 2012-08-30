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
