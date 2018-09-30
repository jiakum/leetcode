
class MyStack {
    queue<int> data;
    public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() { 
        queue<int> back;
        while(data.size() > 1) {
            back.push(data.front());
            data.pop();
        }
        int ret = data.front();
        data.pop();
        while(back.size() > 0) {
            data.push(back.front());
            back.pop();
        }

        return ret;
    }

    /** Get the top element. */
    int top() {
        return data.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
