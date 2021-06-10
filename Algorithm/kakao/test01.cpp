//
// Created by juyeon kim on 2021/05/08.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {

    int answer = 0;
    int i=0;
    while(i<s.size()){
        if(s[i]>='0'&&s[i]<='9'){
            answer=answer*10+s[i]-'0';
            i++;
        }
        else if(i+3<s.size()&&s.substr(i,4)=="zero"){
            answer=answer*10+0;
            i=i+4;
        }else if(i+2<s.size()&&s.substr(i,3)=="one"){
            answer=answer*10+1;
            i+=3;
        }else if(i+2<s.size()&&s.substr(i,3)=="two"){
            answer=answer*10+2;
            i+=3;
        }else if(i+4<s.size()&&s.substr(i,5)=="three"){
            answer=answer*10+3;
            i+=5;
        }else if(i+3<s.size()&&s.substr(i,4)=="four"){
            answer=answer*10+4;
            i+=4;
        }else if(i+3<s.size()&&s.substr(i,4)=="five"){
            answer=answer*10+5;
            i+=4;
        }else if(i+2<s.size()&&s.substr(i,3)=="six"){
            answer=answer*10+6;
            i+=3;
        }else if(i+4<s.size()&&s.substr(i,5)=="seven"){
            answer=answer*10+7;
            i+=5;
        }else if(i+4<s.size()&&s.substr(i,5)=="eight"){
            answer=answer*10+8;
            i+=5;
        }else if(i+3<s.size()&&s.substr(i,4)=="nine"){
            answer=answer*10+9;
            i+=4;
        }
    }


    return answer;
}