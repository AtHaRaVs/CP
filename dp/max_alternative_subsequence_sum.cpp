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
    long long solve(int idx, bool flag, vector<int> &nums, int n, vector<vector<long long>> &dp)
    {

        if (idx >= n)
            return 0;

        if (dp[flag][idx] != -1)
            return dp[flag][idx];

        long long skip = solve(idx + 1, flag, nums, n, dp);

        int val = nums[idx];
        if (!flag)
            val = -val;

        long long steal = solve(idx + 1, !flag, nums, n, dp) + val;

        return dp[flag][idx] = max(steal, skip);
    }
    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<long long>> dp(2, vector<long long>(n + 1, -1));

        return solve(0, true, nums, n, dp);
    }
};