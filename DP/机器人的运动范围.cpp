class Solution {
public:
    
    using V = vector<int>;
    using VV = vector<V>;   
    int dir[5] = {-1, 0, 1, 0, -1};
 
    int check(int n) {
        int sum = 0;
 
        while (n) {
            sum += (n % 10);
            n /= 10;
        }
 
        return sum;
    }
     void dfs(int x, int y, int sho, int r, int c, int &ret, VV &mark) {
        // 检查下标 和 是否访问
        if (x < 0 || x >= r || y < 0 || y >= c || mark[x][y] == 1) {
            return;
        }
        // 检查当前坐标是否满足条件
        if (check(x) + check(y) > sho) {
            return;
        }
        // 代码走到这里，说明当前坐标符合条件
        mark[x][y] = 1;
        ret += 1;
 
        for (int i = 0; i < 4; ++i) {
            dfs(x + dir[i], y + dir[i + 1], sho, r, c, ret, mark);
        }
 
 
 
    }
    int movingCount(int threshold, int rows, int cols) {
        if (threshold < 0) {
            return 0;
        }
        if(threshold == 0)
            return 1;
 
        VV mark(rows, V(cols, -1));
        int ret = 0;
        dfs(0, 0, threshold, rows, cols, ret, mark);
        return ret;
    }
};
