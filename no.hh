#ifndef __NO_H__
#define __NO_H__

#include <list>

#include "tabuleiro.hh"

using std::list;

class no
{
private:
    /* data */
    tabuleiro *data;
    no * parent;
    no * childs[4]; //Child array
    bool valid_childs;
    int depth;

public:
    no(no * parent, tabuleiro *t);
    ~no();
    void trackToRoot(list<no*>& list_out);
    no ** getChilds();
    no ** getChildsNoCreate();

    tabuleiro* getData() const;

	void setData(tabuleiro * data);

	no * getParent() const {
		return parent;
	}

	int getDepth() const {
		return depth;
	}
    void notifyChildLeaf(no * childNode);
    bool isLeaf();
};

#endif
