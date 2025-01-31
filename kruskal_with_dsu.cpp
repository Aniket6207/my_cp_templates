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


void solve(){
    ll n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        make_set(i);
    }
    vector<vector<ll>>edges;
    for (int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.pb({w,u,v});

    }
    sort(all(edges));
    ll ans=0;
    for (auto &c:edges){
        if (find_set(c[1])!=find_set(c[2])){
            ans+=c[0];
            union_set(c[1],c[2]);
        }
    }
    ll curr=find_set(1);
    for (int i=2;i<=n;i++){
        if (find_set(i)!=curr){
            cout << "IMPOSSIBLE" << endl;return;
        }
    }
    cout << ans << endl;

}