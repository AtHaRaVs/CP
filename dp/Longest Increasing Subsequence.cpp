class Solution
{
public:
    int solve(vector<int> &nums, int i, int n, int prev, vector<vector<int>> &dp)
    {

        if (i >= n)
            return 0;

        if (prev != -1 && dp[i][prev] != -1)
            return dp[i][prev];

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev])
            take = 1 + solve(nums, i + 1, n, i, dp);

        int skip = solve(nums, i + 1, n, prev, dp);

        if (prev != -1)
            dp[i][prev] = max(take, skip);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(nums, 0, n, -1, dp);
    }
};