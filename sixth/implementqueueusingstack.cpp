
class MyQueue {
    stack<int> data;
    int front;
    public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        data.push(x);

        if(data.size() == 1) {
            front = x;
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> back;

        while(data.size() > 1) {
            front = data.top();
            back.push(front);
            data.pop();
        }

        int ret = data.top();
        data.pop();

        while(!back.empty()) {
            data.push(back.top());
            back.pop();
        }

        return ret;
    }

    /** Get the front element. */
    int peek() {
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
