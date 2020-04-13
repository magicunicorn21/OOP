#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sumEvenSmallerFibonacci(int max)
{
	int sum = 0, lastNumber = 0, currentNumber = 1;
	while (currentNumber <= max)
	{
		if (currentNumber % 2 == 0)
			sum += currentNumber;
		currentNumber += lastNumber;
		lastNumber = currentNumber - lastNumber;
		currentNumber -= lastNumber;
		currentNumber += lastNumber;
	}
	return sum;
}

int main()
{
	char givenValue[30];
	printf("Insert value: ");
	scanf("%s", givenValue);
	//printf("%s\n", givenValue);
	while (strcmp(givenValue, "exit") != 0)
	{
		int maxValue = 0, sum = 0;
		maxValue = atoi(givenValue);
		sum = sumEvenSmallerFibonacci(maxValue);
		printf("Sum of even numbers: %d\n", sum);
		scanf("%s", givenValue);
	}
	return 0;
}