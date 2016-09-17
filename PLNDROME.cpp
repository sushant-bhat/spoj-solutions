#include <iostream>
#include <cstdio>

using namespace std;

char s[100000];
int n,t,q,diff,total;

int main(){
	scanf("%d",&t);
	total=t;
	while(t--){
		diff=0;
		scanf("%d%s%d",&n,s,&q);
		int i=0,j=n-1;
		while(i<j){
			if(s[i]!=s[j]) diff++;
			i++;
			j--;
		}
		cout<<"Case "<<(total-t)<<":"<<endl;
		while(q--){
			int index;
			char c;
			scanf("%d %c",&index,&c);
			char prev=s[index-1];
			s[index-1]=c;
			if(index-1!=n-index && prev!=s[index-1]){
				if(s[index-1]==s[n-index]) diff--;
				else{
					if(prev==s[n-index])
						diff++;
				}
			}
			if(diff==0) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
