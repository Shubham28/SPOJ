#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
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

int N,Q,fr,to,add;
LL P[(1<<18)+5],mrk[(1<<18)+5];

void update(int ind,int st,int end)
{
	int nxt=ind<<1;
	if(mrk[ind]>0){
		P[ind]+=(LL)(end-st+1)*mrk[ind];
		if(st!=end){
			mrk[nxt]+=mrk[ind];
			mrk[nxt+1]+=mrk[ind];
		}
		mrk[ind]=0;
	}
	if(fr>end || to<st)		return;

	if(fr<=st && end<=to){
		P[ind]+=(LL)(end-st+1)*(LL)add;
		if(st!=end){
			mrk[nxt]+=(LL)add;
			mrk[nxt+1]+=(LL)add;
		}
		return;
	}

	int mid=(st+end)>>1;
	update(2*ind,st,mid);
	update(2*ind+1,mid+1,end);
	P[ind]=P[nxt]+P[nxt+1];

	return;
}

LL query(int ind,int st,int end)
{
	int nxt=ind<<1;
	if(mrk[ind]>0){
		P[ind]+=(LL)(end-st+1)*mrk[ind];
		if(st!=end){
			mrk[nxt]+=mrk[ind];
			mrk[nxt+1]+=mrk[ind];
		}
		mrk[ind]=0;
	}

	if(fr>end || to<st)		return -1;
	if(st>=fr && end<=to)	return P[ind];

	int mid=(st+end)>>1;
	LL p1=query(nxt,st,mid);
	LL p2=query(nxt+1,mid+1,end);

	if(p1==-1)		return p2;
	if(p2==-1)		return p1;

	return p1+p2;
}

int main()
{
	int T,ch;
	Input(T);

	while(T--){
		Input(N),Input(Q);
		int lim=min((1<<18)+2,(N+1)<<2);

		memset(P,0,sizeof(LL)*lim);
		memset(mrk,0,sizeof(LL)*lim);

		FOR(as,0,Q){
			Input(ch),Input(fr),Input(to);
			fr--,to--;
			if(ch==0){
				Input(add);
				update(1,0,N-1);
			} else
				printf("%lld\n",query(1,0,N-1));
		}
	}

	return 0;
}
