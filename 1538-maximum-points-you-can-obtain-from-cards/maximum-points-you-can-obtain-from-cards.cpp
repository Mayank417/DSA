class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       long lsum=0;
        long mx=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        mx=lsum;
        long rsum=0;
        int idx=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
             lsum-=cardPoints[i];
             rsum+=cardPoints[idx];
             mx=max(mx,lsum+rsum);
             idx--;
        }
        return mx;
    }
};