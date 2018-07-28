#include <iostream>

using namespace std;

int main() {
    int n,flagAll(1);
    char s[18];
    char quan[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2},yan[11]={'1','0','X','9','8','7','6','5','4','3','2'};
    cin >> n;
    for(int i = 0;i < n ;i++){
        int flag(1),sum(0);
        cin >> s;
        for(int j=0;j<17;j++)
        {
            if(s[j]>='0' && s[j]<='9') {
                sum = sum + (s[j]-'0')*quan[j];
            } else{
                flag = 0;
            }
            if(j == 16 && yan[sum%11] != s[17])flag = 0;
        }
        if(!flag) {
            flagAll = 0;
            cout<<s<<endl;
        }
    }

    if(flagAll) cout<<"All pass"<<endl;

    return 0;
}