#include <stdlib.h>
#include "List.h"

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
	while(this->current!=NULL && position<=index){
		if(this->current->next==NULL){
			Node * temp=this->tail;
			this->tail->next=toAdd;
			this->current=this->tail->next;
			this->current->prev=temp;
			this->tail=this->current;
		}
		else{
		this->current=this->current->next;
		  if(position==(index){
				if(this->current=this->head){
					Node * temp=this->current;
					this->head=toAdd;
					this->current=this->head;
					this->current->next=temp;
					this->current->prev=NULL;
					temp->prev=this->current;
				}
			else{
				Node * temp=this->current;
				Node * temp2=this->current->prev;
				this->current=toAdd;
				this->current->next=temp;
				this->current->prev=temp2;
				temp->prev=this->current;
				temp2->next=this->current;
				}
			break;

		}
		position++;
		}

	}


Planet* List::read(int index){
	this->reset();
	int position=0
	while(this->current!=NULL && position<=index){
		if(this->current->next==NULL){
			return NULL;
		}
		this->current=this->current->next;
		if(position==index){
			return &(this->current->data);
		}
		position++;
	}

}
//chekc for special cases tail or head
bool List::remove(int index){
	this->reset();
	int position=0;
	while(this->current!=NULL && position<=index){
		Node * curr=this->current;
		if(position==index){
				if(this->current==this->head){
					this->head=this->current->next;
					this->head->prev=NULL;
					delete this->current;
				}
				else if(this->current==this->tail){
					this->tail=this->current->prev;
					this->tail->next=NULL;
					delete this->current;
				}
				else{
				this->current->prev->next=this->current->next;
				this->current->next->prev=this->current->prev;
				delete this->current;
				this->current=NULL;
			}
				//OR this->reset();
			return true;
			}
			position++;
			this->current=curr->next;
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
