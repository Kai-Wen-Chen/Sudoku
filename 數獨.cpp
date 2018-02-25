#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int x, y, sudoku[9][9];
    bool chk[27],error;
    while ( cin >> sudoku[0][0] >> sudoku[1][0] >> sudoku[2][0]
                 >> sudoku[3][0] >> sudoku[4][0] >> sudoku[5][0]
                 >> sudoku[6][0] >> sudoku[7][0] >> sudoku[8][0] ) {

	    for(y=1;y<9;y++) {
	    	for(x=0;x<9;x++)
	    		cin>>sudoku[x][y];
		}
		
	    for(y=0, error=false; y<9 && !error; y++) {
	    	memset(chk, false, 27); //fill "false" in chk[0] ~ chk[26] 
	    	
			for(x=0; x<9; x++) {
		    	error = chk[9*0 + sudoku[x][y] - 1] ||
		    				chk[9*1 + sudoku[y][x] - 1] ||
		    				chk[9*2 + sudoku[x%3 + y%3*3][x/3 + y/3*3] -1];
		    	if(error) break;
				
		    	chk[9*0 + sudoku[x][y] - 1] = true;
		    	chk[9*1 + sudoku[y][x] - 1] = true;
		    	chk[9*2 + sudoku[x%3 + y%3*3][x/3 + y/3*3] -1] = true;
			}
		}
		
		if(error) cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
    return 0;
}