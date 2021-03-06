#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int N;
    cin>>N;
    int board[100][100];
    memset(board,-1,sizeof(board));
    int res=0;
    int start=0;
    for(int i=N;i>=1;i--){
        for(int j=start;j<N;j++){
            board[j][N-(j-start)-1]=res;
            res=(res+1)%26;
        }
        start++;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==-1){
                cout<<"  ";
            }
            else
                cout<<(char)(board[i][j]+'A')<<" ";
        }
        cout<<"\n";
    }
    return 0;
}