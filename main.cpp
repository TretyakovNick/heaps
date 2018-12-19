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

void check_heap() {
    all.clear();
    THeap <int> w;
    const int MAXN = 1e3 + 7;
    vector <THeap <int> :: Pointer> ptrs;
    int cnt = 0;
    for (int i = 0; i < MAXN; i++) {
        int tp = rand() % 15;
        //cout << tp << "\n";
        if (tp > 2) {
            int x = rand();
            ptrs.push_back(w.insert(x));
            add(x);
            cnt++;
        } else if (tp == 2) {
            if (!cnt) continue;
            //cout << get_min() << " " << w.get_min() << "\n";
            assert(get_min() == w.get_min());
            extract();
            w.extract_min();
            cnt--;
        } else if (tp == 1) {
            if (!cnt) continue;
            int p = rand() % all.size();
            if (all[p] == INF) continue;
            if (!w.exist(ptrs[p])) {
                continue;
            }
            all[p] = INF;
            cnt--;
            w.erase(ptrs[p]);
        } else {
            if (!cnt) continue;
            int p = rand() % all.size(), v = rand();
            if (all[p] == INF) continue;
            if (!w.exist(ptrs[p])) {
                continue;
            }
            all[p] = v;
            w.change(ptrs[p], v);
        }
        //cout << "heh\n";
    }
}

int main() {
    //srand(time(0));
    std::cout << "kek\n";
    int iter = 0;
    while (true) {
        check_heap();
        cout << "OK " << iter++ << "\n";
    }
}

/*
int n;
    cin >> n;
    vector <THeap<int>::Pointer> pointers;
    THeap <int> q;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "insert") {
            int x;
            cin >> x;
            pointers.push_back(q.insert(x));
            cout << "ok\n";
        } else if (s == "extract_min") {
            if (!q.size()) {
                cout << "error\n";
            } else {
                cout << q.extract_min() << "\n";
            }
        } else if (s == "delete") {
            int p;
            cin >> p;
            p--;
            if (p >= pointers.size()) {
                cout << "error\n";
                continue;
            }
            auto ptr = pointers[p];
            if (ptr.element->index == -1) {
                cout << "error\n";
                continue;
            }
            q.erase(ptr);
            cout << "ok\n";
        } else if (s == "change") {
            int p, x;
            cin >> p >> x;
            p--;
            if (p >= pointers.size()) {
                cout << "error\n";
                continue;
            }
            auto ptr = pointers[p];
            if (ptr.element->index == -1) {
                cout << "error\n";
                continue;
            }
            q.change(ptr, x);
            cout << "ok\n";
        } else if (s == "get_min") {
            if (!q.size()) {
                cout << "error\n";
            } else {
                cout << q.get_min() << "\n";
            }
        } else if (s == "size") {
            cout << q.size() << "\n";
        } else if (s == "clear") {
            while (q.size()) {
                q.extract_min();
            }
            cout << "ok\n";
        }
    }
*/
