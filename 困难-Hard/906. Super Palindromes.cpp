/*
906. 超级回文数
如果一个正整数自身是回文数，而且它也是一个回文数的平方，那么我们称这个数为超级回文数。

现在，给定两个正整数 L 和 R （以字符串形式表示），返回包含在范围 [L, R] 中的超级回文数的数目。

 

示例：

输入：L = "4", R = "1000"
输出：4
解释：
4，9，121，以及 484 是超级回文数。
注意 676 不是一个超级回文数： 26 * 26 = 676，但是 26 不是回文数。
 

提示：

1 <= len(L) <= 18
1 <= len(R) <= 18
L 和 R 是表示 [1, 10^18) 范围的整数的字符串。
int(L) <= int(R)
*/
/*
906. Super Palindromes
Let's say a positive integer is a superpalindrome if it is a palindrome, and it is also the square of a palindrome.

Now, given two positive integers L and R (represented as strings), return the number of superpalindromes in the inclusive range [L, R].

 

Example 1:

Input: L = "4", R = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
 

Note:

1 <= len(L) <= 18
1 <= len(R) <= 18
L and R are strings representing integers in the range [1, 10^18).
int(L) <= int(R)
*/
class Solution {
public:
	/**
	 * @param L: a string
	 * @param R: a string
	 * @return: the number of superpalindromes
	 */
	int superpalindromesInRange(string& L, string& R) {
		// Write your code here
		long long l = stoll(L);
        long long r = stoll(R);
        
        vector<long> t = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004,100000020000001,100220141022001,102012040210201,102234363432201,121000242000121,121242363242121,123212464212321,123456787654321,400000080000004,10000000200000001,10002000300020001,10004000600040001,10020210401202001,10022212521222001,10024214841242001,10201020402010201,10203040504030201,10205060806050201,10221432623412201,10223454745432201,12100002420000121,12102202520220121,12104402820440121,12122232623222121,12124434743442121,12321024642012321,12323244744232321,12343456865434321,12345678987654321,40000000800000004,40004000900040004};

        int d = 0;
        for (int i=0; i<t.size(); ++i) {
            if (t[i] >= l && t[i] <=r) d++;
        }

        return d;
	}
};