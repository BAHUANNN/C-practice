
#include <iostream>
#include <string>
using namespace std;

string str[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main() {

    string n;

    cin >> n;

    int sum(0);


    for(int i = 0;i < n.length();i++){

        sum += (n[i] - '0');

    }

    string s1 = to_string(sum);

    for(int i=0;i<s1.length();i++){

        if(i==s1.length()-1){
            cout << str[ s1[i] - '0' ];
        }else {
            cout << str[ s1[i] - '0' ] << " ";
        }

    }

    return 0;
}
