// 排序算法编程实践

#include <iostream> 
#define max(a,b) (a>=b?a:b)//不编译直接运行，inline会增加代码量
using namespace std;

// 冒泡排序

void BubbleSort(int a[], int n)
{
	bool flag = true;
	int k = n;
	while (flag)
	{
		flag = false;
		for (int i = 1; i < k; i++)
		{
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
				flag = true;
			}
		}
		k--;
	}
}

void MyBubbleSort(int a[],int n)
{
	int len = n;
	bool flag = true;
	while(flag)
	{
		flag = false;
		for(int i=0;i<len-1;i++)
		{
			if(a[i]>a[i+1])
			{
				swap(a[i], a[i + 1]);
				flag = true;
			}
		}
		len--;
	}
}

// 直接插入排序
void Insertsort(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j + 1] < a[j])
				swap(a[j], a[j + 1]);
		}
	}
}

// 希尔排序(分组插入排序，增量为d，d=1是直接插入排序)
void Shellsort(int a[], int n) {
	int i, j, gap;

	for (gap = n / 2; gap > 0; gap /= 2)
	{
		//for (i = 0; i < gap; i++)
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (a[j + gap] < a[j])
					swap(a[j + gap], a[j]);
			}
		}
	}
}

// 直接选择排序
void Selectsort(int a[], int n) {
	int i, j;
	for (i = 0; i < n; i++)
	{
		int minIndex = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[minIndex])
			{
				minIndex = j;
			}
		}
		swap(a[i], a[minIndex]);
	}
}

void MySelectSort(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i; j < n-1; j++)
		{
			if (a[j + 1] < a[minIndex])
			{
				minIndex = j + 1;
			}
		}
		swap(a[i],a[minIndex]);
	}
}

// 归并排序(分治法)

// 将有序数组a[first...mid]和a[mid...last]合并
void MergeArray(int a[], int first, int mid, int last, int tmp[])
{
	int i = first, n = mid;
	int j = mid + 1, m = last;
	int k = 0;

	while (i <= n&&j <= m)
	{
		if (a[i] < a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}

	while (i <= n)
	{
		tmp[k++] = a[i++];
	}

	while (j <= m)
		tmp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = tmp[i];
}

// 先递归地分解数列，再合并数列完成归并排序
void MergesortSection(int a[], int first, int last, int tmp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergesortSection(a, first, mid, tmp);  // 左边有序
		MergesortSection(a, mid + 1, last, tmp); // 右边有序
		MergeArray(a, first, mid, last, tmp); // 合并两个有序序列
	}
}

void Mergesort(int a[], int n)
{
	int *p = new int[n];
	if (p == NULL)
		return;
	MergesortSection(a, 0, n - 1, p);
	delete[] p;
}

// 快速排序

// 找中枢（挖坑填数）
int Partition(int a[], int left, int right)
{
	int flag = a[left];
	while (left < right)
	{
		while (a[right] >= flag&&left < right)
			right--;
		if (left < right)
		{
			a[left] = a[right];
			left++;
		}

		while (a[left] < flag&&left < right)
			left++;
		if (left < right)
		{
			a[right] = a[left];
			right--;
		}
	}
	a[left] = flag;
	return left;
}

void QuicksortSection(int a[], int left, int right)
{
	if (left < right)
	{
		int i = Partition(a, left, right);
		QuicksortSection(a, left, i - 1);
		QuicksortSection(a, i + 1, right);
	}
}

void Quicksort(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	QuicksortSection(a, left, right);
}

// 堆排序

// 新加入节点i  其父节点为(i-1)/2
void MinHeapFixUp(int a[], int i)
{
	for (int j = (i - 1) / 2; a[i] > a[j] && i != 0 && j >= 0; i = j, j = (i - 1) / 2)
		swap(a[i], a[j]);
}

// 插入节点，只能在最小堆的末尾插入
void MinHeapAddNumber(int a[], int n, int nNum)
{
	a[n] = nNum;
	MinHeapFixUp(a, n);
}

// 删除节点i  调整堆  只能删除最小堆的堆顶元素，将最后一个元素a[n]放在堆顶，进行调整
void MinHeapFixDown(int a[], int i, int n)
{
	int j, tmp;
	tmp = a[i];
	j = 2 * i + 1;  // 左儿子
	while (j < n)
	{
		if (j + 1 < n&&a[j + 1] < a[j]) // 在左儿子和右儿子中找最小
			j++;

		if (a[j] >= tmp)
			break;

		swap(a[j], a[i]);
		i = j;
		j = 2 * i + 1;
	}
	a[i] = tmp;
}

void MinHeapDeleteNumber(int a[], int n)
{
	swap(a[0], a[n - 1]);
	MinHeapFixDown(a, 0, n - 1);
}

// 建立最小堆，数组画成堆后，叶子节点已经是合法的堆了，只要从最后一个叶子（即数组的最后一个元素）的双亲节点，向下调整就好
void MakeMinHeap(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		MinHeapFixDown(a, i, n);
}

