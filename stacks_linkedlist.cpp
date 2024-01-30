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

class Stack{
    Node* head;
    int capacity;
    int top;
    int currSize;

    public:
    Stack(int size){
        capacity=size;
        currSize=0;
        head=NULL;
    }

    bool isEmpty(){
        if(currSize==0) return true;
        else return false;
    }

    
    bool isFull(){
        if(currSize==capacity) return true;
        else return false;
    }

    void push(int data){
        if(currSize==capacity){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        Node* new_node=new Node(data);
        new_node->next=head;
        head=new_node;
        currSize++;
    }

    int pop(){
        if(currSize==0){
            cout<<"Stack Underflow"<<endl;
            return INT8_MIN;
        }
        currSize--;
        Node* new_head=head->next;
        head->next=NULL;
        Node* toBeDeleted=head;
        int result=toBeDeleted->val;
        delete toBeDeleted;
        head=new_head;
        return result;
    }
    int getTop(){
        if(currSize==0){
            cout<<"Stack Underflow"<<endl;
            return INT8_MIN;
        }
        return head->val;
    }
    int size(){
        return currSize;
    }
};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.getTop()<<endl;
    st.push(4);
    st.push(5);
    cout<<st.getTop()<<endl;
    st.push(8);

    return 0;
}