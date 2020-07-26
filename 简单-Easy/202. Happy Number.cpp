/*
202. 快乐数
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

 

示例：

输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
/*
202. Happy Number
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> index;
        index[n] = 1;
        while (n != 1)
        {
            stack<short> s;
            // update new n
            while (n)
            {
                s.push(n % 10);
                n /= 10;
            }
            while (!s.empty())
            {
                n += s.top() * s.top();
                s.pop();
            }
            if (index.find(n) == index.end())
            {
                index[n] = true;
            }
            else return false;
        }
        return true;
    }
};