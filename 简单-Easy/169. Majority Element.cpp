/*
169. 多数元素
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2
*/
/*
169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = nums.size();
        if(m == 1) return nums[0];
        int count = 0;
        int major = -1;
        for(int i = 0; i < m; ++i)
        {
            if(!count) {
                major = nums[i];
                count = 1;
            }
            else major == nums[i]? ++count:--count;
        }
        int numbers = 0;
        for(int i = 0; i < m; ++i)
        {
            if(major == nums[i]) ++numbers;
        }
        if(numbers > m/2) return major;
        else return -1;
    }
};