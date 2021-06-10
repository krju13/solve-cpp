#include<iostream>

using namespace std;

int main(){
    int s,e;
    cin>>s>>e;
    if(s<e){
            for(int dan=s;dan<=e;dan++){
        for(int i=1;i<=9;i++) {
            cout << dan << " * " << i << " = ";
            if (dan * i < 10)
                cout << " ";
            cout << dan * i;
            if (i % 3 == 0)
                cout << "\n";
            else
                cout << "   ";
        }
            cout<<"\n";
        }
    }else{
            for(int dan=s;dan>=e;dan--){
        for(int i=1;i<=9;i++){
                cout<<dan<<" * "<<i<<" = ";
                if(dan*i<10)
                    cout<<" ";
                cout<<dan*i;
                if(i%3==0)
                    cout<<"\n";
                else
                    cout<<"   ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
