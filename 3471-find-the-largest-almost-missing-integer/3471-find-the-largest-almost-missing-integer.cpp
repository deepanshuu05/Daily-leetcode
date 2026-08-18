class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(int i=0;i<=n-k;i++) {

            set<int>s;
            for(int j=i;j<i+k;j++){
                s.insert(nums[j]);
            }
            for(int x:s) {

                freq[x]++;
            }
        }
        int ans=-1;
        for(auto it:freq) {
            if(it.second==1) {
                ans=max(ans,it.first);
            }
        }

        return ans;
    }
};