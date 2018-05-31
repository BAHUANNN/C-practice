//给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。
//现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。
//在letecode上好像见过类似的题，难度不大，但是如何做到最优算法有点儿头疼
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    long n,p;
    cin>>n>>p;
    int num[n],temp,max(0);
    for(int i = 0; i < n; i++){
        cin>>temp;
        num[i]=temp;
    }

    sort(num,num+n);

    for(int i = 0; i < n; i++){
        int t(0);
        temp = num[i]*p;
        for(int j = i; j < n;j++){
            if(num[j] <= temp) t++;
            else{
                if(t>max)max=t;
                break;
            }
        }
    }

    cout<<max;

    return 0;
}
