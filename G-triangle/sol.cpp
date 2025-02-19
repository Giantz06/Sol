#include <bits/stdc++.h>

using namespace std;
struct tg
{
    int st;
    int e;
};

bool comp(tg a, tg b)
{
    return a.e <= b.e;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<tg> s;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        s.push_back({a, b});
    }
    sort(s.begin(), s.end(), comp);
    int ans = 0;
    multiset<int> ss;
    for (int i = 0; i < k; i++)
        ss.insert(0);
    for (int i = 0; i < n; i++)
    {
        auto it = ss.upper_bound(s[i].st);
        if (it != ss.begin())
        {
            ans++;
            it--;
            ss.erase(it);
            ss.insert(s[i].e);
        }
    }
    cout << ans;
    return 0;
}