#include<iostream>
using namespace std;

class Stack{
    private:
    int capacity;
    int* arr;
    int top;
    public:
    Stack(int size){
        capacity=size;
        arr=new int[capacity];
        top=-1;
    }

    void push(int data){
        if(top==capacity-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            top++;
            arr[top]=data;
        }
    }

    int pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return INT8_MIN;
        }
        top--;
        return arr[top+1];
    }

    int getTop(){
        if(top==-1){
            cout<<"No element found on stack"<<endl;
            return INT8_MIN;
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top==-1)
            return true;
        else 
            return false;
    }

    bool isFull(){
        if(top==capacity-1)
            return true;
        else 
            return false;
    }

    int size(){
        return top+1;
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