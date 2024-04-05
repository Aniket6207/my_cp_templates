struct node{
    ll sum;
    node(){
        sum=0;
    }
};
 
node t[4*200200];
node merge(node a,node b){
    node ans;
    ans.sum=a.sum+b.sum;
    return ans;
}
 
void build(ll id,ll l,ll r){
    if (l==r){
        t[id].sum=0;
        return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=merge(t[2*id],t[2*id+1]);
    
}
void update(ll id,ll l,ll r,ll pos,ll val){
    if (pos<l || pos>r){
        return;
    }
    if (l==r){
        t[id].sum+=val;
        return;
    }
 
    ll mid=(l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    t[id]=merge(t[2*id],t[2*id+1]);
 
}
node query(ll id,ll l,ll r,ll lq,ll rq){
    if (lq>r || rq<l){
        return node();
    }
    if (lq<=l && r<=rq){
        return t[id];
 
    }
    ll mid=(l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
 
}
