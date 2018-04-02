#include <iostream>
#include <queue>
#include <sstream>
#include <stack>

using namespace std;

int main() {

    stack<string> v;

    string s,word;
    getline(cin,s);
    stringstream ss(s);

    while(ss >> word){

        v.push(word);
    }

    int size = v.size();

    for(int i = 0;i < size;i++){

        cout << v.top();
        v.pop();
        if( i != size-1)cout << " ";
    }

    return 0;
}


