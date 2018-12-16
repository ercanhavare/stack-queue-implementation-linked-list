#define STACKSIZE 10
#include <iostream>
#include <cstdlib>
using namespace std;

struct stack{
	int items[STACKSIZE];
	int top;
}Stack; //convert into dynamic

struct node{
	int data;
	struct node * next;	
};//////////////////////////////////////////////////////////////////////////////////////////////////

int isStackEmpty(struct node *header){
	if(header==NULL){
		return 1;
	}else{
		return 0;
	}	
}//////////////////////////////////////////////////////////////////////////////////////////////////

int isStackFull(struct node * header){
	int count=0;
	
	while(header!=NULL){
		count++;
		header=header->next;
		
	}
	return count;
	
}//////////////////////////////////////////////////////////////////////////////////////////////////

struct node * new_node(int inf){
	struct node * temp;
	temp=(struct node *) malloc(sizeof(struct node));
	temp->data=inf;
	temp->next=NULL;
	return temp;
}//////////////////////////////////////////////////////////////////////////////////////////////////

struct node * push(int inf,struct node * header){
	//insert operation is always front of first item
	struct node * temp;
	temp=new_node(inf);//created node
	temp->next=header;
	header=temp;
	return header;
}//////////////////////////////////////////////////////////////////////////////////////////////////

struct node * pop(struct node * header){
	//delete operation is always from first item
	struct node * temp;
		if(isStackEmpty(header)){//check it about header is null
			return header;
		}
		temp=header;
		header=header->next;
		free(temp);//deleted node
		cout<<"poped value"<<endl;			
		return header;
}//////////////////////////////////////////////////////////////////////////////////////////////////

void displayStack(struct node *header){
	if(isStackEmpty(header)){
		cout<<"\nStack is empty!";
	}
	while(!isStackEmpty(header)){
		cout<<header->data<<" ";
		header=header->next;
	}
	
}//////////////////////////////////////////////////////////////////////////////////////////////////
