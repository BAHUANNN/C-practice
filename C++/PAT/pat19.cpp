
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
int main()
{
    vector<int> v;
    int n,a,b;
    cin >> n;

    bool flag = true;
    while(flag)
    {
        v.clear();
        for(int i =0;i<4;i++)
        {
            v.push_back(n%10);
            n /=10;
        }

        sort(v.begin(),v.end());
        a = v[3]*1000 + v[2]*100 + v[1]*10 + v[0];
        b = v[0]*1000 + v[1]*100 + v[2]*10 + v[3];
        n = a - b;

        cout <<setfill('0')<<setw(4)<<a<<" - "<<setfill('0')<<setw(4)<<b<<" = "<<setfill('0')<<setw(4)<<n<<endl;

        if(n == 6174 || n == 0)flag = false;
    }

    return 0;
}
