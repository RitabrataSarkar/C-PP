#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> a(5);
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }

    a.push_back(8);

    for(int i=0;i<6;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    //a.resize(7);
    a.insert(a.begin()+2,9);
    for(int i=0;i<7;i++)
    {
        cout<<a[i];
    }

    cout<<endl;

    a.pop_back();
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<endl;
    }

}