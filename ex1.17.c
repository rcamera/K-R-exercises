/*Problem: print all lines that are longer than 80 characters.
 *
 * This is probably the simplest way of doing this, which is to concanate all lines longer than 80 chars to a single array, separating each line with a newline (\n). We have to keep track of where the array ends, so we can save input after the last line, not overwriting anything, and in order to do that, copy() will now return a value, which is the value of i.*/

#include <stdio.h>
#define MAXLINE 1000
#define MINIMUM 80

int get_line(char line[], int maxline);
int copy(char to[], char from[], int offset);

/*print the longest input line*/
main()
{
	int len; 		/*current line length*/
	int offset;	/*offset to append next line longer than MINIMUM*/
	char line[MAXLINE]; 		/*current input line*/
	char longest[MAXLINE]; 	/*longest lines than MINIMUM chars saved here*/

	offset = 0;
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len >= MINIMUM)
			offset = copy(longest, line, offset);
	if (offset > 0) /*there was a line*/
		printf("%s\n", longest);
	return 0;
}

/*get_line: read a line into s, return length*/
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim-2)
			s[i] = c;
	if (i < lim-1)
		s[i] = '\n';
	else if (i >= lim-1){
		s[lim-2] = '\n';
		s[lim-1] = '\0';
	}
	return i;
}

/*copy: copy from[] into to[]; assume from is big enough*/
int copy(char to[], char from[], int offset)
{
	int i;

	i = 0;
	while ((to[i+offset] = from[i]) != '\n' && (i + offset) < (MAXLINE - 2))
		++i;
	if ((i + offset) < (MAXLINE - 1)){
		to[i+ offset] = '\n';
		++i;
		to[i + offset] = '\0';
	}
	else
		to[MAXLINE - 1] = '\0';
	return (i + offset);
}
