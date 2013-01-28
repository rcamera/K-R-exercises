#include <stdio.h>

#define CHAR_START 33
#define CHAR_END 126

/*Print a histogram of the frequencies of characters from an input*/
main()
{
	int c, i;
	double total, counter[CHAR_END - CHAR_START + 1];

	for (i = 0; i < CHAR_END - CHAR_START; ++i)
		counter[i] = 0;
	
	while ((c = getchar()) != EOF)
		if (c >= CHAR_START && c <= CHAR_END)
			++counter[c - CHAR_START];

	for (i = 0; i < CHAR_END - CHAR_START; ++i)
		total = total + counter[i];

	for (i = 0; i < CHAR_END - CHAR_START; ++i)
		counter[i] = counter[i] / total * 100;
	
	for (i = 0; i < CHAR_END - CHAR_START; ++i)
		if (counter[i] >= 0.2){
			putchar(i+CHAR_START);
			printf(":");
			while (counter[i] >= 0.5){
				if (counter[i] >= 1)
					printf("#");
				else
					printf("]");
				counter[i] = counter[i] - 1;
			}
			printf("\n");
		}
}
