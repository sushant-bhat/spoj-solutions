#include <stdio.h>
#include <stdlib.h>
 
long long int perform(long long a,long long b,char op){
	switch(op){
	case '+':
		return a+b;
		break;
	case '-':
		return a-b;
		break;
	case '/':
		return a/b;
		break;
	case '*':
		return a*b;
	}
	return 0;
}
 
int main() {
	int t;
	long long int n1,n2;
	char op='+';
	scanf("%d",&t);
	while(t--){
		n1=0;n2=0;
		op='+';
		while(1){
			scanf("%lld",&n1);
			n2=perform(n2,n1,op);
			//printf("%lld\n",n2);
			op=' ';
			while(op==' ')
				scanf("%c",&op);
			if(op=='=') break;
		}
		printf("%lld\n",n2);
	}
	return 0;
}