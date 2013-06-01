#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define LL long long

using namespace std;

char inp[101],conv[101];
int len;

inline void tojava()
{
	conv[0]=inp[0];
	int pos=1;

	FOR(ind,1,len){
		if(inp[ind]=='_'){
			conv[pos]=char(inp[ind+1]-32);
			++ind;
		} else
			conv[pos]=inp[ind];
		++pos;
	}
	conv[pos]='\0';
	printf("%s\n",conv);

	return;
}

inline void toc()
{
	conv[0]=inp[0];
	int pos=1;

	FOR(ind,1,len){
		if(inp[ind]<='Z'){
			conv[pos]='_';
			++pos;
			conv[pos]=char(inp[ind]+32);
		} else
			conv[pos]=inp[ind];
		++pos;
	}
	conv[pos]='\0';
	printf("%s\n",conv);

	return;
}

int main()
{
	bool java,c,none;

	while(scanf("%s",inp)!=EOF){
		len=strlen(inp);

		if(inp[0]=='_' || inp[len-1]=='_' || ('A'<=inp[0] && inp[0]<='Z')){
			printf("Error!\n");
			continue;
		}

		java=false,c=false,none=false;
		FOR(chk,0,len){
			if(inp[chk]=='_'){
				if(chk>=1 && inp[chk-1]=='_'){
					none=true;
					break;
				}
				c=true;
			} else if('A'<=inp[chk] && inp[chk]<='Z')
				java=true;

			if(java && c)
				break;
		}

		if(none || (java && c)){
			printf("Error!\n");
			continue;
		}
		if(c)
			tojava();
		else if(java)
			toc();
		else if(!c && !java)
			printf("%s\n",inp);
	}

	return 0;
}
