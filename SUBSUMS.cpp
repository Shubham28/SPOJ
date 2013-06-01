#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
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

int main()
{
	int N;
	Input(N);

	int minim,maxim;
	Input(minim),Input(maxim);

	int fir[(1<<17)+1],sec[(1<<17)+1];
	int firlen=0,seclen=0;
	int ar[35];

	FOR(inp,0,N){
		int tmp;
		Input(tmp);
		ar[inp]=tmp;
	}

	int mid=(N/2);
	int tmp=0;

	unsigned LL cnt=0;
	FOR(all,1,1<<(N-mid)){

		if(all<(1<<mid)){
			tmp=0;
			FOR(mask,0,mid)
				if(all&(1<<mask))
					tmp+=(ar[mask]);

			if(minim<=tmp && tmp<=maxim)
				++cnt;
			fir[firlen++]=tmp;
		}

		tmp=0;
		FOR(mask,0,(N-mid))
			if(all&(1<<mask))
				tmp+=(ar[mid+mask]);

		if(minim<=tmp && tmp<=maxim)
			++cnt;
		sec[seclen++]=tmp;
	}
	sort(sec,sec+seclen);

	FOR(allfr,0,firlen){
		int tmp=fir[allfr];
		int lessr=minim-tmp,grt=maxim-tmp;
		int from,to;

		int st=0,end=seclen-1;

		if(sec[st]>=lessr)
			from=st;
		else if(sec[end]<lessr)
			continue;
		else {
			while(st<=end){
				int cent=(st+end)/2;
				if(sec[cent]<lessr && sec[cent+1]>=lessr){
					from=cent+1;
					break;
				}
				if(sec[cent]<lessr)
					st=cent+1;
				else
					end=cent-1;
			}
		}

		st=from,end=seclen-1;
		if(sec[st]>grt)
			continue;
		else if(sec[end]<=grt)
			to=end;
		else {
			while(st<=end){
				int cent=(st+end)/2;
				if(sec[cent]<=grt && sec[cent+1]>grt){
					to=cent;
					break;
				}
				if(sec[cent]<=grt)
					st=cent+1;
				else
					end=cent-1;
			}
		}
		cnt+=(1+to-from);
	}
	if(minim<=0 && 0<=maxim)
		++cnt;

	printf("%llu",cnt);

	return 0;
}
