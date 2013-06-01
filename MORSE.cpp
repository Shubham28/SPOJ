#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <utility>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())

using namespace std;

struct trie{
	int mat;
	struct trie *dot,*dash;
};

int L;
char inp[10002],dict[10000][22];
int ways[10002];
struct trie* orig;

string mat[26]={".-","-...","-.-.","-..",
				".","..-.","--.","....",
				"..",".---","-.-",".-..",
				"--","-.","---",".--.",
				"--.-",".-.","...","-",
				"..-","...-",".--","-..-",
				"-.--","--.."};

inline void init(struct trie* &tmp)
{
	tmp=new trie;
	tmp->mat=0;
	tmp->dash=tmp->dot=NULL;
	return;
}

void addWrd(char seq[])
{
	struct trie* prs=orig;
	struct trie* tmp;

	int ln=strlen(seq);
	FOR(all,0,ln){
		int lr=seq[all]-'A';

		FOR(add,0,SZ(mat[lr])){
			if(mat[lr][add]=='.'){
				if(prs->dot==NULL){
					init(tmp);
					prs->dot=tmp;
				}
				prs=prs->dot;
			} else {
				if(prs->dash==NULL){
					init(tmp);
					prs->dash=tmp;
				}
				prs=prs->dash;
			}
		}
	}
	(prs->mat)++;
	return;
}

int cntWrd()
{
	MEM(ways,0);
	ways[L]=1;
	struct trie* srch;

	RFOR(ps,L-1,0){
		srch=orig;
		for(int inc=ps;inc<L && srch!=NULL;inc++){
			char ch=inp[inc];
			if(ch=='.')		srch=srch->dot;
			else if(ch=='-')	srch=srch->dash;

			if(srch!=NULL && srch->mat)
				ways[ps]+=(srch->mat*ways[inc+1]);
		}
	}
	return ways[0];
}

int main()
{
	int T,N;
	scanf("%d",&T);

	while(T--){
		scanf("%s%d",inp,&N);
		L=strlen(inp);

		init(orig);
		FOR(inp,0,N){
			scanf("%s",dict[inp]);
			addWrd(dict[inp]);
		}
		printf("%d\n",cntWrd());
	}

	return 0;
}
