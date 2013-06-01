#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())

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

int ar[50005];
int N,Q;
int flp,val,fr,to;
int S[(1<<17)+1],P[(1<<17)+1];
int lf[(1<<17)+1],rt[(1<<17)+1];

inline int MX(int a,int b)
{	return (a>b)?a:b;	}

void init(int in,int st,int end)
{
	if(st==end){
		S[in]=P[in]=ar[st];
		lf[in]=rt[in]=ar[st];
		return;
	} else {
		int mid=(st+end)>>1,nx=in<<1;

		init(nx,st,mid);
		init(nx+1,mid+1,end);

		S[in]=S[nx]+S[nx+1];
		lf[in]=MX(lf[nx],S[nx]+lf[nx+1]);
		rt[in]=MX(rt[nx+1],S[nx+1]+rt[nx]);

		P[in]=MX(P[nx],P[nx+1]);
		P[in]=MX(P[in],S[in]);
		P[in]=MX(P[in],lf[in]);
		P[in]=MX(P[in],rt[in]);
		P[in]=MX(P[in],rt[nx]+lf[nx+1]);
	}
	return;
}

void update(int ind,int st,int end)
{
	int nx=ind<<1;
	if(flp>end || flp<st)		return;

	if(st==end && flp==st){
		S[ind]=P[ind]=val;
		lf[ind]=rt[ind]=val;
		return;
	}

	int mid=(st+end)>>1;
	update(nx,st,mid);
	update(nx+1,mid+1,end);

	S[ind]=S[nx]+S[nx+1];
	lf[ind]=MX(lf[nx],S[nx]+lf[nx+1]);
	rt[ind]=MX(rt[nx+1],S[nx+1]+rt[nx]);

	P[ind]=MX(P[nx],P[nx+1]);
	P[ind]=MX(P[ind],S[ind]);
	P[ind]=MX(P[ind],lf[ind]);
	P[ind]=MX(P[ind],rt[ind]);
	P[ind]=MX(P[ind],rt[nx]+lf[nx+1]);

	return;
}

void query(int ind,int st,int end,int ret[4])
{
	int nxt=ind<<1;
	if(fr>end || to<st){
		ret[0]=-1;
		return;
	}

	if(fr<=st && end<=to){
		ret[0]=S[ind],ret[1]=P[ind];
		ret[2]=lf[ind],ret[3]=rt[ind];
		return;
	}

	int mid=(st+end)>>1;
	int tlf[4],trg[4];

	query(nxt,st,mid,tlf);
	query(nxt+1,mid+1,end,trg);

	if(tlf[0]==-1){
		memcpy(ret,trg,sizeof(trg));
		return;
	}
	if(trg[0]==-1){
		memcpy(ret,tlf,sizeof(tlf));
		return;
	}

	ret[0]=tlf[0]+trg[0];
	ret[2]=MX(tlf[2],tlf[0]+trg[2]);
	ret[3]=MX(trg[3],tlf[3]+trg[0]);

	ret[1]=MX(tlf[1],trg[1]);
	ret[1]=MX(ret[1],ret[0]);
	ret[1]=MX(ret[1],ret[2]);
	ret[1]=MX(ret[1],ret[3]);
	ret[1]=MX(ret[1],tlf[3]+trg[2]);

	return;
}

int main()
{
	Input(N);
	FOR(ip,0,N)
		Input(ar[ip]);
	init(1,0,N-1);

	int ch,tmp[4];
	Input(Q);
	FOR(ip,0,Q){
		Input(ch);
		if(ch==0){
			Input(flp),Input(val);
			flp--;
			update(1,0,N-1);
		} else {
			Input(fr),Input(to);
			fr--,to--;
			query(1,0,N-1,tmp);
			printf("%d\n",tmp[1]);
		}
	}

	fclose(stdin);
	return 0;
}
