#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

float temp_conversion(float fahr);

float temp_conversion(float fahr){
	float result;
	result = (5.0/9.0) * (fahr-32);
	return result;
}

main()
{
	float fahr;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("Fahrenheit\tCelsius\n");
	while (fahr <= upper) {
		printf("%.2f\t\t%.2f\n", fahr, temp_conversion(fahr));
		fahr = fahr + step;
	}

}
