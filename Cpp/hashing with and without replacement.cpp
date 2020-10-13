

/*

Store data of students with telephone no and name in the structure using hashing function for telephone number and
implement chaining with and without replacement.

*/


#include <iostream>
#include<string.h>
#include<iomanip>
#define data 11

using namespace std;


class student                            //class student
{
    char name[40],mobile_no[10];
    int chain;

    public:

    student()
    {
        name[0]=mobile_no[0]='\0';
        chain=-1;
    }

    int valid_number(char x[]);
    void getdata();
    void display();
    int get_chain();
	char* get_number();
	void update_chain(int x);

};


int student::valid_number(char x[])            //function to check if mobile no. is valid or not
{
    int len,i;

    len=strlen(x);

    if(len!=10)                             //if length is not equal to 10
        return 0;

    for(i=0;i<len;i++)
    {
        if(x[i]<48 || x[i]>57)              //if entered characters are not digits
            return 0;
    }

    return 1;
}


void student::getdata()                   //function to get inputs
{
    int flag=1;

	cout<<"\nEnter name :";
	cin>>name;

    cout<<"\nEnter mobile number :";
    cin>>mobile_no;

    flag=valid_number(mobile_no);

    while(flag==0)
    {
        cout<<"\nINVALID!!!   ENTER AGAIN";
        cout<<"\nEnter mobile number :";
        cin>>mobile_no;

        flag=valid_number(mobile_no);
    }
}


void student::display()               //function to display output
{
      cout<<"\n"<<left<<setw(10)<<name<<left<<setw(20)<<mobile_no<<left<<setw(5)<<chain;
}


int student::get_chain()            //function to return value of chain
{
	return chain;
}


char* student::get_number()        //function to return mobile no.
{
	return mobile_no;
}


void student::update_chain(int x)      //function to update value of chain
{
	chain=x;
}


class hashing                            //class hash
{
    student table[data];
    int n;
    int hash1(char number[]);

    public:

    hashing()
    {
        n=0;
    }

    void insert_without_replacement();
    void insert_with_replacement();
    void display();
	void disp(int x);
	int search1(char number[]);
	void clear1();
};


int hashing::hash1(char number[])         //function to return index
{
	int total=0,i;

	for(i=0;i<10;i=i+2)                                  //loop to calculate sum of no. formed by 2 digits alternatively
	{
		total+=((number[i]-48)*10)+(number[i+1]-48);
	}

	return total%data;

}


void hashing::insert_without_replacement()                  //function to insert data in hash table without replacement
{

	if(n!=data)                                            //if hash table is not full
	{
		int index,old_index;

		student S;

		S.getdata();

		index=hash1(S.get_number());

		if(strcmp(table[index].get_number(),"\0")!=0)       //if another data is already present
		{
			while(table[index].get_chain()!=-1)
			{
				index=table[index].get_chain();            //storing value of chain in index
			}

			old_index=index;

			while(strcmp(table[index].get_number(),"\0")!=0)   //if another data is already present
			{
				index=(index+1)%data;
			}

			table[old_index].update_chain(index);
		}

		table[index]=S;

		n++;
	}

	else
		cout<<"\nTable is full!";

}


void hashing::insert_with_replacement()                    //function to insert data in hash table with replacement
{
	if(n!=data)
	{
		int index,old_index,tempindex;

		student S,temp;

		S.getdata();

		index=hash1(S.get_number());

		if(strcmp(table[index].get_number(),"\0")!=0)         //if another data is already present
		{
			if(hash1(table[index].get_number())==index)      //if another data is at correct index
			{
				while(table[index].get_chain()!=-1)
				{
					index=table[index].get_chain();          //storing value of chain in index
				}

				old_index=index;

				while(strcmp(table[index].get_number(),"\0")!=0)   //if another data is already present
				{
					index=(index+1)%data;
				}

				table[old_index].update_chain(index);
			}

			else                                        //if another data is not at correct index
			{
				temp=table[index];
				table[index]=S;
				S=temp;

				old_index=index;

				while(strcmp(table[index].get_number(),"\0")!=0)
				{
					index=(index+1)%data;
				}

				tempindex=hash1(S.get_number());

				while(table[tempindex].get_chain()!=old_index)
				{
					tempindex=table[tempindex].get_chain();
				}

				table[tempindex].update_chain(index);
			}
		}

		table[index]=S;
		n++;
	}
	else
		cout<<"\nTable is full!";
}


void hashing::disp(int index)
{
    cout<<"\n"<<left<<setw(10)<<"Name"<<left<<setw(20)<<"Mobile_no"<<left<<setw(5)<<"Chain";
	table[index].display();
}


void hashing::display()                          //function to display records
{
	cout<<"\n"<<left<<setw(10)<<"Name"<<left<<setw(20)<<"Mobile_no"<<left<<setw(5)<<"Chain";

	int i;

	for(i=0;i<data;i++)
       table[i].display();

}


int hashing::search1(char key[])                      //function to search data
{
	int index=hash1(key);

	while(index!=-1 && strcmp(table[index].get_number(),key)!=0)
	{
		index=table[index].get_chain();
	}

	return index;
}


void hashing::clear1()
{
	student S;

	for(int cnt=0;cnt<data;cnt++)
	{
		table[cnt]=S;
	}
}

int main()
{
    hashing h;
    student s;

	char key[10];

	int ch,ch1,index,f;

	do
	{
	    //h.clear1();
		cout<<"\n\nWhat type of collision resolution?";
		cout<<"\n\n1.Chaining with replacement";
		cout<<"\n2.Chaining without replacement";
		cout<<"\n3.EXIT";
		cout<<"\nEnter choice :";
		cin>>ch;

		if(ch==1 || ch==2)
		{
			do
			{
				cout<<"\n\n1.Add record";
				cout<<"\n2.Display records";
				cout<<"\n3.Search record";
				cout<<"\nEnter choice :";
				cin>>ch1;

				switch(ch1)
				{
					case 1:

                    if(ch==2)
                      h.insert_without_replacement();

                    else
                      h.insert_with_replacement();

                    break;


					case 2:

                    h.display();

                    break;


					case 3:

                    cout<<"Enter number to search :";
                    cin>>key;

                    if(s.valid_number(key))
                    {
                        index=h.search1(key);

                        if(index==-1)
                        cout<<"\nRecord not found!!!";

                        else
                        {
								h.disp(index);
                        }
                    }

                    else
                      cout<<"\nInvalid number!!!";

					break;

				}

				cout<<"\n\nDo u want to select another choice ?  (0/1) :";
				cin>>f;
			}

			while(f==1);
		}
	}

	while(ch!=3);

    return 0;
}

