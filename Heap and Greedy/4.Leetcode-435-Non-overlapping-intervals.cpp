// 435. Non-overlapping Intervals

// Given an array of intervals intervals 
// where intervals[i] = [starti, endi], 
// return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

// Example 1:
// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

// Example 2:
// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

// Example 3:
// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

//Solution:
// we need to find intervals that overlap , it can be determined by checking if start of an interval
//is less than end of another interval, that way we know the interval starts inside another

//for [1,2] and [1,3] we know that [1,3] starts inside [1,2] , but which one to remove??
//we remove the one which is shorter because it gives more room for other intervals to stay
//like say [1,4],[2,3],[3,6] in this if we remove [2,3] then [3,6] needs to be removed as well
//because [3,6] is also inside [1,4] but if we remove [1,4] then that's it, only one removal.

//so we start by sorting the elements on the basis of their end interval:
   sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1]; 
         })

//this way the array becomes [2,3],[1,4],[3,6] so 2,3 comes first, now we simply store the 
//end index of last element and compare it with start index of current element, if start < end then
//count++, otherwise just store the end index of current element.

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int count = 0;
        int prevEnd = intervals[0][1];

        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] < prevEnd)
             count++;

            else
             prevEnd = intervals[i][1];
        }
     return count;   
    }
};

//TC - O(n*logn) ; n = intervals.size();
//SC - O(1)