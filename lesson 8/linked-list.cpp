#include <iostream>

using namespace std;

// Node class
class Node{
    private:
        int data;
        Node* next;
  public:
        Node(){
        };
        void setDataLinkedList(int aData){
            data = aData;
        };
        void setNextData(Node* aNext){
            next = aNext;
        };
        int dataLinkedList(){
            return data;
        };
        Node* nextData(){
            return next;
        };
};

// List class
class List{
    private:
        Node* head;
    public:
        List(){
            head = NULL;
        };
        void printLinkedList();
        void addLinkedList(int data);
        void delLinkedList(int data);
};

void List::printLinkedList(){
    // Temp pointer
    Node* tmp = head;
    // No nodes
    if (tmp == NULL){
        cout<<"EMPTY"<<endl;
        return;
    }
    // One node in the list
    if (tmp->nextData() == NULL){
        cout<<tmp->dataLinkedList()<<" --> "<<"NULL"<< endl;
    } else {
            // Parse and print the list
            do {
                cout<<tmp->dataLinkedList()<<" --> ";
                tmp = tmp->nextData();
            } while(tmp != NULL);
            cout<<"NULL"<<endl;
        }
}

 //Add a node to the linked list
 void List::addLinkedList(int data){
    // Create a new node
    Node* newNode = new Node();
    newNode->setDataLinkedList(data);
    newNode->setNextData(NULL);
    // Create a temp pointer
    Node* tmp = head;
    if (tmp != NULL){
        // Nodes already present in the list parse to end of list
        while(tmp->nextData() != NULL){
            tmp = tmp->nextData();
        }
        // Point the last node to the new node
        tmp->setNextData(newNode);
    } else {
            // First node in the list
            head = newNode;
        }
}

//Delete a node from the list
void List::delLinkedList(int data){
    // Create a temp pointer
    Node* tmp = head;
    // No nodes
    if (tmp == NULL){
        return;
    }
    // Last node of the list
    if (tmp->nextData() == NULL){
        delete tmp;
        head = NULL;
    } else {
            // Parse thru the nodes
            Node* prev;
            do {
                if (tmp->dataLinkedList() == data){
                  break;
                }
                prev = tmp;
                tmp = tmp->nextData();
            } while (tmp != NULL);

            // Adjust the pointers
            prev->setNextData(tmp->nextData());

            // Delete the current node
            delete tmp;
        }
}

int main()
{
    // New list
    List list;

    // Add nodes to the list
    list.addLinkedList(2);
    list.printLinkedList();
    list.addLinkedList(5);
    list.printLinkedList();
    list.addLinkedList(7);
    list.printLinkedList();

    // Delete nodes from the list
    list.delLinkedList(7);
    list.printLinkedList();
    list.delLinkedList(5);
    list.printLinkedList();
    list.delLinkedList(2);
    list.printLinkedList();

    return 0;
}
