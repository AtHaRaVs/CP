class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
            return n;

        int a = 2;
        int b = 3;
        int c;

        for (int i = 0; i < n - 3; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};