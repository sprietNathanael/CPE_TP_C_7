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

/**
 * @brief      Recursively insert a value in a binary tree
 *
 * @param      root   The tree root
 * @param[in]  value  The value to insert
 */
void insertValueInTree(Node** root, int value);

/**
 * @brief      Recursively browse a binary tree in post order
 *
 * @param      root  The tree root
 */
void browsePostOrder(Node* root);

/**
 * @brief      Recursively browse a binary tree in symetrical
 *
 * @param      root  The tree root
 */
void browseSymetrical(Node* root);

/**
 * @brief      Recursively browse a binary tree in pre order
 *
 * @param      root  The tree root
 */
void browsePreOrder(Node* root);

/**
 * @brief      Removes a value from the binary tree.
 *
 * @param[in]  value  The value
 * @param      root   The tree root
 */
void removeValue(int value, Node** root);

void fillTree(Node** root, const char* fileName);

/**
 * @brief      Recusrsively free the tree
 *
 * @param      root  The tree oot
 */
void freeTree(Node* root);

/**
 * @brief      Recusrsively replace the root value from a sub tree with its left
 *             branch maximum
 *
 * @param[in]  value  The value to remove
 * @param      root   The sub-tree root
 *
 * @return     The maximum value
 */
int supmax(int value, Node** root);
#endif
