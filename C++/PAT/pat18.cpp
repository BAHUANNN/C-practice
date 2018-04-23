
#include <iostream>
#include<string.h>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int N;
    char F,S;
    int i=0,j=0,ii=0,jj=0,kk=0;
    int ix=0,jx=0,kx=0;
    int aa,bb;
    cin>>N;
    for(int m=0;m<N;m++)
    {
        cin>>F>>S;
        if(F==S)i++;
        if((F=='C')&&(S=='J')||(F=='B')&&(S=='C')||(F=='J')&&(S=='B')) j++;
        if((F=='B')&&(S=='C'))ii++;
        if((F=='C')&&(S=='J'))jj++;
        if((F=='J')&&(S=='B'))kk++;
        if((S=='B')&&(F=='C'))ix++;
        if((S=='C')&&(F=='J'))jx++;
        if((S=='J')&&(F=='B'))kx++;

    }
    cout<<j<<" "<<i<<" "<<N-j-i<<endl;
    cout<<N-j-i<<" "<<i<<" "<<j<<endl;

    if(ii>=jj&&ii>=kk)
    {printf("B");}
    else if(jj>=kk)
    {printf("C");}
    else
    {printf("J");}


    if(ix>=jx&&ix>=kx)
    {printf(" B");}
    else if(jx>=kx)
    {printf(" C");}
    else
    {printf(" J");}

    return 0;

}