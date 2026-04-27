//travelling salesman problem using bitmasking and dynamic programming
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int tsp(vector<vector<int>>& cost){
    int n=cost.size();
    vector<vector<int>> dp(1<<n,vector<int>(n,-1));
    function<int(int,int)> solve=[&](int mask,int pos){
        if(mask==(1<<n)-1){
            return cost[pos][0];
        }
        if(dp[mask][pos]!=-1){
            return dp[mask][pos];
        }
        for(int city=0;city<n;city++){
            if((mask&(1<<city))==0){
                dp[mask][pos]=min(dp[mask][pos],cost[pos][city]+solve(mask|(1<<city),city));
            }
        }
        return dp[mask][pos];
    };
}
};
