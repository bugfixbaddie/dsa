class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum=0;
        int main=x;
      while(x){
        int digit=x%10;
        x=x/10;
         sum+=digit;
      }
      if(main%sum==0)
      return sum;
      else
      return -1;

    }
};