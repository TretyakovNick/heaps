#include <exception>
#include <stdexcept>
//#include "heap.h"

template <typename Key>
void THeap<Key>::sift_down(int v) {
    while (2 * v + 1 < heap_size) {
        int p = -1;
        for (int i = 0; i < 2 && v * 2 + i + 1 < heap_size; i++) {
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
}

template <typename Key>
void THeap<Key>::sift_up(int v) {
    while (v > 0 && a[v] < a[(v - 1) / 2]) {
        std::swap(a[v], a[(v - 1) / 2]);
        v = (v - 1) / 2;
    }
}

template <typename Key>
THeap<Key>::THeap() {
    heap_size = 0;
    a;
}

template <typename Key>
THeap<Key>::~THeap() {
    heap_size = 0;
    a.~Array();
}

template <typename Key>
bool THeap<Key>::is_empty() const {
    return !heap_size;
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
    int mind = a[0];
    std::swap(a[0], a[--heap_size]);
    a.pop_back();
    sift_down(0);
    return mind;
}

template <typename Key>
void THeap<Key>::insert(Key x) {
    a.push_back(x);
    heap_size++;
    sift_up(heap_size - 1);
}
