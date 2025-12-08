const int MAXN = 1e5+10;
int n;
vector<vector<int>> adj;

int id = 0, sccCount = 0;
int ids[MAXN], low[MAXN], onStack[MAXN];
stack<int> st;

void dfs(int at){
    st.push(at);
    onStack[at] = 1;
    ids[at] = low[at] = id++;

    for (auto to : adj[at]){
        if (ids[to] == -1)
            dfs(to);
        if (onStack[to])
            low[at] = min(low[at], low[to]);
    }

    if (ids[at] == low[at]){
        while (!st.empty()){
            int node = st.top();
            st.pop();
            onStack[node] = 0;
            low[node] = ids[at];
            if (node == at)
                break;
        }
        sccCount++;
    }
}

void fixIndex(){
    map<int, int> old_new;
    int newi = 0;
    for (int i = 0; i < n; i++){
        if (old_new.find(low[i]) == old_new.end()){
            old_new[low[i]] = newi++;
        }
    }
    for (int i = 0; i < n; i++){
        low[i] = old_new[low[i]];
    }
}

void tarjan(){
    memset(ids, -1, sizeof(ids));
    for (int i = 0; i < n; i++){
        if (ids[i] == -1)
            dfs(i);
    }
    fixIndex();
}
