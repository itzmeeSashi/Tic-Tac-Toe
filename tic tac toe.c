#include <stdio.h>
#define SIZE 3
int CW(char board[SIZE][SIZE], char player) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }
    for (j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    
    return 0;
}

int main() {
    char board[SIZE][SIZE];
    int i, j, row, col,index,count=0;
    char currentPlayer = 'X';
    int moves = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '_';
        }
    }
    while (moves < SIZE * SIZE) {
        printf("Player %c,enter your box number: ", currentPlayer);
        scanf("%d", &index);
        for(i=0;i<1;i++){
        if(index%3==0){
        	col=2;
        	row=(index/3)-1;
		}else{
			col=(index%3)- 1;
			row=index/3;
		}}
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '_') {
            board[row][col] = currentPlayer;
            moves=moves+1;
            
            if (CW(board, currentPlayer)) {
                for (i = 0; i < SIZE; i++) {
             for (j = 0; j < SIZE; j++){ 
            printf("%c ",board[i][j]);
            count++;
            if(count%3==0)
            printf("\n");
            }}printf("Player %c won\n", currentPlayer);
                break;
            }
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }for (i = 0; i < SIZE; i++) {
             for (j = 0; j < SIZE; j++){ 
            printf("%c ",board[i][j]);
            count++;
            if(count%3==0)
            printf("\n");
        } }} else {
            printf("Invalid,try again \n");
        }
    }
    if (moves == SIZE * SIZE)
        printf("tie....\n");
}
