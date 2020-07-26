/*
371. 两整数之和
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1
*/
/*
371. Sum of Two Integers
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
*/
class Solution {
public:
    int getSum(int a, int b) {
        while (b)
        {
            auto carry = ((unsigned) (a & b)) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};