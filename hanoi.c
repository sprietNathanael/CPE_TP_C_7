/**
 * CPE-TP7 : Récusivité
 *
 * @file hanoi.c
 * @brief      Useful tools to resolve hanoi tower
 * @author     Nathanaël SPRIET, Caroline ASSAF
 * @date       01/03/2017
 */

#include "hanoi.h"

void resolveHanoi(int discsNumber)
{
	int i = 0;
	// Fill the source array
	log_info("Tour de départ : [");
	for(i = 0; i < discsNumber; i++)
	{
		source.array[i] = i+1;
		log_info(" %d ",source.array[i]);
	}
	log_info("]\n");
	totalDiscNumber = discsNumber;
	printPuzzle();
	// Initializes the towers indexes
	source.index = i-1;
	target.index = -1;
	intermediate.index = -1;
	// Gives numbers to identify towers
	source.towerNumber = 1;
	intermediate.towerNumber = 2;
	target.towerNumber = 3;
	// Call the recursive function
	moveDisc(discsNumber, &source,&target,&intermediate);
	// Print the target tower
	log_info("Tour d'arrivée : [");
	for(i = 0; i < discsNumber; i++)
	{
		log_info(" %d ",target.array[i]);
	}
	log_info("]\n");
	printPuzzle();

}

void moveDisc(int discsNumber, HanoiTower* from, HanoiTower* to, HanoiTower* auxiliary)
{
	if(discsNumber > 0)
	{
		// Move discs number - 1 from "from" to "auxiliary"
		moveDisc(discsNumber-1, from, auxiliary, to);

		// Move last disc of "from" to "to"
		to->array[++to->index] = from->array[from->index];
		log_info("Move disc %d from %d [%d] to %d [%d]\n",from->array[from->index],from->towerNumber, from->index,to->towerNumber, to->index);
		from->array[from->index] = 0;
		printPuzzle();
		from->index--;

		// Move the discs from "auxiliary" to "to"
		moveDisc(discsNumber-1, auxiliary, to, from);
	}
}

void printPuzzle()
{
	log_info("\n\n");
	log_info(" |  |  |\n");
	int i = totalDiscNumber;
	for(i = totalDiscNumber; i >= 0; i--)
	{
		log_info(" %d  %d  %d\n",source.array[i],intermediate.array[i],target.array[i]);
	}
	log_info("---------\n\n");
}
