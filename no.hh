#include "tabuleiro.hh"

class no
{
private:
    /* data */
    tabuleiro *data;
    no * parent;
    bool valid_childs;
    no childs[4]; //Child array

public:
    no(no * parent, tabuleiro *t);
    ~no();

    void getChilds(no * childs[]);

    const tabuleiro* getData() const {
		return data;
	}

	void setData(tabuleiro * data) {
		this->data = data;
	}
};
