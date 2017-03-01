/**
 * CPE-TP7 : Récusivité
 *
 * @file file.h
 * @brief      Tools to read binary tree from file
 * @author     Nathanaël SPRIET, Caroline ASSAF
 * @date       01/03/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "log.h"

#ifndef FILE_H
#define FILE_H

/**
 * @brief         Reads a binary tree from file.
 *
 * @param[in,out] resArray  The result array
 * @param[in]     fileName  The file name
 *
 * @return        The length of the result array
 */
int readFromFile(int** resArray, const char* fileName);

#endif
