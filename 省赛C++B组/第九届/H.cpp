#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

const int MAX_N=1005;
char map[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];
int N;
int ans;
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, 1, 0, -1};

void dfs(int i, int j){
	int i, j, k;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(map[i][j]=='#'&& !visit[i][j]){
				for(k=0; k<4; k++){
					int nx = i+X[k], ny = j+Y[k];
					if(nx>=0&&nx<N&&ny>=0&&ny<N&&map[nx][ny]='.') {
						map[i][j] = '.';
					}
				}	
			}
		}
	}
}

void solve() {
	scanf("%d", &N);
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			scanf(" %c", &map[i][j]);
		}
	}
	dfs();
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(map[i][j] == '#') ans++;
		}
	}
	printf("%d\n", ans);
}

int main() {
	solve();
	return 0;
}
