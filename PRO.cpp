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
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0'&&ch<='9');

	N*=sign;
	return;
}

int main()
{
	int N,K,winr,losr;
	Input(N);

	multiset<int>rec;
	multiset<int>::iterator it;

	LL ans=0;
	FOR(all,0,N){
		Input(K);

		int tmp;
		FOR(inp,0,K){
			Input(tmp);
			rec.insert(tmp);
		}
		it=rec.begin();
		losr=*it;
		rec.erase(it);
		it=rec.end();
		it--;
		winr=*it;
		rec.erase(it);

		ans+=(winr-losr);
	}
	printf("%lld\n",ans);

	return 0;
}
