//正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
//
//现给定A、DA、B、DB，请编写程序计算PA + PB。
//
//输入格式：
//
//输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
//
//输出格式：
//
//在一行中输出PA + PB的值。
//
//输入样例1：
//3862767 6 13530293 3
//输出样例1：
//399
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string s1,s2;
    char c1,c2;
    int i(0),j(0),num1(0),num2(0);
    cin>>s1>>c1>>s2>>c2;

    while(s1[i]){
        if(s1[i] == c1)num1++;
        i++;
    }

    while(s2[j]){
        if(s2[j] == c2)num2++;
        j++;
    }

    i=0,j=0;

    for(int a = 0;a < num1;a++){
        i += (c1-48)*pow(10,a);
    }

    for(int a = 0;a < num2;a++){
        j += (c2-48)*pow(10,a);
    }

    cout<<i+j;

    return 0;
}
