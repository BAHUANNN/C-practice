
#include <array>
#include <iostream>
#include <sstream>

using namespace std;

int stringToint(const string &s){
    stringstream ss;
    int result;
    ss << s;
    ss >> result;
    return result;
}

int main(){
    string str,numA;
    int exp;
    cin >> str;
    char sign = str[0];
    int e = str.find('E');
    numA = str[1];
    numA += str.substr(3,e-3);
    exp = stringToint(str.substr(e+1));

    if(sign == '-')cout << '-';
    if(exp<0){
        cout<<"0.";
        for(int i = 0;i < -exp-1;i++)cout<<'0';
        cout << numA;
    } else if (exp >= numA.length()-1){
        cout << numA;
        for(int i = 0;i < exp-numA.length();i++)cout<<'0';
    } else{
        cout<<numA.substr(0,exp+1);
        cout<<".";
        cout<<numA.substr(exp+1);
    }
    return 0;
}
