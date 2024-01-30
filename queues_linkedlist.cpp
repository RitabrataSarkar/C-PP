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

class Queue{
    private:
    int size;
    Node* head;
    Node* tail; 
    public:
    Queue(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    void enqueue(int data){
        Node* new_node=new Node(data);
        if(head==NULL){
            head=tail=new_node;
        }        
        else{
            tail->next=new_node;
            tail=new_node;
        }
        size++;
    }

    void dequeue(){
        if(head==NULL){
            cout<<"Queue Underflow";
            return;
        }
        else{
            Node* oldHead=head;
            Node* newHead=head->next;
            head=newHead;
            if(head==NULL) tail=NULL;
            oldHead->next=NULL;
            delete oldHead; 
            
        }
    }

    bool isEmpty(){
        return head==NULL;
    }

    int front(){
        if(head==NULL)return -1;  
        return head->val;
    }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.enqueue(4);
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.dequeue();
    }
    return 0;
}