//大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
//
//输入格式：
//
//输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。
//
//输出格式：
//
//在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。
//

#include "stdio.h"
int main() {
    char week[][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    char a[60],b[60],c[60],d[60];
    int count = 0;
    scanf("%s",a);
    scanf("%s",b);
    scanf("%s",c);
    scanf("%s",d);
    int i = 0,j = 0;

    for(i;a[i]&&b[i];i++){

        if(count == 1 && a[i] >= '0' && a[i] <= '9' ){
            if(a[i] == b[i]){
                printf("%02d",a[i] - '0');
                break;
            }
        }
        else if(count == 1 && a[i] >= 'A' && a[i] <= 'N' )
        {
            if(a[i] == b[i])
            {
                printf("%02d:",a[i] - 55);
                break;
            }
        }

        if(count == 0 && a[i] >= 'A' && a[i] <= 'G' ){
            if(a[i] == b[i]){
                int num = a[i]-'A';
                printf("%s ",week[num]);
                count++;
            }
        }
    }

    for(j;c[j]&&d[j];j++){
        if((c[j] >= 'a' && c[j] <= 'z') || (c[j] >= 'A' && c[j] <= 'Z')){
            if(c[j] == d[j]){
                printf("%02d",j);
                break;
            }
        }
    }

    return 0;
}