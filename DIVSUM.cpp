#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <bitset>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	int T,limit=500000;
	VI div(limit+1,1);
	div[0]=0,div[1]=0;

/*	Unoptimised
	EFOR(fac,2,limit/2){
		for(int mul=fac*2;mul<=limit;mul+=fac)
			div[mul]+=fac;
	}
*/
	int end=int(sqrt(limit+0.0)+1.0+1e-7);
	EFOR(fac,2,end){
		div[fac*fac]+=fac;
		for(int mul=fac+1;mul*fac<=limit;mul++)
			div[mul*fac]+=(mul+fac);
	}

	scanf("%d",&T);
	EFOR(cases,1,T){
		int inp;
		scanf("%d",&inp);
		printf("%d\n",div[inp]);
	}

	return 0;
}
