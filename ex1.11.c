#include <stdio.h>

#define IN 1	/*inside a word*/
#define OUT 0	/*outside a word*/

/*count lines, words and characters in input*/
/*This small program has a few problems, it won't count the proper number of words, if words have only punctuation without any spaces, tabs or newlines between them.*/
main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
