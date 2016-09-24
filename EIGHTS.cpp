#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	long long n;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		long long start=n/4;
		if(n%4==0) start--;
		short fact=n%4,end=0;
		switch(fact){
		case 0:
			end=942;
			break;
		case 1:
			end=192;
			break;
		case 2:
			end=442;
			break;
		case 3:
			end=692;
			break;
		}
		if(start>0)
			cout<<start<<end<<endl;
		else cout<<end<<endl;
	}
	return 0;
}
