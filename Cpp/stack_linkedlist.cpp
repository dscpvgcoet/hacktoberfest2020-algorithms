/* Rasika Deshpande
   SE IT
   19012088 (branch change)
*/
#include <iostream>
using namespace std;
class Node {
 public:
 	int no;
 	Node *next;
};
class Stack {
	Node *top;
 	public:
 		Stack() {
 			top = NULL;
 		}
 		void push(int);
 		void pop();
 		void display();
};
void Stack :: push(int num) {
 	Node *temp;
 	temp = new Node();
 	temp->no = num;
 	if(top == NULL) {
 		temp->next = NULL;
 	} else {
 		temp->next = top;
 	}
 	top = temp;
 	display();
}
void Stack :: pop() {
 	Node *temp;
 	if(top==NULL) {
 		cout << "\nStack Underflow\n";
 		return;
 	} else {
 		temp = top;
 		top = top->next;
 		temp->next = NULL;
 		cout<<temp->no<<" is popped.";
 	}
 	display();
}
void Stack :: display() {
 	Node* temp;
 	if (top == NULL) {
 		cout<<"\nStack is empty\n";
 	} else {
 		cout<<"\nStack: "<<endl;
 		temp = top;
 		while (temp != NULL) {
 			cout<<temp->no<<" ";
 			temp = temp->next;
 		}
 		cout<<"\n\n";
 	}
}
int main() {
 	Stack S;
 	int choice, no;
 	do {
 		cout<<"1. Push element in stack\n2. Pop element from stack\n3. Exit"<<endl;
 		cout<<"\nEnter choice : ";
 		cin>>choice;
 		switch(choice) {
 			case 1:
 			{
 				cout<<"\nEnter the number to be pushed : ";
 				cin>>no;
 				S.push(no);
 				break;
 			}
 			case 2:
 				S.pop();
 				break;
 			case 3:
			 	cout<<"Exit.";
 				break;
 
 			default:
 				cout<<"Invalid choice";
 				break;
 
 		}
 	}while(choice!=3);

 return 0;
}


