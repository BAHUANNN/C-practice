#include <iostream>

using namespace std;

int main() {

    int num;

    cin >> num ;

    int n = 0;

    while(num != 1){

        if(num%2 == 0){

            num /= 2;
        } else{

            num = (num*3+1)/2;
        }

        n ++;
    }

    cout << n;

    return 0;
}
