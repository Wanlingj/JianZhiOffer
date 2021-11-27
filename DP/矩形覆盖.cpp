class Solution {
public:
    int rectCover(int number) {
        if((number==0)||(number==1)||(number==2))
            return number;
        int a=1,b=2,c;
        for(int i=3;i<=number;++i){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
