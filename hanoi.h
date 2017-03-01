/**
 * CPE-TP7 : Récusivité
 *
 * @file hanoi.c
 * @brief      Useful tools to resolve hanoi tower
 * @author     Nathanaël SPRIET, Caroline ASSAF
 * @date       01/03/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "log.h"

#ifndef HANOI_H
#define HANOI_H
#define MAX_ARRAY_LENGTH 255

/*
***************************** Structures *************************
*/

/**
 * @brief      A type defined over the hanoiTower structure
 */
typedef struct hanoiTower HanoiTower;

/**
 * @brief      Represents a chained list of hanoiTower
 */
struct hanoiTower
{
	int array[MAX_ARRAY_LENGTH];/*!< The array containing discs*/
	int index;/*!< The current index of tower*/
	int towerNumber;/*!< The number Id of tower */
};


/*
***************************** Static variables *************************
*/
static HanoiTower source;
static HanoiTower intermediate;
static HanoiTower target;
static int totalDiscNumber;

/*
***************************** Functions *************************
*/

/**
 * @brief      Resolves a hanoi puzzle with a given discs number
 *
 * @param[in]  discsNumber  The discs number
 */
void resolveHanoi(int discsNumber);

/**
 * @brief      Recursively moves a disc from a tower to another
 *
 * @param[in]  discsNumber  The discs number
 * @param      from         The source tower
 * @param      to           The destination tower
 * @param      auxiliary    The auxiliary tower
 */
void moveDisc(int discsNumber, HanoiTower* from, HanoiTower* to, HanoiTower* auxiliary);

/**
 * @brief      Prints the whole puzzle
 */
void printPuzzle();

#endif
