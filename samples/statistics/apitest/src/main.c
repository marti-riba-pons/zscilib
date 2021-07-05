/*
 * Copyright (c) 2021 Marti Riba Pons
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>
#include <zsl/zsl.h>
#include <zsl/statistics.h>

void main(void)
{
	printk("TODO: statistics api demo\n\n");

	//int rc = zsl_sta_test();
	//printk("Results: %d\n", rc);

	while (1) {
		k_sleep(K_FOREVER);
	}
}
