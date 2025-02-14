int a[200001];
vector<ll> queries[200001];
string ans[200001];
int mp[1000001];
const int m=500;
bool mos_sort(vector<ll>&a,vector<ll>&b){
    if (a[0]/m==b[0]/m){
        return a[1]<b[1];

    }
    else{
        return a[0]/m<b[0]/m;
    }
}


void solve(){
    ll n,q;
    cin>>n>>q;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        queries[i]={l,r,i};
    }
    sort(queries,queries+q,mos_sort);
    int l=0;
    int r=-1;
    ll cnt=0;
    for (int i=0;i<q;i++){
        while(l>queries[i][0]){
            l--;
            mp[a[l]]++;
            if (mp[a[l]]%2==0){
                cnt--;
            }
            else{
                cnt++;
            }
        }  
        while(l<queries[i][0]){
            mp[a[l]]--;
            if (mp[a[l]]%2==0){
                cnt--;
            }
            else{
                cnt++;
            }
            l++;
        }
        while(r<queries[i][1]){
            r++;
            mp[a[r]]++;
            if (mp[a[r]]%2==0){
                cnt--;
            }
            else{
                cnt++;
            }
        }
        while(r>queries[i][1]){
            mp[a[r]]--;
            if (mp[a[r]]%2==0){
                cnt--;
            }
            else{
                cnt++;
            }
            r--;
        }
        if (cnt==0){
            ans[queries[i][2]]="YES";
        }
        else{
            ans[queries[i][2]]="NO";
        }




    }
    // cout << ans << endl;
    for (int i=0;i<q;i++){
        cout << ans[i] << endl;
    }
    for (int i=0;i<n;i++){
        mp[a[i]]=0;
    }

} 


// Ref question -> https://codeforces.com/problemset/problem/2014/H