#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VS vector<string>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	char inp[101];
	scanf("%s",inp);

	int N=strlen(inp);
	int cnt=0;
	FOR(zer,0,N)
		if(inp[zer]=='0')
			++cnt;

	double rot=0.0,sh=0.0;
	double fr=double(cnt)/double(N);

	FOR(all,0,N)
		if(inp[all]=='0'){
			if(inp[(all+1)%N]=='0')
				sh+=1.0;
			rot+=fr;
		}

	if(rot==sh)
		printf("EQUAL\n");
	else if(rot<sh)
		printf("SHOOT\n");
	else
		printf("ROTATE\n");

	return 0;
}
