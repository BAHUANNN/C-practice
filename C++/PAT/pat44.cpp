#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    stringstream ss;
    string s1[13]={"tre","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
    string s2[13]={"tre","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
    string temp;
    int n,tempInt;
    int one,two;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        getline(cin,temp);
        if(temp[0]<='9'){
            ss<<temp;
            ss>>tempInt;
            one = tempInt/13;
            two = tempInt%13;
            if(one==0){cout<<s1[two];}
            else{cout<<s2[one]<<" "<<s1[two];}
        } else{
            if(temp.size()>5){
                string temp1 = temp.substr(0,3);
                for (int j = 0; j < 13; ++j) {
                    if(s2[j] == temp1){
                        one = j;
                        break;
                    }
                }
                string temp2 =temp.substr(4,3);
                for (int j = 0; j < 13; ++j) {
                    if(s1[j] == temp2){
                        two = j;
                        break;
                    }
                }
                cout<<one*13+two;
            } else{
                for (int j = 0; j < 13; ++j) {
                    if(s1[j] == temp){
                        cout<<j;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

