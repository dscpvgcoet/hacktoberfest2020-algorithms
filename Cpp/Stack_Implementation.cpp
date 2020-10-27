#include <iostream>
#include "stack_array.h"
using namespace std;
int main(){
  cout << "enter number of elements in stack "<<endl;
  int num;
  int opt;
  cin >> num;
  stackarray a(num);
  label:
    int option;
      cout << "Enter option     1.push   2.pop "<<endl;
      cin >> option;
      switch (option) {
      case 1:
        cout << "enter key to add to stack "<<endl;
        int element;
        cin >> element;
        a.push(element);
        cout << "top is " << a.top << endl;
        //cout << "top element is " << a.arr[a.top] << endl;
        break;
      case 2:
        cout << "popped element is " << a.pop()<<endl;
        break;
  }
  cout << "would you like to choose from the menu again? 1 for yes, 0 for no "<<endl;
  cin >> opt;
  if (opt == 1) {
    goto label;
  } else cout << "Thank you "<<endl;

}
