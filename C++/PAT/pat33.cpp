#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string a,b;
    getline(cin,a);
    cin>>b;
    for(int i=0;i<a.length();i++){
        if(a[i]=='+'){
            for(int j=0;j<b.length();j++){
                if(b[j]>='A' && b[j]<='Z')b[j]='!';
            }
        } else if(a[i]>='A' && a[i]<='Z'){
            for(int j=0;j<b.length();j++){
                if(b[j]==a[i] || b[j]-32==a[i]) b[j]='!';
            }
        } else{
            for(int j=0;j<b.length();j++){
                if(b[j]==a[i]) b[j]='!';
            }
        }
    }

    for(int i=0;i<b.length();i++){
        if(b[i] != '!'){
            cout<<b[i];
        }

    }

    return 0;
}