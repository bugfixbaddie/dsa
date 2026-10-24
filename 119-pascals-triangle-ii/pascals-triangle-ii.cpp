class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>r={1};
        for(int i=1;i<=rowIndex;i++){
            r.push_back(1);
            for(int j=i-1;j>0;j--){
                r[j]=r[j]+r[j-1];
            }
        }
        return r;
        
    }
};