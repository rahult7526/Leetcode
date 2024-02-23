class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k) continue;
            for(auto x:adj[node]){
                int adjnode=x.first;
                int edgW=x.second;
                if(edgW+cost<dist[adjnode] && stops<=k ){
                    dist[adjnode]=edgW+cost;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
        
    }
};