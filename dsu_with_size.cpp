int N=2e5+10;
vector<ll>parent(N);
vector<ll>size_set(N);

void make_set(ll v){
    parent[v] = v;
    size_set[v] = 1;
}

ll find_set(ll v){
    if (v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(ll a,ll b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (size_set[a] < size_set[b]){
            swap(a,b);
        }
        parent[b] = a;
        size_set[a] += size_set[b];
    }
}
