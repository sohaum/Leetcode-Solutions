class Solution {
public:
    int clumsy(int n) {
        stack<int>st;
        st.push(n);
        int op = 0;
        for(int i=n-1;i>0;i--) {
            if (op==0) { // multiply
                int top=st.top();
                st.pop();
                st.push(top*i);
            } else if (op==1) { // divide
                int top=st.top();
                st.pop();
                st.push(top/i);
            } else if (op==2) { // add
                st.push(i);
            } else { //subtract
                st.push(-i);
            }
            op=(op+1)%4;
        }
        int res=0;
        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};