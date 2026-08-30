class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX, mx = INT_MIN;
        int mnIndex = -1, mxIndex = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] < mn) {
                mn = nums[i];
                mnIndex = i;
            }
            if(nums[i] > mx) {
                mx = nums[i];
                mxIndex = i;
            }
        }
        int a = min(mnIndex, mxIndex);
        int b = max(mnIndex, mxIndex);
        return min({
            b + 1,
            n - a,
            a + 1 + n - b
        });
    }
};