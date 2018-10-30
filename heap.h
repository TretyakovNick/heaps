#include "array.h"
#pragma once

template <typename Key>
class THeap {
public:
    class Pointer {
    friend THeap;
    private:
        int *index;
        THeap *heap;
    public:
        Pointer(int index, THeap *heap);
        Pointer();
    };
    ~THeap();
    THeap();
    bool is_empty() const;
    Key get_min();
    Key extract_min();
    Pointer insert(Key key);
private:
    Array <Key> a;
    int sift_down(int v);
    int sift_up(int v);
    void erase(Pointer &ptr);
    void change(Pointer &ptr, Key key);
};

#include "heap.cpp"
