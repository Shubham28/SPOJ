#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
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

inline void MINM(int &fir, int sec)
{
	fir=(fir<sec)?fir:sec;
	return;
}

int main()
{

	int T,R,C;
	int cb[105][105],fl[2][105][105];

	int mr[]={-1,0,0,1};
	int mc[]={0,-1,1,0};

	Input(T);
	while(T--){
		Input(R),Input(C);

		EFOR(cl,0,C+1)	cb[0][cl]=0;
		EFOR(cl,0,C+1)	fl[0][0][cl]=0;

		EFOR(rw,1,R){
			cb[rw][0]=fl[0][rw][0]=cb[rw][C+1]=fl[0][rw][C+1]=0;

			EFOR(cl,1,C){
				Input(cb[rw][cl]);
				fl[0][rw][cl]=10000;
			}
		}
		EFOR(cl,0,C+1)	cb[R+1][cl]=fl[0][R+1][cl]=0;

		EFOR(cl,1,C)	fl[0][1][cl]=fl[0][R][cl]=0;
		EFOR(rw,1,R)	fl[0][rw][1]=fl[0][rw][C]=0;

		int chn=0;
		bool sm=0;
		while(!sm){

			EFOR(rw,0,R+1)	EFOR(cl,0,C+1){
				fl[chn^1][rw][cl]=fl[chn][rw][cl];
				if(fl[chn^1][rw][cl]==0)
					continue;

				FOR(mv,0,4){

					int tr=rw+mr[mv],tc=cl+mc[mv];
					if(0<=tr && tr<=(R+1) && 0<=tc && (tc<=C+1)){

						int op=(mv<2)?(chn^1):chn;
						int df=cb[tr][tc]-cb[rw][cl];

						if(df==0)
							MINM(fl[chn^1][rw][cl],fl[op][tr][tc]);

						else if(df<0){
							if(fl[op][tr][tc]>=abs(df))
								MINM(fl[chn^1][rw][cl],fl[op][tr][tc]+df);
							else
								fl[chn^1][rw][cl]=0;
						}
						else
							MINM(fl[chn^1][rw][cl],df+fl[op][tr][tc]);
					}
				}
			}

			sm=1;
			EFOR(rw,0,R+1) EFOR(cl,0,C+1){
				if(fl[chn][rw][cl]!=fl[chn^1][rw][cl]){
					sm=0;
					break;
				}
			}
			chn^=1;
		}

		int ans=0;
		EFOR(ar,1,R) EFOR(ac,1,C)	ans+=fl[chn][ar][ac];

		printf("%d\n",ans);
	}

	return 0;
}
