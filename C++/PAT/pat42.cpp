#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i[26]={0},max(0),maxId;
    string s;
    getline(cin,s);
    for (int j = 0; j < s.size(); ++j) {
        if(s[j]>='A' && s[j]<='z'){
            if(s[j]>='a'){
                i[s[j]-'a']++;
            } else{
                i[s[j]-'A']++;
            }
        }
    }

    for (int k = 25; k >= 0; ++k) {
        if(i[k]>max){max=i[k];maxId=k;}
    }

    printf("%c %d",maxId+'a',max);
    return 0;
}

