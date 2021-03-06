#ifndef _STACK_H_
#define _STACK_H_

#include <string>

using namespace std;

template <class T>
class Stack
{
public:
    Stack():tail(0), head(0){
    }

    ~Stack(){
        delete tail;
        delete head;
    }

    void push(T val){
        Node* Temp;
        Temp = new Node;
        Temp->elem = val;
        if(tail == 0){
            tail = Temp;
        } else{
            Temp->next = tail;
            tail = Temp;
        }
    }

    T top(){
        if(tail == 0){
            cout<<"Stack is empty!";
        }
        return tail->elem;
    }

    void pop(){
        if(tail == 0){
            cout<<"Stack is empty!";
        }
        Node* delptr = tail;
        tail = tail->next;
        delete delptr;
    }

    void print(){
        if(tail == 0){
            cout<<"Stack is empty!";
        }
        for(Node* ptr = tail; ptr != 0; ptr = ptr->next){
            cout<<ptr->elem<<' ';
        }
        cout<<'\n';
    }
private:
    struct Node{
        Node():elem(0), next(0){
        }
        Node* next;
        T elem;
    };
    Node* head;
    Node* tail;
};

#endif
