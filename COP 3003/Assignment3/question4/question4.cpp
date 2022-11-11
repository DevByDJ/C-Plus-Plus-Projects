#include <iostream>
#include <stack>

using namespace std;


int main()
{
  stack<int> myStack;

  //pushing elements to my stack
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);
  myStack.push(4);


  
  cout<<endl<<"The top element in stack is: "<<myStack.top();

  cout<<endl<< "Size of the stack is: "<<myStack.size();

  cout<<endl<<"Elements in stack are: ";

  //Checks if the stacks empty and if it isnt, it'll print the next element in the stack.
  while (!myStack.empty())
  {
    cout<<myStack.top()<<" ";
    myStack.pop();
  }

  return 0;
  
}