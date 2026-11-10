// 1464. Maximum Product of Two Elements in an Array

// You are given an array of integers nums.
// Choose two different indices i and j of that array.
// Return the maximum value of (nums[i] - 1) * (nums[j] - 1).

// Example 1:
// Input: nums = [3,4,5,2]
// Output: 12 
// Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

// Example 2:
// Input: nums = [1,5,4,5]
// Output: 16
// Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.

// Example 3:
// Input: nums = [3,7]
// Output: 12

//Solution:
//Using Heap
//put all elements in heap and take out top 2 elements

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;

        for(auto ele: nums)
        {
            pq.push(ele);
        }

        int first = pq.top();
        pq.pop();
        int second = pq.top();

        int ans = (first-1)*(second-1);

        return ans;
        
    }
};

//Time-Complexity: traversing : O(n), Insertion: O(n*logn), Removing element: O(logn)
//TC: O(n*logn)
//SC: O(n)

//Optimised Approach(no heap)

//store the elements in 2 variables first and second as you go
//if ele > first then second = first and first = ele ; else if ele>second then second = ele

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0, second = 0;

        for(auto ele: nums)
        {
            if(ele > first)
            {
                second = first;
                first = ele;
            }
            else if(ele > second)
            {
                second = ele;
            }
        }

        return (first-1)*(second-1);
    }
};

//TC - O(n), SC - O(1)