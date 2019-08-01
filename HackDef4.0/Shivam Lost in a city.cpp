#include<bits/stdc++.h>
using namespace std;
void BFS(vector<int> g[],int *a,int n,int m,int s)
{   bool vis[n];
    fill(vis,vis+n,0);
    int d[n];
    memset(d,63,sizeof(d));
    d[s] =a[s];
    queue<int> q({s});
    while(q.size())
    {
        int v= q.front();
        q.pop();
        vis[v] =0;
        for(int& u:g[v])
        {
            if(d[u]>max(a[u],d[v]))
            {
                d[u] = max(a[u],d[v]);
                if(!vis[u])
                {
                    vis[u]=1;
                    q.push(u);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<d[i]<<" ";
    }
 
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,m,s; cin>>n>>m>>s;
        int a[n];
        s--;
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int> g[n];
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            x--,y--;
            g[x].push_back(y);
        }
        BFS(g,a,n,m,s);
        cout<<endl;
    }
}