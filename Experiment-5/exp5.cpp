class Solution {
public:
    int countSub(int idx, vector<int>& arr, int target) {
        if(target == 0)
            return 1;
        if(idx == arr.size())
            return 0;
        int take = 0;
        if(arr[idx] <= target)
            take = countSub(idx + 1, arr, target - arr[idx]);
        int notTake = countSub(idx + 1, arr, target);
        return take + notTake;
    }
    int perfectSum(vector<int>& arr, int target) {
        return countSub(0, arr, target);
    }
};

