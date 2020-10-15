// Program to demonstrate bubble sort in C++
#include <iostream>
using namespace std;

class bubbleSort {
  public:
  int i, j, n, temp, arr[20];
  void get_elements();
  void sort();
  void display();
};
void bubbleSort :: get_elements() {
  cout << "Enter the number of elements: ";
  cin >> n;
  for (i = 0; i < n; i++) {
    cout << "Enter number: ";
    cin >> arr[i];
  }
}
void bubbleSort :: sort() {
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[i]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
void bubbleSort :: display() {
  cout << "Displaying sorted elements: " << endl;
  for (i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
int main() {
  bubbleSort obj;
  obj.get_elements();
  obj.sort();
  obj.display();
}