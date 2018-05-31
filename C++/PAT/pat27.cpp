//
// Created by zdf on 18-5-29.
//给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。



#include <iostream>

using namespace std;

int main(){
    int n,num(1),last;
    int needN;
    char c;
    cin>>n>>c;

    for(int i = 1; i < n; i++){

        num += (1+2*i)*2;
        if(num == n){needN = i+1;
            break;}
        if(num > n){needN = i;
            break;}
    }

    for(int i = needN; i > 0; i--){
        for(int j = i; j < needN; j++){
            cout<<" ";
        }
        for(int j = 0; j < (2*i-1); j++){
            cout<<c;
        }
        cout<<endl;
    }

    for(int i = 2; i <= needN; i++){
        for(int j = i; j < needN; j++){
            cout<<" ";
        }
        for(int j = 0; j < (2*i-1); j++){
            cout<<c;
        }
        cout<<endl;
    }

    return 0;
}
