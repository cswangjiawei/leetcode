class Solution {
public:
    double myPow(double x, int n) {
       if (n==0) {
           return 1;
       }
       if (n==1) {
           return x;
       }

        long long k = n;
       if (n < 0) {
           k = -1 * k;
       } else {
           k = n;
       }

       double y = myPow(x, k/2);
       if (k%2 == 0) {
           if (n > 0) {
               return y * y;
           } else {
               return 1.0/(y*y);
           }
       } else {
           if (n > 0) {
               return y*y*x;
           } else {
               return 1.0/(y*y*x);
           }
           
       }
    }
};