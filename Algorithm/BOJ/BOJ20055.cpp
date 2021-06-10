//컴베이어 벨트 위의 로봇
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int N,K;
    int arr[200]={0,};
    cin>>N>>K;
    for(int i=0;i<2*N;i++){
        cin>>arr[i];
    }
    int cnt=0;
    int res=0;
    int visit[100]={0,};//robot is here
    while(cnt<K){
        res++;
        //1. turn arr
        int tmp=arr[2*N-1];
        for(int i=2*N-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=tmp;
        //2. turn robot with line
        for(int i=N-1;i>0;i--){
            visit[i]=visit[i-1];
        }
        visit[N-1]=0;//edit
        visit[0]=0;//처음 위치는 새로 온거여서 올라가있는 로봇 없음
        //move robot
        for(int i=N-2;i>=0;i--){
            if(visit[i]&&visit[i+1]==0&&arr[i+1]>0){
                arr[i+1]--;
                if(arr[i+1]==0)cnt++;
                visit[i+1]=1;
                visit[i]=0;
            }
        }
        //
        if(arr[0]){
            arr[0]--;
            if(arr[0]==0)cnt++;
            visit[0]=1;
        }
    }
    cout<<res;
    return 0;
}


//
// Created on 2021/04/29.
//

