#include "tabuleiro.hh"

class no
{
private:
    /* data */
    tabuleiro *data;

    no *filhos[4];

public:
    no(tabuleiro *t);
    ~no();

	const tabuleiro* getData() const {
		return data;
	}

	void setData(const tabuleiro *&data) {
		this->data = data;
	}
};
