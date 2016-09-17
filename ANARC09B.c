#include <stdio.h>
#include <stdlib.h>
 
unsigned long long int findGcd(unsigned long long int a,unsigned long long int b){
	unsigned long long int temp;
	if(a<b){
		temp=a;
		a=b;
		b=temp;
	}
	while(b>0){
		temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}
 
int main() {
	unsigned long long int w,h;
	scanf("%llu%llu",&w,&h);
	while(w!=0&&h!=0){
		int fact=2;
		unsigned long long int start,n1=(w<=h)?h:w,n2=(w+h)-n1;
		start=n1;
		while(start%n2!=0){
			start=n1*fact;
			fact++;
		}
		printf("%llu\n",start/findGcd(w,h));
		scanf("%llu%llu",&w,&h);
	}
	return 0;
}