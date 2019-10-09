#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX 1024

void combine(int *a, int *b, int len1, int len2)
{
	if (a == NULL || b == NULL || (len1 + len2) > MAX)
		return;

	int new_point;
	int a_point = len1 - 1;
	int b_point = len2 - 1;

	new_point = len1 + len2 - 1;	//总的长度

	while (a_point >= 0 && b_point >= 0)
	{
		if (a[a_point] > b[b_point])
		{
			a[new_point--] = a[a_point--];
		}
		else
		{
			a[new_point--] = b[b_point--];
		}
	}

	while (a_point >= 0)
	{
		a[new_point--] = a[a_point--];
	}

	while (b_point >= 0)
	{
		a[new_point--] = b[b_point--];
	}

	return;
}

int main()
{
	int b[MAX] = { 1,2,3,4 };
	int a[MAX] = { 5,6,7,8 };

	combine(a, b, 4, 4);

	for (int i = 0; i <= 4 + 4 - 1; i++)
	{
		cout << a[i] << " ";
	}

	system("pause");
	return 0;
}