/*全排列问题C++代码
输入：全排列元素数量 n
n个需要排列的字符
输出：该n个字符的全排列序列
*/
#include <iostream>
using namespace std;
void swap(int &a, int &b) {      //交换
	int temp = a;
	a = b;
	b = temp;
}

void perm(char list[], int low, int high) {      //递归函数
	if (low == high) {      //当执行完一趟递归排列便输出排列结果
		for (int i = 0; i <= low; i++)
			cout << list[i];
		cout << endl;
	}
	else {
		for (int i = low; i <= high; i++) {
			swap(list[i], list[low]);      //把第low个元素和第i个元素交换
			perm(list, low + 1, high);       //对子序列list[low+1]~list[high]执行递归排列操作
			swap(list[i], list[low]);      //将之前交换的两个元素换回来
		}
	}
}

int main()
{
	int n;
	char list[100];
	cout << "Number of elements for Full Permutation: ";
	cin >> n;      //输入排列字符的数量
	cout << "\nInput: ";
	for (int i = 0; i < n; i++)
		cin >> list[i];      //输入n个需要排列的字符
	cout << "\nOutput:" << endl;
	perm(list, 0, n - 1);
	cout << endl;
	system("pause");
	return 0;
}

///*
//* 对n个不同的字符进行全排列
//* 算法思想：
//*     假设求 1234 的全排列
//*     ① 把 1 固定，234 求全排，进行递归排列，直到为一个元素，打印所有元素，最后恢复最初的排序
//*     ② 把 1 和 2 进行交换，把 2 固定，134 求全排列，直到为一个元素，打印所有元素，最后恢复最初的排序
//*     ③ 同上所示，直到把 4 作为第一个为止。
//*/
//#include <iostream>
//using namespace std;
//
//void FullArray(char *str, int m, int n)
//{
//	int i, tmp;
//
//	if (n == m)
//	{
//		for (i = 0; i < n; i++)
//			cout << str[i];
//		cout << endl;
//	}
//	else
//	{
//		for (i = m; i < n; i++)
//		{
//			tmp = str[i];
//			str[i] = str[m];
//			str[m] = tmp;
//
//			FullArray(str, m + 1, n);
//
//			tmp = str[i];
//			str[i] = str[m];
//			str[m] = tmp;
//		}
//	}
//}
//
//int main(void)
//{
//	char str[100] = "1234";
//	FullArray(str, 0, strlen(str));
//
//	system("pause");
//	return 0;
//}