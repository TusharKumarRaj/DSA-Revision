// In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
// Rearrange the barcodes so that no two adjacent barcodes are equal. 
// You may return any answer, and it is guaranteed an answer exists.

// Example 1:
// Input: barcodes = [1,1,1,2,2,2]
// Output: [2,1,2,1,2,1]

// Example 2:
// Input: barcodes = [1,1,1,1,2,2,3,3]
// Output: [1,3,1,3,1,2,1,2]

//solution: using heap
//store number of occurence of each number in a vector, so for ex-1 you will get 3 at 1st index
// and 3 and 2nd index.
//push pair {count,index} in heap for every number with count > 0.

//now create a pair prev as {0,0} and run a loop on barcodes array; 
// auto [c,v] = pq.top(); pq.pop(); {pq is heap}
//now do barcodes[i] = v and c --;
//now if prev.first > 0 pq.push(prev) and
//finally prev = {c,v}; 

//This way the we keep filling the 2 indexes with greatest and 2nd greatest count.

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        int n = barcodes.size();
        vector<int> count(10001,0);

         for(int i=0;i<n;i++)
         {
            count[barcodes[i]]++;
         }

         priority_queue<pair<int,int>>pq;

         for(int i=0;i<count.size();i++)
         {
            if(count[i] == 0)
             continue;
            
            pq.push({count[i],i});
         }
        
        pair<int,int> prev = {0,0};
         for(int i=0;i<n;i++)
         {
            auto [c,v] = pq.top(); //c->count, v->value
            pq.pop();

            barcodes[i] = v;
            c--;

            if(prev.first > 0) 
             pq.push(prev);

            prev = {c,v};           
 
         }

        return barcodes;
    }
};

//Time-Complexity: O(n*logk) where k is number of distinct barcodes 
//pq.pop() → O(log k) and pq.push(prev) → O(log k)

//Space-complexity: O(1)

//optimised approach: find the value with highest frequency and arrange it in the array alternatively on even slots
//everything else in the odd remaining slots

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        int n = barcodes.size();
        vector<int> count(10001,0);
        int maxVal = 0;

         for(int i=0;i<n;i++)
         {
            count[barcodes[i]]++;

            if(count[barcodes[i]] > count[maxVal])
             maxVal = barcodes[i];
         }

         int idx = 0;

         while(count[maxVal] > 0)
         {
            barcodes[idx] = maxVal;
            idx+=2;
            count[maxVal]--;
         }


         for(int val=1; val<=10000;val++)
         {
            while(count[val] > 0)
            {
                if (idx >= n) idx = 1;  //switch to odd only after all even slots are filled.
                barcodes[idx] = val;
                idx+=2;
                count[val]--;
            }
         }


        return barcodes;
    }
};

//* -> an important part of code, we dont switch idx =1 before the val loop because it is possible
//that the some further even index were left empty because the maxVal didnt have the frequency to
//cover all even indexes, so first we finish all even indexes and then reset idx to 1.

//Time complexity: O(n)
//Space complexity: O(1)




