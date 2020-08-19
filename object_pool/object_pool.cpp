#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>

using namespace std;

template<class T>
class ObjectPool {
public:
    T *Allocate() {
        if (free.empty()) {
            free.push(new T);
        }
        auto ret = free.front();
        free.pop();
        allocated.insert(ret);
        return ret;
    }

    T *TryAllocate() {
        if (free.empty()) {
            return nullptr;
        }
        return Allocate();
    }

    void Deallocate(T *object) {
        if (allocated.find(object) == allocated.end()) {
            throw invalid_argument("");
        }
        allocated.erase(object);
        free.push(object);
    }

    ~ObjectPool() {
        for (auto x : allocated) {
            delete x;
        }
        while (!free.empty()) {
            auto x = free.front();
            free.pop();
            delete x;
        }
    }

private:
    queue<T*> free;
    set<T*> allocated;
};

void TestObjectPool() {
    ObjectPool<string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    pool.Deallocate(p1);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}
