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
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
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
	int seq1[10001],seq2[10001];
	int len1,len2;
	int tot1[10001],tot2[10001];

	int com1[10001],com2[10001];
	int cmlen;
	int best1[10001],best2[10001];

	Input(len1);
	while(len1!=0){
		int sum=0;
		FOR(inp,0,len1){
			Input(seq1[inp]);
			sum+=seq1[inp];
			tot1[inp]=sum;
		}

		sum=0;
		Input(len2);
		FOR(inp,0,len2){
			Input(seq2[inp]);
			sum+=seq2[inp];
			tot2[inp]=sum;
		}

		cmlen=0;
		FOR(all,0,len1){
			int pos=lower_bound(seq2,seq2+len2,seq1[all])-seq2;
			if(pos==len2)
				continue;
			else if(seq1[all]==seq2[pos])
				com1[cmlen]=all,com2[cmlen]=pos,cmlen+=1;
		}

		if(cmlen==0)
			printf("%d\n",max(tot1[len1-1],tot2[len2-1]));
		else {
			best1[0]=tot1[com1[0]],best2[0]=tot2[com2[0]];
			FOR(bst,1,cmlen){
				if(best1[bst-1]>=best2[bst-1]){
					best1[bst]=best1[bst-1]+tot1[com1[bst]]-tot1[com1[bst-1]];
					best2[bst]=best1[bst-1]+tot2[com2[bst]]-tot2[com2[bst-1]];
				} else {
					best1[bst]=best2[bst-1]+tot1[com1[bst]]-tot1[com1[bst-1]];
					best2[bst]=best2[bst-1]+tot2[com2[bst]]-tot2[com2[bst-1]];
				}
			}
			int last1=max(best1[cmlen-1],best2[cmlen-1])+tot1[len1-1]-tot1[com1[cmlen-1]];
			int last2=max(best1[cmlen-1],best2[cmlen-1])+tot2[len2-1]-tot2[com2[cmlen-1]];
			printf("%d\n",max(last1,last2));
		}
		Input(len1);
	}

	return 0;
}
