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
	 tabuleiro * t;

	 if (not valid_childs) {    //create it if not created.
		valid_childs = true;

		t = this->data->left();
		if (t and (not parent or t->getHash() != parent->getData()->getHash()) ){
			this->childs[0] = new no(this,t);
		}
		else{
			this->childs[0] = nullptr;
		}

		t = this->data->top();
		if (t and (not parent or t->getHash() != parent->getData()->getHash()) ){
			this->childs[1] = new no(this,t);
		}
		else{
			this->childs[1] = nullptr;
		}

		t = this->data->bot();
		if (t and (not parent or t->getHash() != parent->getData()->getHash()) ){
			this->childs[2] = new no(this,t);
		}
		else{
			this->childs[2] = nullptr;
		}

		t = this->data->right();
		if (t and (not parent or t->getHash() != parent->getData()->getHash()) ){
			this->childs[3] = new no(this,t);
		}
		else{
			this->childs[3] = nullptr;
		}
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
