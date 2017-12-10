#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    try{
        NodeQueue<int> Queue;
        Queue.enqueue(10);
        Queue.enqueue(20);
        Queue.enqueue(30);
        cout<<"Top is: "<<Queue.front()<<'\n';
        Queue.dequeue();
        Queue.print();
    }catch(const string& e){
        cout<<e<<'\n';
    }
}
