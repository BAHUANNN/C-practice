#include <iostream>
#include <string>
#include "queue"
#include <sstream>
#include <map>
#include "stack"

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> all(101);
    vector<int> list;

    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        v[i] = temp;
        while(temp != 1){
            if(temp%2 != 0)temp = (3*temp+1)/2;
            else temp = temp/2;

            if(temp <= 100)all[temp] = 1;
        }
    }

    for(int i = 0;i < n;i++){
        if(all[v[i]] == 0){
            list.push_back(v[i]);
        }
    }

    for(int i = 1;i < list.size();i++){
        for(int j=0;j<list.size()-i;j++){
            if(list[j]>list[j+1]){
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

    for(int i = list.size();i > 0;i--){
        cout << list[i-1] ;
        if(i != 1)cout << " ";
    }


    return 0;
}


