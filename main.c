#include <stdio.h>

int sum_array_rec(int arr[], int num, int sum)
{
	if (num == -1) {
		return 0;
	}

	sum += arr[num - 1] + sum_array_rec(arr, num - 1, sum);
	return sum;
}

int sum_array_iter(int arr[], int num, int sum)
{
	if (num == 0) {
		return sum;
	}
	sum += arr[num - 1];
	return (sum_array_iter(arr, num - 1, sum));
}

int fibonacci_rec(int n)
{
	if (n == 0 || n == -1) {
		return 1;
	}
	if ((n == 0) || (n == 1)) {
		return 1;
	}
	return (fibonacci_rec(n - 2) + fibonacci_rec(n - 1));
}



int fibonacci_iter(int n)
{
	int count = 2;
	int result = 1;
	int previousResult = 1;
	int tmp = 0;
	
	while(count <= n)
	{
		tmp = result;
		result += previousResult;
		previousResult = tmp;
		count++;
	}

	return result;
}

void print_array(int arr[], int num)
{
	printf("Array:\n");
	for (int i = 0; i < num; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

int main()
{
	int num = 5;
	int sum = 0;
	int arr[5] = {1, 2, 3, 4, 5};
	print_array(arr, num);
	
	//Recursive
	printf("\nsum_array_recursive = %d\n\n", sum_array_rec(arr, num, sum));

	sum = 0;
	//Iteration
	printf("\nsum_array_iteration = %d\n\n", sum_array_iter(arr, num, sum));
	int n[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print_array(n, 11);

	//
	printf("\nFibonacci_rec:\n");
	for (int i = 0; i < 11; i++){
		printf("%d\t", fibonacci_rec(n[i]));
	}
	printf("\nFibonacci_iter:\n");
	for (int i = 0; i < 11; i++){
		printf("%d\t", fibonacci_iter(n[i]));
	}
	printf("\n");
	return 0;
}
