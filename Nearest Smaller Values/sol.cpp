#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
stack<int> c;

int main()
{
    int n;
    cin >> n;
    int x[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    x[0] = 0;
    c.push(0);
    for (int i = 1; i <= n; i++)
    {
        while (!c.empty())
        {
            int pos = c.top();
            if (x[i] > x[pos])
            {
                cout << pos << " ";
                break;
            }
            else
            {
                c.pop();
            }
        }
        c.push(i);
    }
    return 0;
}