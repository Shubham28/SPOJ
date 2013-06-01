#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define LL long long

using namespace std;

int LIM=255;

int N,R;
unsigned LL nCr[251][251];

inline void calComb()
{
	nCr[0][0]=1;
	EFOR(row,1,200){
		nCr[row][0]=1;
		EFOR(col,1,row)
			nCr[row][col]=nCr[row-1][col-1]+nCr[row-1][col];
	}
	return;
}

int main()
{
//	freopen("Input.txt","r",stdin);
	char inp[LIM];
	int alph[26],coef[26],numer[26];
	int len,tmpl,terms;
	calComb();

	while(gets(inp)!=NULL){
		memset(alph,0,sizeof(alph));
		tmpl=strlen(inp),len=0;

		FOR(pos,0,tmpl){
			inp[pos]=tolower(inp[pos]);
			if(97<=inp[pos] && inp[pos]<=122){
				++alph[inp[pos]-'a'];
				++len;
			}
		}
		if(len==0){
			printf("1\n");
			continue;
		}

		int odd=0;
		FOR(all,0,26)
			odd+=(alph[all]&1)?1:0;

		if(odd>1)
			printf("0\n");
		else if((len&1)==0 && odd)
			printf("0\n");
		else {
			memset(coef,0,sizeof(coef));
			memset(numer,0,sizeof(numer));
			terms=0;

			FOR(all,0,26)
				if(alph[all]){
					coef[terms++]=alph[all]/2;
					numer[terms-1]=coef[terms-1]+((terms==1)?0:numer[terms-2]);
				}

			unsigned LL ans=1;
			FOR(tot,0,terms)
				ans*=nCr[numer[tot]][coef[tot]];

			printf("%lld\n",ans);
		}
	}

//	fclose(stdin);
	return 0;
}
