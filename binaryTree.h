/**
 * CPE-TP7 : Récusivité
 *
 * @file binaryTree.c
 * @brief      Useful tools to browse binary trees
 * @author     Nathanaël SPRIET, Caroline ASSAF
 * @date       01/03/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "log.h"

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

/*
***************************** Structures *************************
*/

/**
 * @brief      A type defined over the node structure
 */
typedef struct node Node;

/**
 * @brief      Represents node of binary tree
 */
struct node
{
	int value;/*!< The value of the node*/
	Node* left;/*!< The left neighbour of the node*/
	Node* right;/*!< The right neighbour of the node*/
};

/*
***************************** Functions *************************
*/

void insertValueInTree(Node** root, int value);

void browseLRR(Node* root);

void browseRLR(Node* root);

void remove(Node** root, int value);

void fill(Node** root, const char* fileName);
#endif
