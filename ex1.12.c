#include <stdio.h>

/*Print a word per line.*/
main()
{
	int c;

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t')
			c = '\n';
		putchar(c);
	}
}
