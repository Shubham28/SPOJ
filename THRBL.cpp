#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int N,fr,to;
int ar[50001];

int M[50001][17];

inline int LG(int num)
{
	int ret=1,ans=1;
	while((ret<<1)<=num)
		ret<<=1,ans++;
	return (ans-1);
}

void sparTab()
{
	FOR(in,0,N)		M[in][0]=in;

	for(int pwr=1;(1<<pwr)<=N;pwr++)
		for(int ps=0;ps+(1<<pwr)-1<N;ps++){
			if(ar[ M[ps][pwr-1] ] >= ar[ M[ps+(1<<(pwr-1))][pwr-1] ])
				M[ps][pwr]=M[ps][pwr-1];
			else
				M[ps][pwr]=M[ps+(1<<(pwr-1))][pwr-1];
		}

	return;
}

int main()
{
	int Q;
	Input(N),Input(Q);

	FOR(a,0,N)
		Input(ar[a]);

	sparTab();

	int cnt=0;
	FOR(qr,0,Q){
		Input(fr),Input(to);
		fr--,to--;
		if(fr==to || fr+1==to || fr==to+1){
			++cnt;
			continue;
		}

		int lim=ar[fr];
		if(fr>to){
			swap(fr,to);
			fr++;
		} else
			to--;

		int ind=LG(to-fr+1);
		int mx;

		if(ar[ M[fr][ind] ] >= ar[ M[to-(1<<ind)+1][ind] ])
			mx=ar[ M[fr][ind] ];
		else
			mx=ar[ M[to-(1<<ind)+1][ind] ];

		if(mx<=lim)
			++cnt;
	}
	printf("%d\n",cnt);

	return 0;
}
