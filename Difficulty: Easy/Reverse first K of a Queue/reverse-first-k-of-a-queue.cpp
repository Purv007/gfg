class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if(k<=0 || k>q.size()) return q;
        // code here
        stack<int>s;
        
        for(int i=0;i<k;i++){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            int a=s.top();
            s.pop();
            q.push(a);
        }
        
        for(int i=0;i<q.size()-k;i++){
            int a=q.front();
            q.pop();
            q.push(a);
        }
        return q;
    }
};