// Maximum Meetings in One Room

// Given two arrays s[] and f[], where s[i] and f[i] denote the start time and finish time of the ith meeting, respectively. There is only one meeting room. A meeting can be scheduled only if its start time is strictly greater than the finish time of the previously selected meeting.
// Find the maximum number of meetings that can be scheduled in the room such that no two selected meetings overlap. Return the indices (1-based) of the selected meetings in sorted (increasing) order.
// Note: If multiple schedules are possible, prefer meetings with earlier finish times. If two meetings have the same finish time, prefer the meeting with the smaller index.

// Examples:
// Input: s[] = [1, 3, 0, 5, 8, 5], f[] = [2, 4, 6, 7, 9, 9] 
// Output: [1, 2, 4, 5]
// Explanation: We can attend the 1st meeting from (1 to 2), then the 2nd meeting from (3 to 4), then the 4th meeting from (5 to 7), and the last meeting we can attend is the 5th from (8 to 9). It can be shown that this is the maximum number of meetings we can attend.

// Input: s[] = [3], f[] = [7]
// Output: [1]
// Explanation: Since there is only one meeting, we can attend the meeting.

//Solution:
//It is similar to Q.4 but we can't just sort f[] here because then we will lose index, so we
//create a data structure and store s,f and index in it then sort on the basis of f and if f same
//then index(given in problem)

//after this step its same logic:
class Solution {
public:
    vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
        
        vector<vector<int>> v;
        int n = start.size();

        for(int i = 0; i < n; i++)
        {
            v.push_back({end[i], start[i], i+1});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            
            if(a[0] == b[0])
             return a[2] < b[2];

            return a[0] < b[0];
        });

        vector<int> ans;

        int prevEnd = -1;

        for(int i = 0; i < n; i++)
        {
            if(v[i][1] > prevEnd)
            {
                ans.push_back(v[i][2]);
                prevEnd = v[i][0];
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

//TC - for sorting - O(n*logn), traversal - O(logn)
//TC - O(n*logn)
//SC - O(n)