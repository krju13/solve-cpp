//
// Created by juyeon kim on 2021/03/16.
//
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
int T=10,N;
int map[101][101]={0};
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    //input speedly
    for(int tc=1;tc<=T;tc++){
        memset(map,0,sizeof(map));
        //init
        cin>>N;
        int start;
        cin>>start;
        int from,to;
        for(int i=0;i<N/2;i++){
            cin>>from>>to;
            map[from][to]=1;
        }
        vector<int> que;
        vector<int> next;
        int result=start;
        map[start][0]=1;
        que.push_back(start);

        do{
            while(next.size()){
                que.push_back(next.at(next.size()-1));
                next.pop_back();
            }
            while(que.size()){
                int node=que.at(que.size()-1);que.pop_back();
                for(int n=1;n<101;n++){
                    if(map[n][0]==0&&map[node][n]==1){
                        map[n][0]=1;
                        next.push_back(n);
                    }
                }
            }
            sort(next.begin(),next.end());
            if(next.size())
                result=next.at(next.size()-1);
        }while(next.size());
        cout<<"#"<<tc<<" "<<result<<"\n";
    }
    return 0;
}
