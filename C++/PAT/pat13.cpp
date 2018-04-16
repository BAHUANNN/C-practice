#include <iostream>
#include <queue>
#include <sstream>
#include <tgmath.h>

using namespace std;

bool su(int d){
    for(int i = 2;i <= d/2;i += 1){
        if(d%i == 0)return false;
    }
    return true;

}

int main() {
    int a,b,c(0),d(0);
    cin>>a>>b;
    for(int i = 2;i <= 10000;i++){
        if(su(i)){
            c++;

            if(c >= a){
                d++;
                cout<<i;
                if(c == b)break;
                if(d%10==0)cout<<endl;
                else cout<<" ";
            }
        }
    }
    return 0;
}


