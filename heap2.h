#include <exception>
#include <stdexcept>
//#include "heap.h"

template <typename Key>
int THeap<Key>::sift_down(int v) {
    while (2 * v + 1 < a.size()) {
        int p = -1;
        for (int i = 0; i < 2 && v * 2 + i + 1 < a.size(); i++) {
            if (p == -1 || a[v * 2 + p + 1] > a[v * 2 + i + 1]) {
                p = i;
            }
        }
        if (a[v] < a[v * 2 + p + 1]) {
            break;
        }
        std::swap(a[v], a[v * 2 + p + 1]);
        v = v * 2 + p + 1;
    }
    return v;
}

template <typename Key>
int THeap<Key>::sift_up(int v) {
    while (v > 0 && a[v] < a[(v - 1) / 2]) {
        std::swap(a[v], a[(v - 1) / 2]);
        v = (v - 1) / 2;
    }
    return v;
}

template <typename Key>
THeap<Key>::THeap() {
    a = Array<Key>();
}

template <typename Key>
THeap<Key>::~THeap() {
    a.~Array();
}

template <typename Key>
bool THeap<Key>::is_empty() const {
    return a.empty();
}

template <typename Key>
Key THeap<Key>::get_min() {
    if (is_empty()) {
        throw std::out_of_range("Heap is empty");
    }
    return a[0];
}

template <typename Key>
Key THeap<Key>::extract_min() {
    if (is_empty()) {
        throw std::out_of_range("Heap is empty");
    }
    Key mind = a[0];
    std::swap(a[0], a[a.size() - 1]);
    a.pop_back();
    if (!is_empty()) {
        sift_down(0);
    }
    return mind;
}

template <typename Key>
THeap<Key>::Pointer::Pointer(int index, THeap *heap) {
    this->index = new int(index);
    this->heap = heap;
}

template <typename Key>
THeap<Key>::Pointer::Pointer() {
    this->index = new int(-1);
    this->heap = nullptr;
}

template <typename Key>
typename THeap<Key>::Pointer THeap<Key>::insert(Key x) {
    a.push_back(x);
    return Pointer(sift_up(a.size() - 1), this);
}

template <typename Key>
void THeap<Key>::erase(typename THeap <Key>::Pointer &ptr) {
    if (ptr->heap != this) {
        throw std::out_of_range("Wrong Heap");
    }
    if (is_empty()) {
        throw std::out_of_range("Heap is empty");
    }
    int v = *(ptr.index);
    std::swap(a[a.size() - 1], a[v]);
    delete ptr;
    v = sift_up(v);
    sift_down(v);
}

template <typename Key>
void THeap<Key>::change(typename THeap <Key>::Pointer &ptr, Key key) {
    if (ptr->heap != this) {
        throw std::out_of_range("Wrong Heap");
    }
    int v = *(ptr.index);
    v = sift_up(v);
    sift_down(v);
}

#include "heap2.cpp"
