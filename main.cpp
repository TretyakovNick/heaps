#include <bits/stdc++.h>
#include "array.h"
#include "binomial_heap.h"
#include "heap2.h"

#define ll long long

using namespace std;

const int INF = 1e9 + 7;

void check_array() {
    vector <ll> a;
    Array <ll> b;
    for (int i = 0; i < 10000; i++) {
        int tp = rand() % 3;
        if (!tp) {
            ll x = rand();
            a.push_back(INF);
            b.push_back(INF);
        } else if (tp == 1) {
            if (!a.size()) {
                continue;
            }
            a.pop_back();
            b.pop_back();
        } else {
            if (!a.size()) continue;
            ll v = rand() % a.size();
            assert(a[v] == b[v]);
        }
    }
}

vector <int> all;

void add(int x) {
    all.push_back(x);
}

int get_min() {
    int res = INF;
    for (int x : all) {
        res = min(res, x);
    }
    return res;
}

void extract() {
    int x = get_min();
    for (int &y : all) {
        if (y == x) {
            y = INF;
            break;
        }
    }
}

void check_heaps() {
    all.clear();
    BinomialHeap <int> w;
    THeap <int> q;
    const int MAXN = 1e3 + 7;
    vector <BinomialHeap <int> :: Pointer> ptrs;
    vector <THeap <int> :: Pointer> heap_ptrs;
    int cnt = 0;
    for (int i = 0; i < MAXN; i++) {
        int tp = rand() % 15 + 2;
        if (tp > 2) {
            int x = rand();
            ptrs.push_back(w.insert(x));
            heap_ptrs.push_back(q.insert(x));
            add(x);
            cnt++;
        } else if (tp == 2) {
            if (!cnt) continue;
            //cout << get_min() << " " << w.get_min() << "\n";
            assert(get_min() == w.get_min());
            assert(get_min() == q.get_min());
            extract();
            w.extract_min();
            q.extract_min();
            cnt--;
        } else if (tp == 1) {
            if (!cnt) continue;
            int p = rand() % all.size();
            if (all[p] == INF) continue;
            if (!q.exist(heap_ptrs[p])) {
                continue;
            }
            all[p] = INF;
            cnt--;
            q.erase(heap_ptrs[p]);
        } else {
            if (!cnt) continue;
            int p = rand() % all.size(), v = rand();
            if (all[p] == INF) continue;
            if (!q.exist(heap_ptrs[p])) {
                continue;
            }
            all[p] = v;
            q.change(heap_ptrs[p], v);
        }
        //cout << "heh\n";
    }
}

int main() {
    //srand(time(0));
    int iter = 0;
    while (true) {
        check_heaps();
        cout << "OK " << iter++ << "\n";
    }
}