#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

//	http://ace.delos.com/TESTDATA/NOV09.xoinc.htm

#define MAXX 16050
char *ipos, InpFile[MAXX], DIP[15];

inline int InpInt(int flag=0)
{
	while(*ipos<=32)	++ipos;

	if (flag)	return (*ipos++ - '0');

	int x=0,neg=0;
	char c;
	while(true){
		c=*ipos++;
		if(c=='-')	neg=1;
		else {
			if(c<=32)	return (neg?-x:x);
			x=(x<<1)+(x<<3)+(c-'0');
		}
	}
}

inline void InitFASTIO()
{
	ipos=InpFile;
	fread(InpFile,MAXX,1,stdin);
}


int cns[2005];
int S[2005];
int opt[2005][2005];

/*	Recursive

int plBest(int pos,int lim)
{
	if(lim<=0)		return 0;

	int &ret=opt[pos][lim];

	if(ret!=-1)		return ret;
	if(pos+1-lim<=0)	return (ret=S[pos+1]);

	ret=plBest(pos,lim-1);
	ret=max(ret,S[pos+1]-plBest(pos-lim,lim<<1));

	return ret;
}

	plBest(N-1,2)

*/

int main()
{
	InitFASTIO();

	int N=InpInt();
	RFOR(in,N,1)
		cns[in]=InpInt();

	EFOR(fl,1,N)
		S[fl]=S[fl-1]+cns[fl];

	EFOR(ps,1,N)
		EFOR(amt,1,N){
			opt[ps][amt]=max(opt[ps][amt],opt[ps][amt-1]);
			if(ps>=2*amt-1)
				opt[ps][amt]=max(opt[ps][amt],S[ps]-opt[ps-(2*amt-1)][2*amt-1]);
			if(ps>=2*amt)
				opt[ps][amt]=max(opt[ps][amt],S[ps]-opt[ps-2*amt][2*amt]);
		}

	printf("%d\n",opt[N][1]);

	return 0;
}
