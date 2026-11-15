class Solution {
public:
    bool isPossible(vector<int>& target) {
        //maxheap
        priority_queue<long long>p;
        long long  sum=0;
        for(int x:target){
            p.push(x);
            sum+=x;
        }
        while(p.top()>1){
            long long maxe=p.top();
           p.pop();
            long long remsum=sum-maxe;
           //edge cases
            if (remsum == 1) {
                return true;
            }
            if (remsum == 0 || maxe <=remsum) {
                return false;
            }
 long long prev=maxe%remsum;
           if(prev==0)
            return false;
           sum=remsum+prev;
           p.push(prev);
        }
        return 1;
    }
};