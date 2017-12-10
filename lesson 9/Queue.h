#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <string>

using namespace std;

template<class T>
class NodeQueue{
public:
    NodeQueue():head(0), tail(0){
    }

    ~NodeQueue(){
        delete head;
        delete tail;
    }

    void enqueue(T val){
        Node* Temp = new Node;
        Temp->elem = val;
        if(head == 0){
            head = Temp;
            tail = Temp;
            return;
        }
        tail->next = Temp;
        tail = Temp;
    }

    void dequeue(){
        if (empty()){
            throw string("Queue is empty");
        }
        Node* delPtr = head;
        cout<<"Element "<< head->elem <<" is deleted from the queue\n";
        head = head->next;
        delete delPtr;
    }

    const T& front() const{
        if (empty()){
            throw string("Queue is empty");
        }
        return head->elem;
    }

    void print() const{
        if (empty()){
            throw string("Queue is empty");
        }
        for(Node* ptr = head; ptr != 0; ptr = ptr->next){
            cout<<ptr->elem<<' ';
        }
        cout<<'\n';
    }

    bool empty() const{
        return head == 0;
    }
private:
    struct Node{
        Node():next(0), elem(0)
        {
        }
        Node* next;
        T elem;
    };
    Node* head;
    Node* tail;
};
#endif
