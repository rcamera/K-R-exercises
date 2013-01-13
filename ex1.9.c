#include <stdio.h>

/*Replace multiple blanks for single blanks*/
main(){
	int c, last;
	
	while ((c = getchar()) != EOF){
		if( c != ' '){
			putchar(c);
			last = 0;
		}
		if ( c == ' '){
			if ( last == 0)
				putchar(c);
			last = 1;
		}
	}
}
