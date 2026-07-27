class Solution {
  public:
    int n;
    vector<vector<int>>vis;
    void func(vector<vector<int>>& maze,vector<string>& res,int x,int y,string& curr){
        if(x==n-1 && y==n-1){
            res.push_back(curr);
            return;
        }
        
        vis[x][y]=1;
        
        if(x+1<n && maze[x+1][y] && !vis[x+1][y]){
            curr.push_back('D');
            func(maze,res,x+1,y,curr);
            curr.pop_back();
        } 
        if(y-1>=0 && maze[x][y-1] && !vis[x][y-1]){
            curr.push_back('L');
            func(maze,res,x,y-1,curr);
            curr.pop_back();
        } 
        if(y+1<n && maze[x][y+1] && !vis[x][y+1]){
            curr.push_back('R');
            func(maze,res,x,y+1,curr);
            curr.pop_back();
        } 
        
        if(x-1>=0 && maze[x-1][y] && !vis[x-1][y]){
            curr.push_back('U');
            func(maze,res,x-1,y,curr);
            curr.pop_back();
        } 
        
        vis[x][y]=0;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze){
        // code here
        vector<string>res;
        n=maze.size();
        vis.assign(n, vector<int>(n, 0));
        
        if (n == 0) return res;
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) return res;
        
        string curr;
        func(maze,res,0,0,curr);
        return res;
        
    }
};