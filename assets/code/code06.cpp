class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        //递归
        if(!head)
            return {};
        vector<int> a = reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};