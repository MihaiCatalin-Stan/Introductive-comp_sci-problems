// 315CA_StanMihaiCatalin
#include <stdio.h>

void citire_matrice(int n, long long v[1000][1000])
{
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < n ; j++)
			scanf("%lld", &v[i][j]);
}

int mutare_alb(int n, int x_c, int y_c, long long v[1000][1000], long long *d)
{
	int y_temp = y_c;
	if (v[x_c][y_c] > 0) {
		*d += v[x_c][y_c];
		while (v[x_c][y_c] > n)
			v[x_c][y_c] -= n;
		if (y_c + v[x_c][y_c] < n)
			y_c += v[x_c][y_c];
		else
			y_c = y_c + v[x_c][y_c] - n;
	} else {
		*d -= v[x_c][y_c];
		while (-v[x_c][y_c] > n)
			v[x_c][y_c] += n;
		if (y_c + v[x_c][y_c] >= 0)
			y_c += v[x_c][y_c];
		else
			y_c = n + v[x_c][y_c] + y_c;
	}
	v[x_c][y_temp] = 0;
	return y_c;
}

int mutare_negru(int n, int x_c, int y_c, long long v[1000][1000], long long *d)
{
	int x_temp = x_c;
	if (v[x_c][y_c] > 0) {
		*d += v[x_c][y_c];
		while (v[x_c][y_c] > n)
			v[x_c][y_c] -= n;
		if (x_c + v[x_c][y_c] < n)
			x_c += v[x_c][y_c];
		else
			x_c = x_c + v[x_c][y_c] - n;
	} else {
		*d -= v[x_c][y_c];
		while (-v[x_c][y_c] > n)
			v[x_c][y_c] += n;
		if (x_c + v[x_c][y_c] >= 0)
			x_c += v[x_c][y_c];
		else
			x_c = n + v[x_c][y_c] + x_c;
	}
	v[x_temp][y_c] = 0;
	return x_c;
}

void indexare_coloane(int y_curent)
{
	int c = 0;
	if (y_curent % 26)
		c = y_curent % 26;
	if (y_curent >= 26) {
		y_curent /= 26;
		indexare_coloane(y_curent - 1);
	}
	printf("%c", c + 'A');
}

int main(void)
{
	long long v[1000][1000] = {}, d = 0;
	int n, x_c = 0, y_c = 0;
	scanf("%d", &n);
	citire_matrice(n, v);
	do {
		if ((x_c + y_c) % 2 == 0)
			y_c = mutare_alb(n, x_c, y_c, v, &d);
		else
			x_c = mutare_negru(n, x_c, y_c, v, &d);
	} while (v[x_c][y_c]);
	printf("%lld\n", d);
	printf("%d ", n - x_c);
	indexare_coloane(y_c);
	printf("\n");
	return 0;
}
