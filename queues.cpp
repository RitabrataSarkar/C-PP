#include<iostream>
#include<vector>
using namespace std;

class Queue{
    private:
    int size; 
    int front;
    int back;
    vector<int> v;
    public:
    Queue(){
        front=-1;
        back=-1;
        size=0;
    }

    void enqueue(int data){
        v.push_back(data);
        back++;
        if(back==0) 
            front==0;
    }

    void dequeue(){
        if(front==back){
            front=-1;
            back=-1;
        }
        else{
            v.pop_back();
            front++;
        }
    }

    bool isEmpty(){
        return front==-1;
    }

    int getFront(){
        if(front==-1)   return -1;
        return v[front];
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
        cout<<q.getFront()<<" ";
        q.dequeue();
    }
    return 0;
}