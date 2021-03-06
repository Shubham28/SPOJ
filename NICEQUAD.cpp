#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>
#define VB vector<bool>
#define SZ(A) int(A.size())
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

int cnt[4][4];								// EE,EO,OE,OO sequence for Rows

inline int fnquad(int tx,int ty)
{
	if(tx>0 && ty>0)
		return 0;
	else if(tx<0 && ty>0)
		return 1;
	else if(tx<0 && ty<0)
		return 2;
	else if(tx>0 && ty<0)
		return 3;
}

int main()
{
	int T,N;
	Input(T);

	while(T--){

		memset(cnt,0,sizeof(cnt));
		Input(N);

		FOR(inp,0,N){
			int tx,ty;
			Input(tx),Input(ty);

			if(tx!=0 && ty!=0){
				int quadr=fnquad(tx,ty);
				tx=(tx&1),ty=(ty&1);
				++cnt[tx*2+ty][quadr];
			}
		}

		LL ans=0;
		FOR(mask,0,1<<8){
			int x1=mask&1,y1=(mask>>1)&1,x2=(mask>>2)&1,y2=(mask>>3)&1;
			int x3=(mask>>4)&1,y3=(mask>>5)&1,x4=(mask>>6)&1,y4=(mask>>7)&1;

			int par=(x1*y2)-(x2*y1)+(x2*y3)-(x3*y2);
			par+=( (x3*y4)-(x4*y3)+(x4*y1)-(x1*y4) );

			if((par&1)==0)
				ans+=((LL)(cnt[x1*2+y1][0])*(LL)(cnt[x2*2+y2][1])*(LL)(cnt[x3*2+y3][2])*(LL)(cnt[x4*2+y4][3]));
		}
		printf("%llu\n",ans);
	}

	return 0;
}
