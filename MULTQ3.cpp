#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
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
	while((ch=getchar())>='0'&&ch<='9');

	N*=sign;
	return;
}

int N,Q;
int fr,to;
int P[(1<<18)+5][3];
short mrk[(1<<18)+5];

inline void init(int ind,int st,int end)
{
	int nxt=ind<<1,mid=(st+end)>>1;
	if(st==end){
		P[ind][0]=1;
		P[ind][1]=P[ind][2]=mrk[ind]=0;
	} else {
		init(nxt,st,mid);
		init(nxt+1,mid+1,end);

		P[ind][0]=P[nxt][0]+P[nxt+1][0];
		P[ind][1]=P[ind][2]=mrk[ind]=0;
	}
	return;
}

inline void incr(int val[3])
{
	int tmp=val[2];
	val[2]=val[1],val[1]=val[0],val[0]=tmp;
	return;
}

inline void mrkChk(int ind,int st,int end)
{
	int nxt=ind<<1;
	if(mrk[ind]!=0){
		incr(P[ind]);
		if(mrk[ind]==2)
			incr(P[ind]);

		if(st!=end){
			mrk[nxt]=(mrk[ind]==1)?(mrk[nxt]+1)%3:(mrk[nxt]+2)%3;
			mrk[nxt+1]=(mrk[ind]==1)?(mrk[nxt+1]+1)%3:(mrk[nxt+1]+2)%3;
		}
		mrk[ind]=0;
	}
	return;
}

void update(int ind,int st,int end)
{
	int nxt=ind<<1;
	mrkChk(ind,st,end);

	if(fr>end || to<st)		return;

	if(fr<=st && end<=to){
		incr(P[ind]);
		if(st!=end){
			mrk[nxt]=(mrk[nxt]+1)%3;
			mrk[nxt+1]=(mrk[nxt+1]+1)%3;
		}
		return;
	}

	int mid=(st+end)>>1;
	update(nxt,st,mid);
	update(nxt+1,mid+1,end);

	P[ind][0]=P[nxt][0]+P[nxt+1][0];
	P[ind][1]=P[nxt][1]+P[nxt+1][1];
	P[ind][2]=P[nxt][2]+P[nxt+1][2];

	return;
}

int query(int ind,int st,int end)
{
	int nxt=ind<<1;
	mrkChk(ind,st,end);

	if(fr>end || to<st)		return -1;
	if(st>=fr && end<=to)	return P[ind][0];

	int mid=(st+end)>>1;
	int p1=query(nxt,st,mid);
	int p2=query(nxt+1,mid+1,end);

	if(p1==-1)		return p2;
	if(p2==-1)		return p1;

	return p1+p2;
}

int main()
{
	Input(N),Input(Q);
	init(1,0,N-1);

	int ch;
	FOR(in,0,Q){
		Input(ch),Input(fr),Input(to);

		if(ch==0)
			update(1,0,N-1);
		else
			printf("%d\n",query(1,0,N-1));
	}

	return 0;
}
