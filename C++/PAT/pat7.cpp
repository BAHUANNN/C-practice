#include <iostream>
#include "cmath"
using namespace std;

int temp(-5);
int num(0);

bool ifPrime(int x){
    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x%i == 0)
            return false;
    }
    return true;
}

int main() {

    int n(0);
    cin >> n;

    for(int i = 1;i <= n;i++){
        if(ifPrime(i)){
              if(i - temp == 2)num++;
              temp = i;
        }
    }

    cout << num;

    return 0;
}


