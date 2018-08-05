#include <iostream>
#include <string.h>
#include<stdio.h>
#include <algorithm>

void merger(int a[], int b[], int n);

using namespace std;

bool equal(int a[],int b[],int n){
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
            return false;
    return true;
}

int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    int i,j;//记录
    for(i=0; b[i]<=b[i+1]&&i<n-1; i++);//i是有序的最后一个数字
    i++;//现在i是无序的第一个数字
    for(j=i; a[j]==b[j]&&j<n; j++);
    if(j==n){
        cout<<"Insertion Sort"<<endl;
        sort(a,a+i+1);
    } else{
        cout<<"Merge Sort"<<endl;
        merger(a,b,n);
    }

    for(int k=0;k<n;k++){
        if(k!=0)
            cout<<" ";
        cout<<a[k];
    }

    return 0;
}

void merger(int a[], int b[], int n) {
    int edge=1;
    for(;;edge*=2){
        bool istrue=true;
        istrue=equal(a,b,n);
        for(int j=0;j<n;j+=edge){
            int temp=edge+j;
            if(temp>n)
                temp=n;
            sort(a+j,a+temp);
        }
        if(istrue){
            break;

        }
    }
}
