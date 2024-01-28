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
void insertAtTail(node* &tail, int d){
            node* temp = new node(d);
            tail ->next = temp;
            tail = temp;
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
    node* tail = node1; 
    node* head = node1;   
    print(head);
    // insertions 
    insertAtTail(tail, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);
}