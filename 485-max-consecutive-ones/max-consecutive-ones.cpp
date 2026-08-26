class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ct=0,ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==1)ct++;
            else {
                ans=max(ans,ct);
                ct=0;
            }
        }
       ans = max(ans, ct);
        return ans;
    }
};