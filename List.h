#ifndef LIST_H
#define LIST_H
#include <iostream>

class Node{
public:
	Planet data;
	Node * next, * prev;
	Node(Planet p) {data=p; next=NULL;}
	};

class List{
private:
	Node *head, *tail, *current;
public:
	List();
	~List();
	void insert(int index, Planet * p);
	Planet* read(int index);
	bool remove(int index);
	unsigned size();
	void reset();

};



#endif
