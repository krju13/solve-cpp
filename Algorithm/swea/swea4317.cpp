#include<iostream>

using namespace std;

int H,W;
int wafer[10][25];
bool canattack(int ch,int cw){
    if(wafer[ch][cw]+wafer[ch][cw+1]+wafer[ch+1][cw]+wafer[ch+1][cw+1]==0)
        return true;
    return false;
}

int attach(int cnt,int ch,int cw){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){

        cin>>H>>W;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cin>>wafer[i][j];
            }
        }
        //input
        int cnt=0;


        cout<<"#"<<t<<" "<<cnt<<"\n";
    }
}