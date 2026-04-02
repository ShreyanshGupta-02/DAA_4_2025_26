class Solution {
public:
    int rob(vector<int>& nums) {
        
        int prev1 = 0;
        int prev2 = 0;

        for(int i = 0; i < nums.size(); i++){
            int pick = nums[i] + prev2;
            int not_pick = prev1;

            int curr = max(pick, not_pick);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
