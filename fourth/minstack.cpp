
class MinStack {
    stack<int> alldata, mindata;
    public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        alldata.push(x);
        if(mindata.empty()) {
            mindata.push(x);
        } else {
            int m = min(x, mindata.top());
            mindata.push(m);
        }
    }

    void pop() {
        alldata.pop();
        mindata.pop();
    }

    int top() {
        return alldata.top();
    }

    int getMin() {
        return mindata.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
