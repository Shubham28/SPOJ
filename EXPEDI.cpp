#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <queue>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define SZ(A) int(A.size())
#define INF 1000000000
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int T,N,L,P;
vector< VI >stp(10001,VI(2));

int main()
{
	Input(T);
	while(T--){
		Input(N);

		int tot=0;
		FOR(pt,0,N){
			Input(stp[pt][0]),Input(stp[pt][1]);
			tot+=stp[pt][1];
		}
		Input(L),Input(P);

		if(tot+P<L){
			printf("-1\n");
			continue;
		}
		sort(stp.begin(),stp.begin()+N,greater< VI >());

		int cur=L,cnt=0;
		bool posb=1;
		priority_queue<int>plcs;

		int trv=0;
		cur-=P;
		while(cur>0){

			while(trv<N && stp[trv][0]>=cur){
				plcs.push(stp[trv][1]);
				trv++;
			}

			if(SZ(plcs)==0){
				posb=0;
				break;
			} else {
				int nxt=plcs.top();
				plcs.pop();
				cur-=nxt,cnt++;
			}
		}
		printf("%d\n",((posb)?cnt:-1));
	}

	return 0;
}
