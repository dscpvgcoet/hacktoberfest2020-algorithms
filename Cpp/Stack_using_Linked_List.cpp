//Siddhant Kulkarni

#include <iostream>
using namespace std;

class node
{
    public:
    int no;
    node *next;
};

class Stack
{
    node *top;
    public:
    Stack()
    {
        top = NULL;
    }
    void push(int);
    void pop();
    void display();
};

void Stack :: push(int num)
{
    node *temp;
    temp = new node();
    temp->no = num;
    if(top == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = top;
    }
    top = temp;
    display();
}

void Stack :: pop()
{
    node *temp;
    if(top==NULL)
    {
        cout << "\nStack Underflow"; 
        return;
    }
    else
    {
        temp = top;
        top = top->next;
        temp->next = NULL;
        cout<<"Popped element is : "<<temp->no;
    }
    display();
}

void Stack :: display()
{
    node* temp;
    if (top == NULL) 
    {  
        cout<<"\nStack is empty";
    }  
    else 
    {  
        cout<<"\nLinked List: "<<endl;
        temp = top;  
        while (temp != NULL) 
        {  
            cout<<temp->no<<"  ";
            temp = temp->next;  
        }  
    }  
}

int main()
{
    Stack S;
    int choice, no;
    cout<<"1) Push element in stack"<<endl;
    cout<<"2) Pop element from stack"<<endl;
    cout<<"3) Exit";
    do
    {
        cout<<"\n\nEnter choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the number to be pushed : ";
                cin>>no;
                S.push(no);
                break;
            }
            case 2:
            {
                S.pop();
                break;
            }
            case 3:
            {
                cout<<"Exit.";
                break;
            }
            default:
            {
                cout<<"Invalid choice";
                break;
            }
        }
    }while(choice!=3);
    
    return 0;
}

/*
OUTPUT :-

1) Push element in stack
2) Pop element from stack
3) Exit

Enter choice : 1
Enter the number to be pushed : 3

Linked List: 
3  

Enter choice : 1
Enter the number to be pushed : 5

Linked List: 
5  3  

Enter choice : 1
Enter the number to be pushed : 7

Linked List: 
7  5  3  

Enter choice : 1
Enter the number to be pushed : 2

Linked List: 
2  7  5  3  

Enter choice : 1
Enter the number to be pushed : 6

Linked List: 
6  2  7  5  3  

Enter choice : 2
Popped element is : 6
Linked List: 
2  7  5  3  

Enter choice : 2
Popped element is : 2
Linked List: 
7  5  3  

Enter choice : 2
Popped element is : 7
Linked List: 
5  3  

Enter choice : 2
Popped element is : 5
Linked List: 
3  

Enter choice : 2
Popped element is : 3
Stack is empty

Enter choice : 2

Stack Underflow

Enter choice : 3
Exit.
*/

