#include<iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t-->0) {
        int n;
        cin >> n;
        map<string,int> m;
        string s;
        string second[1000];
        int change[1000];
        for (int i = 0; i < n; i++) {
            cin >> s;
            m[s]=i;
        }
        for (int i = 0; i < n; i++) {
            cin >> s;
            change[i]=m[s];
        }
        for(int i=0;i<n;i++){
            cin>>s;
            second[change[i]]=s;
        }
        for(int i=0;i<n;i++){
            cout<<second[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

//
// Created on 2021/04/29.
//

