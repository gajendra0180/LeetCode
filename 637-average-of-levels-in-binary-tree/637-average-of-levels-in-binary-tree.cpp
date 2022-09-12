/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 static bool csort(pair<int,int> p1,pair<int,int> p2)
  {
    if(p1.first<p2.first)
      return true;
   return false;
  }
  vector<pair<int,int>> s;
  void tree(TreeNode* rt,int depth)
  {
    if(rt==NULL)
      return;
    s.push_back({depth,rt->val});
    tree(rt->left,depth+1);
    tree(rt->right,depth+1);
  }
    vector<double> averageOfLevels(TreeNode* root) {
        tree(root,0);
    vector<double> v;
    auto it=s.begin();
      int tet=0;
      double sum=0;
      double k=0;
      sort(s.begin(),s.end(),csort);
      for(auto i:s)
      {
        if(i.first==tet)
        {
          sum=sum+i.second;
          k++;
        }
        else
        {
          v.push_back(sum/k);
          sum=i.second;
          k=1;
          tet=i.first;
        }
      }
      
      v.push_back(sum/k);
      return v;
    }
};