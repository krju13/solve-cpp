#include <string>
#include <vector>

using namespace std;

int Min=1987654321;

void dfs(int visit[],int end,int now,vector<vector<pair<int,int>>> gsd,vector<vector<pair<int,int>>> gds,int nowcost){
    if(now==end){
        Min=Min>nowcost?nowcost:Min;
        return;
    }
    if(nowcost>Min){
        return;
    }
    if(visit[now]==2){
        vector<pair<int,int>> tmpsd=gsd[now];
        vector<pair<int,int>> tmpds=gds[now];
        gsd[now]=tmpds;
        gds[now]=tmpsd;
    }
    for(int i=0;i<gsd.size();i++){
        int next=gsd[now][i].first;
        int cost=gsd[now][i].second;
        if(visit[next]!=1){
            if(visit[next]==0){
                visit[i]=1;
            }
            dfs(visit,end,next,gsd,gds,nowcost+cost);
            if(visit[next]==1){
                visit[next]=0;
            }
        }
    }
    if(visit[now]==2){
        vector<pair<int,int>> tmpsd=gsd[now];
        vector<pair<int,int>> tmpds=gds[now];
        gsd[now]=tmpds;
        gds[now]=tmpsd;
    }
}
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {

    vector<vector<pair<int,int>>> gsd(n);
    vector<vector<pair<int,int>>> gds(n);
    int visit[1000]={0};
    for(int i=0;i<roads.size();i++){
        gsd[roads[i][0]-1].push_back({roads[i][1]-1,roads[i][2]});
        gds[roads[i][1]-1].push_back({roads[i][0]-1,roads[i][2]});
    }
    int s=start-1,End=end-1;
    for(int i=0;i<traps.size();i++){
        visit[traps[i]-1]=2;
    }

    dfs(visit,end-1,start-1,gsd,gds,0);


    return Min;
}