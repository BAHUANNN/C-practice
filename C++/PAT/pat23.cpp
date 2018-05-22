
#include <array>
#include <iostream>

using namespace std;


int main(){
    int min[50];
    int num[10];
    int sum(0);
    for(int i = 0;i < 10;i++){
        cin>>num[i];
        sum += num[i];
    }
    for(int i = 1;i < 10;i++){
        if(num[i]>0){
            min[0] = i;
            num[i]--;
            break;
        }
    }
    int k = 1;
    for(int i = 0;i < 10;i++){
        int j = num[i];
        for(j;j > 0;j--){
            min[k] = i;
            k++;
        }
    }
    for(int i = 0;i < sum;i++){
        cout<<min[i];
    }


    return 0;
}
