#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SZ(A) int(A.size())

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	cin.ignore(1,'\n');

	while(T--){
		string line;
		getline(cin,line);
		line+=" ";

		string word;
		stringstream brk;
		brk<<line;

		int last=-1,cnt=0;
		int ans=0;
		while(brk>>word){
			if(SZ(word)==last)
				++cnt;
			else
				last=SZ(word),cnt=1;

			ans=max(ans,cnt);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
