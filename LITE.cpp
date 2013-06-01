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

int N,fr,to;
int P[(1<<18)+5];
bool mrk[(1<<18)+5];

void update(int ind,int st,int end)
{
	if(mrk[ind]){
		mrk[ind]=0;
		P[ind]=(end+1-st)-P[ind];
		if(st!=end){
			mrk[2*ind]=!mrk[2*ind];
			mrk[2*ind+1]=!mrk[2*ind+1];
		}
	}
	if(fr>end || to<st)		return;
	
	if(fr<=st && end<=to){
		P[ind]=(end+1-st)-P[ind];
		if(st!=end){
			mrk[2*ind]=!mrk[2*ind];
			mrk[2*ind+1]=!mrk[2*ind+1];
		}
		return;
	}

	update(2*ind,st,(st+end)/2);
	update(2*ind+1,(st+end)/2+1,end);
	P[ind]=P[2*ind]+P[2*ind+1];

	return;
}

int query(int ind,int st,int end)
{
	if(mrk[ind]){
		mrk[ind]=0;
		P[ind]=(end+1-st)-P[ind];
		if(st!=end){
			mrk[2*ind]=!mrk[2*ind];
			mrk[2*ind+1]=!mrk[2*ind+1];
		}
	}

	if(fr>end || to<st)		return -1;
	if(st>=fr && end<=to)	return P[ind];

	int p1=query(2*ind,st,(st+end)/2);
	int p2=query(2*ind+1,(st+end)/2+1,end);

	if(p1==-1)		return p2;
	if(p2==-1)		return p1;

	return p1+p2;
}

int main()
{
	Input(N);
	MEM(mrk,0);	MEM(P,0);

	int M,ch;
	Input(M);

	FOR(ip,0,M){
		Input(ch),Input(fr),Input(to);
		fr--,to--;

		if(ch==0)
			update(1,0,N-1);
		else
			printf("%d\n",query(1,0,N-1));
	}

	return 0;
}
