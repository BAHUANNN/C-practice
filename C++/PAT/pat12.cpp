#include <iostream>
#include <queue>
#include <sstream>
#include <tgmath.h>

using namespace std;

int main() {
    int a(0),b(0),c(0),d(0),e(0),temp;
    int a2(0),b2(0),d2(0),ssNum(0);
    string s;
    getline(cin,s);
    stringstream ss(s);

    while(ss >> temp){
        ssNum++;
        if(ssNum>1){
            if(temp%5==0&&temp%2==0){
                a2++;
                a += temp;
            }else if(temp%5==1){
                b2++;
                b += pow(-1,b2+1)*temp;
            }else if(temp%5==2){
                c++;
            }else if(temp%5==3){
                d2++;
                d += temp;
            }else if(temp%5==4){
                if(temp>e)e=temp;
            }
        }
    }

    if(a2==0)cout<<'N';
    else cout<<a;
    if(b2==0)cout<<" N";
    else cout<<" "<<b;
    if(c==0)cout<<" N";
    else cout<<" "<<c;
    if(d2==0)cout<<" N";
    else printf(" %.1f",d*1.0/d2);
    if(e==0)cout<<" N";
    else cout<<" "<<e;

    return 0;
}


