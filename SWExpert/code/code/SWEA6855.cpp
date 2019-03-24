#include<stdio.h>
int n, k, x[100001], gab[100001];

void quick(int left, int right)
{
	int i, j, s, m;
	if (left<right)
	{
		i = left - 1;
		j = right + 1;
		m = gab[(left + right) / 2];
		while (1)
		{
			while (gab[++i]<m);
			while (gab[--j]>m);
			if (i >= j)break;
			s = gab[i];
			gab[i] = gab[j];
			gab[j] = s;
		}
		quick(left, i - 1);
		quick(j + 1, right);
	}
}

int main()
{
	int t, tn, i, dab;
	scanf("%d", &tn);
	for (t = 1; t <= tn; t++)
	{
		scanf("%d %d", &n, &k);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &x[i]);
			if (i != 1)
			{
				gab[i - 1] = x[i] - x[i - 1];
			}
		}
		dab = x[n] - x[1];
		if (k >= n)
		{
			printf("#%d %d\n", t, 0);
			continue;
		}
		quick(1, n - 1);
		for (i = 1; i <= k - 1; i++)
		{
			dab -= gab[n - i];
		}
		printf("#%d %d\n", t, dab);
	}
}