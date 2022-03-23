#include "no.hh"

no::no(no * parent, tabuleiro *t)
{
    this->data   = t;
    this->parent = parent;
    this->valid_childs = false;
    if (parent == nullptr){
    	depth = 0;
    }
    else {
    	depth = parent->depth + 1;
    }

}

no::~no()
{
	delete this->data;
}


 no ** no::getChilds() {
	if (not valid_childs) {    //create it if not created.
		valid_childs = true;
		this->childs[0] = this->data->left()  ? new no((no*)this,(tabuleiro *)this->data->left())  : nullptr;
		this->childs[1] = this->data->top()   ? new no((no*)this,(tabuleiro *)this->data->top())   : nullptr;
		this->childs[2] = this->data->bot()   ? new no((no*)this,(tabuleiro *)this->data->bot())   : nullptr;
		this->childs[3] = this->data->right() ? new no((no*)this,(tabuleiro *)this->data->right()) : nullptr;
	}
	return this->childs; //controlled aliasing
}

void no::trackToRoot(list<no*> &list_out) {
	no * node = this;

	while(node->parent){
		list_out.push_front(node);
		node = node->parent;
	}

	list_out.push_front(node);  //last node
}

tabuleiro* no::getData() const {
	return data;
}

void no::setData(tabuleiro * data) {
	this->data = data;
}

void no::notifyChildLeaf(no * childNode)
{
	int alreadyNull = 0;
	for (size_t i = 0; i < 4; i++)
	{
		if(this->childs[i] == nullptr)
		{
			alreadyNull++;
		} else if (this->childs[i] == childNode)
		{
			this->childs[i] = nullptr;
		}
	}
	if(alreadyNull == 3) {
		this->parent->notifyChildLeaf(this);
		delete this;
	}
	
}

no** no::getChildsNoCreate() {
	return this->childs;
}

bool no::isLeaf() {
	if(this->valid_childs) {
		//int nchildren = 0;
		for (size_t i = 0; i < 4; i++)
		{
			if(this->childs[i] != nullptr) return false;
		}
		
	} else {
		return false;
	}
	return true;
}
