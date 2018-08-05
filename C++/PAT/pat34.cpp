#include <iostream>
#include <string.h>
#include<stdio.h>

using namespace std;

void print(long a, long b);

void huajian(long a, long b);

int Gcd(int m,int n)
{
    if(m == 0) return n;
    return Gcd(n%m,m);
}
void print(long fenzi,long fenmu)
{
    int flag = 0;
    if(fenzi == 0) printf("0");
    else
    {
        if(fenzi < 0)
        {
            flag = 1;
            printf("(-");
            fenzi = -fenzi;
        }
        long s = fenzi/fenmu, remain = fenzi%fenmu;
        if(s != 0) printf("%ld",s);
        if(s != 0 && remain != 0) printf(" ");
        if(remain != 0)
        {
            long gcd = Gcd(remain,fenmu);
            printf("%d/%d",remain/gcd,fenmu/gcd);
        }
        if(flag) printf(")");
    }


}

int main()
{
    long a1,b1,a2,b2,c1,c2;
    char op[5] = {'+','-','*','/','\0'};
    scanf("%ld/%ld %ld/%ld",&a1,&b1,&a2,&b2);

    c2 = b1 * b2;
    long fenzi1 = a1*b2,fenzi2 = a2*b1;
    for(int i = 0;i < 4;i++)
    {
        print(a1,b1);
        printf(" %c ",op[i]);
        print(a2,b2);
        printf(" = ");
        if(op[i] == '+') c1 = fenzi1 + fenzi2;
        else if(op[i] == '-') c1 = fenzi1 - fenzi2;
        else if(op[i] == '*')
        {
            c1 = a1*a2;
            c2 = b1*b2;
        }
        else
        {
            if(a2 < 0)
            {
                c1 = -a1*b2;
                c2 = -b1*a2;
            }
            else if(a2 == 0)
            {
                c1 = 0;
                c2 = b1*b2;
                printf("Inf");
                continue;
            }
            else
            {
                c1 = a1*b2;
                c2 = b1*a2;
            }

        }
        print(c1,c2);
        printf("\n");
    }
    return 0;
}
