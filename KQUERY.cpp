#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

char DIP[11];

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

inline void Outp(int x)
{
	int y;
	int dig=0;
	while(x || !dig){
		y=x/10;
		DIP[dig++]=x-((y<<3)+(y<<1))+'0';
		x=y;
	}
	while(dig--)	printf("%c",DIP[dig]);
}

struct qr
{
	int vl[4];
	bool tp;
};

qr dt[230002];
int idx,fr,to;
int P[(1<<16)+2];

bool cmpr(qr fr,qr sc)
{
	if(fr.vl[0]>sc.vl[0])	return 1;
	if(fr.vl[0]<sc.vl[0])	return 0;
	return (!fr.tp);
}

void update(int ind,int st,int end)
{
	int nxt=ind<<1;
	if(st==end && st==idx){
		P[ind]=1;
		return;
	}

	int mid=(st+end)>>1;
	if(idx<=mid)	update(nxt,st,mid);
	else			update(nxt+1,mid+1,end);

	P[ind]=P[nxt]+P[nxt+1];

	return;
}

int query(int ind,int st,int end)
{
	if(P[ind]==0)	return 0;
	if(st>=fr && end<=to)		return P[ind];

	int nxt=ind<<1,mid=(st+end)>>1;

	int p1=(fr>mid || to<st)?0:query(nxt,st,mid);
	int p2=(fr>end || to<mid+1)?0:query(nxt+1,mid+1,end);

	return p1+p2;
}

int main()
{
	int N;
	Input(N);

	FOR(ip,0,N){
		Input(dt[ip].vl[0]);
		dt[ip].vl[1]=ip;
		dt[ip].tp=1;
	}

	int L=N,Q;
	Input(Q);
	FOR(ip,0,Q){
		Input(dt[L].vl[1]);		Input(dt[L].vl[2]);
		Input(dt[L].vl[0]);
		dt[L].vl[1]--,dt[L].vl[2]--;
		dt[L].vl[3]=ip;
		dt[L++].tp=0;
	}
	sort(dt,dt+L,cmpr);

	int ans[200002];
	FOR(pc,0,L){
		if(dt[pc].tp){
			idx=dt[pc].vl[1];
			update(1,0,N-1);
		} else {
			fr=dt[pc].vl[1],to=dt[pc].vl[2];
			ans[dt[pc].vl[3]]=query(1,0,N-1);
		}
	}

	FOR(pr,0,Q){
		Outp(ans[pr]);
		printf("\n");
	}

	return 0;
}
