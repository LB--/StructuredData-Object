#ifndef __StructuredData_HeaderPlusPlus__
#define __StructuredData_HeaderPlusPlus__
#include <map>

struct SDNode
{
	const int ID;
private:
	static int NextID()
	{
		static int nid = 0;
		return nid++;
	}
	typedef std::map<int, SDNode *> nodes_t;
	static nodes_t nodes;
public:
	typedef nodes_t Nodes_t;
	static const Nodes_t &Nodes;
	SDNode() : ID(NextID())
	{
		nodes[ID] = this;
	}
	~SDNode()
	{
		nodes.erase(ID);
	}

	typedef std::map<stdtstring, SDNode *> nmt;
	nmt nm;
	typedef std::map<stdtstring, int> imt;
	imt im;
	typedef std::map<stdtstring, float> fmt;
	fmt fm;
	typedef std::map<stdtstring, stdtstring> smt;
	smt sm;
};

#endif
