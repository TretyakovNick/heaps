#include <bits/stdc++.h>
#include "..\heap2.h"
#include "..\binomial_heap.h"

#define ll long long

using namespace std;

int main() {
    THeap <int> good, bad;
    THeap <int> :: Pointer ptr = good.insert(rand());
    cout << "WrongHeap tests:\n";
    for (int i = 0; i < 2; i++) {
        try { //Test Bad Heap
            if (i == 0) {
                bad.erase(ptr);
            } else if (i == 1) {
                bad.change(ptr, rand());
            }
            assert(false);
        } catch (const std::logic_error &e) {
            cout << e.what() << "\n";
            //assert(e.what() == "Wrong Heap");
        }
    }
    good.extract_min();
    cout << "EmptyHeap tests:\n";
    for (int i = 0; i < 2; i++) {
        try { //Test Empty Heap
            if (i == 0) {
                good.extract_min();
            } else if (i == 1) {
                good.get_min();
            }
            assert(false);
        } catch (const std::out_of_range &e) {
            cout << e.what() << "\n";
            //assert(e.what() == "Wrong Heap");
        }
    }
    good.insert(rand());
    cout << "BadPointerHeap tests:\n";
    for (int i = 0; i < 2; i++) {
        try { //Test BadPointer Heap
            if (i == 0) {
                good.erase(ptr);
            } else if (i == 1) {
                good.change(ptr, rand());
            }
            assert(false);
        } catch (const std::out_of_range &e) {
            cout << e.what() << "\n";
            //assert(e.what() == "Wrong Heap");
        }
    }
    BinomialHeap <int> good1, bad1;
    cout << "EmptyBinomialHeap tests:\n";
    for (int i = 0; i < 2; i++) {
        try { //Test Empty BinomialHeap
            if (i == 0) {
                good1.extract_min();
            } else if (i == 1) {
                good1.get_min();
            }
            assert(false);
        } catch (const std::out_of_range &e) {
                cout << e.what() << "\n";
            //assert(e.wh   at() == "Wrong Heap");
        }
    }
}
