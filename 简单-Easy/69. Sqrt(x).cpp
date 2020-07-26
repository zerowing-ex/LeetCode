/*
69. x 的平方根
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
*/
/*
69. Sqrt(x)
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
*/
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return x;        
        long long down = 1, upper = x; // 2, 2
        while (down < upper)
        {
            long long mid = (down + upper) / 2; // 1
            if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
            {
                return mid;
            }
            else if (mid * mid < x)
            {
                down = mid + 1;
            }
            else
            {
                upper = mid - 1;
            }
        }       
        return (int)down;
    }
};