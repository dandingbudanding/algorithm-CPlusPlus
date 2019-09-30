#include<iostream>
#include<algorithm>

using namespace std;

struct node {
	long long x, y;
};

node a[100000];
long long X[100001], Y[100001];
long long xadd[100001], xradd[100001], yadd[100001], yradd[100001];

int main() {
	long long n, w, t;
	long long xmin, xmax, ymin, ymax;
	scanf("%lld", &n);

	xmin = ymin = 100000;
	xmax = ymax = 0;
	for (long long i = 0; i<n; ++i) {
		scanf("%lld%lld%lld", &a[i].x, &a[i].y, &w);
		X[a[i].x] += w;
		Y[a[i].y] += w;
		xmin = min(xmin, a[i].x);
		xmax = max(xmax, a[i].x);
		ymin = min(ymin, a[i].y);
		ymax = max(ymax, a[i].y);
	}

	t = X[xmin];
	for (long long i = xmin + 1; i <= xmax; ++i) {
		xadd[i] = xadd[i - 1] + t;
		t += X[i];
	}

	t = X[xmax];
	for (long long i = xmax - 1; i >= xmin; --i) {
		xradd[i] = xradd[i + 1] + t;
		t += X[i];
	}

	t = Y[ymin];
	for (long long i = ymin + 1; i <= ymax; ++i) {
		yadd[i] = yadd[i - 1] + t;
		t += Y[i];
	}

	t = Y[ymax];
	for (long long i = ymax - 1; i >= ymin; --i) {
		yradd[i] = yradd[i + 1] + t;
		t += Y[i];
	}

	long long ans = 0;
	for (long long i = 0; i<n; ++i) {
		long long px = a[i].x;
		long long py = a[i].y;
		if (i == 0)
			ans = xadd[px] + xradd[px] + yadd[py] + yradd[py];
		else
			ans = min(ans, xadd[px] + xradd[px] + yadd[py] + yradd[py]);
	}

	cout << ans;

}