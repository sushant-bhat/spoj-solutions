#include <stdio.h>
#include <stdlib.h>

int t;
unsigned long long int n,sum;

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%llu",&n);
		sum=30*(n);
		if(sum%11==0) printf("0\n");
		else printf("%llu\n",((sum/11+1)*11) - sum);
	}
	return 0;
}
