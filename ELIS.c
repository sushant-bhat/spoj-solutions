#include <stdio.h>
#include <stdlib.h>
 
int v[10];
int table[11][11];
 
int max(int a,int b){
	return (a>=b)?a:b;
}
 
int recur(int prev,int i,int n){
	if(i>=n) return 0;
	if(table[prev][i]>0) return table[prev][i];
	if(v[i]<=prev) return table[prev][i]= recur(prev,i+1,n);
	return table[prev][i]= max(recur(prev,i+1,n),1+recur(v[i],i+1,n));
}
 
int main() {
	int n;
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;++i)
		scanf("%d",&v[i]);
	printf("%d\n",recur(0,0,n));
	return 0;
}
