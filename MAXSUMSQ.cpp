#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define LL long long

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

int main()
{
	int T,N;
	int ar[100001];
	LL ans,tot;
	LL mxsum[100001],cnt[100001];

	Input(T);

	while(T--){
		Input(N);
		FOR(inp,0,N)
			Input(ar[inp]);

		mxsum[0]=ar[0],cnt[0]=1;
		ans=mxsum[0],tot=0;

		FOR(i,1,N){
			mxsum[i]=ar[i],cnt[i]=1;

			if(mxsum[i-1]>0)
				mxsum[i]+=mxsum[i-1],cnt[i]=cnt[i-1];
			else if(mxsum[i-1]==0)
				cnt[i]+=cnt[i-1];

			ans=max(ans,mxsum[i]);
		}

		FOR(fnd,0,N)
			tot+=((mxsum[fnd]==ans)?cnt[fnd]:0);

		printf("%lld %lld\n",ans,tot);
	}

	return 0;
}
