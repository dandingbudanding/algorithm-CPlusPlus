#include<iostream>
#include<queue>

using namespace std;

struct Node
{
	int val;
	int index;
};

void GetMax(int *numSequence, int len, int *result, int k)
{
	Node *que = new Node[len];
	int head = 0;
	int end = 0;

	for (int i = 0; i<len; i++)
	{
		Node tmp;
		tmp.val = numSequence[i];
		tmp.index = i;

		while (end != 0 && que[end].val <= numSequence[i])
			--end;
		++end;
		que[end] = tmp;

		while (end != 0 && que[head].index<i - k + 1)
			++head;
		result[i] = que[head].val;
	}
	delete[]que;
}

int main()
{
	int len, k;
	cout << "请输入队列长度:";
	cin >>  len;
	cout << "请输入窗口大小:";
	cin >> k;

	int *numSequence = new int[len];
	int *maxResult = new int[len];

	cout << "请输入队列元素:";
	for (int i = 0; i<len; i++)
		cin >> numSequence[i];

	GetMax(numSequence, len, maxResult, k);

	for (int i = k - 1; i<len; i++)
		cout << i << ": " << maxResult[i] << endl;

	delete[]numSequence;
	delete[]maxResult;
	numSequence = NULL;
	maxResult = NULL;

	return 0;
}