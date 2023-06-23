class Lca{
	public:
	vector<vector<int>>up,graph;
	vector<int>depth;
	int n;
	Lca(int _n)
	{
		n=_n;
		up.resize(n+1,vector<int>(Log,-1));
		graph.resize(n+1);
		depth.resize(n+1);
	}
	void readTree(int root=1){
		int u,v;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		dfs(root,root,0);
		cal_sparse_table();
	}
	void dfs(int node,int parent,int dis)
	{
		depth[node]=dis;
		up[node][0]=parent;
		for(auto child:graph[node])
		{
		   if(child==parent)continue;
		   dfs(child,node,dis+1);
		}
	}
	void cal_sparse_table(){
        for(int i=1;i<Log;i++)
		{
			for(int j=1;j<=n;j++)
			if(up[j][i-1]!=-1)
			{
				up[j][i]=up[up[j][i-1]][i-1];
			}
		}
	}
	int lca_query(int u,int v){
		if(depth[u]<depth[v])swap(u,v);
		ll diff= depth[u]-depth[v];
		for(int i=0;i<Log;i++)
		{
			if((diff>>i)&1){
				u=up[u][i];
			}
		}
		if(u==v) return u;
		for(int i=Log-1;i>=0;i--)
		{
			if(up[u][i]!=up[v][i]){
				u=up[u][i];
				v=up[v][i];
			}
		}
		return up[u][0];
	}
	int k_thParent(int node,int k){
		for(int i=0;i<Log;i++){
			if((k>>i)&1){
				node=up[node][i];
			}
		}
		return node;
	}
	int cal_distance(int a,int b,int lca_point)
	{
		return depth[a]+depth[b]-depth[lca_point]*2;
	}
	
};
