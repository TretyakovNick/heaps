#include <bits/stdc++.h>
#include "array.h"
#include "heap.h"

using namespace std;

int main() {
    srand(time(0));
    multiset <int> q;
    THeap <int> w;
    const int MAXN = 1e6 + 7;
    for (int i = 0; i < MAXN; i++) {
        int tp = rand() % 2;
        if (!tp) {
            int x = rand();
            w.insert(x);
            q.insert(x);
        } else if (tp == 1) {
            if (!q.size()) continue;
            assert(*q.begin() == w.get_min());
            q.erase(q.begin());
            w.extract_min();
        }
    }
}
