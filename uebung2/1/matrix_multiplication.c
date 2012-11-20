/**
 * Matrix Multiplikation
 * "What Every Programmer Should Know About Memory"
 * 6.2 Cache Access (page 49)
 *
 * AUTHOR: Richard Fussenegger
 * AUTHOR: Markus Deutschl
 */

#include <stdio.h>
#include <sys/time.h>
#include <emmintrin.h>

#define N 1000
#define SM (CLS / sizeof (double))

int i, i2, j, j2, k, k2;
double res[N][N] __attribute__ ((aligned (64)));
double mul1[N][N] __attribute__ ((aligned (64)));
double mul2[N][N] __attribute__ ((aligned (64)));
double tmp[N][N] __attribute__ ((aligned (64)));
double *restrict rres;
double *restrict rmul1;
double *restrict rmul2;

void original() {
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			for (k = 0; k < N; ++k)
				res[i][j] += mul1[i][k] * mul2[k][j];
}

void transposed() {
        for (i = 0; i < N; ++i)
                for (j = 0; j < N; ++j)
                        tmp[i][j] = mul2[j][i];
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			for (k = 0; k < N; ++k)
				res[i][j] += mul1[i][k] * tmp[j][k];
}

void sub_matrix() {
	for (i = 0; i < N; i += SM)
		for (j = 0; j < N; j += SM)
			for (k = 0; k < N; k += SM)
				for (i2 = 0, rres = &res[i][j], rmul1 = &mul1[i][k]; i2 < SM; ++i2, rres += N, rmul1 += N)
					for (k2 = 0, rmul2 = &mul2[k][j]; k2 < SM; ++k2, rmul2 += N)
						for (j2 = 0; j2 < SM; ++j2)
							rres[j2] += rmul1[k2] * rmul2[j2];
}

void vectorized() {
	for (i = 0; i < N; i += SM)
		for (j = 0; j < N; j += SM)
			for (k = 0; k < N; k += SM)
				for (i2 = 0, rres = &res[i][j], rmul1 = &mul1[i][k]; i2 < SM; ++i2, rres += N, rmul1 += N) {
					_mm_prefetch (&rmul1[8], _MM_HINT_NTA);
					for (k2 = 0, rmul2 = &mul2[k][j]; k2 < SM; ++k2, rmul2 += N) {
						__m128d m1d = _mm_load_sd (&rmul1[k2]);
						m1d = _mm_unpacklo_pd (m1d, m1d);
						for (j2 = 0; j2 < SM; j2 += 2) {
							__m128d m2 = _mm_load_pd (&rmul2[j2]);
							__m128d r2 = _mm_load_pd (&rres[j2]);
							_mm_store_pd (&rres[j2], _mm_add_pd (_mm_mul_pd (m2, m1d), r2));
						}
					}
				}
}

long long benchmark(struct timeval start, struct timeval end) {
	return (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
}

double cross_mul(long long original, long long improved) {
	return ((double) improved / (double) original) * 100;
}

int main() {
	struct timeval start1;
	struct timeval start2;
	struct timeval start3;
	struct timeval start4;
	struct timeval end1;
	struct timeval end2;
	struct timeval end3;
	struct timeval end4;
	long long elapsed1;
	long long elapsed2;
	long long elapsed3;
	long long elapsed4;
	double cross_mul2;
	double cross_mul3;
	double cross_mul4;

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j) {
			mul1[i][j] = 0.0;
			mul2[i][j] = 0.0;
		}

	gettimeofday(&start1, 0);
	original();
	gettimeofday(&end1, 0);

	gettimeofday(&start2, 0);
	transposed();
	gettimeofday(&end2, 0);

	gettimeofday(&start3, 0);
	sub_matrix();
	gettimeofday(&end3, 0);

	gettimeofday(&start4, 0);
	vectorized();
	gettimeofday(&end4, 0);

	elapsed1 = benchmark(start1, end1);
	printf("Original: %lld ms\n", elapsed1);

	elapsed2 = benchmark(start2, end2);
	printf("Transposed: %lld ms\n", elapsed2);

	elapsed3 = benchmark(start3, end3);
	printf("Sub-Matrix: %lld ms\n", elapsed3);

	elapsed4 = benchmark(start4, end4);
	printf("Vectorized: %lld ms\n", elapsed4);

	cross_mul2 = cross_mul(elapsed1, elapsed2);
	printf("Transposed needs %.2f%% of time of Original.\n", cross_mul2);

	cross_mul3 = cross_mul(elapsed1, elapsed3);
	printf("Sub-Matrix needs %.2f%% of time of Original.\n", cross_mul3);

	cross_mul4 = cross_mul(elapsed1, elapsed4);
	printf("Vectorized needs %.2f%% of time of Original.\n", cross_mul4);

	return 0;
}
