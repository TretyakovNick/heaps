#include "array.h"
#pragma once

const int MAXN = 1e6 + 7;

template <typename Key>
class THeap {
private:
    Array <Key> a;
    int heap_size;
    void sift_down(int v);
    void sift_up(int v);
public:
    class Pointer {
    private:
        int index;
        THeap *heap;
    };
    ~THeap();
    THeap();
    bool is_empty() const;
    Key get_min();
    Key extract_min();
    void insert(Key key);
};

#include "heap.cpp"
