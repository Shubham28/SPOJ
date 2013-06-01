#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()

using namespace std;

int main()
{	
	string line;
	getline(cin,line);

	printf("Ready\n");
	while(line[0]!=' ' && line[1]!=' '){
		SORT(line);

		if((line[0]=='b' && line[1]=='d') || (line[0]=='p' && line[1]=='q'))
			printf("Mirrored pair\n");
		else
			printf("Ordinary pair\n");

		getline(cin,line);
	}

	return 0;
}
