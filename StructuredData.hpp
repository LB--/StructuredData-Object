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

	typedef std::map<std::string, SDNode *> nmt;
	nmt nm;
	typedef std::map<std::string, int> imt;
	imt im;
	typedef std::map<std::string, float> fmt;
	fmt fm;
	typedef std::map<std::string, std::string> smt;
	smt sm;
};

#endif
