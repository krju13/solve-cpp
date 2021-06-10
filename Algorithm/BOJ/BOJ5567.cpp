//결혼식
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    int *visited=new int[n+1];
    int m;
    cin>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt=0;
    queue<int> qu;
    for(int i=0;i<v[1].size();i++){
        qu.push(v[1][i]);
        visited[v[1][i]]=true;
        cnt++;
    }
    visited[1]=true;
    while(qu.size()){
        int f=qu.front();
        qu.pop();
        for(int i=0;i<v[f].size();i++){
            if(visited[v[f][i]])continue;
            visited[v[f][i]]=true;
            cnt++;
        }
    }
    delete visited;
    cout<<cnt;
}
//
// Created by juyeon kim on 2021/02/22.
//