// 堆排序，对于小顶堆，我们只能从删除堆顶元素开始
// 对于堆用数组表示，我们将堆顶元素a[0]与a[n-1]交换， a[1]与a[n-2]交换...
// 相当于删除堆顶元素，所以向下调整堆
// 结果小顶堆对应的是从大到小的排序，若要从小到大，需要对结果逆序（或者用大顶堆）
void Minheapsort(int a[], int n)
{
	MakeMinHeap(a, 5);
	for (int i = n - 1; i >= 1; i--)
	{
		swap(a[i], a[0]);
		MinHeapFixDown(a, 0, i);
	}
}




//快速排序

//三数取中
int GetMid(int* arr, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (arr[left] <= arr[right])
	{
		if (arr[mid] < arr[left])
		{
			return left;
		}
		else if (arr[mid] > arr[right])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
	else
	{
		if (arr[mid] < arr[right])
		{
			return right;
		}
		else if (arr[mid] > arr[left])
		{
			return left;
		}
		else
		{
			return mid;
		}
	}

}
//左右指针法
int PartSort1(int* arr, int left, int right)
{

	int key;
	int start = left;
	int mid = GetMid(arr, left, right);
	swap(arr[mid], arr[left]);
	key = arr[left];
	while (left < right)
	{
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		swap(arr[left], arr[right]);
	}
	swap(arr[left], arr[start]);
	return left;
}

//挖坑法
int PartSort2(int* arr, int left, int right)
{
	int mid = GetMid(arr, left, right);
	swap(arr[left], arr[mid]);
	int key = arr[left];

	while (left < right)
	{
		while (left < right && arr[left] >= key)
		{
			right--;
		}
		arr[left] = arr[right];
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[right] = arr[left];
	}

	arr[left] = key;
	return left;
}

//前后指针法
int PartSort3(int* arr, int left, int right)
{
	int mid = GetMid(arr, left, right);
	swap(arr[left], arr[mid]);
	int key = arr[left];
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (arr[cur] < key && (++prev) != cur)
		{
			swap(arr[prev], arr[cur]);
		}
		++cur;
	}
	swap(arr[left], arr[prev]);
	return prev;
}
//void QuickSort(int* arr, int left, int right)
//{
//	int mid = 0;
//	if (left >= right)
//		return;
//	//小区间优化
//	if ((right - left) <= 5)
//	{
//		InsertSort(arr, right - left + 1);
//	}
//	mid = PartSort3(arr, left, right);
//	QuickSort(arr, left, mid - 1);
//	QuickSort(arr, mid + 1, right);
//}






size_t Pation1(int *arr, int left, int right)
{
	size_t begin = left;
	size_t end = right-1;
	int key = arr[end];

	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		while (begin < end && arr[end] >= key)
			end--;
		if (begin < end)
			swap(arr[begin], arr[end]);
	}
	if (begin != right - 1)// 1 2 4 5 6
		swap(arr[begin], arr[right - 1]);
	return begin;
}
void MyyQuickSort(int *arr, int left, int right)
{
	if (left < right)
	{
		size_t div = Pation1(arr, left, right);
		MyyQuickSort(arr, left, div);
		MyyQuickSort(arr, div + 1, right);
	}
}

//挖坑法
void f(int a[], int left, int right)
{
	int x = a[left], i = left, j = right;
	if (i >= j)
	{
		return;
	}
	while (i<j)
	{
		while (i<j&&a[j] >= x)
			j--;
		a[i] = a[j];
		while (i<j&&a[i] <= x)
			i++;
		a[j] = a[i];
	}
	a[i] = x;
	f(a, left, i - 1);
	f(a, i + 1, right);
}


/*挖坑法（从小到大排）
取左边值为基准
从右向左找比基准小的填到左边挖掉的那个空
从左向右找比基准大的填到右边挖掉的那个空
如上操作，直到左右相遇，将基准值填入左边值
分别对左右再进行如上操作
大佬介绍的很明白：
https://blog.csdn.net/morewindows/article/details/6684558
*/
bool MyQsort(int a[], int left, int right)
{
	if (left >= right)
	{
		return 0;
	}

	int nowvalue = a[left];
	int leftIndex = left;
	int rightIndex = right;
	while (leftIndex < rightIndex)
	{
		while (leftIndex < rightIndex && a[rightIndex] >= nowvalue)
			rightIndex--;
		a[leftIndex] = a[rightIndex];
		while (leftIndex < rightIndex && a[leftIndex] <= nowvalue)
			leftIndex++;
		a[rightIndex] = a[leftIndex];
	}
	a[leftIndex] = nowvalue;
	MyQsort(a, left, leftIndex-1);
	MyQsort(a, rightIndex+1,right);
	return 1;
}

int main()
{
	cout << max(2, 3.6) << endl;
	int a[] = { 5,3,4,1,2,7,6,3 };
	MyQsort(a, 0, 7);
	//f(a, 0, 7);
	//MyyQuickSort(a, 0, 5);
	//PartSort1(a, 0, 4);
	//MyBubbleSort(a,5);
	//MySelectSort(a, 5);
	//BubbleSort(a, 5);
	//Insertsort(a, 5);
	//Shellsort(a, 5);
	//Selectsort(a, 5);
	//Mergesort(a, 5);
	//Quicksort(a, 5);
	//Minheapsort(a, 5);

	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << ",";
	}
	system("pause");
	return 0;
}

