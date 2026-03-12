#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> par, rnk;
    
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        par.resize(n); rnk.resize(n, 0);
        iota(par.begin(), par.end(), 0);
        
        int mn = INT_MAX;
        for (auto& e : edges) {
            if (e[3] == 1) {
                if (!unite(e[0], e[1])) return -1;
                mn = min(mn, e[2]);
            }
        }
        
        vector<int> parFull(n);
        iota(parFull.begin(), parFull.end(), 0);
        vector<int> rnkFull(n, 0);
        function<int(int)> findF = [&](int x) -> int {
            return parFull[x] == x ? x : parFull[x] = findF(parFull[x]);
        };
        auto uniteF = [&](int a, int b) {
            a = findF(a); b = findF(b);
            if (a == b) return;
            if (rnkFull[a] < rnkFull[b]) swap(a, b);
            parFull[b] = a;
            if (rnkFull[a] == rnkFull[b]) rnkFull[a]++;
        };
        for (auto& e : edges) uniteF(e[0], e[1]);
        set<int> roots;
        for (int i = 0; i < n; i++) roots.insert(findF(i));
        if (roots.size() > 1) return -1;
        
        auto check = [&](int lim) -> bool {
            for (auto& e : edges)
                if (e[3] == 1 && e[2] < lim) return false;
            
            vector<int> p(n);
            iota(p.begin(), p.end(), 0);
            vector<int> r(n, 0);
            function<int(int)> findP = [&](int x) -> int {
                return p[x] == x ? x : p[x] = findP(p[x]);
            };
            auto uniteP = [&](int a, int b) -> bool {
                a = findP(a); b = findP(b);
                if (a == b) return false;
                if (r[a] < r[b]) swap(a, b);
                p[b] = a;
                if (r[a] == r[b]) r[a]++;
                return true;
            };
            
            for (auto& e : edges)
                if (e[3] == 1) uniteP(e[0], e[1]);
            
            for (auto& e : edges)
                if (e[3] == 0 && e[2] >= lim) uniteP(e[0], e[1]);
            
            int used = 0;
            vector<pair<int,long long>> upgradable;
            for (auto& e : edges)
                if (e[3] == 0 && e[2] < lim && 2*e[2] >= lim)
                    upgradable.push_back({e[2], (long long)e[0]*n + e[1]});
            sort(upgradable.rbegin(), upgradable.rend());
            
            for (auto& [s, uv] : upgradable) {
                int u = uv / n, v = uv % n;
                if (used < k && uniteP(u, v)) used++;
            }
            
            int root = findP(0);
            for (int i = 1; i < n; i++)
                if (findP(i) != root) return false;
            return true;
        };
        
        vector<int> candidates;
        for (auto& e : edges) {
            candidates.push_back(e[2]);
            if (e[3] == 0) candidates.push_back(2 * e[2]);
        }
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        
        int ans = -1;
        int lo = 0, hi = (int)candidates.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(candidates[mid])) {
                ans = candidates[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};