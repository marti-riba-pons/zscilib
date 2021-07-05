/*
 * Copyright (c) 2019-2020 Kevin Townsend (KTOWN)
 * Copyright (c) 2021 Marti Riba Pons
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * \defgroup STATISTICS Statistics
 *
 * @brief Statistics-related functions.
 */

/**
 * @file
 * @brief API header file for statistics in zscilib.
 *
 * This file contains the zscilib statistics APIs
 */

#ifndef ZEPHYR_INCLUDE_ZSL_STATISTICS_H_
#define ZEPHYR_INCLUDE_ZSL_STATISTICS_H_

#include <zsl/zsl.h>
#include <zsl/vectors.h>
#include <zsl/matrices.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Computes the arithmetic mean of a vector.
 *
 * @param v  The vector to use.
 * @param m  The arithmetic mean of the components of v.
 *
 * @return int
 */
int zsl_sta_mean(struct zsl_vec *v, zsl_real_t *m);

/**
 * @brief Computes the given percentile of a vector.
 *
 * @param v    The input vector.
 * @param p    The percentile to be calculated.
 * @param val  The output value.
 *
 * @return int
 */
int zsl_sta_percentile(struct zsl_vec *v, size_t p, zsl_real_t *val);

/**
 * @brief Computes the median of a vector.
 *
 * @param v  The vector to use.
 * @param m  The median of the components of v.
 *
 * @return int
 */
int zsl_sta_median(struct zsl_vec *v, zsl_real_t *m);

/**
 * @brief Calculates the first, second and third quartiles of a vector v.
 *
 * @param v   The vector to use.
 * @param q1  The first quartile of v.
 * @param q1  The second quartile of v, also the median of v.
 * @param q1  The third quartile of v.
 *
 * @return int
 */
int zsl_sta_quart(struct zsl_vec *v, zsl_real_t *q1, zsl_real_t *q2,
		  zsl_real_t *q3);

/**
 * @brief Calculates the numeric difference between the third and the first
 *        quartiles of a vector v.
 *
 * @param v  The input vector.
 * @param r  The interquartile range of v.
 *
 * @return int
 */
int zsl_sta_quart_range(struct zsl_vec *v, zsl_real_t *r);

/**
 * @brief Computes the mode or modes of a vector v.
 *
 * @param v  The vector to use.
 * @param w  Output vector whose components are the modes. If there is only
 *           one mode, the length of w will be 1.
 *
 * @return int
 */
int zsl_sta_mode(struct zsl_vec *v, struct zsl_vec *w);

/**
 * @brief Computes the difference between the greatest value and the lowest in
 *        a vector v.
 *
 * @param v The vector to use.
 * @param r The range of the data in v.
 *
 * @return int
 */
int zsl_sta_data_range(struct zsl_vec *v, zsl_real_t *r);

/**
 * @brief Computes the variance of a vector v.
 *
 * @param v     The vector to use.
 * @param var   The variance of v.
 *
 * @return int
 */
int zsl_sta_var(struct zsl_vec *v, zsl_real_t *var);

/**
 * @brief Computes the standard deviation of a vector v.
 *
 * @param v  The vector to use.
 * @param s  The output standard deviation of the vector v.
 *
 * @return int
 */
int zsl_sta_sta_dev(struct zsl_vec *v, zsl_real_t *s);

/**
 * @brief Computes the variance of two sets of data: v and w.
 *
 * @param v  First set of data.
 * @param w  Second set of data.
 * @param c  Covariance of the vectors v and w.
 *
 * @return int
 */
int zsl_sta_covar(struct zsl_vec *v, struct zsl_vec *w, zsl_real_t *c);

/**
 * @brief Calculates the nxn covariance matrix of a set of n vectors of the
 *        same length.
 *
 * @param m   Input matrix, whose columns are the different data sets.
 * @param mc  Output nxn covariance matrix.
 *
 * @return int
 */
int zsl_sta_covar_mtx(struct zsl_mtx *m, struct zsl_mtx *mc);

/**
 * @brief Calculates the slope, intercept and correlation coefficient of the
 *        linear regression of two vectors.
 *
 * @param v   The first input vector.
 * @param w   The second input vector.
 * @param a   The slope of the linear regression.
 * @param b   The intercept of the linear regression.
 * @param r   The correlation coefficient of the linear regression.
 *
 * @return int
 */
int zsl_sta_linear_reg(struct zsl_vec *v, struct zsl_vec *w, zsl_real_t *a,
		       zsl_real_t *b, zsl_real_t *r);


#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_ZSL_STATISTICS_H_ */

/** @} */ /* End of statistics group */
