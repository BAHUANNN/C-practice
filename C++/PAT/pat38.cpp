#include <iostream>

using namespace std;

int main()
{
    int n,m,temp;
    cin>>n;
    int a[101]={0};
    for(int i=0;i<n;i++){cin>>temp;a[temp]++;}
    cin>>m;
    for (int j=0;j<m;++j){
	cin>>temp;
	cout<<a[temp];
	if(j!=m-1)cout<<" ";};


    return 0;
}

