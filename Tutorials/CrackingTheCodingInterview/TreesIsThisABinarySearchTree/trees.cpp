/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
#include <climits>

int get_max (Node *cur)
{
	if (cur == NULL)
		return INT_MIN;
	return max(cur->data,max(get_max(cur->left),get_max(cur->right)));
}

int get_min (Node *cur)
{
	if (cur == NULL)
		return INT_MAX;
	return min(cur->data,min(get_min(cur->left),get_min(cur->right)));
}
bool checkBST(Node* root) {
   	if (root == NULL)
   		return true;

   	if (get_max(root->left) >= root->data || get_min(root->right) <= root->data)
   		return false;
   	if (!checkBST(root->left) || !checkBST(root->right))
   		return false;

   	return true;
}
