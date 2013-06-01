#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );
#define VI vector<int>

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar_unlocked();

	if(ch=='-')
		sign=-1,ch=getchar_unlocked();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar_unlocked())>='0' && ch<='9');

	N*=sign;
	return;
}

void comb(int htmp,int wtmp,int dtmp,VI &dimen)
{
	PB(dimen,htmp);
	PB(dimen,wtmp);
	PB(dimen,dtmp);
}

int main()
{
	int N;
	Input(N);

	while(N!=0){

		VI ht,wd,dp;
		FOR(i,0,N){
			VI dimen(3);
			Input(dimen[0]),Input(dimen[1]),Input(dimen[2]);
			SORT(dimen);

			comb(dimen[0],dimen[1],dimen[2],ht);
			comb(dimen[1],dimen[0],dimen[0],wd);
			comb(dimen[2],dimen[2],dimen[1],dp);
		}

		FOR(i,0,3*N)
			FOR(j,i+1,3*N){
				if(wd[j]*dp[j]>=wd[i]*dp[i]){
					int htmp=ht[i],wtmp=wd[i],dtmp=dp[i];
					ht[i]=ht[j],ht[j]=htmp,wd[i]=wd[j],wd[j]=wtmp,dp[i]=dp[j],dp[j]=dtmp;
				}
			}

		VI S(3*N,0);
		int highest=0;

		FOR(i,0,3*N){
			S[i]=ht[i];
			FOR(j,0,i){
				if(wd[i]<wd[j] && dp[i]<dp[j] && S[i]<S[j]+ht[i])
					S[i]=S[j]+ht[i];
			}
			highest=max(highest,S[i]);
		}

		printf("%d\n",highest);
		Input(N);
	}

	return 0;
}
