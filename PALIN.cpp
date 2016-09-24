#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string s;

string special(int n){
	int carry=1,i=(n-1)/2,j=n/2;
	s[i]=s[j]='0';
	i--;
	j++;
	while(i>=0){
		if(carry){
			if(s[i]=='9') s[i]='0';
			else{
				s[i]++;
				carry=0;
			}
		}
		s[j]=s[i];
		i--;
		j++;
	}
	if(carry){
		s[n-1]='1';
		return "1"+s;
	}
	return s;
}

string palin(){
	int n=s.size(),i=(n-1)/2,j=n/2;
	if(s[i]==s[j]){
		while(i>=0&&s[i]==s[j]){
			i--;
			j++;
		}
		if(i<0||s[i]<s[j]){
			i=(n-1)/2;j=n/2;
			if(s[i]=='9') return special(n);
			s[i]++;
			while(i>=0){
				s[j]=s[i];
				i--;
				j++;
			}
		}
		else{
			while(i>=0){
				s[j]=s[i];
				i--;
				j++;
			}
		}
	}
	else{
		if(s[i]<s[j]){
			if(s[i]=='9') return special(n);
			s[i]++;
		}
		while(i>=0){
			s[j]=s[i];
			i--;
			j++;
		}
	}
	return s;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		cout<<palin()<<endl;
	}
	return 0;
}
