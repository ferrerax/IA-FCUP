#include "no.hh"

no::no(no * parent, tabuleiro *t)
{
    this->data   = t;
    this->parent = parent;
    this->valid_childs = false;

}

no::~no()
{
}

void no::getChilds(no *childs[]) {
	if (not valid_childs) {    //create it if not created.
		valid_childs = true;
		//TODO: Aquestes linies de sota estan mal, nomes sha de crear el node si el resultat no es nullptr!!!
		this->childs[0] = new no(this,this->data->left());
		this->childs[1] = new no(this,this->data->top());
		this->childs[2] = new no(this,this->data->bot());
		this->childs[3] = new no(this,this->data->right());
	}
	childs = this->childs; //controlled aliasing
}
