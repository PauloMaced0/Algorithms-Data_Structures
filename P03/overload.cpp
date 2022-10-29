//
// Tomás Oliveira e Silva, AED, October 2021
//
// example of function overloading (same function name, different argument numbers and/or data types)
//

#include <iostream>

using std::cout; // make this symbol from the std namespace directly visible

void show(const int i)
{
  cout << "int: "
       << i
       << std::endl;
}

void show(const double d)
{
  cout << "double: "
       << d
       << std::endl;
}

void show(const char *s,const char *h = "string: ") // second argument with default value
{
  cout << h
       << s
       << std::endl;
}
void show(int *arr, int size){
  cout << "[" ;
  for (int i = 0; i < size;i++)
  {
    cout << arr[i];
    if(i < size - 1){
      cout << ", ";
    }
  }
  cout << "]"
       << std::endl;
}

void show(char caracter){
  cout << "char: " 
       << caracter
       << std::endl;
}

int main(void)
{
  int arr[5] = {1, 2, 3, 4, 5};
  int size = sizeof(arr)/sizeof(arr[0]);
  show(1.0);
  show("hello");
  show(-3);
  show("John","name: ");
  show('P');
  show(arr, size );
  return 0;
}
