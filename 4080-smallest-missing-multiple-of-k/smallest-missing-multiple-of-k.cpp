class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int h = *max_element(nums.begin(), nums.end());
        for(int i = 1;i<= h/k;i++) {
            bool found = false;
            for(int j=0;j<nums.size();j++) {
                if(nums[j] == i*k) {
                    found = true;
                    break;
                }
            }

            if(!found)
                return i*k;
        }
        return (h/k+1)*k;
    }
};