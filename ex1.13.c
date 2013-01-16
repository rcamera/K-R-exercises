#include <stdio.h>

#define MAX_LENGTH 10

/*Print a horizontal histogram of the lengths of word from input*/
/* a # equals 5% and a ] equals 2.5%*/

main()
{
	int c, i, length;
	double ndigit[MAX_LENGTH];

	length = 0;
	for (i = 0; i < MAX_LENGTH; ++i)
		ndigit[i] = 0;

	/*calculate length of each word, if length is over 10 chars, increment the last array value*/
	while ((c = getchar()) != EOF)
		if ((c == ' ' || c == '\n' || c == '\t') && length > 0){
			if (length <= MAX_LENGTH)
				++ndigit[length-1];
			else
				++ndigit[MAX_LENGTH - 1];
			length = 0;
		}
		else
			++length;

	/*if last character received before EOF wasn't either a \n, \t or ' ', then you need to count the last word as well*/
	if(length > 0 && length <= MAX_LENGTH)
		++ndigit[length-1];
	else if (length > MAX_LENGTH)
		++ndigit[MAX_LENGTH - 1];
	length = 0;

	/*Calculate total number of words*/
	for (i = 0; i < MAX_LENGTH; ++i)
		length = ndigit[i] + length;

	/*Calculate the percentage of each word length, given the total number of words*/
	for (i = 0; i < MAX_LENGTH; ++i)
		ndigit[i] = ndigit[i] / length * 100;
	
	/*Print horizontal histogram with # representing 5% and ] representing 2.5%*/
	for (i = 0; i < MAX_LENGTH; ++i){
		if (i == MAX_LENGTH - 1)
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
