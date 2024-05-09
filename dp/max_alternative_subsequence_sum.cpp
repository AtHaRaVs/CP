// recursion
class Solution
{
public:
    long long solve(int idx, vector<int> &nums, bool flag, int n)
    {

        if (idx >= n)
            return 0;

        long long skip = solve(idx + 1, nums, flag, n);

        long long val = nums[idx];
        if (!flag)
            val = -val;

        long long take = val + solve(idx + 1, nums, !flag, n);

        return max(skip, take);
    }

    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();

        return solve(0, nums, true, n);
    }
};
// memo
class Solution
{
public:
    long long solve(int idx, vector<int> &nums, bool flag, int n, vector<vector<long long>> &dp)
    {

        if (idx >= n)
            return 0;

        if (dp[idx][flag] != -1)
            return dp[idx][flag];

        long long skip = solve(idx + 1, nums, flag, n, dp);

        long long val = nums[idx];
        if (!flag)
            val = -val;

        long long take = val + solve(idx + 1, nums, !flag, n, dp);

        return dp[idx][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(2, -1));

        return solve(0, nums, true, n, dp);
    }
};
