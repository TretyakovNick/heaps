#include <exception>
#include <stdexcept>
//#include "heap.h"
#include "array.h"
#include <queue>

template <typename Key>
bool BinomialHeap<Key>::is_empty() const{
    return size > 0;
}

template <typename Key>
Key BinomialHeap<Key>::get_min() {
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
        if (!min || min->key < arr[i]->key) {
            min = arr[i];
        }
    }
}

template <typename Key>
void BinomialHeap<Key>::merge(BinomialHeap <Key> &otherHeap) {
    Array <TNode*> mas;
    std::cout << "kek1\n";
    int i = 0, j = 0;
    Array <TNode*> &a = arr, &b = otherHeap.arr;
    std::cout << a.size() << " " << b.size() << std::endl;
    while (i < a.size() || j < b.size()) {
        std::cout << i << " " << j << std::endl;
        if (i < a.size() && a[i] == nullptr) {
            std::cout << "pisos1" << std::endl;
            i++;
            continue;
        }
        if (j < b.size() && b[j] == nullptr) {
            std::cout << "pisos2" << std::endl;
            j++;
            continue;
        }
        if (i == a.size()) {
            std::cout << "pisos3" << std::endl;
            mas.push_back(b[j]);
            j++;
            continue;
        }
        if (j == b.size()) {
            std::cout << "pisos4" << std::endl;
            mas.push_back(a[i]);
            i++;
            continue;
        }
        std::cout << "pisos5" << std::endl;
        std::cout << i << " " << a.size() << std::endl;
        if (a[i] == nullptr) {
            std::cout << "kek\n";
        } else {
            std::cout << a[i]->degree << "\n";
        }
        if (a[i]->degree < b[j]->degree) {
            mas.push_back(a[i]);
            i++;
        } else {
            mas.push_back(b[j]);
            j++;
        }
        std::cout << "done!" << std::endl;
    }
    std::cout << "kek2\n" << std::endl;
    Array <TNode*> new_arr;
    for (int i = 0; i < (int) mas.size(); i++) {
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
    BinomialHeap otherHeap;
    otherHeap.arr = min->children;
    merge(otherHeap);
    delete min;
    size--;
    return key;
}

template <typename Key>
typename BinomialHeap<Key>::Pointer BinomialHeap<Key>::insert(Key key) {
    TNode *node = new TNode(key);
    BinomialHeap otherHeap;
    otherHeap.arr.push_back(node);
    otherHeap.min = node;
    merge(otherHeap);
    size++;
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
    size = 0;
}

template <typename Key>
BinomialHeap<Key>::~BinomialHeap() {}
