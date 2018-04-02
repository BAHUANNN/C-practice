#include <iostream>
#include <string>
#include "queue"
#include <sstream>

using namespace std;

queue<string> yesOrNo;

void YesOrNo(string str) {
    bool b = false;
    int a1=0,a2=0,a3=0;
    int p=0,t=0,e=0;

    for(int i=0;i<str.length();i++){
        if(str[i]=='A'){
            if(p==0&&t==0){
                a1++;
            } else if(p==1&&t==0){
                a2++;
            } else if(p==1&&t==1){
                a3++;
            }
        } else if(str[i]=='P'&&t==0){
            p++;
        } else if(str[i]=='T'){
            t++;
        } else {
            e++;
        }

    }

    if(t==1&&p==1&&e==0){
        if(a2==1)b=true;
        if(a2>1&&a2!=0){
            if(a3==a1*a2)b=true;
        }
    }

    if(b){
        yesOrNo.push("YES");
    } else{
        yesOrNo.push("NO");
    }
}


int main() {
    int num;

    cin>>num;

    for(int i=0;i<num;i++){

        string putStr;
        cin>>putStr;
        YesOrNo(putStr);

    }

    int size = yesOrNo.size();
    for(int i=0;i<size;i++){
        string str = yesOrNo.front();
        yesOrNo.pop();
        cout<<str<<endl;
    }

    return 0;
}


