//  Created by Jane Zhang on 1/8/19.
//  Copyright © 2019 Jane Zhang. All rights reserved.
/*  This is an implementation of a binary tree data structure
using structs and pointers in C++, as well as a search method.
--> Leetcode question 700.
*/

#include <iostream>
using namespace std;

//binary tree struct
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {} //struct constructor
}; //tree1, tree2; //2 tree instances


//search method for subtree under val
TreeNode* search(TreeNode* root, int val) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == val){
        return root;
    }

    else if (val < root->val) {
        return search(root->left, val);
    }

    else {
        return search(root->right, val);
    }

}

int main() {
    //making tree of 8 -> 7, 9

    TreeNode tree1 = TreeNode(8); //struct
    TreeNode * tree1_ptr = &tree1; //struct pointer...& finds address

    TreeNode tree2 = TreeNode(7);
    TreeNode * tree2_ptr = &tree2;

    TreeNode tree3 = TreeNode(9);
    TreeNode * tree3_ptr = &tree3;

    tree1_ptr->left = tree2_ptr;
    tree1_ptr->right = tree3_ptr;

    TreeNode* source = search(tree1_ptr, 7);
    cout << source->val << endl;

    return 0;
}