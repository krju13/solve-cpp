#include<iostream>
#include<cstring>
using namespace std;

#define MAX 16

int board[MAX][MAX];
int n;
int visited[MAX][MAX][4];

typedef struct {
    int x,y;//coordinate,
    int d; //entering direction,
            //0 = left, 1 = above, 2 = right, 3 = below
}Position;

void solve(){
    init();
    Position start={.x=0,.y=0,.d=0};
    if(maze(start))cout<<"YES\n";
    else cout<<"NO\n";
}
int offset[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
Position  next_pos(Position p,int turn){
    Position q;
    q.x=p.x+offset[(p.d+turn)%4][0];
    q.y=p.y+offset[(p.d+turn)%4][1];
    q.d=(p.d+turn)%4;
}
bool maze(Position p){
    if(p.x<0||p.x>=n||p.y<0||p.y>=n||board[p.x][p.y]!=0||visited[p.x][p.y][p.d]!=0)
        return false;
    if(p.x==n-1&&p.y==n-1)
        return true;
    visited[p.x][p.y][p.d]=1;
    for(int turn=0;turn<2;turn++){
        //0 = straight, 1= right
        Position q=next_pos(p,turn);
        if(maze(q))
            return true;
    }
    return false;
}
int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    memset(visited,0,sizeof(visited));
    solve();
    return 0;
}