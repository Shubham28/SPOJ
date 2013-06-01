#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SORT(A) sort( A.begin(),A.end() )
#define SZ(A) int(A.size())
#define long long long

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

#define S(A) seq[A].first
#define I(A) seq[A].second

int main()
{
	int T,N;
	Input(T);
	pair<long,int>seq[1000005];

	while(T--){
		Input(N);

		long sum=0,ans=0;
		int tmp;

		seq[0]=make_pair(0,0);
		EFOR(inp,1,N){
			Input(tmp);
			sum+=tmp;
			seq[inp]=make_pair(sum,inp);
		}
		S(N+1)=999999999l;
		sort(seq,seq+N+1);

		int fir=0,lst=0;

		while(lst<=N){
			if(S(lst)-S(fir)<47)
				++lst;
			else if(S(lst)-S(fir)>47)
				++fir;
			else {
				int tmpfr=fir,tmplst=lst;

				for(;S(tmpfr+1)==S(tmpfr);++tmpfr)
					;

				++tmpfr;
				for(;S(tmplst+1)==S(tmplst);++tmplst)
					;

				++tmplst;

				while(fir<tmpfr && lst<tmplst){
					if(I(fir)>I(lst))
						++lst;
					else
						ans+=(tmplst-lst),fir+=1;
				}
				fir=tmpfr,lst=tmplst;
			}
		}
		printf("%ld\n",ans);
	}

	return 0;
}
