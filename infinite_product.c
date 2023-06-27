// 315CA_StanMihaiCatalin
#include <stdio.h>
#include <math.h>

long long baza10(long long a)
{
	long long b = 0, t = 1;
	while (a) {
		b = b + (a % 10) * t;
		t *= 8;
		a /= 10;
	}
	return b;
}

int main(void)
{
	unsigned long long n, a, b, ps = 0, a_max, b_max;
	double n_a = 0, n_b = 0;
	long long a_max2 = -1, b_max2 = -1;
	scanf("%llu", &n);
	if (n) {
		scanf("%llu%llu", &a, &b);
		a = baza10(a);
		b = baza10(b);
		a_max = a;
		b_max = b;
		ps = ps + a * b;
		n_a = n_a + (a * a);
		n_b = n_b + (b * b);
		for (unsigned int i = 0 ; i < n - 1 ; i++) {
			scanf("%llu%llu", &a, &b);
			a = baza10(a);
			b = baza10(b);
			if (a > a_max) {
				a_max2 = a_max;
				a_max = a;
			} else if ((unsigned int)a > a_max2 && a != a_max) {
				a_max2 = a;
			}
			if (b > b_max) {
				b_max2 = b_max;
				b_max = b;
			} else if ((unsigned int)b > b_max2 && b != b_max) {
				b_max2 = b;
			}
			ps = ps + (a * b);
			n_a = n_a + (a * a);
			n_b = n_b + (b * b);
		}
	}
	printf("%llu\n", ps);
	printf("%lld %lld\n", a_max2, b_max2);
	printf("%0.7f %0.7f\n", sqrt(n_a), sqrt(n_b));
	return 0;
}
