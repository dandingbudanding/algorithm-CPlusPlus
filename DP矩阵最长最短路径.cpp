#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int value[1024][1024];

//动态方程 value[i][j]=max(or min){value[i-1][j],value[i][j-1]}
//时间复杂度 O(n*m) 空间复杂度 O(1)
int main()
{
	char str[2][3] = { "a","b"};
	cout << str[0][0];
	cout << str[1][0];
	int m, n;
	scanf_s("%d%d", &m, &n);

	//输入矩阵
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf_s("%d", &value[i][j]);
		}
	}

	//计算
	for (int i = 1; i < m; ++i)
	{
		value[i][0] += value[i - 1][0];
	}
	for (int j = 1; j < n; ++j)
	{
		value[0][j] += value[0][j - 1];
	}
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			value[i][j] += max(value[i - 1][j], value[i][j - 1]);
		}
	}

	////打印调试
	//for (int i = 0; i < m; ++i)
	//{
	//	for (int j = 0; j < n; ++j)
	//	{
	//		cout << value[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	cout << value[m - 1][n - 1] << endl;

	return 0;
}