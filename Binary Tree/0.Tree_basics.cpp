# BINARY TREE BASICS (C++)

// What is a Binary Tree?

// A Binary Tree is a hierarchical data structure in which each node can have at most 2 children.


// IMPORTANT -
// A Binary Tree can have 0, 1, or 2 children per node.
// Left and right children are distinct.
// A Binary Tree does NOT have to be complete or balanced.


// 1. BASIC TREE TERMINOLOGY

// Root - The topmost node of the tree.
// Parent - A node that has one or more children.
// Child - A node directly connected below another node.
// Leaf Node - A node with no children.
// Internal Node - A node having at least one child.
// Sibling - Nodes having the same parent.
// Ancestor - Any node on the path from the root to a particular node.
// Descendant - Any node present below a particular node.
// Subtree - A tree formed by a node and all its descendants.

// Depth of a Node - Number of edges from the root to that node.
// Root has depth 0.

// Height of a Node - Number of edges in the longest path from that node to a leaf.
// Height of a leaf node is 0.

// Height of a Tree - Height of its root.

// IMPORTANT -
// Some implementations define height using the number of nodes instead of edges.
// In that convention, a leaf has height 1.


// 2. HOW TO DEFINE A BINARY TREE NODE?

// C++ structure:

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Creating a Binary Tree:

Node* root = new Node(1);

root->left = new Node(2);
root->right = new Node(3);

root->left->left = new Node(4);
root->left->right = new Node(5);

// Tree formed:

//          1
//        /   \
//       2     3
//      / \
//     4   5

// IMPORTANT -
// root stores the address of the root node.
// left stores the address of the left child.
// right stores the address of the right child.
// NULL means that the node does not have that child.


// 3. TYPES OF BINARY TREES

// 1. FULL BINARY TREE:

// Every node has either 0 or 2 children.
// No node has exactly 1 child.

// 2. COMPLETE BINARY TREE:

// Every level is completely filled except possibly the last.
// The last level is filled from left to right.

// 3. PERFECT BINARY TREE:

// Every internal node has exactly 2 children.
// All leaf nodes are at the same level.

// 4. BALANCED BINARY TREE:

// A tree where the heights of left and right subtrees
// remain balanced according to a specified condition.

// For an AVL tree, the height difference is at most 1.

// 5. SKEWED BINARY TREE:

// Every node has only one child.
// Can be left-skewed or right-skewed.

// IMPORTANT -
// A Binary Search Tree (BST) is a special type of Binary Tree.
// A Binary Tree is NOT necessarily a BST.


// 4. BINARY TREE REPRESENTATION

// A Binary Tree can be represented using:

// 1. Linked Representation:
// Each node contains data and pointers to left and right children.

// 2. Array Representation:
// Commonly used for complete binary trees and heaps.

// For a node at index i (0-based indexing):

// Left Child  = 2*i + 1
// Right Child = 2*i + 2
// Parent      = (i-1)/2

// IMPORTANT -
// Array representation can waste space for sparse or skewed trees.
// Linked representation is commonly used for general Binary Trees.


// 5. TREE TRAVERSALS

// Traversal means visiting every node of a tree in a specific order.

// There are two main categories:

// 1. Depth First Search (DFS):
//    - Preorder
//    - Inorder
//    - Postorder

// 2. Breadth First Search (BFS):
//    - Level Order Traversal


// Consider this tree:

//           1
//         /   \
//        2     3
//       / \   / \
//      4   5 6   7


// 6. PREORDER TRAVERSAL (ROOT -> LEFT -> RIGHT)

// Order:
// 1. Visit Root.
// 2. Traverse Left Subtree.
// 3. Traverse Right Subtree.

// Code:

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

// Output:
// 1 2 4 5 3 6 7

// IMPORTANT -
// Root is processed BEFORE its children.
// Preorder is useful for copying or serializing a tree.


// 7. INORDER TRAVERSAL (LEFT -> ROOT -> RIGHT)

// Order:
// 1. Traverse Left Subtree.
// 2. Visit Root.
// 3. Traverse Right Subtree.

// Code:

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Output:
// 4 2 5 1 6 3 7

// IMPORTANT -
// Root is processed BETWEEN its left and right subtrees.
// Inorder traversal of a BST gives elements in sorted ascending order.

// NOTE -
// Inorder traversal of a normal Binary Tree is NOT necessarily sorted.


// 8. POSTORDER TRAVERSAL (LEFT -> RIGHT -> ROOT)

// Order:
// 1. Traverse Left Subtree.
// 2. Traverse Right Subtree.
// 3. Visit Root.

// Code:

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}

// Output:
// 4 5 2 6 7 3 1

// IMPORTANT -
// Root is processed AFTER both children.
// Postorder is useful for deleting a tree because children
// are processed before their parent.


// 9. LEVEL ORDER TRAVERSAL (BFS)

// Level Order visits nodes level by level from left to right.

// We use a QUEUE because it follows FIFO.

// Code:

void levelOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left != NULL) {
            q.push(curr->left);
        }

        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }
}

// Output:
// 1 2 3 4 5 6 7

