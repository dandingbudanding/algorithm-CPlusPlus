# include <iostream>
# include<string>
# include<algorithm>
using namespace std;


//声明
int Init();
int Manacher();

char str[100];
char s_new[200];
int p[200];

//初始化
int Init()
{
	s_new[0] = '$';
	s_new[1] = '#';
	int j = 2;
	int len = (int)strlen(str);
	for (int i = 0; i < len; i++)
	{
		s_new[j++] = str[i];
		s_new[j++] = '#';
	}
	s_new[j] = '\0';
	return j;
}
//计算p数组
int Manacher()
{
	int len = Init();
	int max_len = -1;
	int id;
	int right = 0;
	for (int i = 1; i < len; i++)
	{
		if (i < right)
		{
			p[i] = min(p[2 * id - i], right - i);
		}
		else
		{
			p[i] = 1;
		}
		while (s_new[i - p[i]] == s_new[i + p[i]])
		{
			p[i]++;
		}
		//cout << p[i] << endl;
		if (i > right)
		{
			right = p[i] + i;
			id = i;
		}
		max_len = max(p[i] - 1, max_len);
	}
	return max_len;
}
//主函数
int main()
{
	cout << "请输入字符串；" << endl;
	cin >> str;
	int max_len = Manacher();
	cout << "最大回文长度：" << max_len << endl;
	return 0;
}