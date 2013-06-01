#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
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

int main()
{
	int T;
	Input(T);

	int opt[2][50][100];
	int inf[1001][3];

	while(T--){
		int nit,oxy;
		Input(oxy),Input(nit);

		int N,n2,o2,wt;

		Input(N);
		FOR(all,0,N){
			Input(o2),Input(n2),Input(wt);
			inf[all][0]=o2,inf[all][1]=n2,inf[all][2]=wt;
		}

		int ans=10000000;

		MEM(opt[0],-1);
		EFOR(flo,0,inf[0][0])	EFOR(fln,0,inf[0][1])	opt[0][flo][fln]=inf[0][2];

		FOR(all,1,N){
			FOR(flo,0,50)		FOR(fln,0,100){
				int &now=opt[all&1][flo][fln];
				now=-1;

				if(flo<=inf[all][0] && fln<=inf[all][1])	now=inf[all][2];

				int his=opt[!(all&1)][flo][fln];
				if(now==-1 && his!=-1)		now=his;
				else if(now!=-1 && his!=-1)		now=min(now,his);

				int prev=-1;
				if(flo>=inf[all][0] && fln>=inf[all][1])
					prev=opt[!(all&1)][flo-inf[all][0]][fln-inf[all][1]];

				if(prev!=-1 && now==-1)		now=prev+inf[all][2];
				else if(prev!=-1 && now!=-1)		now=min(now,prev+inf[all][2]);

			}
		}

		FOR(cko,oxy,50)		FOR(ckn,nit,100){
			int tmp=opt[(N-1)&1][cko][ckn];
			if(tmp!=-1 && tmp<ans)		ans=tmp;
		}
		printf("%d\n",ans);
	}

	return 0;
}
