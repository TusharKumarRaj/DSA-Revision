// Problem Statement:

// You are given an m x n binary matrix mat 
// of 1's (representing soldiers) and 0's (representing civilians). 
// The soldiers are positioned in front of the civilians. 
// That is, all the 1's will appear to the left of all the 0's in each row.
// A row i is weaker than a row j if one of the following is true:
// The number of soldiers in row i is less than the number of soldiers in row j.
// Both rows have the same number of soldiers and i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

//solution: the approach that came to mind at first was to create a pair and store {count,index} in it
// storing them in a vector is quite logical.

// we can search each row one by one for the first zero using binary search and store mid+1 as count (0 based indexing)
//later we can sort the vector and store first k elements of vector[i].second and return it

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();

        vector<pair<int,int>>v;

       for(int i=0;i<m;i++)
       {
        int l = 0, r = n-1;
        int cnt = 0;

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(mat[i][mid] == 1)
            {
                l = mid+1;
                cnt = l;
            }

            else{
                r = mid-1;
            }

        }

        v.push_back({cnt,i});
       } 

       sort(v.begin(),v.end());

       vector<int> ans;

       for(int i=0;i<k;i++)
        ans.push_back(v[i].second);
        
        return ans;
    }
};

// Time complexity: sorting - O(m*log(m)), searching - m*O(logn), inserting answer - O(k)
// TC -> O(m*log(m)) + m*O(logn) + O(k)

//Space Complexity: O(m) + O(k)

//for a different approach, we can use min-heap instead of vector, 
// it saves us the trouble of sorting. 

//IMPORTANT -
//By default, C++ priority_queue is a max-heap.
//for min-heap: priority_queue<int, vector<int>, greater<int>> pq;
//heap takes 3 params - priority_queue<DATA_TYPE, CONTAINER, COMPARATOR>

//if datatype is pair then we have to mention it on all params:
//for our question: priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//pair<int,int> mentioned everywhere

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

       for(int i=0;i<m;i++)
       {
        int l = 0, r = n-1;
        int cnt = 0;

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(mat[i][mid] == 1)
            {
                l = mid+1;
                cnt = l;
            }

            else{
                r = mid-1;
            }

        }

        pq.push({cnt,i});
       } 


       vector<int> ans;

       while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
       }

        return ans;
    }
};

//Time complexity: searching is same: O(m*logn), insertion: O(m*logm) , 
//extract k elements: O(k*logm)
//TC - O(m*logn + m*logm + k*logm) 

//For the most optimised approach (when k is very small as compared to m)
//we use max heap with allowing only k elements and deleting top most element, everytime total exceeds k
//this way the weakest to k will be saved
//we can reverse the order and store them as answer.


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();

        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            int cnt = 0;

            while(l <= r) {
                int mid = l + (r - l) / 2;

                if(mat[i][mid] == 1) {
                    cnt = mid + 1;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }

            pq.push({cnt, i});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};


//Time complexity: binary search: O(m*logn), insertion: O(mlogk), extraction to store: O(klogk)
//TC - O(m*logn + m*logk + k*logk) {k*logk can be ignored for m >> k}
//SC - O(k)