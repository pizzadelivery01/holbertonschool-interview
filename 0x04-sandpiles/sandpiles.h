#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_grid(int grid[3][3]);
void add_grids(int grid1[3][3], int grid2[3][3]);
int stable_check(int grid[3][3]);
void toppling(int grid1[3][3]);

#endif
