#include <iostream>
#include <stdlib.h>
#include "Planet.h"
#include "List.h"
#include "Star.h"

List::List(){
	this->head=NULL;
	this->tail=NULL;
	}

List::~List(){
	this->reset();
	while(this->current!=NULL){
		Node * temp=this->current->next;
		delete(this->current);
		this->current=temp;
		}
	delete(this->current);
	}

	void List::reset(){
		this->current=this->head;
		}

	void List::next(){
		if(this->current!=NULL){
			this->current=this->current->next;
		}
}


void List::addAtHead(Planet * p){
	this->reset();
	Node * toAdd=new Node(*p);
	Node * temp=this->head;
	this->head=toAdd;
	this->head->next=temp;
	this->head->prev=NULL;
	temp->prev=this->head;
}

void List::addAtTail(Planet *p){
	Node * toAdd=new Node(*p);
	Node * temp=this->tail;
	this->tail=toAdd;
	this->tail->next=NULL;
	this->tail->prev=temp;
	temp->next=this->tail;
}

void List::insert(int index, Planet * p){
	Node * toAdd=new Node(*p);
	int position=0;
	this->reset();

	//Empty list
	if(this->head==NULL){
		this->head=toAdd;
		this->tail=toAdd;
		this->tail->next=NULL;
		this->head->next=NULL;
		this->head->prev=NULL;
	}

	else if(position==index && index==0){
		this->addAtHead(p);
	}

	else{
		while(this->current!=NULL && position<=index){
			if(this->current->next==NULL){
				this->addAtTail(p);
				break;
			}
			else if(position==index){
				Node * temp=this->current;
				Node * temp2=this->current->prev;
				this->current=toAdd;
				this->current->next=temp;
				this->current->prev=temp2;
				temp->prev=this->current;
				temp2->next=this->current;
				break;
			}
			position++;
			this->current=this->current->next;
		}
	}
}


Planet* List::read(int index){
	this->reset();
	int position=0;
	while(this->current!=NULL && position<=index){
		if(position==index){
			return &(this->current->data);
			break;
		}
		else if(this->current->next==NULL){
			return NULL;
			break;
		}
		this->current=this->current->next;
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
	//std::cout<<size<<std::endl;
	while(this->current!=NULL){
		size++;
		//std::cout<<"Hello\n"<<std::endl;
		this->current=this->current->next;
		}
	return size;
}
