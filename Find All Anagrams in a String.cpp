class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        map<char,int> m;
        int distinct = 0;
        vector<int> ans;
        int n = s.length();
        int k = p.length();
        
        for(auto x:p){
            
            if(m[x] == 0){
                distinct++;
            }
            
            m[x] += 1;
        }
        
        for(int i=0;i<k;i++){
            
            char c = s[i];
            m[c]--;
            if(m[c] == 0){
                distinct--;
            }
        }
        
        if(distinct == 0){
            ans.push_back(0);
        }
        
        for(int i=k;i<n;i++){
            
            char add = s[i];
            m[add] -= 1;
            if(m[add] == 0){
                distinct--;
            }
            
            char remove = s[i-k];
            m[remove] += 1;
            if(m[remove] == 1){
                distinct++;
            }
            
            if(distinct == 0){
                ans.push_back(i-k+1);
            }
        }
        
        return ans;
    }
};