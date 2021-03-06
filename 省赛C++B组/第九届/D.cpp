/*高楼扔鸡蛋
m个鸡蛋，n层楼
ts[i][j]表示有i个鸡蛋和j层楼的时候所需最小测试次数
这个可以用dp完成
考虑有i个鸡蛋和j层楼
1.如果i==1，则ts[i][j]=j。
因为想要保证能够测出坚硬程度，如果从中间开始测试，如果鸡蛋碎了
就得不到结果（1和中间测试的层数之间的任意一个值），所以只能一层一层
往上测试。
2.如果有i=2个鸡蛋，如果最优为x次
第一次从第x层往下丢。如果碎了，一层一层检测第1到第x-1层。共x次。
否则从第x+(x-1)层往下丢，因为要保证如果碎了，能在第x+1层到x+x-1层共x-2
次检测出来，那样加上之前丢的两次共x次。
所以最多x + x-1 + x-2 +...+ 1=(x+1)*x/2层
所以(x+1)*x>j，可求出最小的x
3.如果i=3,最优为x次
如果碎了，i=2，x-1次，为 x-1 + x-2 + ...+ 1=(x-1)*x/2层
如果没碎，则 x-2 + x-3 +... + 1 = (x-2)(x-1)/2
最后(x-1)*x/2 + (x-2)*(x-1)/2 + ...+ 1*2/2 >j ,可求得最小的x。
4.i>3的情况以此类推。
5.考虑dp的思想。ts[i][j],对每一个k(1<=k<j, 不考虑k=j, 因为没有助益)
如果在k层碎了，则ts[i][j] = ts[i-1][k-1]+1，代表只需要在1到k-1之间测试，
而因为测试了一次，所以+1，如果没碎，则代表需要在k+1到j之间共j-k层测试。
而测试的次数相当于1到j-k层测试的次数，所以ts[i][j] = ts[i][j-k]。
由于考虑最坏情况，所以ts[i][j] = max(ts[i][j-k], ts[i-1][k-1])+1
由于需要测试最好的k所以ts[i][j] = min_k(1+max(ts[i][j-k], ts[i-1][k-1]))  

*/

#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

const int M=4;
const int N=1001;
int ts[M][N];

void solve() {
	int i, j;
	for(int i=1; i<=3; i++){
		for(int j=1; j<=1000; j++){
			ts[i][j] = j;
		}
	}
	for(int i=2; i<=3; i++){
		for(int j=2; j<=1000; j++){
			for(int k=1; k<j; k++){
				ts[i][j] = min(ts[i][j], 1+max(ts[i-1][k-1], ts[i][j-k]));
			}
		}
	} 
	printf("%d\n", ts[3][1000]);
}

int main() {
	solve();
	return 0;
}
