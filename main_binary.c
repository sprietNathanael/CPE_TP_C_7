/**
 * CPE-TP7 : Récursivité
 *
 * @file main_binary.c
 * @brief      Implement browses of binary trees
 * @author     Nathanaël SPRIET, Caroline ASSAF
 * @date       01/03/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "binaryTree.h"

int main()
{
	log_error("This is a error log\n");
	log_info("This is a info log\n");
	log_valid("This is a valid log\n");
	log_debug("This is a debug log\n");
	log_false("This is a false log\n");
	log_warning("This is a warning log\n");
	printf("\n\n");
	Node* tree = malloc(sizeof(Node));
	tree->value = 15;
	tree->left = NULL;
	tree->right = NULL;
	insertValueInTree(&tree, 10);
	insertValueInTree(&tree, 25);
	insertValueInTree(&tree, 33);
	insertValueInTree(&tree, 5);
	insertValueInTree(&tree, 1);
	insertValueInTree(&tree, 20);
	insertValueInTree(&tree, 12);
	insertValueInTree(&tree, 11);
	insertValueInTree(&tree, 6);
	insertValueInTree(&tree, 17);
	insertValueInTree(&tree, 22);
	insertValueInTree(&tree, 13);
	log_info("PreOrder : [");
	browsePreOrder(tree);
	log_info("]\n");

	log_info("Symetrical : [");
	browseSymetrical(tree);
	log_info("]\n");

	log_info("PostOrder : [");
	browsePostOrder(tree);
	log_info("]\n");

	removeValue(1,&tree);

	log_info("PreOrder : [");
	browsePreOrder(tree);
	log_info("]\n");

	removeValue(13,&tree);

	log_info("PreOrder : [");
	browsePreOrder(tree);
	log_info("]\n");

	removeValue(25,&tree);

	log_info("PreOrder : [");
	browsePreOrder(tree);
	log_info("]\n");

	removeValue(15,&tree);

	log_info("PreOrder : [");
	browsePreOrder(tree);
	log_info("]\n");

	freeTree(tree);

	return 0;
}
