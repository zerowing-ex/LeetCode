/*
1. 两数之和
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
/*
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto tmpIndex = index.find(target - nums[i]);
            if (tmpIndex == index.end())
            {
                index[nums[i]] = i;
            }
            else
            {
                int tmp = tmpIndex->second;
                res.push_back(min(tmp, i));
                res.push_back(max(tmp, i));
            }
        }
        return res;
    }
};