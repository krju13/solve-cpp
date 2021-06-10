//
// Created by juyeon kim on 2021/05/08.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<vector<string>> places) {
    int dh[8]={0,1,0, 1,1, 0,2,0};//오 아래 왼 오아,오왼, 오 아래
    int dw[8]={1,0,-1,1,-1,2,0,-2};
    int nh=0,nw=0;
    vector<int> answer;
    int flag=1;
    for(int i=0;i<5;i++){
        flag=1;
        for(int j=0;j<5;j++){
            for(int a=0;a<5;a++){
                if(places[i][j][a]=='P'){
                    for(int d=0;d<8;d++){
                        nh=j+dh[d];
                        nw=a+dw[d];
                        if(nh<0||nw<0||nh>=5||nw>=5)continue;
                        if(d<3){
                            if(places[i][nh][nw]=='P'){
                                flag=0;
                                break;
                            }
                        }else if(d<5){
                            if(places[i][nh][nw]=='P'){
                                if(d==3){
                                    if(places[i][j][a+1]!='X'||places[i][j+1][a]!='X') {
                                        flag = 0;
                                        break;
                                    }
                                }else if(d==4){
                                    if(places[i][j][a-1]!='X'||places[i][j+1][a]!='X'){
                                        flag = 0;
                                        break;
                                    }
                                }
                            }
                        }else {
                            if(places[i][nh][nw]=='P'){
                                if(d==5&&places[i][j][a+1]!='X'){
                                    flag = 0;
                                    break;
                                }else if(d==6&&places[i][j+1][a]!='X'){
                                    flag = 0;
                                    break;
                                }else if(d==7&&places[i][j][a-1]!='X'){
                                    flag = 0;
                                    break;
                                }

                            }
                        }
                    }
                    if(!flag)break;
                }
                if(!flag)break;
            }


        }
        answer.push_back(flag);
    }
    return answer;
}

int main(){
    vector<vector<string>> p={{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

    vector<int> a=solution(p);
    for(int i=0;i<a.size();i++)
        cout<<a[i];
    return 0;
}