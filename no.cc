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

 no ** no::getChilds() {
	if (not valid_childs) {    //create it if not created.
		valid_childs = true;
		this->childs[0] = this->data->left()  ? new no(this,this->data->left())  : nullptr;
		this->childs[1] = this->data->top()   ? new no(this,this->data->top())   : nullptr;
		this->childs[2] = this->data->bot()   ? new no(this,this->data->bot())   : nullptr;
		this->childs[3] = this->data->right() ? new no(this,this->data->right()) : nullptr;
	}
	return this->childs; //controlled aliasing
}

void no::trackToRoot(no *node_in, list<no> &list_out) {
}
