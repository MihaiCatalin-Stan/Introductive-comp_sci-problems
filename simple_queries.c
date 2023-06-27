// 315CA_StanMihaiCatalin
#include <stdio.h>
#include <math.h>

void fractie(long long n, int i)
{
	for (int j = i ; j >= 2 ; j--)
		if (i % j == 0 && n % j == 0) {
			n /= j;
			i /= j;
		}
	printf("%d/%lld\n", i, n);
}

int alerta(long long n, int fr[26])
{
	for (int i = 0 ; i < 26 ; i++)
		if (n % 2 == 0 && fr[i] >= n / 2) {
			printf("%c ", i + 'a');
			fractie(n, fr[i]);
			return 1;
		} else if (n % 2 == 1 && fr[i] >= n / 2 + 1) {
			printf("%c ", i + 'a');
			fractie(n, fr[i]);
			return 1;
		}
	return 0;
}

int diversitate(int fr[26])
{
	int ok = 0;
	for (int i = 0 ; i < 26 ; i++) {
		if (fr[i])
			ok++;
		if (ok == 2)
			return 1;
	}
	return 0;
}

void importante(int fr[26], int K)
{
	int max = 0, indice_max = 0, afisate[26] = {};
	for (int i = 0 ; i < K ; i++) {
		for (int j = 0 ; j < 26 ; j++)
			if (fr[j] > max && afisate[j] == 0) {
				max = fr[j];
				indice_max = j;
			} else if (fr[j] == max && afisate[indice_max] == 1) {
				max = fr[j];
				indice_max = j;
			}
		printf("%c", indice_max + 'a');
		if (i < K - 1)
			printf(" ");
		afisate[indice_max] = 1;
		max = 0;
		indice_max = 0;
	}
	printf("\n");
}

int main(void)
{
	int fr[26] = {}, counter = 0, K;
	long long n = 0;
	char c, L;
	do {
		scanf(" %c", &c);
		if (c == 'Q') {
			scanf(" %c", &L);
			printf("%c %d\n", L, fr[L - 'a']);
		} else if (c == 'T') {
			scanf("%d", &K);
			importante(fr, K);
		} else if (c == 'E') {
			scanf(" %c", &L);
			n -= fr[L - 'a'];
			fr[L - 'a'] = 0;
		} else {
			n++;
			counter++;
			fr[c - 'a']++;
			if (counter >= 5 && diversitate(fr)) {
				if (alerta(n, fr))
					counter = 0;
			}
		}
	} while ((c >= 'a' && c <= 'z') || c == 'Q' || c == 'T' || c == 'E');
	return 0;
}
