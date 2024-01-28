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
        // destructor
        ~node(){
            int value = this-> data;
            // memory free
            if(this-> next !=NULL){
                delete next;
                this -> next = NULL;
            }
            cout<<"memory is free for: "<<value<<endl;
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

void deleteNode(int position, node* &head){
    // to delete first node
    if(position == 1){
        node* temp = head;

        head = head ->next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        // deleting middle or last node
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while (cnt< position)
        {
            prev = curr;
            curr= curr -> next;
            cnt++;
        }
        prev->next = curr -> next;
        curr-> next =NULL;
        delete curr;
    }
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
    // deletion
    deleteNode(3, head);
    print(head); 
}