#include<iostream>

#include <string>
#include <vector>

using namespace std;

int finddown(int visit[],int k){
    int i=k+1;
    while(visit[i]==1){
        i++;
    }
    return i;
}
int findup(int visit[],int k){
    int i=k-1;
    while(visit[i]==1){
        i--;
    }
    return i;
}
int movedown(int visit[],int k,int x){
    int cnt=0;
    int i=k+1;
    while(cnt<x){
        if(visit[i]==0){
            cnt++;i++;
        }else{
            i++;
        }
    }
    return i-1;
}
int moveup(int visit[],int k,int x){
    int cnt=0;
    int i=k-1;
    while(cnt<x){
        if(visit[i]==0){
            cnt++;i--;
        }else{
            i--;
        }
    }
    return i+1;
}
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    int nowend=n-1;
    int select=k;
    vector<int> stack;
    int number[1000000]={0};
    for(int i=0;i<cmd.size();i++){
        //cout<<select<<" ";
        if(cmd[i][0]=='U'){
            int x=stoi(cmd[i].substr(2));
            select=moveup(number,select,x);
        }else if(cmd[i][0]=='D'){
            int x=stoi(cmd[i].substr(2));
            select=movedown(number,select,x);
        }else if(cmd[i][0]=='C'){
            number[select]=1;
            stack.push_back(select);
            if(select==nowend) {
                select = findup(number, select);
                nowend=select;
            }
            else
                select=finddown(number,select);
        }else if(cmd[i][0]=='Z'){
            int j=stack.back();
            stack.pop_back();
            number[j]=0;
            if(j>nowend)
                nowend=j;
        }
    }
    for(int i=0;i<n;i++){
        if(number[i]==0){
            answer.push_back('O');
        }else{
            answer.push_back('X');
        }
    }
    return answer;
}

int main(){
    cout<<solution(8,2,{"D 2","C","U 3","C","D 4","C","U 2","Z","Z"})<<endl;
    cout<<solution(8,2,{"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"})<<endl;
/*
2 4 5 1 2 7 6 3 3 OOOOXOOO
2 4 5 1 2 7 6 3 3 3 2 OOXOXOOO

 */
}