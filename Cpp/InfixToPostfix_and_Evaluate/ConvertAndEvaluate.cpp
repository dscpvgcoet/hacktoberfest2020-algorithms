#include<iostream>
#include<string.h>
using namespace std;
class stack2
{
    public:
    char a[50];
    int top=-1,size,data;
    
    void create();
    void push(char);
    void pop();
    int priority(char);

};



void stack2::push(char  op)
{
    if(top==size) 
    cout<<"\n stack is full";
    else
    {
    
       a[++top]=op;
    }
    
}

void stack2::pop()
{
  data=a[top];
  top--;
}

int stack2::priority(char x)
{
     if(x=='/' || x=='*')
    {
    return 3;
    }
    else if(x=='+' || x=='-')
    
        return 2;
    else 
    return 1;

}

int main()
{
    string s,s1;
    int y,y1,j=0,t;
    stack2 obj;
    
    cout<<"\n Enter a string whose value needs to be evaluated through:";
    cin>>s;

     obj.size=s.length();
      cout<<"size is"<<obj.size;

    for(int i=0;s[i]!='\0';i++)
    {
         if(s[i]=='/' || s[i]=='*' || s[i]=='+' || s[i]=='-' )
         {
         y=obj.priority(s[i]);
         y1=obj.priority(obj.a[obj.top]);
              
           if(obj.top==-1 )
           obj.push(s[i]);
           else if(y1>=y)
           {
           obj.pop();
           obj.push(s[i]);
           s1[j]=obj.data;
           j++;
           }
            else if(y1<y)
            obj.push(s[i]);
           }
           else if(s[i]=='(')
           {
           obj.push(s[i]);
           }

           else if( s[i]==')')
            {    
               //  t=i;
                 while(obj.a[obj.top]!='(')
                  {
                      obj.pop();
                       s1[j]=obj.data;
                       j++;
                       
                  }
                  obj.pop();
            }

              else
             {
             s1[j]=s[i];
             j++;
             }
         
    }
    

     while(obj.top!=-1)
      {
           
              obj.pop();
              s1[j]=obj.data;
           j++;
           
       }
       cout<<endl;


    cout<<"\nOn Conversion: ";
    for(int k=0;s1[k]!='\0';k++)
    cout<<s1[k];
    
//evaluation


  
char oper;
int data1,data2,ans;

    for(int i=0;s1[i]!='\0';i++)
    {
         if(s1[i]=='/' || s1[i]=='*' || s1[i]=='+' || s1[i]=='-')
         {
           oper=s1[i];
           obj.pop();
           data1=(int)obj.data-48;
           obj.pop();
           data2=(int)obj.data-48;

           switch(oper)
           {
             case '+':
              ans=data1+data2;
              break;

              case '-':
              ans=data2-data1;
              break;

              case '*':
              ans=data1*data2;
              break;

              case '/':
              ans=data2/data1;
              break;
           }
           obj.push((char)ans+48);

         }

             else
             {
                 obj.push(s1[i]);
             }
    }
    
    cout<<endl;
    cout<<"Value on evaluation : ";
    cout<<(int)obj.a[0]-48;   


return 0;
} 

/*output

 Enter a string whose value needs to be evaluated through:((3-1)*(4+2))/3
size is15
31-42+*3/
Value on evaluation : 4
*/
