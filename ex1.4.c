#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	printf("Celsius\t\tFahrenheit\n");
	while (celsius <= upper) {
		fahr = ((9.0/5.0) * celsius) + 32;
		printf("%.2f\t\t%.2f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
