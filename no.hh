#include <list>

#include "tabuleiro.hh"

using std::__cxx11::list;

class no
{
private:
    /* data */
    tabuleiro *data;
    no * parent;
    no childs[4]; //Child array
    bool valid_childs;

public:
    no(no * parent, tabuleiro *t);
    ~no();
    void trackToRoot(no * node_in, list<no>& list_out);
    no ** getChilds();

    const tabuleiro* getData() const {
		return data;
	}

	void setData(tabuleiro * data) {
		this->data = data;
	}
};
