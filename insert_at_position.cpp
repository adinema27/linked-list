#include<iostream>
using namespace std;
class node{
    
    public:
        int data;
        node* next;

        node(int data){
            this ->data = data;
            this ->next = NULL;
        }
};
void insertAtHead(node* &head, int d){
    node* temp = new node(d);
    temp ->next = head;
    head = temp;
}
void insertAtTail(node* &tail, int d){
    node* temp = new node(d);
    tail ->next = temp;
    tail = temp;
}

void insertAtPosition(node* &head, node* &tail, int position, int d){
    if (position ==1){
        insertAtHead(head, d);
        return;
    }
    // temp pointing at head
    node* temp = head;

    // creating cnt to reach at particular position
    int cnt = 1;

    // traversing 
    while (cnt < position -1 )
    {
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }
    // creating node for d
    node* nodeToInsert = new node(d);
    nodeToInsert ->next = temp -> next;
    temp -> next = nodeToInsert;
}

void print(node* &head){
    node* temp = head;

    while (temp != NULL)
        {
            cout<<temp-> data<< " ";
            temp = temp-> next;
        }
        cout<<endl;    
        }


int main(){
    // new node created
    node* node1 = new node(10);
    // head point towards that node 
    node* head = node1;  
    node* tail = node1; 
    print(head);
    // insertions 
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    print(head);
    insertAtPosition(head, tail, 4, 22);
    print(head);   
}