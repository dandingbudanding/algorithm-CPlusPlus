#include<iostream>
#include<vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
	if (k <= 1) return 0;

	long p = 1l;
	int i = 0, total = 0;
	for (int j = 0; j < nums.size(); j++) {
		p *= nums[j];
		while (p >= k) {
			p /= nums[i];
			i++;
		}
		total += (j - i + 1);
	}

	return total;
}

int main()
{
	vector<int> nums; nums.clear();
	int k = 5;
	int a[3] = { 1,3,4};
	for(int i=0;i<k;i++)
	{
		nums.push_back(a[i]);
	}
	int result=numSubarrayProductLessThanK(nums, k);
	cout << result << endl;
	system("pause");
	return 1;
}