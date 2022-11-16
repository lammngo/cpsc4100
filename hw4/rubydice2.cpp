#include <iostream>
#include <vector>

using namespace std;

/*





*/

int top_down(vector<int> &weights, vector<int> &values, int size, int cap, vector<vector<int>> &dp)
{
    if (size < 0)
        return 0;

    if (dp[size][cap] != -1)
        return dp[size][cap];

    if (weights[size] > cap)
        dp[size][cap] = top_down(weights, values, size - 1, cap, dp);

    else
        for (int k = 1; k <= 2 && weights[size] * k <= cap; k++)
        {
            int v1 = values[size] * k + top_down(weights, values, size - 1, cap - k * weights[size], dp);
            int v2 = max(v1, top_down(weights, values, size - 1, cap, dp));
            dp[size][cap] = max(dp[size][cap], v2);
        }

    return dp[size][cap];
}
int max_Profit(vector<int> &weights, vector<int> &values, int cap)
{
    vector<vector<int>> dp(weights.size(), vector<int>(cap + 1, -1));
    return top_down(weights, values, weights.size() - 1, cap, dp);
}

// int max_Profit(vector<int> &weights, vector<int> &val, int &cap)
// {
//     int dp[weights.size()][cap];
//     memset(dp, 0, sizeof(dp));
//     for (int i = 1; i <= weights.size(); i++)
//     {
//         for (int j = 0; j < cap; j++)
//         {
//             dp[i][j] = dp[i - 1][j];
//         }
//     }
// }

int main()
{
    int n, C;
    cin >> n;
    cin >> C;

    vector<int> w(n);
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        cin >> v[i];
    }
    cout << max_Profit(w, v, C) << endl;
    return 0;
}
