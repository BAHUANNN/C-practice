

#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
using namespace std;

/*
 *思路 ：
 *贪心算法， 通过总价和重量算出单价， 先卖单价最高的月饼直至需求量为0
 */

struct N{
    double num;
    double total;
    double price;
}data[1001];

bool cmp(N a,N b){
    return a.price>b.price;
}

int main(){
    int n,D;
    cin>>n>>D;

    for(int i=0;i<n;i++){
        cin>>data[i].num;
    }

    for(int i=0;i<n;i++){
        cin>>data[i].total;
    }

    for(int i=0;i<n;i++){
        data[i].price = data[i].total/data[i].num;
    }
    sort(data,data+n,cmp);

    int j=0 ;
    double sum =0;


    while(D>0&&j<n){
        if(D>data[j].num){
            D -= data[j].num;
            sum += data[j].total;
        }
        else{
            sum += data[j].price*D;
            D = 0;
        }
        j++;
    }
    printf("%.2f\n",sum);
    return 0;
}
