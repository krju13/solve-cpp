#include<iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    if(m==1){
        for(int i=1;i<=n;i++){
            for(int j=0;j<n;j++){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }else if(m==2){
        for(int i=1;i<=n;i++){
            if(i&1){
                for(int j=1;j<=n;j++){
                    cout<<j<<" ";
                }
                cout<<"\n";
            }else{
                for(int j=n;j>=1;j--){
                    cout<<j<<" ";
                }
                cout<<"\n";
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<i*j<<" ";
            }
            cout<<"\n";
        }
    }
}