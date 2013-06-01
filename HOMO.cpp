#include <map>
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

int main()
{
	map<int,int>freq;
	set<int>mult;

	int opr;
	scanf("%d",&opr);

	int val;
	char comd[10];

	while(opr--){
		scanf("%s %d",comd,&val);

		if(comd[0]=='i'){
			++freq[val];
			if(freq[val]==2)
				mult.insert(val);
		} else {
			if(freq.find(val)!=freq.end()){
				--freq[val];
				int prs=freq[val];

				if(prs==1)
					mult.erase(val);
				else if(prs==0)
					freq.erase(val);
			}
		}

		bool hm=0,ht=0;
		int T=SZ(freq);
		int L=SZ(mult);

		hm=(L>=1);
		ht=(T>=2);

		if(T==0 || !(hm|ht))
			printf("neither\n");
		else if(hm&ht)
			printf("both\n");
		else if(hm)
			printf("homo\n");
		else
			printf("hetero\n");
	}

	return 0;
}