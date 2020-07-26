/*
64. 最小路径和
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/
/*
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(m == 0) return 0;
        
        vector<int> tmp(n, INT_MAX);
        vector<vector<int> > min(m, tmp);
        
        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                if(i == m - 1 && j == n - 1)
                    min[i][j] = grid[i][j];
                if(i == m - 1 && j < n - 1)
                    min[i][j] = grid[i][j] + min[i][j + 1];
                if(i < m - 1 && j == n - 1)
                    min[i][j] = grid[i][j] + min[i + 1][j];
                if(i < m - 1 && j < n - 1)
                    min[i][j] = grid[i][j] + (min[i + 1][j] < min[i][j + 1]? min[i + 1][j]: min[i][j + 1]);
            }
        }
        return min[0][0];
    }
};