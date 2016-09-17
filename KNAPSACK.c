#include <stdio.h>
#include <stdlib.h>
 
int w[2000],p[2000];
int table[2000][2001];
 
int max(int a,int b){
	return (a>=b)?a:b;
}
 
int recur(int i,int s,int n){
	if(i>=n) return 0;
	if(table[i][s]>0) return table[i][s];
	if(w[i]>s) return table[i][s]= recur(i+1,s,n);
	return table[i][s]= max(recur(i+1,s,n),p[i]+recur(i+1,s-w[i],n));
}
 
int main() {
	int s,n;
	scanf("%d%d",&s,&n);
	int i=0;
	for(i=0;i<n;++i)
		scanf("%d%d",&w[i],&p[i]);
	printf("%d\n",recur(0,s,n));
	return 0;
}