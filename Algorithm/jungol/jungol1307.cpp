#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int board[100][100]={0};
    int cnt=0;
    for(int j=n-1;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            board[i][j]=cnt;
            cnt=(cnt+1)%26;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<(char)('A'+board[i][j])<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

