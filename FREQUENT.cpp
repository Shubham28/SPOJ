#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
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

inline int LG(int num)
{
	int ret=1,ans=1;
	while((ret<<1)<=num)
		ret<<=1,ans++;
	return (ans-1);
}

inline int MX(int fir,int sec)
{	return (fir>=sec)?fir:sec;	}

int main()
{
	int N,Q;
	int ar[100005],frq[100005];
	int lft[100005],rgt[100005];
	int M[100005][18];

	Input(N);
	while(N!=0){
		Input(Q);

		int in=0;
		Input(ar[in++]);
		frq[0]=1,lft[0]=0;

		for(;in<N;in++){
			Input(ar[in]);
			if(ar[in]==ar[in-1])
				frq[in]=frq[in-1]+1,lft[in]=lft[in-1];
			else
				frq[in]=1,lft[in]=in;
		}

		rgt[N-1]=N-1;
		RFOR(in,N-2,0){
			if(ar[in]==ar[in+1])
				frq[in]=frq[in+1],rgt[in]=rgt[in+1];
			else
				rgt[in]=in;
		}

		FOR(in,0,N)		M[in][0]=in;

		for(int pw=1;(1<<pw)<=N;pw++)
			for(int ps=0;ps+(1<<pw)-1<N;ps++){
				if(frq[M[ps][pw-1]]>=frq[M[ps+(1<<(pw-1))][pw-1]])
					M[ps][pw]=M[ps][pw-1];
				else
					M[ps][pw]=M[ps+(1<<(pw-1))][pw-1];
			}

		int fr,to;
		FOR(inp,0,Q){
			Input(fr),Input(to);
			fr--,to--;

			int bnl=rgt[fr]+1,bnr=lft[to]-1;

			int mid=0;
			if(bnl<=bnr){
				int ind=LG(bnr-bnl+1);
				mid=MX(frq[M[bnl][ind]],frq[M[bnr-(1<<ind)+1][ind]]);
			}

			int ans=(bnl<=to)?(bnl-fr):(to-fr+1);
			ans=MX(ans,(bnr>=fr)?(to-bnr):(to-fr+1));
			ans=MX(ans,mid);

			printf("%d\n",ans);
		}

		Input(N);
	}

	return 0;
}
