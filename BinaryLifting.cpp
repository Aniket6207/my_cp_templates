const int N=2e5+1;
vector<vector<ll>>table(31,vector<ll>(N));

ll query(ll node,ll k){
    if (node==-1 || k==0){
        return node;
    }
    for (int i=30;i>=0;i--){
        if (k>=(1LL<<i)){
            return query(table[i][node],k-(1LL<<i));
        }

    }
    return -1;
}
 
 
void solve(){
    ll n,m;
    cin>>n>>m;
    
    for (int i=1;i<=n;i++){
        cin>>table[0][i];
    }
    for (int i=1;i<=30;i++){
        for (int j=1;j<=n;j++){
            table[i][j]=table[i-1][table[i-1][j]];
        }

    }
    for (int i=0;i<m;i++){
        ll u,k;
        cin>>u>>k;
        cout << query(u,k) << endl;

    }
    

    

    
    
 
 
 
    
    
 
 
 
    
}
 
  
 
   
 
  
 
 
 
 
 
    
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    // cin>>T;
    T=1;
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
 
    return 0;
}
