

#include<stdio.h>
#include <array>
#include <iostream>

using namespace std;


int main(){
    string s;
    int ii[10];
    char c;
    cin>>s;
    while(c = cin.get()){
        ii[c-'0']++;
        putchar(c);
    }
    for(int i = 0;i < 10;i++){
        if(ii[i]!=0){
            printf("%d : %d",i,ii[i]);
        }
    }
}
