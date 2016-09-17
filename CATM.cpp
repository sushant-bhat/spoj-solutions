#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct node{
	int x;
	int y;
};

int cats[101][101],mouse[101][101];
int m,n,t;
node mpos,cpos1,cpos2;

void mbfs(){
	queue<node> q;
	mouse[mpos.x][mpos.y]=0;
	q.push(mpos);
	while(!q.empty()){
		node i=q.front();
		q.pop();
		if(i.x>1&&mouse[i.x-1][i.y]>mouse[i.x][i.y]+1){
			mouse[i.x-1][i.y]=mouse[i.x][i.y]+1;
			q.push((node){i.x-1,i.y});
		}
		if(i.x<m&&mouse[i.x+1][i.y]>mouse[i.x][i.y]+1){
			mouse[i.x+1][i.y]=mouse[i.x][i.y]+1;
			q.push((node){i.x+1,i.y});
		}
		if(i.y>1&&mouse[i.x][i.y-1]>mouse[i.x][i.y]+1){
			mouse[i.x][i.y-1]=mouse[i.x][i.y]+1;
			q.push((node){i.x,i.y-1});
		}
		if(i.y<n&&mouse[i.x][i.y+1]>mouse[i.x][i.y]+1){
			mouse[i.x][i.y+1]=mouse[i.x][i.y]+1;
			q.push((node){i.x,i.y+1});
		}
	}
	return;
}

void catbfs(){
	queue<node> q;
	cats[cpos1.x][cpos1.y]=0;
	cats[cpos2.x][cpos2.y]=0;
	q.push(cpos1);
	q.push(cpos2);
	while(!q.empty()){
		node i=q.front();
		q.pop();
		if(i.x>1&&cats[i.x-1][i.y]>cats[i.x][i.y]+1){
			cats[i.x-1][i.y]=cats[i.x][i.y]+1;
			q.push((node){i.x-1,i.y});
		}
		if(i.x<m&&cats[i.x+1][i.y]>cats[i.x][i.y]+1){
			cats[i.x+1][i.y]=cats[i.x][i.y]+1;
			q.push((node){i.x+1,i.y});
		}
		if(i.y>1&&cats[i.x][i.y-1]>cats[i.x][i.y]+1){
			cats[i.x][i.y-1]=cats[i.x][i.y]+1;
			q.push((node){i.x,i.y-1});
		}
		if(i.y<n&&cats[i.x][i.y+1]>cats[i.x][i.y]+1){
			cats[i.x][i.y+1]=cats[i.x][i.y]+1;
			q.push((node){i.x,i.y+1});
		}
	}
	return;
}

int main(){
	cin>>m>>n;
	for(int i=0;i<=m;++i)
		for(int j=0;j<=n;++j){
			cats[i][j]=100000;
			mouse[i][j]=100000;
		}
	cin>>t;
	while(t--){
		for(int i=0;i<=m;++i)
			for(int j=0;j<=n;++j){
				cats[i][j]=100000;
				mouse[i][j]=100000;
			}
		cin>>mpos.x>>mpos.y>>cpos1.x>>cpos1.y>>cpos2.x>>cpos2.y;
		catbfs();
		mbfs();
		int i;
		for(i=1;i<=m;++i){
			if(mouse[i][1]<cats[i][1]||mouse[i][m]<cats[i][m]) break;
		}
		if(i<=m) cout<<"YES"<<endl;
		else{
			for(i=1;i<=n;++i){
				if(mouse[1][i]<cats[1][i]||mouse[m][i]<cats[m][i]) break;
			}
			if(i<=n) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
