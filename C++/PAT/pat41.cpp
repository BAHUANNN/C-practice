#include <iostream>
#include <vector>

using namespace std;

struct stu{
    string s;
    int a;
    int b;
}temp;

int main()
{
    int n1,n2,zuo;
    cin>>n1;
    struct stu student[n1];
    for (int i = 0; i < n1; ++i) {
        cin>>temp.s>>temp.a>>temp.b;
        student[i]=temp;
    }
    cin>>n2;
    for (int j = 0; j < n2; ++j) {
        cin>>zuo;
        for (int i = 0; i < n1; ++i) {
            if(zuo == student[i].a){
                cout<<student[i].s<<" "<<student[i].b<<endl;
                break;
            }
        }
    }
    return 0;
}

