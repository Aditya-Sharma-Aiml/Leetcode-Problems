class MinStack {
    stack<long long>st;
    long long mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long value = val;
        if(st.empty()) {
            st.push(value);
            mini = value;
            return ;
        }
        // case1 
        if(value > mini) st.push(value);
        //case2
        else{
            st.push(2 * value - mini);
            mini = value;
        }
    }
    
    void pop() {
        if(st.empty()) return ;

        long long  x = st.top();
        st.pop();

        if(x < mini) {// x updated hai mtlb
            mini = 2 * mini - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;

        long long  x = st.top();

        if(x > mini ) return x; // mtlb original val top pe hai
        return (int)mini; // mtlb original  minimum hai top pe newval hogi
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */