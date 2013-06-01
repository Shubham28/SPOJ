#include <vector>
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
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())

using namespace std;

#define MAXX 11000000
char *ipos, *opos, InpFile[MAXX], OutFile[100], DIP[30];

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

inline void Outp(int x)
{
	int y;
	int dig=0;
	while(x || !dig){
		y=x/10;
		DIP[dig++]=x-((y<<3)+(y<<1))+'0';
		x=y;
	}
	while(dig--)	*opos++=DIP[dig];
}

inline void InitFASTIO()
{
	ipos=InpFile;	opos=OutFile;
	fread(InpFile,MAXX,1,stdin);
}

inline void FlushFASTIO()
{
	fwrite(OutFile,opos-OutFile,1,stdout);
}

struct cord{
	int x,y,z;

	bool operator< (const cord& tmp) const
	{	return x<tmp.x;		}
};

cord plr[100001];
int N;

bool cmpz(const cord &fr,const cord &sc)
{	return fr.z<sc.z;	}

int main()
{
	InitFASTIO();

	int T;
	set<cord>bndr;
	set<cord>::iterator it;

	T=InpInt();
	while(T--){
		N=InpInt();
		FOR(i,0,N)
			plr[i].x=InpInt(),plr[i].y=InpInt(),plr[i].z=InpInt();

		sort(plr,plr+N,cmpz);

		int ans=1;
		bndr.clear();
		bndr.insert(plr[0]);
		FOR(ck,1,N){
			it=bndr.lower_bound(plr[ck]);

			if(it!=bndr.begin()){
				it--;
				if((*it).y<plr[ck].y)
					continue;
				it++;
			}
			ans++;

			vector< set<cord>::iterator >rem;
			for(;it!=bndr.end();it++){
				if((*it).y>plr[ck].y){
					PB(rem,it);
				} else
					break;
			}
			FOR(dl,0,SZ(rem))
				bndr.erase(rem[dl]);

			bndr.insert(plr[ck]);
		}
		Outp(ans);
		*opos++='\n';
	}

	FlushFASTIO();
	return 0;
}
