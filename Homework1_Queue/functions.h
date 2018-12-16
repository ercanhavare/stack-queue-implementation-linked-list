#define QUEUESIZE  10
#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
	int data;
	struct node * next;	
};//////////////////////////////////////////////////////////////////////////////////////////////////


int is_emptyQueue(struct node *header){
	if(header==NULL){
		return 1;
	}else{
		return 0;
	}	
}//////////////////////////////////////////////////////////////////////////////////////////////////

int is_fullQueue(struct node * header){
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

struct node * insert(int inf,struct node * header){
	//insert operation is always back of previous item
	struct node *temp, *headertemp;
	temp=new_node(inf);
	
	if(is_emptyQueue(header)){
		header=temp;
		return header;
	}
	
	headertemp=header;
	while(headertemp->next!=NULL){
		headertemp=headertemp->next;
	}
	headertemp->next=temp;
	return header;
}//////////////////////////////////////////////////////////////////////////////////////////////////

struct node * remove(struct node * header){
	//delete operation is always from first item
	struct node * temp;
		if(is_emptyQueue(header)){//check it about header is null
			return header;
		}
		temp=header;
		header=header->next;
		free(temp);//deleted node
		cout<<"removed value"<<endl;			
		return header;
}//////////////////////////////////////////////////////////////////////////////////////////////////

void displayQueue(struct node *header){
	if(is_emptyQueue(header)){
		cout<<"\nQueue is empty!";
	}
	while(!is_emptyQueue(header)){
		cout<<header->data<<" ";
		header=header->next;
	}
	
}//////////////////////////////////////////////////////////////////////////////////////////////////
