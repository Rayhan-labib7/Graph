const int N = 1e5+10;
vector<int>g[N];
int par[N];
void dfs(int v,int p=-1)
{
	par[v]=p;
	for(int child:g[v]){
		if(child==p) continue;
        dfs(child,v);
	}

}
vector<int>path(int v)
{
	vector<int>ans;
	while (v!=-1)
	{
		ans.push_back(v);
		v=par[v];
	}
	reverse(ans.begin(),ans.end());
	return ans;
	
}
