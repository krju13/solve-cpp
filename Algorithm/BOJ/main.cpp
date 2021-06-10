#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    char input;
    string s1,s2;
    cin>>s1>>s2;
    string s3;
    for(int i=0;i<s1.length();i++){
        if(s1[i]>='0'&&s1[i]<='9')continue;
        s3.push_back(s1[i]);
    }
    cout<<(s3.find(s2)!=string::npos);
    return 0;
}
//
// Created by juyeon kim on 2021/02/16.
//

