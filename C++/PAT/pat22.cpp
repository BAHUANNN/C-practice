

#include<stdio.h>
#include <array>
#include <iostream>
#include <vector>

using namespace std;


int main(){
    int a,b,c,sum,f;
    vector<int> v;
    cin>>a>>b>>c;
    sum = a+b;

    if(sum == 0){
        cout<<0;
    } else{
        while(sum){
            v.push_back(sum%c);
            sum /= c;
        }
        while(!v.empty()){
            cout<<v.back();
            v.pop_back();
        }
    }
    return 0;
}
