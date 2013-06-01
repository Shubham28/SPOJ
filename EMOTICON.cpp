#include <list>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

struct trie{
	bool fnd;
	struct trie* symb[256];
};

int N,M;
char data[85],optm[85];
struct trie* orig;

void init(struct trie* &prs)
{
	prs=new trie;
	prs->fnd=0;
	FOR(fl,0,256)	prs->symb[fl]=NULL;
	return;
}

void destr(struct trie* prs)
{
	FOR(rem,0,100)
		if(prs->symb[rem]!=NULL)
			destr(prs->symb[rem]);
	free(prs);
	return;
}

void addEm(char emot[])
{
	int ln=strlen(emot);
	struct trie* prs=orig;
	struct trie* tmp;

	FOR(nw,0,ln){
		int ch=(emot[nw]>=0)?emot[nw]:256+emot[nw];

		if(prs->symb[ch]==NULL){
			init(tmp);
			prs->symb[ch]=tmp;
		}
		prs=prs->symb[ch];
	}
	prs->fnd=1;
	return;
}

int calOptm()
{
	int ans=0,prev=0,ln,tot;
	struct trie* srch;
	char word[85];

	sscanf(data+prev,"%s",word);
	tot=strlen(data),ln=strlen(word);
	while(prev<tot && ln!=0){

		RFOR(chk,ln-1,0){
			srch=orig;

			for(int mv=chk;mv<ln && srch!=NULL;mv++){
				int ltr=(word[mv]>=0)?word[mv]:256+word[mv];

				srch=srch->symb[ltr];
				if(srch!=NULL && srch->fnd){
					word[chk]=' ';
					ans++;
					break;
				}
			}
		}

		prev+=ln+1;
		sscanf(data+prev,"%s",word);
		ln=strlen(word);
	}
	return ans;
}

int main()
{
	char emot[20];
	scanf("%d %d",&N,&M);
	while(N!=0 && M!=0){

		init(orig);
		FOR(inp,0,N){
			scanf("%s",emot);
			addEm(emot);
		}

		cin.ignore(1,'\n');

		int ret=0;
		FOR(inp,0,M){
			gets(data);

			list<char>bufr;
			list<char>::iterator it,prv;

			int tot=strlen(data);
			FOR(bl,0,tot)
				PB(bufr,data[bl]);

			prv=it=bufr.begin();
			it++;
			for(;it!=bufr.end();){
				if((*it)==' ' && (*prv)==' ')
					it=bufr.erase(it);
				else
					prv++,it++;
			}

			tot=0;
			for(it=bufr.begin();it!=bufr.end();it++)
				data[tot++]=*it;
			data[tot]=0;

			ret+=calOptm();
		}
		printf("%d\n",ret);
		destr(orig);

		scanf("%d %d",&N,&M);
	}

	return 0;
}
