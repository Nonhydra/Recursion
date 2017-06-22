#include <stdio.h>
#include <math.h>

char *itc_iter(int num, char *str, int n, int pos_num, int size_num)
{
	if (pos_num == n || pos_num == 0) {
		str[n - 1] = 0;
		return str;
	}
	str[pos_num] = '0' + (((int)fabs(num) % (int)pow(10, size_num)) / pow(10, size_num - 1));
	return itc_iter(num, str, n, ++pos_num, --size_num);
}

char *itc(int num, char *str, int n)
{
	//int tmp;
	int size_num = 1;
	int pos_num = 0;
	while (num = num / 10) {
		size_num++;
	}
	if (num < 0) {
		str[0] = '-';
		pos_num++;
	}
	return itc_iter(num, str, n, pos_num, size_num);
}

int main(void)
{
	int num = 1155534;
	int n = 7;
	char str[n];
	printf("%s\n", itc(num, str, n));
}