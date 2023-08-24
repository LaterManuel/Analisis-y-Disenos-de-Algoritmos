#include <iostream>
using namespace std;
int gVect[100]; // Buffer to save the elements
int gnCount; // Counter to know the number of elements used
void Insert(int elem)
  {
  if( gnCount < 100 ) // we can only insert if there is space
    gVect[gnCount++] = elem; // Insert the element at the end
  }
int main() {
  int top=100;
  for(int a=10;a<=100;a++){
    Insert(a);
    cout<<a<<" ";
  }
}