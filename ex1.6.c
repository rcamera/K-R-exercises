#include <stdio.h>

#define TRUE 1

/*print 0 if getchar() != EOF or 1 if otherwise*/
main()
{
	int c;
	while (TRUE == 1){
		c = (getchar() == EOF);
		printf("%d\n", c);
	}
}
