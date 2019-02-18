#include <stdlib.h>

List::List(){
	this->head=NULL;
	this->tail=NULL;
	}

List::~List(){
	this->reset();
	while(this->current!=NULL){
		Node * temp=this->next;
		delete(this->current);
		this->current=temp;
		}
	delete(this->current);
	}

void List::reset(){
	this->current=this->head;
	}


void List::insert(int index, Planet * p){
	Node * toAdd=new Node(*p);
	int position=0;
	this->reset();
	while(this->current!=NULL && position<index){
		if(this->current->next==NULL){
			Node * temp=this->tail;
			this->tail->next=toAdd;
			this->current=this->tail->next;
			this->current->prev=temp;
		}
		else{
		this->current=this->current->next;
		else if(position==(index-1){
			Node * temp=this->current;
			Node * temp2=this->current->prev;
			this->current=toAdd;
			this->current->next=temp;
			this->current->prev=temp2;
			while(this->current->next!=NULL){
				Node * temp =this->current->next;
				Node * temp2=this->current->prev;
				this->current->next=this->current;
				this->current=temp;
				this->current->prev=temp2;
			}
		}
		position++;
		}

	}


Planet* List::read(int index){
	this->reset();
	int position=0
	while(this->current!=NULL && position<index){
		if(this->current->next==NULL){
			return NULL;
		}
		this->current=this->current->next;
		if(position==index-1){
			return &(this->current->data);
		}
		position++;
	}

}

bool List::remove(int index){
	this->reset();
	int position=0;
	while(this->current!=NULL && position<index){
		//		correct check?
		if(this->current->next != NULL){
			this->current=this->current->next;
			}
		if(position==index-1){
			while(this->current->prev!=NULL){
				Node * temp=this->current;
				Node* temp2=this->current->prev;
				this->current=this->current->prev;
				this->current->next=temp;
				this->current->prev=temp2;
			}
			return true;
			}
		}
		return false;
	}


unsigned List::size(){
	int size=0;
	this->reset();
	while(this->current!=NULL){
		size++;
		this->current=this->current->next;
		}
	return size;
}
