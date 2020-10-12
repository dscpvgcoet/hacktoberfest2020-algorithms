#include<iostream.h>
#include<conio.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

class stack
{
	node *top;
	public:
	stack();
	void push(int);
	int pop();
	int isempty();
	void disp();
	int peek();

	};
stack::stack()
{
	top = NULL;
}

void stack:: push(int val)
{
	node *n;

	n = new node;

	if(n != NULL)
	{
		n->data = val;
		n->next = top;
		top = n;
	}
	else
	{
		cout<<"\n Stack is FULL";
	}
}

void stack::disp()
{
	node * p;

	p = top;

	while(p != NULL)
	{
		cout<<" \n "<<p->data;
		p = p->next;
	}
}

int stack::isempty()
{
	if(top == NULL)
		return 1;
	else
		return 0;
}

int stack::peek()
{
	node *p;
	int  val ;

	if(! isempty())
	{
		p = top;
		val = p->data;
	}
	else
	{
		cout<<"\n Stack is empty";
	}
	return val;
}

int stack::pop()
{
	node *p;
	int val ;

	if(! isempty())
	{
		p = top;
		val = p->data;
		top = p->next;
		delete(p);
		return(val);

	}
	else
	{
		return(-1);

	}
	return val;
}

void main()
{
	clrscr();

	stack s;
	int i=0,x, ch;

	do
	{
		cout<<"\n 1. push ";
		cout<<"\n 2. pop ";
		cout<<"\n 3. peek ";
		cout<<"\n 4. disp ";
		cout<<"\n 5. exit ";
		cout<<"\n enter choice ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				if(i!=6)
				{
				cout<<"\n enter val to push : ";
				cin>>x;
				s.push(x);
				i++;
				}
				else
				{
				  cout<<" stack is full";

				}
				break;
			case 2:
				x = s.pop();
				if(x!=-1)
				{


				cout<<"\n "<<x<<" removed ";
				}
				else
				cout<<"\n stack is empty";

				break;
			case 3:
				x = s.peek();
				cout<<"\n "<<x<<" at top of stack ";
				break;
			case 4:
				s.disp();
				break;
		}
	}while(ch != 5);
}