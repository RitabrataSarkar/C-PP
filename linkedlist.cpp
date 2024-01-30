#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data)
    {
        val=data;
        next=NULL;
    }
};

void insertAtHead(Node* &head,int val){
    Node* new_node=new Node(val);
    new_node->next=head;
    head=new_node;
}

void insertAtEnd(Node* &head,int val){
    Node* new_node=new Node(val);
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}

void insertAtPosition(Node* &head,int val,int position){
    Node* new_node= new Node(val);
    Node* temp=head;
    int i=0;
    if(position==0){    
        insertAtHead(head,val);
        return;
    }
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

void updateAtPosition(Node* &head,int val,int position){
    Node* temp=head;
    int i=0;
    while(i<position){
        temp=temp->next;
        i++;
    }
    temp->val=val;
}
void deleteAtHead(Node* &head)
{
    Node* temp=head;
    head=head->next;
    free(temp);
}
void deleteAtPosition(Node* &head,int position){
    int i=0;
    if(position==0){
        deleteAtHead(head);
        return;
    }    
    Node* temp=head;
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    temp->next=(temp->next)->next;
}

void display(Node* head){
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node* head=NULL;
    insertAtHead(head,2);
    display(head);
    insertAtHead(head,1);
    display(head);
    insertAtEnd(head,3);
    display(head);
    insertAtPosition(head,4,2);
    display(head);
    updateAtPosition(head,5,1);
    display(head);
    deleteAtPosition(head,0);
    display(head);
    return 0;
}