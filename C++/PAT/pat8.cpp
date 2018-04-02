#include <iostream>
#include <queue>
#include "cmath"
using namespace std;

int main() {

    queue<int> q;
    int n,m,temp;

    cin>>n>>m;

    for(int i = 0;i < n;i++){
        cin>>temp;
        q.push(temp);
    }

    for(int i = 0;i < n-m%n;i++){
        temp = q.front();
        q.pop();
        q.push(temp);
    }

    for(int i = 0;i < n;i++){
        temp = q.front();
        q.pop();
        cout << temp ;
        if(i != n-1)cout << " ";
    }

    return 0;
}


