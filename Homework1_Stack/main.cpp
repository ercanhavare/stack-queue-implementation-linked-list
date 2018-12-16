#include <iostream>
#include "functions.h"
#define STACKSIZE 10
using namespace std;

/* Ercan Havare */

int main(int argc, char** argv) {
	int key,pushValue;
	
	struct node * Stack=NULL;
do{
	cout<<"\nStack Menu"<<endl;
	cout<<"1) Push item to Stack "<<endl;
	cout<<"2) Pop item from Stack"<<endl;
	cout<<"3) Display all values on Stack"<<endl;
	cout<<"4) Exit"<<endl;
	
	cout<<"Please, select option from menu : ";
	cin>>key;
	
		switch(key){
			case 1://push item
				if(isStackFull(Stack)<STACKSIZE){
					cout<<"Please,enter number : ";
					cin>>pushValue;
	
						Stack=push(pushValue,Stack);//push items to Linked List from here
						cout<<"======================================="<<endl;
						cout<<"Remained "<<(STACKSIZE-isStackFull(Stack))<<" empty values"<<endl;	
						cout<<"======================================="<<endl;
						
					}else{
						cout<<"======================================="<<endl;
						cout<<"You have "<<STACKSIZE<<" values,please pop a few values!"<<endl;
						cout<<"======================================="<<endl;
					}
							
				break;
				
			case 2://pop item
				
				if(isStackEmpty(Stack)){
					cout<<"=======================================";
					cout<<"\nStack is empty, you can not pop!"<<endl;
					cout<<"======================================="<<endl;
				}else{
					cout<<"======================================="<<endl;
					Stack=pop(Stack);//pop items
					cout<<"Remained "<<(STACKSIZE-isStackFull(Stack))<<" empty values"<<endl;
					cout<<"======================================="<<endl;
				}
				
				break;
				
			case 3://show it Linked List values
				cout<<"======================================="<<endl;
				displayStack(Stack);
				cout<<"\nYou have "<<(isStackFull(Stack))<<" values"<<endl;
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
