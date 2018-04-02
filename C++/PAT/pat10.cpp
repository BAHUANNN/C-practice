#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int main() {
    int a(0),i1,i2,word;
    string s;
    vector<int> v;

    getline(cin,s);

    stringstream ss(s);

    while(ss >> word){
        a++;
        if(a%2 != 0){
            i1 = word;
        } else{
            i2 = word;
            if(i2 != 0 && i1 != 0){
                v.push_back(i1*i2);
                v.push_back(i2-1);
            }
            if(i1 == 0 && i1 == 0){
                v.push_back(0);
                v.push_back(0);
            }
        }
    }

    int size = v.size();

    if(size == 0){
        cout<<"0 0";
    }

    for(int i = 0;i < size;i++){

        cout << v[i];
        if( i != size-1)cout << " ";
    }

    return 0;
}


