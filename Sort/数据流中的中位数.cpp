class Solution {
public:
    vector<double> data;
    int cnt=0;
    void Insert(int num) {
        data.push_back(num);
        cnt++;
    }

    double GetMedian() { 
        sort(data.begin(),data.end());
        if(cnt%2==0){
            return (data[(cnt-1)/2]+data[(cnt-1)/2+1])/2;
        }
        else{
            return data[(cnt-1)/2];
        }
    }

};
