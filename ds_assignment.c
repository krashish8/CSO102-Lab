// Find LCA (Least Common Ancestor) of two given nodes in a tree given the child-parent relationship.

#include<stdio.h>

int main(){

	int t;scanf("%d",&t);while(t--){
	int n;scanf("%d",&n);
	int parents[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		parents[i] = 0;
	}


	for(int i=0;i<n-1;i++){

	int a,b;
	scanf("%d%d",&a,&b);parents[b]=a;}

		int visited[n+1];
		for (int ii = 0; ii < n+1; ++ii)
		{
			visited[ii] = 0;
		}

	int e,f;
	scanf("%d%d",&e,&f);
	int ans;

	while(e!=0){
		visited[e]=1;
     	e=parents[e];
		}

	while(f!=0){
		if(visited[f]==1) {ans=f;break;}
		f=parents[f];
		}
		printf("%d\n",ans);}

}
