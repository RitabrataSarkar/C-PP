#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head=NULL;
    }
    void insertAtTail(int data){
        Node* new_node=new Node(data);
        if(head==NULL)
        {
            head=new_node;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

void printInReverse(Node* &head){
    if(head==NULL)  
        return;
    printInReverse(head->next);
    cout<<head->val<<endl;
    return;
}

Node* reverseList(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    Node* new_head=prev;
    return new_head;
}

Node* reverseListRecursion(Node* &head){
    if (head==NULL||head->next==NULL){
        return head;
    }
    Node* new_head=reverseListRecursion(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
}

Node* reversekLL(Node* &head,int k){
    Node* prev=NULL;
    Node* curr=head;

    int counter=0;//for counting first k nodes
    while(curr!=0&&counter<k){// reversing first k nodes
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        counter++;
    }
    if(curr!=NULL){//curr will give us first k+1 nodes
        Node* new_head=reversekLL(curr,k);
        head->next=new_head;    
    }
    return prev;//will give us new head of the connected list
}

int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();
    ll.head=reversekLL(ll.head,2);
    ll.display();
    return 0;
}