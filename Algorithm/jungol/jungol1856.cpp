#include<iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        if(i&1) {
            for (int j = i*m-m+1; j <= i*m; j++) {
                cout<<j<<" ";
            }
            cout<<"\n";
        }else{
            for(int j=i*m;j>=i*m-m+1;j--){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}