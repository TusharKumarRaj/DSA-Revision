// 45. Jump Game II

// You are given a 0-indexed array of integers nums of length n. 
// You are initially positioned at index 0.
// Each element nums[i] represents the maximum length of a forward jump from index i. 
// In other words, if you are at index i, you can jump to any index (i + j) where:
// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach index n - 1. 
// The test cases are generated such that you can reach index n - 1. 

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [2,3,0,1,4]
// Output: 2

//Solution: I started with recursive solution, a loop that goes from 1 to nums[i] and
//fun(index+i,jumps+1) , when we get to index = n-1 , store ans = min(ans,jumps)

class Solution {
public: 
    int ans = INT_MAX;
    void helper(vector<int>&nums,int index,int count)
    {
        if(index == nums.size()-1)
        {
            ans = min(ans,count);
            return;
        }

        if(index >= nums.size())
        {
            return;
        }

        for(int i = 1;i<=nums[index];i++)
        {
            if(index+i >= nums.size())
             break;

             helper(nums,index+i,count+1);

        }

    }

    int jump(vector<int>& nums) {

        helper(nums,0,0);

        return ans;
        
    }
};

//TC - O(N^N), SC- O(N) 

//DP solution can make this N^2, we make dp based on index, the dp[index] will give jumps required
//to reach n-1 index.
// for example , nums = {2,3,1,1,4} then dp[4] = 0 because its already n-1
//dp[3] = 1 because one jump req. , dp[2] = 2 and dp[1] = 1(one jump of 3), dp[0] = 2(jump of 1+3)

//so we start with a dp array [-1,-1,-1,-1,-1] and form answer by int jumps = helper(index+i)
//when index = n-1 we return 0 so jumps = 0 for 2nd last index and ans = 1+0 = 1 and dp[3] = 1
//then jump for index = 2 returns 1 and ans = 2 and dp[2] = 2 , similarly dp[1] = 3
//but then we go to next iteration where i = 2 so for index 1 dp[3] gets called and we get
//jumps = 1 and ans = 2 and dp[1] = 2 and then i = 3 gets called and dp[4] gets called
//but it returns 0 as base case and dp[1] = 1 and it returns to dp[0] = 1+1 and ans = 2;

class Solution {
public:

    int helper(vector<int>& nums, int index, vector<int>& dp)
    {
        if(index == nums.size()-1)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int ans = INT_MAX;

        for(int i = 1; i <= nums[index]; i++)
        {
            if(index+i >= nums.size())
                break;

            int jumps = helper(nums, index+i, dp);

            if(jumps != INT_MAX)
            {
                ans = min(ans, 1+jumps);
            }
        }

        return dp[index] = ans;
    }

    int jump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n,-1);

        return helper(nums, 0, dp);
    }
};

//TC - O(N^2), SC- O(N) 

//The optimised solution is greedy, we create three variables, jump, left and right.
//we start with l,r=0 and then we create a variable farthest to keep track of farthest we can go 
//from that range. we write a for loop from i = l to r and we calculate farthest as
// farthest = max(i+nums[i],farthest),this way we get the farthest possible distance from the range (l,r)
// we update l = r+1 and r = farthest
// all this inside a while loop with check r<n-1 so we stop at r == n-1.

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jumps = 0;
        int l=0,r=0;
        int n = nums.size();

        while(r<n-1)
        {
            int farthest = 0;

            for(int i=l;i<=r;i++)
            {
                farthest = max(i+nums[i],farthest);

            }
            l = r+1;
            r = farthest;
            jumps++;

          
        }

        return jumps;
    }
};

//TC - O(n) , while loop is only for checking if we reached n-1 nothing else.
//we are visiting each element of array at most once
//SC - O(1).