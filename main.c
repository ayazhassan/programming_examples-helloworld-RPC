#include <stdio.h>
#include <rpc/rpc.h>
#include "hw.h"

/* 
   Simple "hello world" program that demonstrates an rpc call.
*/

main (int argc, char *argv[]) {

	CLIENT *cl;
	struct AB ab;
	struct AB *p;
	
	if (argc != 2) {
		printf("Usage: client hostname\n");
		exit(1);
	}

	cl = clnt_create(argv[1], HELLO_WOLRD_PROG, HELLO_WORLD_VERS, "tcp");
	if (cl == NULL) {
		clnt_pcreateerror(argv[1]);
		exit(1);
	}

	ab.a = 10;
	ab.b = 20;
	printf("Getting ready to call hello world\n");
	p = hw_1(NULL, cl);

	printf("Back from hello world\n");
	if (p == NULL) {
		clnt_perror(cl,argv[1]);
		exit(1);
	}

	printf("Returned a=%d\nb=%d",p->a,p->b);

	return 0;
}
