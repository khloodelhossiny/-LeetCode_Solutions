class MyQueue {
public:
     stack<int>first, last;
    MyQueue() {

    }
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        while(!first.empty()){
            last.push(first.top());
            first.pop();
        }
        int ret = last.top();
        last.pop();
         while(!last.empty()){
            first.push(last.top());
            last.pop();
        }
        return ret;
    }
    
    int peek() {
         while(!first.empty()){
            last.push(first.top());
            first.pop();
        }
        int ret = last.top();
         while(!last.empty()){
            first.push(last.top());
            last.pop();
        }
        return ret;
    }
    
    bool empty() {
        return (first.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */