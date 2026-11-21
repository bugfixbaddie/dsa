class Solution {
public:
 vector<int>resultsize;
vector<vector<int>> adj;
vector<vector<int>> newadj;
 vector<int>last;
  vector<int>newparent;

  void dfs(int curr, const string& s){
    int c= s[curr]-'a';
    int near=last[c];
    last[c]=curr;
    for(int child:adj[curr]){
        dfs(child,s);
    }
    last[c]=near;
    if(curr != 0) {
    if(near != -1) {
        newparent[curr] = near;
    }
}}int dfsSize(int node) {
    int size = 1;

    for(int child : newadj[node]) {
        size += dfsSize(child);
    }
    resultsize[node] = size;
    return size;
}
 vector<int> findSubtreeSizes(vector<int>& parent, const string& s) {
       int n=parent.size();
       newparent=parent;
       //parent i=node
    //    node is parent node
    adj.assign(n, {});
    newadj.assign(n, {}); 
    for(int i=1;i<n;i++){
        int u=parent[i];
        int v=i;
        adj[u].push_back(v);
    }resultsize.assign(n,1);
    last.assign(26,-1);
    dfs(0, s);

// Build modified tree
for(int i = 1; i < n; i++) {
    newadj[newparent[i]].push_back(i);
}
     dfsSize(0);
    return resultsize; 
        
    }
};