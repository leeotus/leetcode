#include <chrono>
#include <iostream>
#include <unordered_map>

using namespace std;

// @note 0 <= key <= 10000 && 0 <= value <= 10^5
class LRUCache {
  private:
    using Clock = chrono::steady_clock;

    /// @brief LRU节点
    typedef struct _LRU_CACHE_NODE {
        struct _LRU_CACHE_NODE *prev;
        struct _LRU_CACHE_NODE *next;
        int key;
        int val;
        Clock::time_point expireAt;
    } LRUNode;

    LRUNode *dummy = nullptr;            // 缓存头结点
    int capacity{0};                     // 容量
    int count{0};                        // 当前LRU节点数量
    chrono::seconds ttl{0};              // TTL时长, 0表示不过期
    unordered_map<int, LRUNode *> cache; // 当前缓存查找表

    bool ttlEnabled() const { return ttl.count() > 0; }

    Clock::time_point nextExpireAt() const {
        return ttlEnabled() ? Clock::now() + ttl : Clock::time_point::max();
    }

    bool isExpired(LRUNode *node) const {
        return ttlEnabled() && Clock::now() >= node->expireAt;
    }

    void unlinkNode(LRUNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void pushFront(LRUNode *node) {
        node->next = dummy->next;
        node->prev = dummy;
        dummy->next->prev = node;
        dummy->next = node;
    }

    void moveToFront(LRUNode *node) {
        if (dummy->next == node) {
            return;
        }
        unlinkNode(node);
        pushFront(node);
    }

    void eraseNode(LRUNode *node) {
        unlinkNode(node);
        cache.erase(node->key);
        delete node;
        --count;
    }

    void cleanupExpired() {
        if (!ttlEnabled()) {
            return;
        }

        LRUNode *cur = dummy->next;
        while (cur != dummy) {
            LRUNode *next = cur->next;
            if (isExpired(cur)) {
                eraseNode(cur);
            }
            cur = next;
        }
    }

  public:
    /// @brief LRU算法缓存构造函数
    /// @param capacity [in] 缓存链表的容量
    /// @param ttlSeconds [in] TTL秒数, 0表示不过期
    LRUCache(int cap, int ttlSeconds = 0)
        : capacity(cap), ttl(chrono::seconds(ttlSeconds)) {
        dummy = new LRUNode();

        dummy->next = dummy;
        dummy->prev = dummy;
    }

    ~LRUCache() {
        LRUNode *cur = dummy->next;
        while (cur != dummy) {
            LRUNode *next = cur->next;
            delete cur;
            cur = next;
        }
        delete dummy;
    }

    /// @brief 获取缓存数据
    /// @param key [in] 缓存节点的key值
    /// @return 如果缓存里有key对应的数据,则返回数据,否则返回-1
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        LRUNode *got = it->second;

        if (isExpired(got)) {
            eraseNode(got);
            return -1;
        }

        // 需要把这个LRUNode放到cache链表首部
        moveToFront(got);

        // 返回获取的数据
        return got->val;
    }

    /// @brief 传入数据到LRU缓存链表中
    /// @param key [in] key键
    /// @param value [in] value值
    void put(int key, int value) {
        auto it = cache.find(key);
        if (capacity <= 0) {
            return;
        }

        cleanupExpired();

        if (it != cache.end()) {
            // 这里仅作更新操作,实际需要根据业务做对应修改
            LRUNode *got = it->second;
            got->val = value;

            if (isExpired(got)) {
                eraseNode(got);
                it = cache.end();
            } else {
                got->val = value;
                got->expireAt = nextExpireAt();
                moveToFront(got);
                return;
            }
        }

        if (count == capacity) {
            // 需要淘汰最后的LRU节点
            LRUNode *old = dummy->prev;
            eraseNode(old);
        }

        LRUNode *node = new LRUNode();
        node->key = key;
        node->val = value;
        node->expireAt = nextExpireAt();
        pushFront(node);

        // 放到cache查找表中
        cache[key] = node;

        ++count;
    }
};

int main(int argc, char **argv) { return 0; }