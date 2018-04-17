//输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。
//
//随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。
//
//输出格式：
//
//输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
//

#include <iostream>
#include <queue>
#include <sstream>
#include <tgmath.h>
#include <algorithm>

using namespace std;

struct Student{
    int n; //考生号
    int de; //德分
    int cai; //才分
};

bool cmp(Student a,Student b){
    int suma = a.de+a.cai;
    int sumb = b.de+b.cai;
    if(suma!=sumb){
        return suma>sumb;
    }
    else{
        if(a.de!=b.de){
            return a.de>b.de;
        }
        else{
            return a.n<b.n;
        }
    }
}

int main() {
    int a,b,c,count=0;
    cin>>a>>b>>c;

    vector<Student> A,B,C,D;
    Student temp;

    for(int i=0;i<a;i++){
        cin>>temp.n>>temp.de>>temp.cai;

        if(temp.de>=b&&temp.cai>=b){
            count++;

            if(temp.de>=c&&temp.cai>=c){
                A.push_back(temp);
            } else if(temp.de>=c&&temp.cai<c){
                B.push_back(temp);
            } else if(temp.de<c&&temp.cai>=c){
                C.push_back(temp);
            } else{
                D.push_back(temp);
            }

        }

    }

    sort(A.begin(),A.end(),cmp);
    sort(B.begin(),B.end(),cmp);
    sort(C.begin(),C.end(),cmp);
    sort(D.begin(),D.end(),cmp);

    printf("%d\n",count);

    for(int i = 0;i < A.size();i++){
        printf("%d %d %d\n",A[i].n,A[i].de,A[i].cai);
    }
    for(int i = 0;i < B.size();i++){
        printf("%d %d %d\n",B[i].n,B[i].de,B[i].cai);
    }
    for(int i = 0;i < C.size();i++){
        printf("%d %d %d\n",C[i].n,C[i].de,C[i].cai);
    }
    for(int i = 0;i < A.size();i++){
        printf("%d %d %d\n",C[i].n,C[i].de,C[i].cai);
    }


    return 0;
}
