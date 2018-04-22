#include <iostream>

// worked on with Jon Swiatowski

    int sudoku[9][9] = {{0, 3, 0, 0, 0, 0, 0, 2, 0},
           	 {0, 9, 0, 0, 0, 0, 0, 8, 5},
           	 {5, 0, 0, 0, 8, 0, 4, 0, 0},
            	 {4, 0, 7, 2, 0, 6, 8, 9, 0},
            	 {0, 1, 0, 8, 0, 9, 0, 4, 0},
            	 {0, 8, 9, 5, 0, 1, 3, 0, 2},
           	 {0, 0, 3, 0, 1, 0, 0, 0, 9},
           	 {9, 4, 0, 0, 0, 0, 0, 1, 0},
           	 {0, 7, 0, 0, 0, 0, 0, 3, 0}
    };

    bool containsInRow(int row,int number) {
        for(int i=0;i<9;i++) {
            if(sudoku[row][i]==number) {
                return true;
            }
        }
        return false;
    }

    bool containsInCol(int col,int number) {
        for(int i=0;i<9;i++) {
            if(sudoku[i][col]==number) {
                return true;
            }
        }
        return false;
    }


    bool containsInBox(int row, int col,int number) {
        int r = row - row%3;
        int c = col - col%3;
        for(int i = r ; i< r+3 ; i++) {
            for(int j = c; j < c+3 ; j++) {
                if(sudoku[i][j]==number) {
                    return true;
                }
            }

        }
        return false;
    }

    bool isAllowed(int row, int col,int number) {
        return !(containsInRow(row, number) || containsInCol(col, number) || containsInBox(row, col, number));
    }

     bool solveSudoku() {
        for(int row=0;row<9;row++) {
            for(int col=0;col<9;col++) {
                if(sudoku[row][col]==0) {
                    for(int number=1;number<=9;number++) {
                        if(isAllowed(row, col, number)) {
                            sudoku[row][col] = number;
                            if(solveSudoku()) {
                                return true;
                            }
                            else {
                                sudoku[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

void print(){
    //print the sudoku plate
    for(int i=0;i<9; i++){
    	for(int j=0; j<9; j++){
    		printf("%2d",sudoku[i][j]);
    	}
    	printf("\n");
    }
    return;
}



int main(int argc, char** argv) {

	if(solveSudoku()) {
		print();
	}
}