// IMPORTANT -
// Queue follows FIFO.
// First inserted node is processed first.
// Left child is inserted before right child.
// Level Order is also called Breadth First Search (BFS).


// 10. TRAVERSAL CHEAT SHEET

// PREORDER  - ROOT -> LEFT -> RIGHT
// INORDER   - LEFT -> ROOT -> RIGHT
// POSTORDER - LEFT -> RIGHT -> ROOT
// LEVEL ORDER - LEVEL BY LEVEL

// EASY WAY TO REMEMBER:

// Preorder  - Root comes FIRST.
// Inorder   - Root comes IN BETWEEN.
// Postorder - Root comes LAST.
// Level Order - Visit level by level.


// 11. RECURSION IN BINARY TREES

// Most Binary Tree problems use recursion.

// Why?

// Every node has two subtrees:
// 1. Left Subtree
// 2. Right Subtree

// Each subtree is itself a Binary Tree.

// This allows us to solve a problem for the root
// using solutions for its left and right subtrees.

// IMPORTANT -
// Base Case:
// if(root == NULL) return;

// This prevents recursion from continuing beyond leaf nodes.

// General Recursive Pattern:

void solve(Node* root) {
    if(root == NULL) {
        return;
    }

    // Process current node.

    solve(root->left);
    solve(root->right);

    // Process current node if required.
}


// 12. FIND NUMBER OF NODES

// Number of nodes = 1 + Nodes in Left Subtree + Nodes in Right Subtree.

// Code:

int countNodes(Node* root) {
    if(root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Time Complexity - O(n).
// Space Complexity - O(h) recursion stack.


// 13. FIND HEIGHT OF A BINARY TREE

// Height = Maximum of Left Subtree Height and Right Subtree Height + 1.

// Code (Height in terms of number of nodes):

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int l = height(root->left);
    int r = height(root->right);

    return 1 + max(l, r);
}

// Time Complexity - O(n).
// Space Complexity - O(h).

// IMPORTANT -
// Here an empty tree has height 0.
// A leaf node has height 1.
// This is height measured in number of nodes.


// 14. FIND MAXIMUM ELEMENT IN A BINARY TREE

int findMax(Node* root) {
    if(root == NULL) {
        return INT_MIN;
    }

    int l = findMax(root->left);
    int r = findMax(root->right);

    return max(root->data, max(l, r));
}

// Time Complexity - O(n).
// Space Complexity - O(h).

// IMPORTANT -
// We must visit every node because a normal Binary Tree
// does not follow any ordering property.


// 15. TIME AND SPACE COMPLEXITY

// Let:
// n = Total number of nodes.
// h = Height of the tree.

// PREORDER,INORDER,POSTORDER:
// Time Complexity - O(n).
// Space Complexity - O(h).

// LEVEL ORDER:
// Time Complexity - O(n).
// Space Complexity - O(w).

// w = Maximum width of the tree (maximum nodes at any level).

// COUNT NODES:
// Time Complexity - O(n).
// Space Complexity - O(h).

// FIND HEIGHT:
// Time Complexity - O(n).
// Space Complexity - O(h).

// IMPORTANT -
// Recursive DFS uses O(h) auxiliary space.
// Balanced Tree - O(log n) recursion stack.
// Skewed Tree - O(n) recursion stack.
// Level Order uses O(w) queue space.

// A Binary Tree containing n nodes requires O(n) space.


// 16. IMPORTANT BINARY TREE FORMULAS

// For a PERFECT BINARY TREE:

// Maximum nodes at level L (root at level 0):
// 2^L

// Maximum nodes in a tree of height h (height in edges):
// 2^(h+1) - 1

// Maximum number of nodes in a binary tree of height h:
// 2^(h+1) - 1

// Minimum possible height in edges for n nodes:
// ceil(log2(n+1)) - 1

// Maximum possible height in edges for n nodes:
// n - 1

// IMPORTANT -
// These formulas assume height is measured in edges.
// Maximum nodes at level L assumes every level is completely filled.


// 17. BINARY TREE VS BINARY SEARCH TREE

// BINARY TREE:
// Each node can have at most 2 children.
// No specific ordering property is required.

// BINARY SEARCH TREE (BST):
// All values in the left subtree are smaller than the node.
// All values in the right subtree are greater than the node.
// Both subtrees must also follow the BST property.

// IMPORTANT -
// Every BST is a Binary Tree.
// Every Binary Tree is NOT a BST.

// Inorder traversal of BST gives sorted order.


// 18. FINAL CHEAT SHEET

// BINARY TREE:
// At most 2 children per node.

// DFS:
// Preorder  - Root, Left, Right.
// Inorder   - Left, Root, Right.
// Postorder - Left, Right, Root.

// BFS:
// Level Order - Uses Queue.

// RECURSION:
// Base Case - root == NULL.

// HEIGHT:
// 1 + max(left height, right height).

// COUNT NODES:
// 1 + left count + right count.

// TRAVERSALS:
// Time Complexity - O(n).

// RECURSIVE DFS:
// Auxiliary Space - O(h).

// LEVEL ORDER:
// Auxiliary Space - O(w).

// BST:
// Inorder traversal gives sorted elements.