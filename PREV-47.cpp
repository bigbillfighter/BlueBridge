# include <cstdio>
# include <queue>
# include <vector>
# include <algorithm>

using namespace std;

const int MAX_N=1e4+5;
typedef pair<int, int> P;
vector<P> pt;
vector<P> dt;
int N;
int sm;
bool non_atv[MAX_N];

bool cmp(P p1, P p2){
    return p1.first < p2.first;
}

void solve(){
    scanf("%d", &N);
    int ft, sd;
    int i, j;
    for(i=0; i<N; i++){
        scanf("%d %d", &ft, &sd);
        pt.push_back(P(ft, sd));
    }
    sort(pt.begin(), pt.end(), cmp);

    int lst = pt[0].second; //前面所有的右边界的最大值
    for(i=1; i<N; i++){
        if(pt[i].second<=lst) non_atv[i]=true;
        else lst=pt[i].second;
    }

    int least=0;
    int d;
    int maximum=0;
    for(i=0; i<N; i++){
        if(!non_atv[i]){
            if(pt[i].first>least){
                d = pt[i].first-least;
                if(d>sm) sm=d;
                pt[i].second = pt[i].second-d;
                pt[i].first=least;
            }
            least=pt[i].second;
        }
    }

    int most=N-1;
    for(i=N-1; i>=0; i--){
        if(pt[i].second<most){
            d = most-pt[i].second;
            pt[i].first = pt[i].first+(most-pt[i].second);
            pt[i].second = most;
        }
        most = pt[i].first;
    }


    for(i=0; i<N; i++){
        P t = make_pair(0, 0); // (left, right)
        if(i==0){
            if(pt[i].first!=0) t.first=pt[i].first;
            else t.first=0;
            dt.push_back(t);
        }else{

        }
    }
}

int main(){
    solve();
    return 0;
}



//for(i=0; i<N; i++) printf("%d %d\n", pt[i].first, pt[i].second);
