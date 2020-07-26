/*
263. 丑数
编写一个程序判断给定的数是否为丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

示例 1:

输入: 6
输出: true
解释: 6 = 2 × 3
示例 2:

输入: 8
输出: true
解释: 8 = 2 × 2 × 2
示例 3:

输入: 14
输出: false 
解释: 14 不是丑数，因为它包含了另外一个质因数 7。
说明：

1 是丑数。
输入不会超过 32 位有符号整数的范围: [−231,  231 − 1]。
*/
/*
263. Ugly Number
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:

Input: 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2
Example 3:

Input: 14
Output: false 
Explanation: 14 is not ugly since it includes another prime factor 7.
Note:

1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range: [−231,  231 − 1].
*/
class Solution {
public:
    bool isUgly(int num) {
        if (num == 1) return true;
        if (num == 0) return false;
        bool tag1 = true, tag2 = true, tag3 = true;
        while (tag1 || tag2 || tag3)
        {
            if (!(num % 2)) num /= 2;
            else tag1 = false;
            if (!(num % 3)) num /= 3;
            else tag2 = false;
            if (!(num % 5)) num /= 5;
            else tag3 = false;
        }
        return num == 1;
    }
};