
#include <array>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct node{
    string address;
    string data;
    string next;
};

vector<node> a,b;

void findIt(string it){
    for(int i = 0;i < a.size();i++){
        if(it == a[i].address){
            b.push_back(a[i]);
            if(a[i].next == "-1")return;
            findIt(a[i].next);
            break;
        }
    }
}

int main(){
    string first;
    int n,k;
    cin >> first >> n >> k;

    node temp;
    for(int i = 0;i < n;i++){
        cin >> temp.address >> temp.data >> temp.next;
        a.push_back(temp);
    }

    findIt(first);

    for(int i = 0;i < n;i++){

    }

    return 0;
}
