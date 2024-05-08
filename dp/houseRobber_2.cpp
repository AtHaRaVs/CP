// recusion + memo
class Solution
{
public:
    int solve(vector<int> &nums, int i, int n, vector<int> &dp)
    {
        if (i > n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int steal = nums[i] + solve(nums, i + 2, n, dp);
        int skip = solve(nums, i + 1, n, dp);

        return dp[i] = max(steal, skip);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp1(n + 1, -1);
        int zero_index = solve(nums, 0, n - 2, dp1);

        vector<int> dp2(n + 1, -1);
        int first_index = solve(nums, 1, n - 1, dp2);

        return max(zero_index, first_index);
    }
};

// bottom up

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp(n + 1, 0);

        dp[0] = 0;

        for (int i = 1; i <= n - 1; i++)
        {
            int steal = nums[i - 1] + ((i >= 2) ? dp[i - 2] : 0);
            int skip = dp[i - 1];

            dp[i] = max(steal, skip);
        }

        int result1 = dp[n - 1];

        dp.clear();

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            int steal = nums[i - 1] + dp[i - 2];
            int skip = dp[i - 1];

            dp[i] = max(steal, skip);
        }

        int result2 = dp[n];

        return max(result1, result2);
    }
};

// constant space

class Solution
{
public:
    int solve(int l, int r, vector<int> &nums)
    {
        int prev = 0;
        int prevPrev = 0;

        for (int i = l; i <= r; i++)
        {

            int skip = prev;
            int steal = nums[i] + prevPrev;

            int temp = max(steal, skip);

            prevPrev = prev;
            prev = temp;
        }

        return prev;
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        int firstHouse = solve(0, n - 2, nums);
        int secondHouse = solve(1, n - 1, nums);

        return max(firstHouse, secondHouse);
    }
};