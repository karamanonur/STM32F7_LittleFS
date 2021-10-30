/*
 * bd_operations.c
 *
 *  Created on: Oct 30, 2021
 *      Author: onurkaraman
 */

#include "bd_operations.h"

int bd_read(const struct lfs_config *c, lfs_block_t block,
	lfs_off_t off, void *buffer, lfs_size_t size)
{
	BSP_QSPI_Read((uint8_t*)buffer, (uint32_t)(block * c->block_size + off), (uint32_t)size);
	return 0;
}

int bd_prog(const struct lfs_config *c, lfs_block_t block,
	lfs_off_t off, const void *buffer, lfs_size_t size)
{
	BSP_QSPI_Write((uint8_t*)buffer, (uint32_t)(block * c->block_size + off), (uint32_t)size);
	return 0;
}

int bd_erase(const struct lfs_config *c, lfs_block_t block)
{
	BSP_QSPI_Erase_Block(block * c->block_size);

	return 0;
}

int bd_sync(const struct lfs_config *c)
{
	return 0;
}


