//-------------------- -
//作者：changyuanchn
//来源：CSDN
//原文：https ://blog.csdn.net/changyuanchn/article/details/17354461 
//版权声明：本文为博主原创文章，转载请附上博文链接！
#include <stdio.h>
#include <windows.h>

#define N 8
#define abs(x) (((x)>=0)?(x):-(x)) 
int col[N + 1];
int count = 0;

void Output();
void Queen(int i, int n);

void main()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		col[1] = i;
		Queen(2, N);
	}
	printf("%d\n", count);
	system("pause");
}

void Queen(int i, int n)
{
	if (i>n)
		Output();
	else
	{
		int j;
		for (j = 1; j <= N; j++)
		{
			col[i] = j;
			int k = 1; //已经安排了位置的皇后的游标指示
			while (k<i)//比较现在的皇后与之前的皇后有没有冲突
			{
				if ((col[k] - col[i])*(abs(col[k] - col[i]) - abs(k - i)) != 0)//冲突条件
				{
					k++;
					if (k == i)
						Queen(i + 1, n);
				}
				else
					break;
			}
		}
	}
}
void Output()
{
	int i;
	count++;
	for (i = 1; i <= N; i++)
	{
		printf("(%d,%d)\n", i, col[i]);
	}
	printf("\n");
}
