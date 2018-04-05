#include <fstream> 
//#include <stdio.h> 
//#include <stdlib.h> 

using namespace std;
ifstream cin("inversions.in");
ofstream cout("inversions.out");

void ms(int *a, int s1, int s2, int n) // сортировка слиянием 
{
	if (s1 == s2) return;
	int m = (s1 + s2) / 2;
	ms(a, s1, m, n);
	ms(a, m + 1, s2, n);
	int k1 = s1;
	int k2 = m + 1;
	int *t = new int[s2 - s1 + 1];
	for (int i = 0; i<(s2 - s1 + 1); i++)
	{
		if (((a[k1] <= a[k2]) && (k1 <= m)) || (k2>s2))
		{
			t[i] = a[k1];
			k1++;
		}
		else
		{
			t[i] = a[k2];
			k2++;

		}
	}
	for (int i = 0; i<(s2 - s1 + 1); i++)
	{
		a[s1 + i] = t[i];
	}
	delete[] t;
}


int main()
{
	int i, n, k;
	cin >> n;
	int *s = new int[n];
	for (i = 0; i<n; i++)
	{
		cin >> s[i];
	}
	ms(s, 0, n - 1, n);
// вывод будет здесь
	delete[] s;

	return 0;
}