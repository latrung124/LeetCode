#include <queue>

class MyStack {
std::queue<int> mqueue;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        size_t s = mqueue.size();
        mqueue.push(x);
        for (int i = 0; i < s; ++i) {
            mqueue.push(mqueue.front());
            mqueue.pop();
        }
    }
    
    int pop() {
        int top = mqueue.front();
        mqueue.pop();
        return top;
    }
    
    int top() {
        return mqueue.front();
    }
    
    bool empty() {
        return mqueue.empty();
    }
};