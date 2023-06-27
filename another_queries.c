// 315CA_StanMihaiCatalin
#include <stdio.h>

void citire_tabla(int n, int v[400][400])
{
	for (int i = 0 ; i < n * n ; i++)
		for (int j = 0 ; j < n * n ; j++)
			scanf("%d", &v[i][j]);
}

int op1(int n, int v[400][400], int x, int afisare)
{
	int fr[401] = {};
	for (int k = 1 ; k <= n * n ; k++) {
		int ok = 1;
		for (int i = 0 ; i < n * n ; i++)
			if (v[x - 1][i] == k) {
				ok = 0;
				fr[k]++;
			}
		if (ok && afisare)
			printf("1 ");
		else if (!ok && afisare)
			printf("0 ");
		if (fr[k] >= 2 && !afisare)
			return 1;
	}
	return 0;
}

int op2(int n, int v[400][400], int y, int afisare)
{
	int fr[401] = {};
	for (int k = 1 ; k <= n * n ; k++) {
		int ok = 1;
		for (int i = 0 ; i < n * n ; i++)
			if (v[i][y - 1] == k) {
				ok = 0;
				fr[k]++;
			}
		if (ok && afisare)
			printf("1 ");
		else if (!ok && afisare)
			printf("0 ");
		if (fr[k] >= 2 && !afisare)
			return 1;
	}
	return 0;
}

int op3(int n, int v[400][400], int z, int afisare)
{
	int fr[401] = {};
	for (int k = 1 ; k <= n * n ; k++) {
		int ok = 1;
		for (int i = (z - 1) / n * n ; i < (z - 1) / n * n + n ; i++)
			for (int j = (z - 1) % n * n ; j < (z - 1) % n * n + n ; j++)
				if (v[i][j] == k) {
					ok = 0;
					fr[k]++;
				}
		if (ok && afisare)
			printf("1 ");
		else if (!ok && afisare)
			printf("0 ");
		if (fr[k] >= 2 && !afisare)
			return 1;
	}
	return 0;
}

int afla_cadran(int n, int x, int y)
{
	for (int z = 1 ; z <= n * n ; z++)
		if (x >= (z - 1) / n * n && x < (z - 1) / n * n + n)
			if (y >= (z - 1) % n * n && y < (z - 1) % n * n + n)
				return z;
	return -1;
}

void op4(int n, int v[400][400], int x, int y)
{
	int z = afla_cadran(n, x - 1, y - 1);
	for (int k = 1 ; k <= n * n ; k++) {
		int ok = 1;
		for (int i = 0 ; i < n * n ; i++)
			if (v[x - 1][i] == k || v[i][y - 1] == k || v[x - 1][y - 1]) {
				ok = 0;
				break;
			}
		for (int i = (z - 1) / n * n ; i < (z - 1) / n * n + n ; i++)
			for (int j = (z - 1) % n * n ; j < (z - 1) % n * n + n ; j++)
				if (v[i][j] == k) {
					ok = 0;
					break;
				}
		if (ok)
			printf("1 ");
		else
			printf("0 ");
		}
}

void op5(int v[400][400], int x, int y, int k)
{
	if (!v[x - 1][y - 1])
		v[x - 1][y - 1] = k;
}

int op6(int n, int v[400][400])
{
	for (int i = 1 ; i <= n * n ; i++)
		if (op1(n, v, i, 0) || op2(n, v, i, 0) || op3(n, v, i, 0))
			return 1;
	for (int i = 0 ; i < n * n ; i++)
		for (int j = 0 ; j < n * n ; j++)
			if (v[i][j] == 0)
				return 0;
	return 2;
}

int main(void)
{
	int n, m, v[400][400] = {};
	scanf("%d%d", &n, &m);
	citire_tabla(n, v);
	for (int i = 1 ; i <= m ; i++) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x;
			scanf("%d", &x);
			op1(n, v, x, 1);
			printf("\n");
		}
		if (op == 2) {
			int y;
			scanf("%d", &y);
			op2(n, v, y, 1);
			printf("\n");
		}
		if (op == 3) {
			int z;
			scanf("%d", &z);
			op3(n, v, z, 1);
			printf("\n");
		}
		if (op == 4) {
			int x, y;
			scanf("%d%d", &x, &y);
			op4(n, v, x, y);
			printf("\n");
		}
		if (op == 5)	{
			int k, x, y;
			scanf("%d%d%d", &x, &y, &k);
			op5(v, x, y, k);
		}
		if (op == 6)
			printf("%d\n", op6(n, v));
	}
	return 0;
}
