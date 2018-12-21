#include <exception>
#include <stdexcept>
//#include "heap.h"
#include "array.h"
#include <queue>

template <typename Key>
bool BinomialHeap<Key>::is_empty() const{
    return heap_size == 0;
}

template <typename Key>
Key BinomialHeap<Key>::get_min() const {
    if (is_empty()) {
        throw std::out_of_range("BinomialHeap is empty");
    }
     return min->key;
}

template <typename Key>
void BinomialHeap<Key>::update_min() {
    min = nullptr;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == nullptr) continue;
        if (!min || min->key > arr[i]->key) {
            min = arr[i];
        }
    }
}

template <typename Key>
int BinomialHeap<Key>::size() const {
    return heap_size;
}

template <typename Key>
void BinomialHeap<Key>::merge(BinomialHeap <Key> &otherHeap) {
    Array <TNode*> mas;
    int i = 0, j = 0;
    Array <TNode*> &a = arr, &b = otherHeap.arr;
    while (i < a.size() || j < b.size()) {
        if (i < a.size() && a[i] == nullptr) {
            i++;
            continue;
        }
        if (j < b.size() && b[j] == nullptr) {
            j++;
            continue;
        }
        if (i == a.size()) {
            mas.push_back(b[j]);
            j++;
            continue;
        }
        if (j == b.size()) {
            mas.push_back(a[i]);
            i++;
            continue;
        }
        if (a[i]->degree < b[j]->degree) {
            mas.push_back(a[i]);
            i++;
        } else {
            mas.push_back(b[j]);
            j++;
        }
    }
    Array <TNode*> new_arr;
    for (int i = 0; i <  mas.size(); i++) {
        int deg = mas[i]->degree;
        while (new_arr.size() <= deg) {
            new_arr.push_back(nullptr);
        }
        if (!new_arr[deg]) {
            new_arr[deg] = mas[i];
            continue;
        }
        TNode *node, *child;
        if (new_arr[deg]->key < mas[i]->key) {
            node = new_arr[deg], child = mas[i];
        } else {
            node = mas[i], child = new_arr[deg];
        }
        while (node->children.size() <= child->degree) {
            node->children.push_back(nullptr);
        }
        node->children[child->degree] = child;
        child->parent = node;
        node->degree++;
        while (new_arr.size() <= deg + 1) {
            new_arr.push_back(nullptr);
        }
        new_arr[deg + 1] = node;
        new_arr[deg] = nullptr;
    }
    arr = new_arr;
    update_min();
}

template <typename Key>
Key BinomialHeap<Key>::extract_min() {
    if (is_empty()) {
        throw std::out_of_range("BinomialHeap is empty");
    }
    Key key = min->key;
    for (int i = 0; i < min->children.size(); i++) {
        if (!min->children[i]) continue;
        min->children[i]->parent = nullptr;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == min) {
            arr[i] = nullptr;
            break;
        }
    }
    BinomialHeap otherHeap;
    otherHeap.arr = min->children;
    delete min;
    heap_size--;
    merge(otherHeap);
    return key;
}

template <typename Key>
typename BinomialHeap<Key>::Pointer BinomialHeap<Key>::insert(Key key) {
    TNode *node = new TNode(key);
    BinomialHeap otherHeap;
    otherHeap.arr.push_back(node);
    otherHeap.min = node;
    merge(otherHeap);
    heap_size++;
    return Pointer(node, this);
}

template <typename Key>
bool BinomialHeap<Key>::exist(Pointer &ptr) const{
    if (ptr.heap != this) {
        throw std::out_of_range("Wrong Heap");
    }
    return ptr.node != nullptr;
}

template <typename Key>
void BinomialHeap<Key>::decrease(Pointer &ptr, Key key) {
    if (!exist(ptr)) {
        std::out_of_range("Node isn't exist");
    }
    if (ptr.heap != this) {
        throw std::out_of_range("Wrong BinomialHeap");
    }
    update_min();
}

template <typename Key>
void BinomialHeap<Key>::erase(Pointer &ptr) {
    if (!exist(ptr)) {
        std::out_of_range("Node isn't exist");
    }
    if (ptr.heap != this) {
        throw std::out_of_range("Wrong BinomialHeap");
    }
    decrease(ptr, min->key);
    min = ptr.node;
    extract_min();
}

template <typename Key>
void BinomialHeap<Key>::change(Pointer &ptr, Key key) {
    if (!exist(ptr)) {
        std::out_of_range("Node isn't exist");
    }
    if (ptr.heap != this) {
        throw std::out_of_range("Wrong BinomialHeap");
    }
    erase(ptr);
    ptr = insert(key);
}

template <typename Key>
BinomialHeap<Key>::BinomialHeap() {
    min = nullptr;
    heap_size = 0;
}

template <typename Key>
BinomialHeap<Key>::~BinomialHeap() {}
