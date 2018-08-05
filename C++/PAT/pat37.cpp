#include <iostream>

using namespace std;

int main()
{
    int a1,a2,a3,b1,b2,b3;
    int c1,c2,c3,z1,z2,cha;
    int Galleon = 17*29,Sickle =29;
    scanf("%d.%d.%d",&a1,&a2,&a3);
    scanf("%d.%d.%d",&b1,&b2,&b3);
    z1=a1*Galleon+a2*Sickle+a3;
    z2=b1*Galleon+b2*Sickle+b3;

    if(z1>z2) {cha = z1-z2;cout<<"-";}
    else{cha = z2-z1;}

    c1 = cha/Galleon;
    cha %= Galleon;
    c2 = cha/Sickle;
    cha %= Sickle;
    c3 = cha;
    printf("%d.%d.%d",c1,c2,c3);
    return 0;
}

