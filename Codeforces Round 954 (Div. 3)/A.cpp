#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x1,x2,x3;
        cin >> x1 >> x2 >> x3;

        int p[] = {x1,x2,x3};
        sort(p,p+3);

        int a = p[1];

        int ntr = abs(a-x1) + abs(a-x2) + abs(a-x3);
        cout << ntr << endl;
    }

    return 0;
}
