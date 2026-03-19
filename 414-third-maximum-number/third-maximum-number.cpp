class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for(int num:nums){
             if (num == first || num == second || num == third)
                continue;
            if(first == LONG_MIN  || num>first  ){
                 third = second;
                 second = first ;
                 first = num;
            }else if( second == LONG_MIN || num>second ){
                third=second;
                second =num;
            }else if(third == LONG_MIN || num>third ){
                third = num ;
            }
        }
         if(third==LONG_MIN)return first;
        return third;
    }
};