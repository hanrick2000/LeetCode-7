You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
    
这道题还是dfs递归，但看出来真不容易。。。我们发现 在树A下找到所有path 加起来和等于sum 只有两种情况，1）A参与path, 2) A不参与path.
A不参与path的 情况很简单，即对左右子树进行递归，sum 不变。
那A参与path的情况如何计算？等于令sum-a.value， 而求左右两个子树（均参与path）的情况和。为什么左右两子树也要参与呢？因为path是不能断的，要连下去。
时间复杂度O(nlog n)
class Solution {
public:
    
    void pathSumHelper(TreeNode* root, int sum, int &res) {   //root 参与的和为path的总数。
        if(!root) return;
        if(sum == root->val)  ++res;
        
        pathSumHelper(root->left, sum - root->val,res);
        pathSumHelper(root->right, sum - root->val,res);
    }

    int pathSum(TreeNode* root, int sum) {
        
        if(!root) return 0;
        int res = 0;
        pathSumHelper(root, sum, res);
        return res + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};