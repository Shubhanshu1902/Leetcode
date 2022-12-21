#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    vector<int> queue;
public:
    MyQueue() {
        queue = {};
    }
    
    void push(int x) {
        queue.push_back(x);
    }
    
    int pop() {
        int x = queue[0];
        queue.erase(queue.begin());
        return x;
    }
    
    int peek() {
        return queue[0];
    }
    
    bool empty() {
        return queue.empty();
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