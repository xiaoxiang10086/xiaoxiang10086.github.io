class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i] != i){
                if(nums[nums[i]] == nums[i]) return nums[i];
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }
};