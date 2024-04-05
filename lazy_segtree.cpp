struct node{
    ll sum;
    ll lazy;

    node(){
        sum=0;
        lazy=0;
    }
};

node t[4*200200];
node merge(node a,node b){
    node ans;
    ans.sum=a.sum+b.sum;
    return ans;
}

void push(ll id,ll l,ll r){
    if (t[id].lazy!=0){
        // apply part
        t[id].sum+=(r-l+1)*t[id].lazy;

        // pushdown
        if (l!=r){
            t[2*id].lazy+=t[id].lazy;
            t[2*id+1].lazy+=t[id].lazy;
        }
        t[id].lazy=0;
    }
}

void build(ll id,ll l,ll r){
    if (l==r){
        t[id].sum=a[l];
        t[id].lazy=0;
        return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=merge(t[2*id],t[2*id+1]);
    
}

void update(ll id,ll l,ll r,ll lq,ll rq,ll val){
    push(id,l,r);
    if (lq>r || rq<l){
        return;
    }
    if (lq<=l && r<=rq){
        t[id].lazy+=val;
        push(id,l,r);
        return;
    }

    ll mid=(l+r)/2;
    update(2*id,l,mid,lq,rq,val);
    update(2*id+1,mid+1,r,lq,rq,val);
    t[id]=merge(t[2*id],t[2*id+1]);

}
node query(ll id,ll l,ll r,ll lq,ll rq){
    push(id,l,r);
    if (lq>r || rq<l){
        return node();
    }
    if (lq<=l && r<=rq){
        return t[id];

    }
    ll mid=(l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));

}