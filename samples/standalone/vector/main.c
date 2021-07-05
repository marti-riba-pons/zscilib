/*
 * Copyright (c) 2019-2020 Kevin Townsend (KTOWN)
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "zsl/matrices.h"
#include "zsl/vectors.h"
#include "zsl/statistics.h"

int
main(void)
{
	ZSL_VECTOR_DEF(va, 10);
	ZSL_VECTOR_DEF(vb, 10);
	ZSL_VECTOR_DEF(vc, 10);
	ZSL_VECTOR_DEF(vd, 10);
	ZSL_VECTOR_DEF(ve, 15);
	ZSL_VECTOR_DEF(vf, 15);

	ZSL_MATRIX_DEF(ma, 4, 3);
	ZSL_MATRIX_DEF(mb, 3, 3);


	printf("Hello, zscilib!\n");

	zsl_real_t a[10] = { -1.0, -1.0, 0.0, 1.0, 1.0, -1.0, 1.0, -1.0, 0.0, 1.0 };
	zsl_real_t d[10] = { -4.0, -7.0, 3.0, 2.0, 8.0, -9.0, 9.0, -1.0, 0.0, 5.0 };
	zsl_real_t e[15] = { 1.47, 1.50, 1.52, 1.55, 1.57, 1.60, 1.63, 1.65, 1.68, 1.70, 1.73, 1.75, 1.78, 1.80, 1.83 };
	zsl_real_t f[15] = { 52.21, 53.12, 54.48, 55.84, 57.20, 58.57, 59.93, 61.29, 63.11, 64.47, 66.28, 68.10, 69.92, 72.19, 74.46 };
	zsl_real_t g[12] = { -1.0, -6.5, 1.2,
						  7.0, 5.5, 0.0, 
						 -0.5, 4.0, 6.5,
						 -1.0, 4.0, -8.5 };

	zsl_real_t q1, q2, q3, r, vala, valb;

	/* Assign arrays to vectors. */
	zsl_vec_from_arr(&va, a);
	zsl_vec_init(&vb);
	zsl_vec_print(&va);
	printf("\n");
	zsl_vec_sort(&va, &vb);
	zsl_vec_print(&vb);
	printf("\n");
	zsl_vec_from_arr(&vd, d);
	printf("\n");
	zsl_vec_from_arr(&ve, e);
	printf("\n");
	zsl_vec_from_arr(&vf, f);
	printf("\n");
	zsl_mtx_from_arr(&ma, g);
	printf("\n");

	/* Add va and vb, results in vc. */
	zsl_sta_quart(&va, &q1, &q2, &q3);
	printf("The quartiles are: %f   %f   %f\n", q1, q2, q3);
	zsl_sta_quart_range(&va, &r);
	printf("The interquartile range is: %f\n", r);
	zsl_sta_percentile(&va, 25, &q1);
	printf("The first quartile is: %f\n", q1);
	zsl_sta_percentile(&va, 50, &q2);
	printf("The second quartile (median) is: %f\n", q2);
	zsl_sta_percentile(&va, 75, &q3);
	printf("The third quartile is: %f\n", q3);
	zsl_sta_mode(&va, &vc);
	printf("The mode is: ");
	zsl_vec_print(&vc);
	zsl_sta_data_range(&va, &r);
	printf("The data range is: %f\n", r);
	zsl_sta_var(&va, &r);
	printf("The variance is: %f\n", r);
	zsl_sta_covar(&va, &vd, &r);
	printf("The covariance is: %f\n", r);
	zsl_sta_linear_reg(&ve, &vf, &vala, &valb, &r);
	printf("The value a is: %.16f\n", vala);
	printf("The value b is: %.16f\n", valb);
	printf("The value r is: %.16f\n", r);
	zsl_sta_covar_mtx(&ma, &mb);
	zsl_mtx_print(&mb);

	return 0;
}
