#include<iostream>
#include<string.h>
using namespace std;

char stack[20];
int t=-1,n=20;

void push(int val){
  if(t>=n-1)
  cout<<"Stack Overflow!\n";
  else{
    t++;
    stack[t] = val;
  }
 }

void pop(){
  if(t<=-1) cout<<"Stack empty.\n";
  else  t--;
 } 


bool check(char *s){
  int size = strlen(s);
  char x;
  bool val=true;
  for(int i=0;i<size;i++){
    if(s[i]=='{' || s[i]=='[' || s[i]=='('){
      push(s[i]);
      continue;
    }
    else{
      switch(s[i]){
        case ')':
        {
          x = stack[t];
          pop();
          if(x=='[' || x=='{')
          val = false;
          break;
        }
        case ']':
        {
          x = stack[t];
          pop();
          if(x=='(' || x=='{')
          val = false;
          break;
        } 
        case '}':
        {
          x = stack[t];
          pop();
          if(x=='[' || x=='(')
          val = false;
          break;
        } 
      }
    }
  }
  if(t!=-1)
  val = false;
  return val;
 }

int main(){
  char test[20];
  cout<<"Enter sequence of parenthesis: ";
  cin>>test;
  if(check(test))
  cout<<"Balanced.\n";
  else
  cout<<"Not balanced.\n\n";  
  return 0;
 } 
