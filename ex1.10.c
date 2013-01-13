#include <stdio.h>

/*Replace each tab, backspace or backlash by \t, \b and \\*/
main(){
	int c;
	
	while ((c = getchar()) != EOF){
		if (c == '\t'){
			putchar('\\');
			putchar('t');
		}
		if (c == ' '){
			putchar('\\');
			putchar('b');
		}
		if (c == '\\'){
			putchar('\\');
			putchar('\\');
		}
		if (c != '\t')
			if (c != ' ')
				if (c != '\\')
					putchar(c);
	}
}
