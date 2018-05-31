
//旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。
// 现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。
//主要在于要改变字母大小写，也不能重复输出字母
#include <iostream>
#include <vector>
#include <sstream>

void checkAndAdd();

using namespace std;

void change(string &str){
    for (int i = 0; i < str.length(); i++){
        char c = str[i];
        if (c >= 'a' && c <= 'z')str[i] = c - ('a' - 'A');
    }
}

void checkAndAdd(vector<char> &v, char &c) {
    for(int i = 0; i <= v.size(); i++){
        if(i == v.size()) v.push_back(c);
        if(c == v[i]) break;
    }
}

int main(){
    string a,b;
    vector<char> v;
    char c;
    cin>>a>>b;

    change(a);
    change(b);

    stringstream ss(a);
    while(ss>>c){
        for(int i = 0; i <= b.length(); i++){
            if(i == b.length()) checkAndAdd(v,c);
            if(c == b[i]) break;
        }
    }

    for(int i = 0; i < v.size(); i++){
        cout<<v[i];
    }
    return 0;
}
