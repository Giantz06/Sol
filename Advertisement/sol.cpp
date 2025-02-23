#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
stack<int> c;
stack<int> t;
int main()
{
    int n;
    cin >> n;
    int k[n + 2];
    k[0] = 0;
    k[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    int l[n + 2];
    int l1 = 1;
    c.push(0);
    for (int i = 1; i <= n; i++)
    {
        while (1)
        {
            int pos = c.top();
            if (k[i] > k[pos])
            {
                l[l1++] = pos;
                c.push(i);
                break;
            }
            else
                c.pop();
        }
        c.push(i);
    }
    int r[n + 2];
    int r1 = n;
    t.push(n + 1);
    for (int i = n; i >= 1; i--)
    {
        while (1)
        {
            int pos = t.top();
            if (k[i] > k[pos])
            {
                r[r1--] = pos;
                t.push(i);
                break;
            }
            else
                t.pop();
        }
        t.push(i);
    }
    long long max = 1;
    for (int i = 1; i <= n; i++)
    {
        long long area = 1ll * k[i] * (r[i] - l[i] - 1);
        if (area > max)
            max = area;
    }
    cout << max;
    return 0;
}