// Job Sequencing Problem

// You are given two arrays: deadline[], and profit[], which represent a set of jobs, 
// where each job is associated with a deadline, and a profit. 
// Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. 
// You will earn the profit associated with a job only if it is completed by its deadline.
// Your task is to return the following two values
// Number of jobs selected for the maximum profit. 
// The total maximum profit by completing those jobs.

// Examples :

// Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
// Output: [2, 60]
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20 + 40).

// Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
// Output: [2, 127]
// Explanation: Job1 and Job3 can be done with maximum profit of 127 (100 + 27).

// Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
// Output: [3, 100]
// Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).

//solution: we create a vector of pair and store all deadlines with their profit
//then we sort the vector on the basis of highest profit first, because we want max profit
//then create an array slot and it should be size of the maximum deadline and value -1
//then we take an element and check its deadline if the value of slot[deadline] = -1 then
//we do slot[deadline] = 1 and we do count++, maxprofit+=profit of that deadline. This way we fill
//the slots according to deadline , if slot[4] = 1 then we put it on slot[3] so we do slot[3] = 1
//this way each slot gets filled with a deadline.
//Logic is to get maximum profit and fill available deadline

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        
        int n = deadline.size();
        vector<pair<int,int>> jobs;
        
        for(int i=0;i<n;i++)
        {
            jobs.push_back({profit[i],deadline[i]});
        }
        
        sort(jobs.rbegin(), jobs.rend());
        
        int size = *max_element(deadline.begin(), deadline.end());
        
        vector<int> slot(size+1,-1);
        int cnt = 0;
        int maxProfit = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j = jobs[i].second;j>=1;j--){ //we check slots from "deadline" to 1 
            if(slot[j]==-1)
            {
                  slot[j] = 1;
                  cnt++;
                  maxProfit+=jobs[i].first;
                  break;
            }
            }
        }
        return {cnt,maxProfit};
    }
};

//optimisation - DSU(disjoint set union), we can use this logic to avoid a for loop for checking
//available slot. Instead of slot we create a parent array and fill it with its index,
//size of parent is max deadline. Now what we will do is say parent = [0,1,2,3,4] then if we
//get deadline as 4 then we will check if parent[deadline] = deadline, if yes then cnt++, maxprofit+=profit for 4
// and parent[4] = 3 so it becomes parent = [0,1,2,3,3] next time when deadline = 4, we check
// parent[deadline] == deadline? -> no, then jump to parent[deadline], i.e. 3 then we check
// parent[3] == 3? yes , then we give 3 to the deadline and do parent[3] = 2.

//for this we write a find function that is a recursive function:
 int find(int x, vector<int>&parent)
    {
        if(parent[x] == x)
         return x;
         
         return parent[x] = find(parent[x],parent);
        
    }
    
//for parent = [0,1,1,2,3] if deadline = 4 , it will return 1. dry run yourself.
//this way we can check available slots without for loop.

class Solution {
  public:
    int find(int x, vector<int>&parent)
    {
        if(parent[x] == x)
         return x;
         
         return parent[x] = find(parent[x],parent);
        
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        
        int n = deadline.size();
        vector<pair<int,int>> jobs;
        
        for(int i=0;i<n;i++)
        {
            jobs.push_back({profit[i],deadline[i]});
        }
        
        sort(jobs.rbegin(), jobs.rend());
        
        int size = *max_element(deadline.begin(), deadline.end());
        
        vector<int> parent(size+1);
        int cnt = 0;
        int maxProfit = 0;
        
        for(int i=0;i<=size;i++)
        {
            parent[i] = i;
        }
        
        for(int i=0;i<n;i++)
        {
            int available = find(jobs[i].second,parent); //gives available slot
            
            if(available > 0) //for ==0 all slots are filled
            {
                cnt++;
                maxProfit+=jobs[i].first;
                
                parent[available] = find(available-1,parent); // updating parent[4] = 3.
            }
    //parent[avail] = avail-1 also works but, for parent = {0, 1, 2, 2, 3}; if we do avail-1
    // then we find(4) -> find(3) -> find(2) -> find(1) -> return 1 everytime
    //but for find(available-1,parent) we do that traversal one time and 
    // array becomes parent = {0, 0, 1, 1, 1} (gets updated in find function). 
    // so 4 → 1 → 0 next time that's it not 4->3->2->1->0.
          
        }
        
        return {cnt,maxProfit};
    }
};

