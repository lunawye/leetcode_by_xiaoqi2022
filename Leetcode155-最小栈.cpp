class MinStack
{
public:
    stack<int> A;
    stack<int> res;
    MinStack()
    {
        res.push(INT_MAX);
    }

    void push(int val)
    {
        A.push(val);
        res.push(min(res.top(), val));
    }

    void pop()
    {
        A.pop();
        res.pop();
    }

    int top()
    {
        return A.top();
    }

    int getMin()
    {
        return res.top();
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