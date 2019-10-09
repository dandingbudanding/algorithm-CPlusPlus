#include <iostream>  
#include <cstdio>  
#include <cstring>  
#define Min(a,b) a>b?b:a  
#define Max(a,b) a>b?a:b  
#define MAXLENGTH 1000
using namespace std;
int Len[MAXLENGTH];
char str[MAXLENGTH], s[MAXLENGTH];
int n, len;

void init() {
	int k = 0;
	str[k++] = '$';
	for (int i = 0; i < len; i++) {
		str[k++] = '#';
		str[k++] = s[i];
	}
	str[k++] = '#';
	len = k;
}

int Manacher() {
	Len[0] = 0;
	int sum = 0;
	int mx = 0;
	int id = 0;
	for (int i = 1; i < len; i++) {
		if (i < mx) Len[i] = Min(mx - i, Len[2 * id - i]);
		else Len[i] = 1;
		while (str[i - Len[i]] == str[i + Len[i]]) Len[i]++;
		if (Len[i] + i > mx) {
			mx = Len[i] + i;
			id = i;
			sum = Max(sum, Len[i]);
		}
	}
	return (sum - 1);
}

int MyMaNaCher(char* str, int len)
{
	int lenarray[MAXLENGTH] = { 0 };
	int sum = 0;
	int mx = 0;
	int id = 0;
	for (int i = 1; i<len; i++)
	{
		lenarray[i] = i < mx ? Min(mx - i, lenarray[2 * id - i]) : 1;
		while (str[i - lenarray[i]] == str[i + lenarray[i]]) lenarray[i]++;
		if (lenarray[i] + i>mx)
		{
			mx = lenarray[i] + i;
			id = i;
			sum = Max(sum, lenarray[i]);
		}
	}
	return (sum - 1);
}

int main()
{
	memset(str, 0, sizeof(str));
	scanf("%s", s);
	len = strlen(s);
	init();
	int aaaa=MyMaNaCher(str, len);
	cout << aaaa << endl;
	int temp = Manacher();
	cout << temp << endl;

	system("pause");
	return 0;
}


