class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        int n = (int)points.size();
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++)
        {
            x[i] = points[i][0];
            y[i] = points[i][1];
        }
        deque<int> dq;
        int ans = -1000000010;
        for (int i = 0; i < n; i++)
        {
            while ((!dq.empty()) && (x[i] - x[dq.front()]) > k)
            {
                dq.pop_front();
            }
            if (!dq.empty())
                ans = max(ans, x[i] + y[i] + y[dq.front()] - x[dq.front()]);
            while (!dq.empty() && (y[i] - x[i]) >= (y[dq.back()] - x[dq.back()]))
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans;
    }
};