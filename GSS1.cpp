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
#define MEM(A,B) memset(A,B,sizeof(A))

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

int N,Q,fr,to;
int ar[50001],S[50001];

int P[(1<<17)+1];
int lf[(1<<17)+1],rt[(1<<17)+1];

inline int MX(int a,int b)
{	return (a>b)?a:b;	}

void init(int in,int st,int en)
{
	if(st==en){
		P[in]=ar[st];
		lf[in]=rt[in]=st;
	} else {
		int mid=(st+en)/2,nx=2*in;

		init(nx,st,mid);
		init(nx+1,mid+1,en);

		int tmp;

		tmp=lf[nx];
		if( (S[mid+1]-S[st])+(S[lf[nx+1]+1]-S[mid+1])>(S[tmp+1]-S[st]) )
			tmp=lf[nx+1];
		lf[in]=tmp;

		tmp=rt[nx+1];
		if( (S[en+1]-S[mid+1])+(S[mid+1]-S[rt[nx]])>(S[en+1]-S[tmp]) )
			tmp=rt[nx];
		rt[in]=tmp;

		P[in]=MX(P[nx],P[nx+1]);
		P[in]=MX(P[in],S[lf[in]+1]-S[st]);
		P[in]=MX(P[in],S[en+1]-S[rt[in]]);
		P[in]=MX(P[in],S[lf[nx+1]+1]-S[rt[nx]]);
	}
	return;
}

void query(int in,int st,int en,int op[3])
{
	if(fr>en || to<st){
		op[0]=-1;
		return;
	}
	if(st>=fr && en<=to){
		op[0]=P[in],op[1]=lf[in],op[2]=rt[in];
		return;
	}
	int mid=(st+en)/2;
	int ch1[3],ch2[3];

	query(2*in,st,mid,ch1);
	query(2*in+1,mid+1,en,ch2);

	if(ch1[0]==-1){
		memcpy(op,ch2,sizeof(ch2));
		return;
	}
	if(ch2[0]==-1){
		memcpy(op,ch1,sizeof(ch1));
		return;
	}

	int bl1=MX(st,fr),br1=mid;
	int bl2=mid+1,br2=min(en,to);
	int tmp;

	tmp=ch1[1];
	if( (S[br1+1]-S[bl1])+(S[ch2[1]+1]-S[bl2])>(S[tmp+1]-S[bl1]) )
		tmp=ch2[1];
	op[1]=tmp;

	tmp=ch2[2];
	if( (S[br2+1]-S[bl2])+(S[br1+1]-S[ch1[2]])>(S[br2+1]-S[tmp]) )
		tmp=ch1[2];
	op[2]=tmp;

	op[0]=MX(ch1[0],ch2[0]);
	op[0]=MX(op[0],S[op[1]+1]-S[bl1]);
	op[0]=MX(op[0],S[br2+1]-S[op[2]]);
	op[0]=MX(op[0],S[ch2[1]+1]-S[ch1[2]]);

	return;
}

int main()
{
	S[0]=0;
	Input(N);
	FOR(in,0,N){
		Input(ar[in]);
		S[in+1]=S[in]+ar[in];
	}
	init(1,0,N-1);

	int tmp[3];
	Input(Q);
	FOR(ip,0,Q){
		Input(fr),Input(to);
		fr--,to--;
		query(1,0,N-1,tmp);
		printf("%d\n",tmp[0]);
	}

	return 0;
}
