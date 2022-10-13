#include <iostream>

using namespace std;

int stack[4];
int sp = 0;

void push(int value)
{
    stack[sp++] = value;
}

int pop()
{
    return stack[--sp];
}


int main()
{
    push(3);
    push(2);
    push(1);
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    return 0;
}