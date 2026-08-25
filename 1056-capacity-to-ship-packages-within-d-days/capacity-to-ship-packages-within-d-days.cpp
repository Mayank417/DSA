class Solution {
public:
int solve(vector<int>& v,int cap){
    int d=1,load=0;
    for(int i=0;i<v.size();i++){
        load+=v[i];
        if(load>cap){
            load=v[i];
            d++;
        }
    }
    return d;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int st=*max_element(weights.begin(),weights.end());
        int en=accumulate(weights.begin(),weights.end(),0);
        int totald=0;
        int ans=INT_MAX;
        while(st<=en){
            int mid=st+(en-st)/2;
            totald=solve(weights,mid);
            if(totald<=days){
                ans=mid;
                en=mid-1;
            }
            else st=mid+1;
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};