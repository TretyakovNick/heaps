#include <bits/stdc++.h>
#include "heap2.h"
#include "binomial_heap.h"
using namespace std;
#define ll long long

const int MAXN = 1e6 + 7;
const int TESTS = 10;

void heap_test() {
    THeap <int> q;
    vector <THeap<int> :: Pointer> ptrs;
    for (int i = 0; i < MAXN; i++) {
        int tp = rand() % 10;
        if (tp > 2) {
            int key = rand();
            ptrs.push_back(q.insert(key));
        } else if (tp == 2) {
            if (!q.size()) continue;
            q.extract_min();
        } else if (tp == 1) {
            if (!ptrs.size()) continue;
            int ind = rand() % ptrs.size();
            if (!q.exist(ptrs[ind])) continue;
            int key = rand();
            q.change(ptrs[ind], key);
        } else if (!tp) {
            if (!ptrs.size()) continue;
            int ind = rand() % ptrs.size();
            if (!q.exist(ptrs[ind])) continue;
            q.erase(ptrs[ind]);
        }
    }
}

void bheap_test() {
    BinomialHeap <int> q;
    vector <BinomialHeap<int> :: Pointer> ptrs;
    for (int i = 0; i < MAXN; i++) {
        int tp = rand() % 10;
        if (tp) {
            int key = rand();
            ptrs.push_back(q.insert(key));
        } else {
            if (!q.size()) continue;
            q.extract_min();
        }
    }
}


int main() {
    freopen("speed.txt", "w", stdout);
    srand(time(0));
    ll pr_time = clock();
    ll sum = 0;
    cout << "Heap:\n";
    for (int i = 0; i < TESTS; i++) {
        cout << "Test " << i + 1 << ": ";
        heap_test();
        ll now_time = clock();
        cout << (double) (now_time - pr_time) / CLOCKS_PER_SEC << "\n";
        sum += now_time - pr_time;
        pr_time = now_time;
        cerr << "kek\n";
    }
    cout << "Median : " << (double) sum / TESTS / CLOCKS_PER_SEC << "\n";
    pr_time = clock();
    sum = 0;
    cout << "BinomialHeap:\n";
    for (int i = 0; i < TESTS; i++) {
        cout << "Test " << i + 1 << ": ";
        bheap_test();
        ll now_time = clock();
        cout << (double) (now_time - pr_time) / CLOCKS_PER_SEC << "\n";
        sum += now_time - pr_time;
        pr_time = now_time;
        cerr << "kek\n";
    }
    cout << "Median : " << (double) sum / TESTS / CLOCKS_PER_SEC << "\n";
}