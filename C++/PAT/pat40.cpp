#include <iostream>

using namespace std;

int main()
{
    string n;
    cin>>n;
    int l = n.length();
    int t(0),p(0);
    long num(0);

    for (int i = 0; i < l ; ++i) {
        if(n[i] == 'T')t++;
    }
    for (int j = 0; j < l ; ++j) {
        if(n[j] == 'P')p++;
        if(n[j] == 'A')num += p*t;
        if(n[j] == 'T')t--;
    }

    cout<<num%1000000007;
    return 0;
}

