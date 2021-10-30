/*
 * littlefs_operations.c
 *
 *  Created on: Oct 30, 2021
 *      Author: onurkaraman
 */

#include "littlefs_operations.h"

const struct lfs_config cfg = {
    // block device operations
    .read  = bd_read,
    .prog  = bd_prog,
    .erase = bd_erase,
    .sync  = bd_sync,

    // block device configuration
    .read_size = 128,
    .prog_size = 128,
    .block_size = 4096,
    .block_count = 128,
    .cache_size = 128,
    .lookahead_size = 16,
    .block_cycles = 500,
};

void littlefs_write(void)
{
	uint8_t writeBuff[] = "LittleFs on STM32F7";

	int err = lfs_mount(&lfs, &cfg);

	  if (err)
	  {
	      lfs_format(&lfs, &cfg);
	      lfs_mount(&lfs, &cfg);
	  }

	  lfs_file_open(&lfs, &file, "sample", LFS_O_RDWR | LFS_O_CREAT);
	  lfs_file_rewind(&lfs, &file);
	  lfs_file_write(&lfs, &file, &writeBuff, sizeof(writeBuff));
	  lfs_file_close(&lfs, &file);

	  lfs_unmount(&lfs);
}

void littlefs_read(void)
{
	int err = lfs_mount(&lfs, &cfg);

	  if (err)
	  {
	      lfs_format(&lfs, &cfg);
	      lfs_mount(&lfs, &cfg);
	  }

	lfs_file_open(&lfs, &file, "sample", LFS_O_RDONLY);
	lfs_file_read(&lfs, &file, &readBuff, sizeof(readBuff));
	lfs_file_close(&lfs, &file);

	lfs_unmount(&lfs);
}

void littlefs_erase(void)
{
	lfs_mount(&lfs, &cfg);
	lfs_remove(&lfs, "sample");
	lfs_unmount(&lfs);
}
