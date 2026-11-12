class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1)return n;
        priority_queue<int>p;
        for(int i=0;i<n;i++)
            p.push(stones[i]);
        while(p.size()>1){
            int wt=p.top();
            p.pop();
            wt-=p.top();
            p.pop();
            if(wt)
            p.push(wt);
        }
        return p.empty()?0: p.top();
        }
    
};