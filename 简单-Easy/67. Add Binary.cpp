/*
67. 二进制求和
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
 

提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。
*/
/*
67. Add Binary
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string res; bool c = false; int sum = 0;
        int m = a.length();
        int n = b.length();
        for (int i = 0; i < max(m, n); ++i)
        {
            int op1 = 0, op2 = 0;
            if(m >= i + 1)
                op1 = a[m - i - 1] - 48;
            if(n >= i + 1)
                op2 = b[n - i - 1] - 48;
            sum = op1 + op2 + c;
            c = sum / 2;
            res = char(sum % 2 + 48) + res;
            sum = 0;
        }
        if (c) res = '1' + res;
        return res;
    }
};