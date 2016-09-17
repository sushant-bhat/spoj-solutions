#include <stdio.h>
#include <stdlib.h>

int t,n,tc;
char s[2001];
int lcount[2001];

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		tc=0;
		for(n=0;s[n];++n);
		int i=0,li=0;
		while(i<n){
			if(s[i]=='K') tc++;
			else if(s[i]=='E'){
				lcount[li]=tc;
				li++;
			}
			i++;
		}
		int ans=0;
		for(i=0;i<li;++i)
			ans += lcount[i]*(tc-lcount[i]);
		printf("%d\n",ans);
	}
	return 0;
}
