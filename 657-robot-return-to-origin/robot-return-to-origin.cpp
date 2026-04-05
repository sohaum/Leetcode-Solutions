class Solution {
public:
    bool judgeCircle(string moves) {
        int countR=0, countL=0, countU=0, countD=0;
        for (char ch: moves) {
            if (ch=='R') countR++;
            else if (ch=='L') countL++;
            else if (ch=='U') countU++;
            else countD++;
        }
        return (countR==countL && countU==countD);
    }
};