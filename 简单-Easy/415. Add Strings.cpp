/*
415. 字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
*/
/*
415. Add Strings
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int m = num1.length();
        int n = num2.length();
        bool c = false;
        for (int i = 0; i < max(m, n); ++i)
        {
            int oprand1 = 0, oprand2 = 0, sum = 0;
            if (i < m) oprand1 = num1[m - i - 1] - 48;
            if (i < n) oprand2 = num2[n - i - 1] - 48;
            sum = oprand1 + oprand2 + c;
            res = char(sum % 10 + 48) + res;
            c = sum / 10;
        }
        if (c) res = '1' + res;
        return res;
    }
};