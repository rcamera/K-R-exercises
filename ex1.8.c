#include <stdio.h>

/*count blanks, tabs and newlines from input;*/
main()
{
	int c;
	double b, t, n;
	b = t = n = 0;
	while ((c = getchar()) != EOF){
		if(c == ' ')
			++b;
		if(c == '\t')
			++t;
		if(c == '\n')
			++n;
	}

	printf("\nBlanks: %.0f\tTabs: %.0f\tNewlines: %.0f\n", b,t,n);
}

