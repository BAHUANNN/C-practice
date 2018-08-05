#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a[6]={0,0,0,0,0,0},max(0);
    char c[6]={'P','A','T','e','s','t'};
    string s;
    cin>>s;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 6; ++j) {
            if(s[i] == c[j]){
                a[i]++;
                break;
            }
        }
    }

    for (int k = 0; k < 6; ++k) {
        if(a[k]>max)max=a[k];
    }

    for (int l = 0; l < max; ++l) {
        for (int i = 0; i < 6; ++i) {
            if(a[i]>0){
                cout<<c[i];
                a[i]--;
            }
        }
    }

    return 0;
}

