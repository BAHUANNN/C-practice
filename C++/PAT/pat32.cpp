#include <iostream>

using namespace std;

int main() {
    int n;
    int schId,stuS;
    int schIdMax,stuSMax(0);
    int score[100] = {0};

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>schId>>stuS;
        score[schId] += stuS;
    }

    for(int i=0;i<100;i++){
        if(score[i] > stuSMax){
            schIdMax = i;
            stuSMax = score[i];
        }
    }

    cout<<schIdMax<<" "<<stuSMax;

    return 0;
}