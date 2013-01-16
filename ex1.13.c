#include <stdio.h>

/*Print a horizontal histogram of the lengths of word from input*/
/* a # equals 5% and a ] equals 2.5%*/

main()
{
	int c, i, length;
	double ndigit[10];

	length = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if ((c == ' ' || c == '\n' || c == '\t') && length > 0){
			if (length <=10)
				++ndigit[length-1];
			else
				++ndigit[9];
			length = 0;
		}
		else
			++length;

		if(length > 0 && length <=10)
			++ndigit[length-1];
		else if (length > 10)
			++ndigit[9];
		length = 0;

		for (i = 0; i < 10; ++i)
			length = ndigit[i] + length;

		for (i = 0; i < 10; ++i)
			ndigit[i] = ndigit[i] / length * 100;
		
		for (i = 0; i < 10; ++i){
			if (i == 9)
				printf("%d+: \t", i+1);
			else
				printf("%d: \t", i+1);

			while (ndigit[i] >= 2.5){
				if (ndigit[i] >=5){
					printf("#");
					ndigit[i] = ndigit[i] - 5;
				}
				else {
					printf("]");
					ndigit[i] = ndigit[i] - 2.5;
				}
			}
			printf("\n");
		}
}	
