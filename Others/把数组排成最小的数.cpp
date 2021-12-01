//O(nlogn)
class Solution {
public:
    struct Cmp{//仿函数，重载"()"运算符，叫做“函数调用符”
        bool operator()(string a,string b){
        return a+b<b+a;
    }
};
    string PrintMinNumber(vector<int> numbers) {
        vector<string> s;
       for(int i=0;i<numbers.size();i++){//将数组转换成字符串，放进vector中
          s.push_back(to_string(numbers[i]));//to_string为C++11新特性，如果用DevC++,命令记得加上-std=c++11
      }
      sort(s.begin(),s.end(),Cmp());//记得Cmp后面有一个“()” 
      string ans;
      for(string s1:s)ans+=s1; //C++11新特性,for(元素 i:容器)，拼接答案
      return ans;
        
    }
};
