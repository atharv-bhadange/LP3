#include<bits/stdc++.h>
#include<iostream>
#include <queue>

using namespace std;

int recur(vector<int>& wt, vector<int>& val, int n, int W, vector<vector<int> >& dp) {
    if(n==0 || W == 0)
        return 0;
    
    if(dp[n][W] != -1) {
        return dp[n][W];
    }
    int ans1 = 0, ans2 = 0;
    if(wt[n-1] <= W) {
        ans1 = val[n-1] + recur(wt, val, n-1, W-wt[n-1], dp);
        ans2 = recur(wt, val, n-1, W, dp);
    }
    else {
        ans2 = recur(wt, val, n-1, W, dp);
    }

    return dp[n][W] = max(ans1, ans2);
}

int main() {

    int n;
    cin>>n;

    int W;
    cin>>W;

    vector<int> wt(n), val(n);

    for(int i=0; i<n; i++)
        cin>>wt[i];
    for(int i=0; i<n; i++)
        cin>>val[i];
    
    vector<vector<int> > dp(n+1, vector<int>(W+1, -1));

    cout<<recur(wt, val, n, W, dp);

    return 0;
}
