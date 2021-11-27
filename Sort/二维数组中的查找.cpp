class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m=array.size(),n;
        if(m) 
            n=array[0].size();
        else return false;
        int i,j;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(target<array[i][j])
                    break;
                if(target==array[i][j])
                    return true;
            }
            
        }
        return false;
    }
};
