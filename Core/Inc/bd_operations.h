/*
 * bd_operations.h
 *
 *  Created on: Oct 30, 2021
 *      Author: onurkaraman
 */

#ifndef INC_BD_OPERATIONS_H_
#define INC_BD_OPERATIONS_H_

#include "lfs.h"
#include "stm32746g_discovery_qspi.h"

int bd_read(const struct lfs_config *c, lfs_block_t block,
					lfs_off_t off, void *buffer, lfs_size_t size);
int bd_prog(const struct lfs_config *c, lfs_block_t block,
					lfs_off_t off, const void *buffer, lfs_size_t size);
int bd_erase(const struct lfs_config *c, lfs_block_t block);
int bd_sync(const struct lfs_config *c);

#endif /* INC_BD_OPERATIONS_H_ */
