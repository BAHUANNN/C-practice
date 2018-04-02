#include <iostream>
#include <string>
#include "queue"
#include <sstream>
#include <map>
#include "stack"

using namespace std;

int main() {

    int num;
    map<int,vector<string>> m;

    cin>>num;

    int list[num];

    for(int i=0;i<num;i++){
        string name,str;
        int n;

        cin>>name>>str>>n;

        if(n>0&&n<101){
            vector<string> s;
            s.push_back(name);
            s.push_back(str);

            list[i] = n;
            m.insert(make_pair(n,s));

        }
    }

    for(int i=1;i<num;i++){
        for(int j=0;j<num-i;j++){
           if(list[j]>list[j+1]){
               int temp = list[j];
               list[j] = list[j+1];
               list[j+1] = temp;
           }
        }
    }

    int max = list[num-1];
    int min = list[0];

    vector<string> temp1 = m[max];
    for(int i=0;i<2;i++){
        string string1 = temp1[i];
        cout<<string1;
        if(i==0)cout<<" ";
    }

    cout<<endl;

    vector<string> temp2 = m[min];
    for(int i=0;i<2;i++){
        string string1 = temp2[i];
        cout<<string1;
        if(i==0)cout<<" ";
    }

    return 0;
}


