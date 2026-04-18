class Solution {
public:
    int reverse(int n) {
        int rev=0;
        while (n>0) {
            int lastDigit=n%10;
            rev=rev*10+lastDigit;
            n/=10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};