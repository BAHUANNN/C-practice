#include <iostream>

using namespace std;

int main()
{
    string n,m;
    int num(0);
    cin>>n;
    cin>>m;

    for (int i = 0; i < n.length(); ++i) {
        for (int j = 0; j < m.length(); ++j) {
            if(n[i]==m[j]){
                n[i]='!';
                m[j]='!';
            }
        }
    }

    for (int k = 0; k < m.length(); ++k) {
        if(m[k]!='!')num++;
    }

    if(num>0)cout<<"No "<<num;
    else cout<<"Yes "<<n.length()-m.length();

    return 0;
}

