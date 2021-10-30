/*
 * littlefs_operations.h
 *
 *  Created on: Oct 30, 2021
 *      Author: onurkaraman
 */

#ifndef INC_LITTLEFS_OPERATIONS_H_
#define INC_LITTLEFS_OPERATIONS_H_

#include "bd_operations.h"

lfs_t lfs;
lfs_file_t file;

uint8_t readBuff[20];

void littlefs_write(void);
void littlefs_read(void);
void littlefs_erase(void);

#endif /* INC_LITTLEFS_OPERATIONS_H_ */
