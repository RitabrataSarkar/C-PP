#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(4);
    s.insert(5);
    cout<<s.size()<<endl;
    s.insert(3);
    cout<<s.size()<<endl;
    for(auto value:s){
        cout<<value<<" ";
    }cout<<endl;
    //s.erase(4);

    // auto itr=s.begin();
    // advance(itr,3);
    // s.erase(itr);

    auto start_itr=s.begin();
    start_itr++;

    auto end_itr=s.begin();
    advance(end_itr,3);

    s.erase(start_itr,end_itr); 

    //traversing a set
  //  set<int>::iterator itr;
    // for(itr=s.begin();itr!=s.end();i++){
    //     cout<<*itr<<" ";
    // }cout<<endl;
    for(auto value:s){
        cout<<value<<" ";
    }cout<<endl;
    return 0;
}