#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
char board[];
 void display_board(){
	printf("%c | %c | %c\n",board[0],board[1],board[2] );
	printf("%c | %c | %c\n",board[3],board[4],board[5] );
	printf("%c | %c | %c\n",board[6],board[7],board[8] );
}
 char* getUserInput(){
	char* list = malloc(sizeof(char) *3);
	char c = getchar();
	int count = 0;
	while(c != '\n'){
		if(count < 3){
			list[count++] = c;
		}
		
		c = getchar();

	}

	for(int i = 0; i <count;i++ ){
		if(isdigit(list[i]) == 0){
			free(list);
			return NULL;

		}

	}
	//convert string to int 
	int num = atoi(list);

	if(num < 1 || num > 9){
		free(list);
		return NULL;

	}else{
		if(board[num-1] == 'x' || board[num-1] == 'o'){
			free(list);
			return NULL;

		}
	}
	
	
	return list;

}
 int getInput(char player){
	printf("%c enter a number (1-9)\n",player);
	char* final = getUserInput();
	while(final == NULL){
		system("clear");
		display_board();
		printf("Invalid input try again\n");
		printf("%c enter a number (1-9)\n",player);
		final = getUserInput();

	}

	
	int num = atoi(final);
	free(final);
	
	


	if(player == 'x'){
		board[num-1] = 'x';





	}else if(player == 'o'){
		board[num-1] = 'o';

	}else{
		printf("Invalid input\n");
	}
	return num;


}
 int drawGame(){
	if((board[0] == 'x' || board[0] == 'o') && (board[1] == 'x' || board[1] == 'o') && (board[2] == 'x' || board[2] == 'o') && (board[3] == 'x' || board[3] == 'o') && (board[4] == 'x' || board[4] == 'o') && (board[5] == 'x' || board[5] == 'o') && (board[6] == 'x' || board[6] == 'o') && (board[7] == 'x' || board[7] == 'o') && (board[8] == 'x' || board[8] == 'o')){
		return -1;
	}
	return 0;
}
 int checkWinner(){
	//return 1- x won
	//return 2- o won
	//return 0- if game is still going on
	//return -1- if the game is a draw

	//x- moves
	//line accross
	if(board[0] == 'x' && board[1] == 'x' && board[2] == 'x'){
		return 1;
	}else if(board[3] == 'x' && board[4] == 'x' && board[5] == 'x'){
		return 1;

	}else if(board[6] == 'x' && board[7] == 'x' && board[8] == 'x'){
		return 1;
	}
	//line diagonal
	else if(board[0] == 'x' && board[4] == 'x' && board[8] == 'x'){
		return 1;
	}else if(board[2] == 'x' && board[4] == 'x' && board[6] == 'x'){
		return 1;

	}
	//line down
	else if(board[0] == 'x' && board[3] == 'x' && board[6] == 'x'){
		return 1;
	}else if(board[1] == 'x' && board[4] == 'x' && board[7] == 'x'){
		return 1;
	}else if(board[2] == 'x' && board[5] == 'x' && board[8] == 'x'){
		return 1;

	}

	//o- moves
	//line accross
	if(board[0] == 'o' && board[1] == 'o' && board[2] == 'o'){
		return 2;
	}else if(board[3] == 'o' && board[4] == 'o' && board[5] == 'o'){
		return 2;

	}else if(board[6] == 'o' && board[7] == 'o' && board[8] == 'o'){
		return 2;
	}
	//line diagonal
	else if(board[0] == 'o' && board[4] == 'o' && board[8] == 'o'){
		return 2;
	}else if(board[2] == 'o' && board[4] == 'o' && board[6] == 'o'){
		return 2;

	}
	//line down
	else if(board[0] == 'o' && board[3] == 'o' && board[6] == 'o'){
		return 2;
	}else if(board[1] == 'o' && board[4] == 'o' && board[7] == 'o'){
		return 2;
	}else if(board[2] == 'o' && board[5] == 'o' && board[8] == 'o'){
		return 2;

	}
	return drawGame();

}
 extern void game(){
	system("clear");
	while(1){

		display_board();
		getInput('x');
		
		if(checkWinner() == 1){
			system("clear");
			display_board();
			printf("X won\n");
			break;
		}else if(checkWinner() == -1){
			system("clear");
			display_board();
			printf("Game is a Draw :/\n");
			break;

		}else{
			
			system("clear");
		}
		display_board();
		getInput('o');
		
		if(checkWinner() == 2){
			system("clear");
			display_board();
			printf("O won\n");
			break;

		}else if(checkWinner() == -1){
			system("clear");
			display_board();
			printf("Game is a Draw :/\n");
			break;


		}else{
			system("clear");
		}

	}

}