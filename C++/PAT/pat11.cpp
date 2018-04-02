#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int main() {
    long a,b,c;
    int num;
    vector<string> v;

    cin>>num;

    for(int i = 0;i < num;i++){
        cin>>a>>b>>c;
        if(a+b>c) v.push_back("true");
        else v.push_back("false");
    }

    for(int i = 0;i < num;i++){
        cout<<"Case #"<<i+1<<": "<<v[i]<<endl;
    }

    return 0;
}


