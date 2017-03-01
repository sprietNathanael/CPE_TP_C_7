/**
 * CPE-TP7 : Récusivité
 *
 * @file binaryTree.c
 * @brief      Useful tools to browse binary trees
 * @author     Nathanaël SPRIET, Caroline ASSAF
 * @date       01/03/2017
 */

#include "binaryTree.h"

void insertValueInTree(Node** root, int value)
{
	if(*root == NULL)
	{
		*root = malloc(sizeof(Node));
		(*root)->value = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
	{
		if(value < (*root)->value)
		{
			insertValueInTree(&(*root)->left, value);
		}
		else
		{
			insertValueInTree(&(*root)->right, value);
		}
	}
}

void browsePostOrder(Node* root)
{
	if(root != NULL)
	{
		browsePostOrder(root->left);
		browsePostOrder(root->right);
		log_info(" %d ",root->value);
	}
}

void browsePreOrder(Node* root)
{
	if(root != NULL)
	{
		log_info(" %d ",root->value);
		browsePreOrder(root->left);
		browsePreOrder(root->right);
	}
}

void browseSymetrical(Node* root)
{
	if(root != NULL)
	{
		browseSymetrical(root->left);
		log_info(" %d ",root->value);
		browseSymetrical(root->right);
	}
}

void freeTree(Node* root)
{
	if(root != NULL)
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

void removeValue(int value, Node** root)
{
	if(*root == NULL)
	{
		log_error("Valeur %d non trouvée !\n",value);
	}
	else
	{
		// If the value is smaller than the current node value
		if(value < (*root)->value)
		{
			removeValue(value, &((*root)->left));
		}
		else
		{
			// If the value is greater than the current node value
			if(value > (*root)->value)
			{
				removeValue(value, &((*root)->right));
			}
			// If the value is found
			else
			{
				// If there is no left value, replace the current node by its right neighbour
				if((*root)->left == NULL)
				{
					free(*root);
					*root = (*root)->right;
				}
				else
				{
					// If there is no right value but a left value
					if((*root)->right == NULL)
					{
						free(*root);
						*root = (*root)->left;
					}
					// If there is a value on both sides
					else
					{
						(*root)->value = supmax(value, &((*root)->left));
					}

				}
			}
		}
	}
}

int supmax(int value, Node** root)
{
	int max = 0;
	if((*root)->right != NULL)
	{
		supmax(value,&((*root)->right));
	}
	else
	{
		max = (*root)->value;
		free(*root);
		*root = (*root)->left;
		return max;
	}
}

void fillTree(Node** root, const char* filename)
{
	int* array;
	int arrayLength;
	arrayLength = readFromFile(&array, filename);
	*root = malloc(sizeof(Node));
	(*root)->value = array[0];
	(*root)->left = NULL;
	(*root)->right = NULL;
	int i =1;
	for(i = 1; i < arrayLength; i++)
	{
		insertValueInTree(root, array[i]);
	}

}
