//
// Created by zdf on 18-5-29.
//人口普查　算比较有趣的一个题...
//某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
//这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。
//在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    int num,n(0);
    char name[10],age[11];
    char max[11] = "2014/09/07",min[11] = "1814/09/05",minN[10],maxN[10];
    char small[11] = "1814/09/05";
    char large[11] = "2014/09/07";
    cin>>num;
    for(int i = 0;i < num;i++){
        cin >> name >> age;
        if(strcmp(age,small)>0 && strcmp(large,age)>0){
            n++;

            if(strcmp(age,min)>0){
                strcpy(min,age);
                strcpy(minN,name);
            }

            if(strcmp(max,age)>0){
                strcpy(max,age);
                strcpy(maxN,name);
            }
        }
    }

    if(n>0){
        printf("%d %s %s",n,maxN,minN);
    } else{
        printf("0");
    }

    return 0;
}
