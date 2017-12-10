#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack <char> St;
    St.push('a');
    St.push('b');
    St.push('c');
    St.push('d');
    try{
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
    }
    catch(const string& e){
        cout<<e<<'\n';
    }
    return 0;
}
