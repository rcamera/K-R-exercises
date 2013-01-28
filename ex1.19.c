/* Problem: write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
 *
 * solution: The idea is to call the reverse function on every '\n' encountered, print the result array and reset the index from the input array, until EOF is hit. Note that the reverse function isn't needed unless there are more than 2 characters in the line.*/

#include <stdio.h>

#define MAXLINE 1000

void reverse(char input[], int i);

main()
{
	int c, i;
	char input[MAXLINE];
	
	i = 0;
	while ((c = getchar()) != EOF && i < (MAXLINE - 1)){
		input[i] = c;
		++i;
		if (c == '\n'){
			if (i > 2)
				reverse(input, i);
			printf("%s", input);
			i = 0;
		}
	}
	return 0;
}

void reverse(char input[], int i)
{
	char temp[MAXLINE];
	int j;
	i = i - 2;
	j = 0;
	while(i >= j){
		temp[j] = input[i-j];
		++j;
	}
	temp[j] = '\n';
	++j;
	temp[j] = '\0';
	i = 0;
	while (i <= j){
		input[i] = temp[i];
		++i;
	}
}
