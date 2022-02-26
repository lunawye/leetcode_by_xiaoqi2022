class CQueue
{
public:
    stack<int> A;
    stack<int> B;
    CQueue()
    {
    }

    void appendTail(int value)
    {
        A.push(value);
    }

    int deleteHead()
    {
        if (A.empty())
            return -1;
        while (!A.empty())
        {
            int x = A.top();
            A.pop();
            B.push(x);
        }
        int res = B.top();
        B.pop();
        while (!B.empty())
        {
            int x = B.top();
            B.pop();
            A.push(x);
        }
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */