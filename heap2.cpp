#include <exception>
#include <stdexcept>
//#include "heap.h"

template <typename Key>
Key THeap<Key>::get(int index) const{
     return (arr[index])->key;
}

template<typename Key>
bool THeap<Key>::is_empty() const{
    return (!arr.size());
}

template<typename Key>
int THeap<Key>::size() const{
    return arr.size();
}
template <typename Key>
void THeap<Key>::swap(int a, int b) {
    if (a == b) return;
    arr[a]->index = b;
    arr[b]->index = a;
    std::swap(arr[a], arr[b]);
}

template <typename Key>
void THeap<Key>::sift_up(int index) {
    assert(index >= 0 && index < size());
    while (index > 0 && get(index) < get((index - 1) / 2)) {
        swap(index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

template <typename Key>
void THeap<Key>::sift_down(int index) {
    while (index < size()) {
        int nxt = index;
        if (2 * index + 1 < size() && get(nxt) > get(2 * index + 1)) {
            nxt = 2 * index + 1;
        }
        if (2 * index + 2 < size() && get(nxt) > get(2 * index + 2)) {
            nxt = 2 * index + 2;
        }
        if (nxt == index) {
            break;
        }
        swap(index, nxt);
        index = nxt;
    }
}

template <typename Key>
Key THeap<Key>::get_min() const{
    if (!size()) {
        throw std::out_of_range("Heap is empty");
    }
    return get(0);
}

template <typename Key>
Key THeap<Key>::extract_min() {
    if (!size()) {
        throw std::out_of_range("Heap is empty");
    }
    Key key = get(0);
    swap(0, size() - 1);
    arr[size() - 1]->index = -1;
    arr.pop_back();
    sift_down(0);
    return key;
}

template <typename Key>
typename THeap<Key>::Pointer THeap<Key>::insert(Key key) {
    Element *elem = new Element(key, size());
    arr.push_back(elem);
    sift_up(size() - 1);
    Pointer ptr(elem, this);
    return ptr;
}

template <typename Key>
void THeap<Key>::erase(Pointer &ptr) {
    if (ptr.heap != this) {
        throw std::out_of_range("Wrong Heap");
    }
    if (!size()) {
        throw std::out_of_range("Heap is empty");
    }
    int ind = ptr.element->index;
    assert(ind != -1);
    swap(ind, size() - 1);
    arr[size() - 1]->index = -1;
    arr.pop_back();
    if (ind == size()) return;
    sift_down(ind);
    sift_up(ind);
}

template <typename Key>
void THeap<Key>::change(Pointer &ptr, Key key) {
    if (ptr.heap != this) {
        throw std::out_of_range("Wrong Heap");
    }
    Element *elem = ptr.element;
    elem->key = key;
    int ind = elem->index;
    assert(ind != -1);
    sift_down(ind);
    sift_up(ind);
}

template <typename Key>
bool THeap<Key>::exist(Pointer &ptr) const{
    if (ptr.heap != this) {
        throw std::out_of_range("Wrong Heap");
    }
    return ptr.element->index != -1;
}

template <typename Key>
THeap<Key>::THeap() {}

template <typename Key>
THeap<Key>::~THeap() {}

template <typename Key>
template <class Iterator>
THeap<Key>::THeap(Iterator begin, Iterator end) {
    THeap();
    Iterator now = begin;
    while (now != end) {
        insert(now->key);
        now++;
    }
    insert(now->key);
}