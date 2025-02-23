#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
int n;
vector<string> a;
bitset<3005> upperbit[3005];

int main()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][j] == '1')
            {
                upperbit[i][j] = 1;
            }
        }
    }
    long long ans = 0LL;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][j] == '1')
            {
                bitset<3005> common = upperbit[i] & upperbit[j];
                ans += common.count();
            }
        }
    }
    cout << ans;
    return 0;
}