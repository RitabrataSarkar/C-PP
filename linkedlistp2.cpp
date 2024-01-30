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
    
    void insertAtHead(int data){
        Node* new_node=new Node(data);
        new_node->next=head;
        head=new_node;
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

void deleteAlternateNodes(Node* &head){
    Node* temp=head;
    while(temp->next!=NULL&&temp!=NULL){
        Node* deleteWala=temp->next;
        temp->next=temp->next->next;
        free(deleteWala);
        temp=temp->next;
    }
}

void deleteDuplicateElements(Node* &head){
    Node* temp=head;
    while(temp!=0&&temp->next!=0)
    {
        if(temp->val==temp->next->val){
            Node* deleteWala=temp->next;
            temp->next=temp->next->next;
            free(deleteWala);
        }
        temp=temp->next;
    }
}

void printInReverse(Node* &head){
    if(head==NULL)  
        return;
    printInReverse(head->next);
    cout<<head->val<<endl;
    return;
}

int main()
{
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.display();
    printInReverse(ll.head);
    return 0;
}