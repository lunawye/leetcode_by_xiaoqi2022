struct DLinkedNode
{
    int key;
    int value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
}; //自己写一个双向链表
class LRUCache
{
private:
    map<int, DLinkedNode *> cache; //用map来快速查找存取
    DLinkedNode *head;             //辅助头尾
    DLinkedNode *tail;
    int size; //容量
    int capacity;

public:
    LRUCache(int capacity) : size(0), capacity(capacity)
    {
        head = new DLinkedNode(); //初始化LRUcache
        tail = new DLinkedNode();
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
            return -1;
        DLinkedNode *node = cache[key];
        int value = node->value;
        moveToHead(node);
        return value;
    }

    void put(int key, int value)
    {
        if (cache.count(key))
        {
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
        else
        {
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node; //加入map
            addToHead(node);   //加入头部
            size++;
            if (size > capacity)
            {
                DLinkedNode *removeNode = removeTail(); //删除尾部
                cache.erase(removeNode->key);           //从map移除
                delete removeNode;                      //防止内存泄漏
                size--;
            }
        }
    }
    void addToHead(DLinkedNode *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode *removeTail()
    {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */