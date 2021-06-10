#include <iostream>

using namespace std;

int n=0;
int map[500][500];
int dp[500][500];
int k=0;
int dh[]={0,0,1,-1};
int dw[]={1,-1,0,0};

int dfs(int i,int j,int deep){
    for(int d=0;d<4;d++){
        int nh=i+dh[d];
        int nw=j+dw[d];
        if(nh<0||nw<0||nh>=n||nw>=n)continue;
        if(map[i][j]>map[nh][nw])
        {
            if(dp[i][j]<dp[nh][nw])
                dp[i][j]=dp[nh][nw]+1;
            else if(dp[nh][nw]==0){
                dp[i][j]=dfs(nh,nw,deep+1)+1;
            }
        }
    }
    if(k<dp[i][j])
        k=dp[i][j];
    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dfs(i,j,1);
        }
    }
    cout<<k;


    return 0;
}

//
// Created by juyeon kim on 2021/04/29.
//

