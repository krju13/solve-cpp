//
// Created by juyeon kim on 2021/03/23.
//
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

string Reverse(string b){
    string rt;
    for(int i=b.size()-1;i>=0;i--){
        rt.push_back(b[i]);
    }
    return rt;
}
bool ismake(string a,string b,string rb){
    if(a.compare(b)==0){
        return true;
    }
    if(a.size()>b.size())return false;
    if(b.find(a)!=string::npos||rb.find(a)!=string::npos){
        bool a=ismake(a+"A",b,rb);
        bool b=ismake(Reverse(a)+"B",b,rb);
    }
    else
        return false;
}
int main(){
    string a,b;
    cin>>a>>b;
    string rb=Reverse(b);
    cout<<rb;




    return 0;
}
