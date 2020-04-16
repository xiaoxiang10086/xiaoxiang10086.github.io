class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) return nums[i];
            else mp[nums[i]] ++;
        }
        return -1;
    }
};