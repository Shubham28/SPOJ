#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

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
	char num[5001];
	LL comb[2];

	scanf("%s",num);
	while(strcmp(num,"0")!=0){
		int N=strlen(num);

		if(N==1)
			printf("1\n");
		else {
			int chn=0,fir,sec;
			comb[0]=1,comb[1]=1;

			FOR(pos,1,N){
				fir=chn,sec=1-chn;

				if(num[pos]=='0'){
				} else if(num[pos-1]=='0')
					comb[fir]=comb[sec];
				else if(num[pos-1]<='1' || (num[pos-1]=='2' && num[pos]<='6'))
					comb[fir]+=comb[sec];
				else 
					comb[fir]=comb[sec];

				chn+=1,chn%=2;
			}
			printf("%lld\n",comb[1-chn]);
		}
		scanf("%s",num);
	}

	return 0;
}
