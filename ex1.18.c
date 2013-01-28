/*Problem: write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines
 *
 * Solution: Hold all input into a character array, copy that array to a new array, removing trailing blanks and entirely blank newlines (which means a line with just \n, \t or ' ' characters). Print that result array.*/

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void clear_blanks(char from[], char to[], int length);

main()
{
	int i; 									/*array position*/
	int c;
	char line[MAXLINE]; 		/*current input line*/
	char result[MAXLINE]; 	/*result string, to be printed*/

	i = 0;
	while ((c = getchar()) != EOF && i < MAXLINE){
		line[i] = c;
		++i;
	}
	if (i == MAXLINE)
		printf("Maximum input length exceeded. Removing trailing blanks from computed text\n");
	if (i > 0) 							/*there was a line*/
		clear_blanks(line, result, i);
		printf("%s\n", result);
	return 0;
}

/*copy from[] to to[], but removing trailing blanks and tabs, as well as entirely blank lines */
void clear_blanks(char from[], char to[], int length)
{
	int i;
	int j;
	i = j = 0;
	while (i < length){
		to[j] = from[i];
		if(to[j] == '\n' && j > 0){
			while ((to[j-1] == '\n' || to[j-1] == '\t' || to[j-1] == ' ') && j > 0)
				--j;
			to[j] = '\n';
		}
		++i;
		++j;
	}
	if (to[j-1] == '\n')
		to[j-1] = '\0';
	else
		to[j] = '\0';
}
