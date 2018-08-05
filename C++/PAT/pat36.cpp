#include <iostream>
#include <string.h>
#include<stdio.h>
#include <tgmath.h>

using namespace std;

int main()
{
    int n;
    char c;
    cin>>n>>c;
    int a = round(n/2.0);
    for(int i=0;i<a;i++){
        if(i==0 || i==a-1){
            for(int j=0;j<n;j++)cout<<c;
            cout<<endl;
        } else{
            for(int j=0;j<n;j++){
                if(j==0 || j==n-1)cout<<c;
                else cout<<" ";
            }
            cout<<endl;
        }

    }

    return 0;
}

