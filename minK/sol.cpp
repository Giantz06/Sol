#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int index;
        int min = 2e9 + 1;
        for (int i = 1; i <= k; i++) // xử lí k thằng đầu
        {
            if (a[i] < min)
            {
                index = i;
                min = a[i];
            }
        }
        cout << a[index] << " ";
        deque<int> dq;
        dq.push_back(index);
        for (int i = 2; i <= n - k + 1; i++)
        {
            if (index >= i) // nếu index thằng nhỏ nhất vẫn nằm trong đoạn đang xét
            {
                if (a[i + k - 1] >= a[index]) // so sánh thằng mới với thằng nhỏ nhất hiện tại
                {
                    cout << a[index] << " ";
                }
                else
                {
                    index = i + k - 1;
                    dq.pop_back();
                    dq.push_back(index);
                    cout << a[index] << " ";
                }
            }
            else
            {
                dq.pop_back();
                min = 2e9 + 1;
                for (int j = i; j <= i + k - 1; j++)
                {
                    if (a[j] < min)
                    {
                        index = j;
                        min = a[j];
                    }
                }
                cout << a[index] << " ";
                dq.push_back(index);
            }
        }
        cout << endl;
    }
    return 0;
}
