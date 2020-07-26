/*
412. Fizz Buzz
写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

示例：

n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/
/*
412. Fizz Buzz
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> a;
        string temp;
        for(int i = 1;i <= n;++i)
        {
            if(!(i % 3)&&!(i % 5))
            {
                temp = "FizzBuzz";
                a.push_back(temp);
            }
            else if(!(i % 3))
            {
                temp = "Fizz";
                a.push_back(temp);
            }
            else if(!(i % 5))
            {
                 temp = "Buzz";
                a.push_back(temp);
            }
            else
            {
                temp = to_string(i);
                a.push_back(temp);
            }
        }
        return a;
    }
};