#include <iostream>
#define N 10
int main()
{
	int a[N] = { 1,2,7,99,3,3,4,1,2,4 }, flat[N] = { 0 };
	int i, j, sum = a[0], last_bit = 0, sum0 = 0, sum1 = 0;
	// 对数组中所有元素进行异或操作
	// 如果当数组中只有一个元素只出现一次时，则异或的结果就是只出现一次那个元素 
	for (i = 1; i < N; i++)
	{
		sum = sum ^ (a[i]);
	}
	// 如果当数组中有两个元素只出现一次时，则将上述异或的结果转化成二进制，并从右到左进行判断，将第一个为 1的位置记录为 i 
	for (i = 0; last_bit != 1; i++)
	{
		last_bit = sum & 1;
		sum = sum >> 1;
	}
	// 接着对所有的元素的二进制形式的第 i位进行扫描，将结果记录到 flat数组
	// flat[j]=1表明第 j元素的第 i位为 1，否则为 0 
	for (j = 0; j < N; j++)
	{
		flat[j] = (a[j] >> (i - 1)) & 1;
	}
	// 根据上述循环得到的 flat数组，对所有元素进行分组
	// 结果为 1的在一起进行异或操作，为 0的在一起进行异或操作 ，两组异或的结果就是两个只出现一次的元素 
	for (j = 0; j < N; j++)
	{
		(flat[j] == 1) ? (sum1 = sum1 ^ (a[j])) : (sum0 = sum0 ^ (a[j]));
	}
	printf("%d %d\n", sum0, sum1);
	system("pause");
}