#include<iostream>

using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    int res=A*B*C;
    int num[10]={0};
    while(res){
        int a=res%10;
        num[a]++;
        res/=10;
    }
    for(int i=0;i<10;i++){
        cout<<num[i]<<"\n";
    }
    return 0;
}

