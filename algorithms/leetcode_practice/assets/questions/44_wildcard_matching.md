# 44. Wildcard Matching

## Question link
(https://leetcode.com/problems/wildcard-matching/description/)

## Question Description

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false


## 解题思路

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int> > dp(p.size() + 1, vector<int>(s.size() + 1, 0));
        
        dp[0][0] = 1;
        
        for(int i = 1;i < dp.size();i++){
            for(int j = 0;j < dp[i].size();j++){
                if(p[i-1] == '*'){
                    if(j == 0){
                        dp[i][j] = dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j] ;
                    }
                }else if(p[i-1] == '?'){
                    if(j == 0) continue;
                    dp[i][j] = (dp[i-1][j-1] == 1) ? 1 : 0;  
                }else{
                    if(j == 0) continue;
                    dp[i][j] = (dp[i-1][j-1] == 1 && p[i-1] == s[j-1]) ? 1 : 0;  
                }
            }
        }
        
        return dp[p.size()][s.size()];
    }
};
```