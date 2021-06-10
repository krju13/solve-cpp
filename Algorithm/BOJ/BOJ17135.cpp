#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int H,W,D;
int map[16][15];
int copym[16][15];
typedef struct Enemy{
    int h,w,d;
};
bool cmp(Enemy a,Enemy b){
    if(a.d==b.d)return a.w<b.w;
    return a.d<b.d;
}
void swap(int i,int j){
    int tmp=map[H][i];
    map[H][i]=map[H][j];
    map[H][j]=tmp;
}
bool np(){
    int i=W-1;
    while(i>0&&map[H][i-1]>=map[H][i])i--;
    if(i==0)return false;

    int j=W-1;
    while(map[H][i-1]>=map[H][j])j--;
    swap(i-1,j);
    int k=W-1;
    while(i<k){
        swap(i++,k--);
    }
    return true;
}
bool alldead(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(copym[i][j])return true;
        }
    }
    return false;
}
Enemy mindistance(int Arch){
    vector<Enemy> qu;
    vector<Enemy>::iterator iter=qu.begin();
    while(iter!=qu.end()){iter++;
    cout<<(*iter).h;
    }

    int dis=0;
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            if(copym[h][w]==1&&abs(H-h)+abs(Arch-w)<=D){
                qu.push_back({h,w,abs(H-h)+abs(Arch-w)});
            }
        }
    }
    sort(qu.begin(),qu.end(),cmp);
    if(qu.size()==0)
        return {-1,-1,-1};
    else
        return {qu.at(0).h,qu.at(0).w,qu.at(0).d};
}
void moveforward(){
    for(int i=H-2;i>=0;i--){
        for(int j=0;j<W;j++){
            copym[i+1][j]=copym[i][j];
        }
    }
    for(int j=0;j<W;j++){
        copym[0][j]=0;
    }
}
int solve(){
    int dead=0;
    memcpy(copym,map,sizeof(map));//map -> copym
    while(alldead()){
        Enemy p[3];
        int target=0;
        for(int Arch=0;Arch<W;Arch++){
            if(copym[H][Arch]==1){
                p[target++]=mindistance(Arch);
            }
        }
        for(int k=0;k<3;k++){
            if(p[k].h!=-1&&copym[p[k].h][p[k].w]==1){
                copym[p[k].h][p[k].w]=0;
                dead++;
            }
        }
        moveforward();
    }
    return dead;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>H>>W>>D;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>map[i][j];
        }
    }
    for(int i=W-1;i>W-4;i--){
        map[H][i]=1;
    }
    int maxdead=0;
    do{
        int dead=solve();
        maxdead=max(maxdead,dead);
    }while(np());
    cout<<maxdead;
    return 0;
}


//
// Created by juyeon kim on 2021/02/17.
//

