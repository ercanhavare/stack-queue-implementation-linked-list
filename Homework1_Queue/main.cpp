#include <iostream>
#include "functions.h"
#define QUEUESIZE 10
using namespace std;

/* Ercan Havare */

int main(int argc, char** argv) {
	int key,pushValue;
	
	struct node * Queue=NULL;
do{
	cout<<"\nQueue Menu"<<endl;
	cout<<"1) Insert item to Queue "<<endl;
	cout<<"2) Remove item from Queue"<<endl;
	cout<<"3) Display all values on Queue"<<endl;
	cout<<"4) Exit"<<endl;
	
	cout<<"Please, select option from menu : ";
	cin>>key;
	
		switch(key){
			case 1://push item
				if(is_fullQueue(Queue)<QUEUESIZE){
					cout<<"Please,enter number : ";
					cin>>pushValue;
	
						Queue=insert(pushValue,Queue);//push items to Linked List from here
						cout<<"======================================="<<endl;
						cout<<"Remained "<<(QUEUESIZE -is_fullQueue(Queue))<<" empty values"<<endl;	
						cout<<"======================================="<<endl;
						
					}else{
						cout<<"======================================="<<endl;
						cout<<"You have "<<QUEUESIZE <<" values,please remove a few values!"<<endl;
						cout<<"======================================="<<endl;
					}
							
				break;
				
			case 2://pop item
				
				if(is_emptyQueue(Queue)){
					cout<<"=======================================";
					cout<<"\nQueue is empty, you can not pop!"<<endl;
					cout<<"======================================="<<endl;
				}else{
					cout<<"======================================="<<endl;
					Queue=remove(Queue);//pop items
					cout<<"Remained "<<(QUEUESIZE -is_fullQueue(Queue))<<" empty values"<<endl;
					cout<<"======================================="<<endl;
				}
				
				break;
				
			case 3://show it Linked List values
				cout<<"======================================="<<endl;
				displayQueue(Queue);
				cout<<"\nYou have "<<(is_fullQueue(Queue))<<" values"<<endl;
				cout<<"======================================="<<endl;
				break;
				
			case 4://exit
				cout<<endl;
				cout<<"======================================="<<endl;
				cout<<"Goodbye :)"<<endl;
				cout<<"======================================="<<endl;
				break;
		}
	}while(key!=4);


	return 0;
}
