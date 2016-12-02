/*
 * =====================================================================================
 *
 *       Filename:  spiral_array.c
 *
 *    Description:  Print 2D array in spiral order.
 *
 *        Version:  1.0
 *        Created:  12/01/2016 08:07:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Kurup (), prakashkurup7@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Directions for spiral traversal */
typedef enum {
	RIGHT = 1, DOWN, LEFT, UP

} Directions;

/* Functions to print 2D array in spiral order */
void printSpiral(int size, int arr[][size])
{
	/* Variables for denoting rows and columns */
	int top, bottom, left, right;
	top = 0; 		// top row
	bottom = size - 1; 	// bottom row
	left = 0; 		// left column
	right = size - 1;	// right column

	int row, col;
	/* Start from right direction */
	Directions dir = RIGHT;

	while (top <= bottom || left <= right) {
		switch(dir) {
			/* Print row in right direction */
			case RIGHT:
				row = top;
				for (col = left; col <= right; col++) {
					printf("%d ", arr[row][col]);
				}
				top++; // Increment so not to print the same row
				dir = DOWN;
				break;
			
			/* Print column in downward direction */
			case DOWN:
				col = right;
				for (row = top; row <= bottom; row++) {
					printf("%d ", arr[row][col]);
				}
				right--; // Decrement so not to print the same column
				dir = LEFT;
				break;
			
			/* Print row in left direction */
			case LEFT:
				row = bottom;
				for (col = right; col >= left; col--) {
					printf("%d ", arr[row][col]);
				}
				bottom--;
				dir = UP;
				break;

			/* Print column in upward direction */
			case UP:
				col = left;
				for (row = bottom; row >= top; row--) {
					printf("%d ", arr[row][col]);
				}
				left++;
				dir = RIGHT;
				break;				
		}
	}
	
	
}

int main(void)
{
	int arr[][3] = 
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int i, j, N = 3;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printSpiral(N, arr);

	return 0;
}
