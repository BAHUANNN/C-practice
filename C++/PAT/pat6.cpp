#include <iostream>
using namespace std;

int main() {

    int n(0);
    cin >> n;

    if(n>99){
        int ii = n/100;
        for(int i = 0;i < ii;i++){
            cout << "B";
        }

        n -= ii*100;
    }

    if(n>9){
        int ii = n/10;
        for(int i = 0;i < ii;i++){
            cout << "S";
        }

        n -= ii*10;
    }

    for(int i = 1;i < n+1;i++){
        cout << i ;
    }


    return 0;
}


