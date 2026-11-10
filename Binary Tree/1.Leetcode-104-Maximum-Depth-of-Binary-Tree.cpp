// 104. Maximum Depth of Binary Tree

// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]    
// Output: 3

// Example 2:
// Input: root = [1,null,2]
// Output: 2

//solution: go to left and right and explore all paths return the max of left/right.

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root== NULL)
         return 0;
       
        int left=0;
        int right = 0;
        

         left = 1 + maxDepth(root->left);
         right = 1 + maxDepth(root->right);


       return max(left,right);
        
    }
};

//TC - O(n), SC - O(n)

//through bfs:
//we go through each node and keep doing depth++ so we end up at the final depth because
//as long as nodes are there depth keeps increasing

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL)
         return 0;
        
        queue<TreeNode*> q;

        q.push(root);

        int depth = 0;

        while(!q.empty())
        {
            int n = q.size();

            for(int i=0;i<n;i++)
            {
                auto front = q.front();
                q.pop();

                if(front->left)
                {
                    q.push(front->left);
                }

                if(front->right)
                 q.push(front->right);
            }
            depth++;
        }

        return depth;
    }
};

//TC - O(n)
//SC - O(w), where w -> maximum width of binary tree at any level