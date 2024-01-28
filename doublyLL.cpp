#include<iostream>
#include<map>
using namespace std;


class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int d){
        this -> data =d;
        this -> prev = NULL;
        this -> next = NULL;
    }  
};


void print(node* head){
    node* temp = head;
    
    while(temp != NULL){
        cout<<temp->data<< " ";
        temp = temp-> next;
    }
    cout<<endl;
}

/*int getLength(node* head){
    node* temp = head;
    int cnt = 0; 
    while(temp != NULL){
        cnt++;
        temp = temp-> next;
    }
    return cnt;
}
*/
void insertAtHead(node* &head, int d){
    // new node is created
    node* temp = new node(d);
    temp ->next = head;
    head -> prev = temp;
    head = temp;
}
void insertAtTail(node* &tail, int d){
    node* temp = new node(d);
    tail-> next = temp;
    temp -> prev = tail;
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
    nodeToInsert -> next = temp ->next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev - temp; 
}

bool detectLoop (node* head){
    if(head == NULL)
        return false;
    
    map<node*, bool> visited;

    node* temp = head;

    while (temp != NULL)
    {
        if(visited[temp] == true){
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
    
}

int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    print(head);
    // cout<<getLength(head);
    insertAtHead(head, 11);
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 13);
    print(head);
    insertAtTail(tail, 9);
    print(head);

    insertAtPosition(head, tail, 6, 8);
    print(head);
    insertAtPosition(head, tail, 3, 111);
    print(head);
    tail = head ->next;
    print(head);
    cout<<tail->data;
    if (detectLoop(head) )
    {
        cout<<"loop is detected"<<endl;
    }
    else{
        cout<< "no loop"<<endl;
    }
    
}