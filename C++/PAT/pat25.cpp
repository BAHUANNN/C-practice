
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
    return;
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
    a.clear();

    int m = n/k;
    for(int i = 0;i < m;i++){
        for(int j = (i+1)*k-1 ; j >= i*k ; j--){
            if(j == i*k && (i+1)*k < n){
                temp.next = b[j+k].address;
            } else if (j == i*k && (i+1)*k == n){
                temp.next = "-1";
            } else{
                temp.next = b[j-1].address;
            }
            temp.address = b[j].address;
            temp.data = b[j].data;

            a.push_back(temp);
        }
    }
    for(int i = m*k;i < n;i++){
        temp.next = b[i].next;
        temp.address = b[i].address;
        temp.data = b[i].data;

        a.push_back(temp);
    }

    for(int i = 0;i < n;i++){
        cout<<a[i].address<<" "<<a[i].data<<" "<<a[i].next<<endl;
    }

    return 0;
}
