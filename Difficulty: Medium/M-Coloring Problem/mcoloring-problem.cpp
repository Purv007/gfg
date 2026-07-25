class Solution {
  public:
    bool check(int curr,vector<vector<int>>&adj,vector<int>&color,int node){
        for(auto i:adj[node]){
            if(color[i]==curr) return false;
        }
        return true;
    }
  
  bool solve(int v,int m,vector<vector<int>>&adj,vector<int>&color,int node){
      if(node==v){
          return true;
      }
      
      for(int i=1;i<=m;i++){
          if(check(i,adj,color,node)){
              color[node]=i;
              if(solve(v,m,adj,color,node+1)) return true;
              color[node]=0;
          }
      }
      return false;
  }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adj(v);
        vector<int>color(v,0);
        
        for(auto &i:edges){
            int a=i[0];
            int b=i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        return solve(v,m,adj,color,0);
    }
};