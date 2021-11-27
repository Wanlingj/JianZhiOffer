class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        // write code here
        if (pattern.empty())
            return str.empty();
        int m = str.size(), n = pattern.size();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1)); // 定义动态规划数组
        // 初始化
        dp[0][0] = true;
        for (int i = 2; i <= n; i += 2) {
            if (pattern[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        }
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.') // pattern字符串当前字符与str字符串当前字符相等，或pattern字符串当前字符为`.`
                    dp[i][j] = dp[i - 1][j - 1];
                else if (pattern[j - 1] == '*') { // pattern字符串当前字符为`*`
                    if (dp[i][j - 1]) { // 星号匹配一次
                        dp[i][j] = dp[i][j - 1];
                    }
                    else if (j >= 2 && dp[i][j - 2]) { // 星号匹配零次
                        dp[i][j] = dp[i][j - 2];
                    }
                    else if (i >= 2 && j >= 2) // 星号匹配多次
                        dp[i][j] = (dp[i - 1][j] && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.')); 
                }
            }
        }
        return dp[m][n];
    }
};
