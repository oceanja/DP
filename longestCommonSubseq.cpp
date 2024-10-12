
// Approach 1 (recur+memo)
class Solution {
public:

int t[1001][1001];

int solve(string &s1, string &s2,int i,int j){
    int n=s1.length();
    int m=s2.length();

    if(i>=n || j>=m){
        return 0;
    }

    if(t[i][j]!=-1){
        return t[i][j];
    }

    if(s1[i]==s2[j]){
        return t[i][j]=1+solve(s1,s2,i+1,j+1);
    }

    return t[i][j]=max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));

}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        memset(t,-1,sizeof(t));

        return solve(text1,text2,0,0);
        
    }
};

//Approach-2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
        
        return t[m][n];
    }
};
