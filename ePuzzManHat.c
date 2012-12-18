#include<stdio.h>

static int UP = 1;
static int DOWN = 2;
static int RIGHT = 3;
static int LEFT = 4;


int goalMat[3][3] = {{1, 2, 3}, { 4,5, 6 }, { 7, 8, 0 }};
//int intialMat[3][3];
   
int misplacedTiles(int first[3][3], int second[3][3]) {
  
  int count = 0;
  int i,j;
  for ( i = 0; i < 3; i++) {
    for ( j = 0; j < 3; j++) {
      
      if (first[i][j] != second[i][j]) {
	count++;
      }
    }
  }
  return count;
}


//swap Right and check the misplaced tiles...
int swapRIGHT(int matrixr[3][3]) {
  
  // finding the blank space
  int i,j;
  for ( i = 0; i < 3; i++) {
    for ( j = 0; j < 3; j++) {

      if (matrixr[i][j] == 0) {
	// System.out.print("\n 0 found at location i= " + i +
	// "  j= "
	// + j + "\n");
	// if blank space is at the rightmost position
	if (j == 2) {
	  // do nothing
	} else {
	  // swap the blank
	  matrixr[i][j] = matrixr[i][j + 1];
	  
	  matrixr[i][j + 1] = 0;
	  break;
	}
      }
    }
  }
  printMatix(matrixr);
  return misplacedTiles(matrixr,goalMat);
  
}

int swapLEFT(int matrix[3][3]) {
  int i,j;
  // finding the blank space
  for ( i = 0; i < 3; i++) {
    for ( j = 0; j < 3; j++) {
      
      if (matrix[i][j] == 0) {
	// if blank space is at the leftmost position
	if (j == 0) {
	  // do nothing
	} else {
	  // swap the blank to the left
	  matrix[i][j] = matrix[i][j - 1];
	  matrix[i][j - 1] = 0;
	}
      }
    }
  }
  printMatix(matrix);
  return misplacedTiles(matrix,goalMat);
  
}

int swapUP(int matrix[3][3]) {
  int i,j;
  // finding the blank space
  for ( i = 0; i < 3; i++) {
    for ( j = 0; j < 3; j++) {
      
      if (matrix[i][j] == 0) {
	// if blank space is at the upmost position
	if (i == 0) {
	  // do nothing
	} else {
	  // swap the blank to the up
	  matrix[i][j] = matrix[i - 1][j];
	  matrix[i - 1][j] = 0;
	}
      }
    }
  }
  printMatix(matrix);
  return misplacedTiles(matrix,goalMat);
}

int swapDOWN(int matrix[3][3]) {
  // finding the blank space
  int j,i;
  printMatix(matrix);
  for ( j = 0; j < 3; j++) {
    for ( i = 0; i < 3; i++) {
      
      if (matrix[i][j] == 0) {
	// System.out.print("\n 0 found at location i= " + i +
	// "  j= "
	// + j + "\n");
	// if blank space is at the downmost position
	if (i == 2) {
	  // do nothing
	} else {
	  // swap the blank to the down
	  matrix[i][j] = matrix[i + 1][j];
	  matrix[i + 1][j] = 0;
	  break;
	}
      }
      // break;
    }
  }
  printMatix(matrix);
  return misplacedTiles(matrix,goalMat);
}

// OR Alternatively we can do this... :)
/*
 * public static void swapDOWN(int matrix[][]) { // finding the blank space
 * for (int i = 0; i < 3; i++) { for (int j = 0; j < 3; j++) {
 * 
 * if (matrix[j][i] == 0) { System.out.print("\n 0 found at location i= " +
 * i + "  j= " + j + "\n"); // if blank space is at the downmost position if
 * (j == 2) { // do nothing } else { // swap the blank to the down
 * matrix[j][i] = matrix[j + 1][i]; matrix[j + 1][i] = 0; break; } } //
 * break; } } }
 */
