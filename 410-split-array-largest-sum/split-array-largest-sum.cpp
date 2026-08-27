class Solution {
public:
    int solve(vector<int>& v, int m){
        int s=1,sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(sum>m){
                s++;sum=v[i];
            }
            
        }
        return s;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k)return -1;
        int st=*max_element(nums.begin(),nums.end());
        int en=accumulate(nums.begin(),nums.end(),0);
        while(st<=en){
            int mid=st+(en-st)/2;
            int splits=solve(nums,mid);
            if(splits<=k){
                en=mid-1;
            }
            else st=mid+1;
        }
        return st;
    }
};