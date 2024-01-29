class MyQueue {
 public:
  MyQueue() {}
  stack<int> st1, st2;
  void push(int x) { st1.push(x); }

  int pop() {
    while (st1.size()) {
      st2.push(st1.top());
      st1.pop();
    }
    int cur = st2.top();
    st2.pop();
    while (st2.size()) {
      st1.push(st2.top());
      st2.pop();
    }
    return cur;
  }

  int peek() {
    while (st1.size()) {
      st2.push(st1.top());
      st1.pop();
    }
    int cur = st2.top();
    while (st2.size()) {
      st1.push(st2.top());
      st2.pop();
    }
    return cur;
  }

  bool empty() { return !st1.size(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */