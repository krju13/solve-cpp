#include<iostream>
#include<cstring>

using namespace std;

int main(){
    int N;
    cin>>N;
    if(N<1||N>100||(N%2==0)){
        cout<<"INPUT ERROR";
        return 0;
    }
    int board[100][100];
    memset(board,-1,sizeof(board));
    int starty=N/2,startx=N/2;
    int res=0;
    for(int i=1;i<=N;i+=2){
        for(int j=0;j<i;j++){
            board[starty+j][startx]=res;
            res=(res+1)%26;
        }
        startx--;
        starty--;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==-1){
                break;
            }
            else{
                cout<<(char)('A'+board[i][j])<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
