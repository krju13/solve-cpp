#include<iostream>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int last=a*b;
    while(b){
        int c=b%10;
        cout<<a*c<<"\n";
        b/=10;
    }
    cout<<last;
    return 0;
}