// ***************************************************************************

void printMatix(int first[3][3]) {
  
  int count = 0;
  int i,j;
  // System.out.println();
  for ( i = 0; i < 3; i++) {
    for ( j = 0; j < 3; j++) {
      printf("%d",first[i][j]);
      printf("\t");
    }
    printf("\n");
  }
  printf("\n===================\n\n");
}
    
    
/*
  calculateDirection(intialMat,depth);
	
  while (intialMat != goalMat) {
		    
  DIRECTIONS d = calculateDirection(intialMat, depth);
  System.out.print("\nrection found is: "+d);
  switch (d) {
  case UP:
  swapUP(intialMat);
  break;
  case DOWN:
  swapDOWN(intialMat);
  break;
  case RIGHT:
  swapRIGHT(intialMat);
  break;
  case LEFT:
  swapLEFT(intialMat);
  break;
				
  }
  depth++;
  System.out.print("\ndepth measured: " + depth + "\n");
  break;
  // printMatix(intialMat);
			
  }*/

//System.out.print("hello well done.\n");
//	printMatix(intialMat);
		
//}
/*  
int calculateDirection(int matrixxx[3][3], int depth) {
	    
  // int[][] presentMat = new int[2][2];
  int tempTotal[4];
   		
  //left direction <--
  tempTotal[0] = swapLEFT(matrixxx) + depth;
  //	System.out
  //		.print("\nFor LEFT direction \nTotal Misplaced Tiles Distance count= "
  //				+ tempTotal[0]);
  //printMatix(swapLEFT(matrixxx));
  //	printMatix((matrixxx));
  //right direction
  //printMatix(swapRIGHT(matrixxx));
  tempTotal[1] = swapRIGHT(matrixxx) + depth;
  //	System.out
  //		.print("\nFor RIGHT direction \nTotal Misplaced Tiles Distance count= "
  //				+ tempTotal[1]);
  //up direction
  //	printMatix(swapUP(matrixxx));
  tempTotal[2] = swapUP(matrixxx) + depth;
  //System.out
  //		.print("\nFor UP direction \nTotal Misplaced Tiles Distance count= "
  //				+ tempTotal[2]);
  //down direction
  //	printMatix(swapDOWN(matrixxx));
  tempTotal[3] = swapDOWN(matrixxx) + depth;
  //	System.out
  //		.print("\nFor DOWN direction \nTotal Misplaced Tiles Distance count= "
  //				+ tempTotal[3]);
		
   
  // if (tempTotal < misplacedTiles(presentMat, goalMat) + depth) {
  // tempTotal = misplacedTiles(presentMat, goalMat) + depth;
  // }
  /*		
		for (int i = 0; i < 3; i++) {
			
		if (tempTotal[0] < tempTotal[1]) {
		temp = RIGHT;
		} else {
		temp = DIRECTIONS.LEFT;
		tempTotal[0] = tempTotal[1];
		}
			
		if (tempTotal[0] < tempTotal[2]) {
		// do nothing since functional value of right and left is small
		// than up direction
		} else {
		tempTotal[0] = tempTotal[2];
		temp = DIRECTIONS.UP;
				
		}
			
			
   //}
  //printing the function value calculated
  //System.out.println("left: "+tempTotal[0]+"\nright: "+tempTotal[1]+"\nup: "+tempTotal[2]+"\ndown: "+tempTotal[3]);
  //System.out.println("\nDirection Selected is " + temp);
  return 1;
}
*/
void main() {
  int depth =0;
  int temp[3];
  int intialMat[3][3] =  { { 1, 2, 3 }, { 4, 0, 6 }, { 7, 5, 8 } };
  
  printf("\n the function value on right: %d\n",swapRIGHT(intialMat));
  //  printMatix(intialMat);
	 printf("\nwhen left...: %d\n",swapLEFT(intialMat));
  
  
}

