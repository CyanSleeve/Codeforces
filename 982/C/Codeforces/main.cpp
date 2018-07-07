//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 1.Row
 [题目链接](http://codeforces.com/contest/982/problem/C)
 **题目大意：**
 
 
 
 
 **输入数据：**
 
 Examples
 
 
 **题目解析：**
 对于每个节点u, 假设v1/v2/v3..等是子节点。
 对于边（u,v）只有两种可能，cut or retain；
 如果v的节点数是偶数，那么可以cut，并且cut之后不会影响u点这个集合；
 如果v的节点数是基数，那么只能retian；
 
 遍历树上的节点，记录cut的数量；
 最终看root所在集合的节点数量，如果是奇数，无解；
 
 
 
 **思考🤔：**
 
 ************************* 题解 ***********************/
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long lld;
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first > tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

struct cmp
{
    bool operator()(Node a,Node b) { return  a.first < b.first; }
};

vector<int> g[N];
int vis[N];
int num[N];
int ans;

int dfs(int u) {
    int sum = 1;
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!vis[v]) {
            dfs(v);
            if (num[v] % 2 == 0) {
                ++ans;
            }
            else {
                sum += num[v];
            }
        }
    }
    num[u] = sum;
    return sum;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1);
    
    if (num[1] % 2 == 0) {
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
