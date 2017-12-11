#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack<char> St;
    St.push('d');
    St.push('c');
    St.push('b');
    St.push('a');

    St.print();
    cout<<St.top()<<'\n';
    St.pop();
    St.print();
    cout<<St.top()<<'\n';
    St.pop();
    St.print();
    cout<<St.top()<<'\n';
    St.pop();
    St.print();
    cout<<St.top()<<'\n';
    St.pop();
    St.print();

    return 0;
}
