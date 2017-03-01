/**
 * CPE-TP7 : Récusivité
 *
 * @file file.c
 * @brief      Tools to read binary tree from file
 * @author     Nathanaël SPRIET, Caroline ASSAF
 * @date       01/03/2017
 */

#include "file.h"

int readFromFile(int** resArray, const char* filename)
{
	FILE *treeFile = fopen(filename, "r");
	if (treeFile == NULL)
	{
	    log_error("Error opening file!\n");
	    exit(1);
	}
	int valueFound = 0;
	size_t length = 0;
	ssize_t read;
	int numberOfLines = 0;
	// Read the file line by line
	while((fscanf(treeFile,"%d",&valueFound)) != EOF)
	{
		numberOfLines++;
	}
	rewind(treeFile);
	*resArray = malloc(numberOfLines*sizeof(int));
	int resArrayIndex = 0;
	while((fscanf(treeFile,"%d",&valueFound)) != EOF)
	{
		(*resArray)[resArrayIndex++] = valueFound;
	}
	fclose(treeFile);
	return numberOfLines;
}
