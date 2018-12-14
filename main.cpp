#include <bits/stdc++.h>
#include "array.h"
#include "heap1.h"
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

void check_heap() {
    all.clear();
    THeap <int> w;
    const int MAXN = 1e3 + 7;
    for (int i = 0; i < MAXN; i++) {
        int tp = rand() % 10;
        if (tp) {
            int x = rand();
            w.insert(x);
            add(x);
        } else {
            if (!w.size()) continue;
            assert(get_min() == w.get_min());
            extract();
            w.extract_min();
        }
    }
}

int main() {
    srand(time(0));
    //check_array();
    int iter = 0;
    while (true) {
        check_heap();
        cout << "OK " << iter++ << "\n";
    }
}
