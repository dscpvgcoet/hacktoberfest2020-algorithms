#include<iostream>
using namespace std;
struct node{
	int data;
	node * next,*back;
};
class dlinklist
{
	private:
		int number;
		node *head,*curr,*prev;
	public:
		dlinklist()		//create constructor
		{
			head=NULL;
		}
	void create()
	{
		int length;
		cout<<"length of linlist:";
		cin>>length;
		while(length--)
		{
		node * temp=new node();
		cout<<"enter the data:";
		cin>>number;
		temp->data=number;
		temp->next=NULL;
		temp->back=NULL;
			if(head==NULL)
			{
				head=temp;
				curr=temp;
				prev=temp;
			}
			else
			{
				 temp->back=curr;
		   		 curr->next=temp;
		   		 prev=curr;
		   		 curr=curr->next;
			}
		}
	}
	void display()
	{
		node * temp;
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
	}
	void add();
	void remove();
};
void dlinklist :: add()
{
	node * temp=new node();
	node * temp1=head;
	int choice,position;
	cout<<"data wanted to add:";
	cin>>number;
	temp->data=number;
	temp->next=NULL;
	temp->back=NULL;
	 	cout<<"1.add at begin\n 2.add at end\n 3.add at position mentioned\n";
	 	cin>>choice;
	 	switch(choice)
	 	{
	 		case 1:
	 					 temp->next=head;
	 					 head->back=temp;
	 					 head=temp;
	 					 break;
	 		case 2:
	 					while(temp1->next!=NULL)
	 					{
	 						temp1=temp1->next;
	 					}
	 					temp1->next=temp;
	 					temp->back=temp1;
	 					break;
	 		case 3:
	 				cout<<"enter position after want to add data(integer):";
					cin>>position;
					while((position-1)!=0)
					{
						temp1=temp1->next;
						position--;
					}
					temp->next=temp1->next;
					temp->back=temp1;
					temp1->next=temp;
					temp->next->back=temp;
					break;			
	 	}
}
void dlinklist :: remove()
{
	int choice,position;
	node * temp=new node();
	temp=head;
	cout<<"1.delete begining node\n 2.delete end node\n 3.delete node at mentioned positon\n";
	cin>>choice;
	switch(choice)
	 	{
	 		case 1:
	 					 temp=temp->next;
	 					 temp->back=NULL;
	 					 head->next=NULL;
	 					 head=temp;
	 					 break;
	 		case 2:
	 					while(temp->next->next!=NULL)
	 					{
	 						temp=temp->next;
	 					}
	 					temp->next=NULL;
	 					break;
	 		case 3:
	 				cout<<"enter position of node wanted to delete:";
					cin>>position;
					while((position-1)!=0)
					{
						temp=temp->next;
						position--;
					}
					temp->back->next=temp->next;
					temp->next->back=temp->back;
					break;			
	 	}
	
}

int main()
{
int choice;
char ch;
dlinklist d;
do
{
	cout<<" 1.create link list\n 2.display link list\n 3.add number to linklist\n 4.delete node\n";
	cout<<"enter your choice:";
	cin>>choice;
		switch(choice)
		{
			case 1:
					d.create();
					break;
			case 2:
					d.display();
					break;
			case 3:
					d.add();
					break;
			case 4:
					d.remove();
					break;
		}
		cout<<"\ndo you want to countinue:";
		cin>>ch;
}while(ch=='y' || ch=='Y');
return 0;
}
