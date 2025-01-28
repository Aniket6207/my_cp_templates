const int N=2e5+10;
vector<ll>parent(N);
vector<vector<ll>>children(N);
vector<vector<ll>>up(31,vector<ll>(N));
vector<ll>depth(N);


void dfs(int a) {
    for(int b : children[a]) {
        depth[b] = depth[a] + 1;
        up[b][0] = a; // a is parent of b
        for(int j = 1; j < 30; j++) {
            up[b][j] = up[up[b][j-1]][j-1];
        }
        dfs(b);
    }
}

ll get_lca(ll a,ll b){
    if(depth[a] < depth[b]) {
        swap(a, b);
    }
    // 1) Get same depth.
    int k = depth[a] - depth[b];
    for(int j = 30 - 1; j >= 0; j--) {
        if(k & (1 << j)) {
            a = up[a][j]; // parent of a
        }
    }
    // 2) if b was ancestor of a then now a==b
    if(a == b) {
        return a;
    }
    // 3) move both a and b with powers of two
    for(int j = 30 - 1; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
    
}

void solve(){
    ll n;
    cin>>n;
    for (int i=0;i<n;i++){
        ll cnt;
        cin>>cnt;
        for (int j=0;j<cnt;j++){
            ll x;
            cin>>x;
            children[i].pb(x);
        }
    }
    dfs(0);
    ll q;
    cin>>q;
    for (int i=0;i<q;i++){
        ll u,v;
        cin>>u>>v;
        cout << get_lca(u,v) << endl;
    }
    

    
}
   