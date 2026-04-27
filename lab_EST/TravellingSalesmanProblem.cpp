//travelling salesman problem using bitmasking and dynamic programming
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int tsp(vector<vector<int>>& cost){
    int n=cost.size();
    vector<vector<int>> dp(1<<n,vector<int>(n,INT_MAX));
    dp[1][0]=0;
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                for(int j=0;j<n;j++){
                    if(mask&(1<<j) && i!=j){
                        dp[mask][i]=min(dp[mask][i],dp[mask^(1<<i)][j]+cost[j][i]);
                    }
                }
            }
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[(1<<n)-1][i]+cost[i][0]);
    }
    return ans;
}
};
