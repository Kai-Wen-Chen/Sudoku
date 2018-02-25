#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool Check(int[]);

int main() {
	int sudoku[9][9];
	int row[9], col[9], m[9];
	int i, j, k;
	bool result = true;
	
	while (true) {
		for (i=0; i<9; i++) {
			for (j=0; j<9; j++) {
				scanf("%d", &sudoku[i][j]);
			}
		}
		
		for (i=0; i<9; i++) {
			for (j=0; j<9; j++) {
				row[j] = sudoku[i][j]; //pick one row
				col[j] = sudoku[j][i]; //pick one column
			}
			
			if (!Check(row)) { //check rows
				result = false;
			}
			if (!Check(col)) { //check columns
				result = false;
			}
		}
		
		if (!result) {
			printf("no\n");
			continue;
		}
		
		/*--------check #----------------------------------*/
		k = 0;
		for (i=0; i<3; i++) { 
			for (j=0; j<3; j++) m[k++] = sudoku[i][j]; 
		}
		if (!Check(m)) {
			printf("no\n");
			continue;
		}
		
		k = 0;
		for (i=0; i<3; i++) { 
			for (j=3; j<6; j++) m[k++] = sudoku[i][j]; 
		}
		if (!Check(m)) {
			printf("no\n");
			continue;
		}
		
		k = 0;
		for (i=0; i<3; i++) { 
			for (j=6; j<9; j++) m[k++] = sudoku[i][j]; 
		}
		if (!Check(m)) {
			printf("no\n");
			continue;
		}
		
		k = 0;
		for (i=3; i<6; i++) { 
			for (j=0; j<3; j++) m[k++] = sudoku[i][j]; 
		}
		if (!Check(m)) {
			printf("no\n");
			continue;
		}
		
		k = 0;
		for (i=3; i<6; i++) { 
			for (j=3; j<6; j++) m[k++] = sudoku[i][j]; 
		}
		if (!Check(m)) {
			printf("no\n");
			continue;
		}
		
		k = 0;
		for (i=3; i<6; i++) { 
			for (j=6; j<9; j++) m[k++] = sudoku[i][j]; 
		}
		if (!Check(m)) {
			printf("no\n");
			continue;
		}
		
		k = 0;
		for (i=6; i<9; i++) { 
			for (j=0; j<3; j++) m[k++] = sudoku[i][j]; 
		}
		if (!Check(m)) {
			printf("no\n");
			continue;
		}
		
		k = 0;
		for (i=6; i<9; i++) { 
			for (j=3; j<6; j++) m[k++] = sudoku[i][j]; 
		}
		if (!Check(m)) {
			printf("no\n");
			continue;
		}
		
		k = 0;
		for (i=6; i<9; i++) { 
			for (j=6; j<9; j++) m[k++] = sudoku[i][j]; 
		}
		if (!Check(m)) {
			printf("no\n");
			continue;
		}
	
		printf("yes\n");
	}
}

bool Check(int sudo[]){
	int i=0;
	bool check[9];
	
	for (i=0; i<9; i++) check[i] = false; //initialize check
	for (i=0; i<9; i++) {
	    check[sudo[i]-1] = !check[sudo[i]-1]; //if there's no duplicated number, it'll be all true
	    //printf("%d ", check[sudo[i]-1]);
	}
	for (i=0; i<9; i++) {
		if (!check[i]) return false;
	}
	
	return true;
}