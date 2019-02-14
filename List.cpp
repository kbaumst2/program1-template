#include <stdlib.h>

List::List(){
	this->head=NULL;
	this->tail=NULL;
	}

List::~List(){
	this->reset();
	while(this->next!=NULL){
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
	this->reset();
	for(int i=0; i<index; i++){
		if(this->next==NULL){
			tail->next=toAdd;
		}
		else if(i==(index-1)){
			Node * temp=this->current;
			this->current=toAdd;
			while(this->next!=NULL){
					Node * temp=this->next;
					this->next=this->current;	
			}		
		}
		this->current=this->next;			
	}
}

Planet* List::read(int index){
	this->reset();
	for(int i=0; i<index: i++){
		if(this->next!=NULL){
			this->current=this->next;	
			}
		else return NULL;
	}
	return &(this->current->data);
	}

bool List::remove(int index){
	this->reset();
	for(int i=0; i<index;i++){
		if(this->next!=NULL){
			this->current=this->next;
			}
		if(index=index-1){
			while(this->next!=NULL){
				this->current=this->next;
			}
			return true;
		}
	}
	return false;
}

unsigned List::size(){
	int size=0;
	while(this->current!=NULL){
		size++;
		this->current=this->next;
		}
	return size;
}
		

			
				











	
