/*
7. 整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/
/*
7. Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
class Solution {
public:
    long stol(string str)
    {
        long result;
        istringstream is(str);
        is >> result;
        return result;
    }
    int reverse(int x) {
        string tmp = to_string(x);
        if(tmp[0] == '-')
            std::reverse(tmp.begin() + 1, tmp.end());
        else
            std::reverse(tmp.begin(), tmp.end());
        long res = stol(tmp);
        if(res > INT_MAX || res < INT_MIN)
            return 0;
        else
            return (int)res;
    }
};