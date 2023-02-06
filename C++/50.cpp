class Solution {
public:
    double myPow(double x, int n) {
       if (x == 0) {
           return 0;
       }

       if (n==0) {
           return 1;
       }

       if (n==1) {
           return x;
       }

       if (n==-1) {
           return 1.0/x;
       }

       

       double tmp = myPow(x, n/2); 
       double ans = 0;
       if (n%2 == 0) {
           ans = tmp * tmp;
       } else {
           if (n > 0) {
               ans = tmp * tmp * x;
           } else {
               ans = tmp * tmp * (1/x);
           }
       }
       return ans;

    }
};