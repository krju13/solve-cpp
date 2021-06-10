#include<iostream>

using namespace std;

int main(){
    int s,e;
    while(1) {
        cin >> s >> e;
        if (s < 2 || e < 2 || s > 9 || e > 9) {
            cout << "INPUT ERROR!\n";
            continue;
        }
        else{
            if(s<e){
                for(int i=1;i<=9;i++){
                    for(int dan=s;dan<=e;dan++){
                        cout<<dan<<" * "<<i<<" = ";
                        if(dan*i<10)
                            cout<<" ";
                        cout<<dan*i;
                        if(dan!=e)
                            cout<<"   ";
                    }
                    cout<<"\n";
                }
            }else{
                for(int i=1;i<=9;i++){
                    for(int dan=s;dan>=e;dan--){
                        cout<<dan<<" * "<<i<<" = ";
                        if(dan*i<10)
                            cout<<" ";
                        cout<<dan*i;
                        if(dan!=e)
                            cout<<"   ";
                    }
                    cout<<"\n";
                }
            }
            break;
        }

    }
    return 0;
}