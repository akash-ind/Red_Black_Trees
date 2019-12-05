#include<iostream>
#include<string>
#include"Redblack.cpp"
using namespace std;
int main()
{
    int n,v;
    char c;
    cout<<"Enter the no of key value pair"<<endl;
    cin>>n;
    while(n)
    {
        cout<<"Enter key"<<endl;
        cin>>c;
        cout<<"Enter Value"<<endl;
        cin>>v;
        redBlack<char,int>::insert(c,v);
        n--;
    }
    cout<<"Enter the value you want to get"<<endl;
    cin>>c;
    cout<<redBlack<char,int>::get(c)<<endl;
    redBlack<char,int>::iterator();
}
