class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stac;
        int res = 0;
        stac.push(-1);
        int check = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                stac.push(i);
            else
            {
                stac.pop();
                if (stac.empty())
                {
                    stac.push(i);
                }
                else
                {
                    res = max(res, i - stac.top());
                }
            }
        }
        return res;
    }
};