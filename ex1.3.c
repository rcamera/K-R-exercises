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

	fahr = lower;
	printf("Fahrenheit\tCelsius\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32);
		printf("%.2f\t\t%.2f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
