class Solution {
public:
	unordermap<int, int> mp;
	std::vector<int> preorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preLen = preorder.size();
        int inLen = preorder.size();

        // 可以不做判断，因为题目中给出的数据都是有效的
        if (preLen != inLen) {
        	return NULL;
        }

        this.preorder = preorder;

        // 以空间换时间，否则，找根结点在中序遍历中的位置需要遍历
        for (int i = 0; i < inLen; ++i)
        {
        	mp.insert(pair<int, int>(preorder[i]), i);
        }

        return buildTree(0, preLen - 1, 0, inLen - 1);
    }
private:
	/**
     * 根据前序遍历数组的 [preL, preR] 和 中序遍历数组的 [inL, inR] 重新组建二叉树
     *
     * @param preL 前序遍历数组的区间左端点
     * @param preR 前序遍历数组的区间右端点
     * @param inL  中序遍历数组的区间左端点
     * @param inR  中序遍历数组的区间右端点
     * @return 构建的新二叉树的根结点
     */

	TreeNode* buildTree(int preL, int preR,
						int inL, int inR) {
		if (preL > preR || inL > inR) {
			return NULL;
		}
		// 构建的新二叉树的根结点一定是前序遍历数组的第 1 个元素
		int pivot = preorder[preL];
		TreeNode *root = new TreeNode(pivot);

		int pivotIndex = mp.find(pivot);

		root->left = buildTree(preL + 1,  preL + (pivotIndex - inL), inL, pivotIndex - 1);
		root->right = buildTree(preL + (pivotIndex - inL) + 1, preR, pivotIndex + 1, inR);

	}
};