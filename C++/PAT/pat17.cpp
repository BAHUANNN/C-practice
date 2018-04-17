//本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
//
//输入格式：
//
//输入在1行中依次给出A和B，中间以1空格分隔。
//
//输出格式：
//
//在1行中依次输出Q和R，中间以1空格分隔。
//
//跟网上的答案一毛一样，结果还不是全对？？？？
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char a[1000],q[1000];
    int b,n(0);
    scanf("%s %d", a, &b);

    for(int i = 0;i < strlen(a);i++){
        q[i] = (a[i]-48+10*n)/b + 48;
        n = (a[i]-48+10*n) % b;
    }

    if(q[0] == '0' && q[1] != 0){
        printf("%s", q + 1);
    } else{
        printf("%s", q);
    }
    printf(" %d\n",n);
    return 0;
}
