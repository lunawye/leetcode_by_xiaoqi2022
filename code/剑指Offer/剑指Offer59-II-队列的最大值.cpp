class MaxQueue
{
public:
    queue<int> res;
    deque<int> ans;
    MaxQueue()
    {
    }

    int max_value()
    {
        if (ans.empty())
            return -1; //如果没有返回-1
        else
            return ans.front(); //返回ans记录最大值的最大个
    }

    void push_back(int value)
    {
        res.push(value); //推入记录队列
        while (!ans.empty() && value > ans.back())
            ans.pop_back();   //如果value比ans队列尾部要大，pop出来，接上次大值
        ans.push_back(value); //推入次大值，ans整体是一个非递增队列，可能出现重复值
    }

    int pop_front()
    {
        if (res.empty())
            return -1;       //空，返回1
        int x = res.front(); //如果pop出去的等于最大值，ans也需要pop
        res.pop();
        if (ans.front() == x)
            ans.pop_front(); //判断ans是否需要pop
        return x;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */