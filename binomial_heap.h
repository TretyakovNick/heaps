#include "array.h"
#pragma once

template <typename Key>
class BinomialHeap {
private:
    class TNode {
    friend BinomialHeap;
    private:
        Key key;
        TNode *parent;
        Array <TNode*> children;
        int degree;
        TNode(Key key) : key(key) {
            parent = nullptr, degree = 0;
        }
    };
    Array <TNode*> arr;
    int heap_size;
    TNode *min;
    void update_min();
public:
    class Pointer{
    friend BinomialHeap;
    private:
        TNode *node;
        BinomialHeap *heap;
        Pointer(TNode *node, BinomialHeap *heap) : node(node), heap(heap) {}
    };
    ~BinomialHeap();
    BinomialHeap();
    bool is_empty() const;
    int size() const;
    Key get_min() const;
    Key extract_min();
    Pointer insert(Key key);
    void decrease(Pointer &ptr, Key key);
    void erase(Pointer &ptr);
    void change(Pointer &ptr, Key key);
    bool exist(Pointer &ptr) const;
    void merge(BinomialHeap &otherHeap);
    void print();
};

#include "binomial_heap.cpp"
