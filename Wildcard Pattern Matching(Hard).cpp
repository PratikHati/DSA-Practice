#include<bits/stdc++.h>
int wildcardMatchingDP(string pattern, string text, int n,int m, vector<vector<int>> &dp){
    
    //base case
    if(n==0 && m==0){      
        return 1;
    }
    
    if(n==0 && m > 0){
        return 0;
    }
    
    if(n>0 && m == 0){
        while(n){
            if(pattern[n-1] != '*'){
                return 0;
            }
            n--;
        }
        
        return 1;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    
    if(pattern[n-1] == text[m-1] || pattern[n-1]=='?'){
        dp[n][m] = wildcardMatchingDP(pattern, text, n-1,m-1, dp);
        return dp[n][m];
    }
    
    if(pattern[n-1]=='*'){
        int b1 = wildcardMatchingDP(pattern, text, n, m-1, dp);
        int b2 = wildcardMatchingDP(pattern, text,n-1 ,m, dp);
        
        dp[n][m] = b1||b2;
        return dp[n][m];
    }
    
    else{
        dp[n][m] = 0;
        return dp[n][m];
    }
}
bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
    int n = pattern.length();
    int m = text.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    
    return wildcardMatchingDP(pattern, text, n, m,dp);
    
  
}
