#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void flush(){
	char tmp = 0;
	while(tmp != 10){
		scanf("%c",&tmp);
	}
}

short givePlayer(short num){
	return (num / 4) + 1;
}

void moveCsr(short row, short col){ // https://en.wikipedia.org/wiki/ANSI_escape_code
	char code[] = "\e[000;000H";

	code[2] = 48 + (row / 100);
        code[3] = 48 + ((row % 100) / 10);
        code[4] = 48 + (row % 10);

        code[6] = 48 + (col / 100);
        code[7] = 48 + ((col % 100) / 10);
        code[8] = 48 + (col % 10);

        printf("%s",code);
}

void setForColor(int inp){ // inp - https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit
	inp = inp + 30;
	char code[] = "\e[30m";

	code[2] = 48 + (inp / 10);
        code[3] = 48 + (inp % 10);
	
	printf("%s",code);
}

void drawBoard(){
	setForColor(7);
	printf("|===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|\n");
        printf("|                       |   |   |   |                       |\n");
        printf("|   \e[31m|===|===|===|===|   \e[37m|===\e[32m|===|===|   |===|===|===|===|   \e[37m|\n");
        printf("|   \e[31m|   |   |   |   |   \e[37m|   \e[32m|   |   |   |   |   |   |   |   \e[37m|\n");
        printf("|   \e[31m|===|===|===|===|   \e[37m|===\e[32m|===|===|   |===|===|===|===|   \e[37m|\n");
        printf("|   \e[31m|   |   |   |   |   \e[37m|   \e[32m|   |   \e[37m|   \e[32m|   |   |   |   |   \e[37m|\n");
        printf("|   \e[31m|===|===|===|===|   \e[37m|===\e[32m|===|\e[37m===|   \e[32m|===|===|===|===|   \e[37m|\n");
        printf("|   \e[31m|   |   |   |   |   \e[37m|   \e[32m|   |\e[37m   |   \e[32m|   |   |   |   |   \e[37m|\n");
        printf("|   \e[31m|===|===|===|===|   \e[37m|===\e[32m|===|\e[37m===|   \e[32m|===|===|===|===|   \e[37m|\n");
        printf("|   \e[31m|   |   |   |   |   \e[37m|   \e[32m|   |\e[37m   |   \e[32m|   |   |   |   |   \e[37m|\n");
        printf("|   \e[31m|===|===|===|===|   \e[37m|===\e[32m|===|\e[37m===|   \e[32m|===|===|===|===|   \e[37m|\n");
        printf("|                       |   \e[32m|   |   \e[37m|                       |\n");
        printf("|===\e[31m|===|\e[37m===|===|===|===|\e[32m===|===|===\e[37m|===|===|===|===|===|===|\n");
	printf("|   \e[31m|   |\e[37m   |   |   |   \e[31m|\e[37m \\       / \e[33m|\e[37m   |   |   |   |   |   |\n");
        printf("|===\e[31m|===|===|===|===|===|\e[37m   \\===/   \e[33m|===|===|===|===|===|\e[37m===|\n");
        printf("|   \e[31m|   |   |   |   |   |\e[37m   | X |   \e[33m|   |   |   |   |   |\e[37m   |\n");
	printf("|===\e[31m|===|===|===|===|===|\e[37m   /===\\   \e[33m|===|===|===|===|===|\e[37m===|\n");
        printf("|   |   |   |   |   |   \e[31m|\e[37m /       \\ \e[33m|\e[37m   |   |   |   \e[33m|   |\e[37m   |\n");
	printf("|===|===|===|===|===|===|\e[34m===|===|===\e[37m|===|===|===|===\e[33m|===|\e[37m===|\n");
        printf("|                       |   \e[34m|   |\e[37m   |                       |\n");
        printf("|   \e[34m|===|===|===|===|\e[37m   |===\e[34m|===|\e[37m===|   \e[33m|===|===|===|===|\e[37m   |\n");
        printf("|   \e[34m|   |   |   |   |\e[37m   |   \e[34m|   |\e[37m   |   \e[33m|   |   |   |   |\e[37m   |\n");
        printf("|   \e[34m|===|===|===|===|\e[37m   |===\e[34m|===|\e[37m===|   \e[33m|===|===|===|===|\e[37m   |\n");
        printf("|   \e[34m|   |   |   |   |\e[37m   |   \e[34m|   |\e[37m   |   \e[33m|   |   |   |   |\e[37m   |\n");
        printf("|   \e[34m|===|===|===|===|\e[37m   |===\e[34m|===|\e[37m===|   \e[33m|===|===|===|===|\e[37m   |\n");
	printf("|   \e[34m|   |   |   |   |\e[37m   |   \e[34m|   |\e[37m   |   \e[33m|   |   |   |   |\e[37m   |\n");
        printf("|   \e[34m|===|===|===|===|\e[37m   \e[34m|===|===|\e[37m===|   \e[33m|===|===|===|===|\e[37m   |\n");
	printf("|   \e[34m|   |   |   |   |\e[37m   \e[34m|   |   |\e[37m   |   \e[33m|   |   |   |   |\e[37m   |\n");
        printf("|   \e[34m|===|===|===|===|\e[37m   \e[34m|===|===|\e[37m===|   \e[33m|===|===|===|===|\e[37m   |\n");
        printf("|                       |   |   |   |                       |\n");
        printf("|===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|\n");
         
}

void drawDice(char inp){
	moveCsr(3,70);
	printf("|=======|");
	moveCsr(4,70);
	printf("|       |");
	moveCsr(5,70);
	printf("|       |");
	moveCsr(6,70);
        printf("|       |");
	moveCsr(7,70);
	printf("|=======|");


	switch (inp){
		case 1 : moveCsr(5,74);
			 printf("*");
			 break;

		case 2 : moveCsr(5,72);
			 printf("*   *");
			 break;

		case 3 : moveCsr(4,72);
			 printf("*");
			 moveCsr(5,74);
			 printf("*");
			 moveCsr(6,76);
			 printf("*");
			 break;

		case 4 : moveCsr(4,72);
			 printf("*   *");
			 moveCsr(6,72);
			 printf("*   *");
			 break;

		case 5 : moveCsr(4,72);
                         printf("*   *");
			 moveCsr(5,74);
                         printf("*");
                         moveCsr(6,72);
                         printf("*   *");
                         break;

		case 6 : moveCsr(4,72);
                         printf("* * *");
                         moveCsr(6,72);
                         printf("* * *");
                         break;
	}
	moveCsr(33,0);
}

void moveHomeLoc(int piece){
	switch (piece){
		case 0 : moveCsr(4,7);
			 break;
		case 1 : moveCsr(4,19);
                         break;
		case 2 : moveCsr(10,19);
                         break;
		case 3 : moveCsr(10,7);
                         break;
		case 4 : moveCsr(4,43);
                         break;
		case 5 : moveCsr(4,55);
                         break;
		case 6 : moveCsr(10,55);
                         break;
		case 7 : moveCsr(10,43);
                         break;
		case 8 : moveCsr(22,43);
                         break;
		case 9 : moveCsr(22,55);
                         break;
		case 10: moveCsr(28,55);
                         break;
		case 11: moveCsr(28,43);
                         break;
		case 12: moveCsr(22,7);
                         break;
		case 13: moveCsr(22,19);
                         break;
		case 14: moveCsr(28,19);
                         break;
		case 15: moveCsr(28,7);
                         break;
	}
}

short toMainMap(short loc, short player, short piece){
	if(loc > 51 && loc < 57){
	
		switch (player){
			case 1 : loc += 1;
				 break;
			case 2 : loc += 10;
				 break;
			case 3 : loc += 19;
				 break;
			case 4 : loc += 28;
				 break;
		}
		

	}else if(loc == 57){
		switch (player){
			case 1 : loc = 58 + (piece % 4);
				 break;
			case 2 : loc = 67 + (piece % 4);
                                 break;
			case 3 : loc = 76 + (piece % 4);
                                 break;
			case 4 : loc = 85 + (piece % 4);
                                 break;

		}
	}else{

		switch (player){
			case 2 : loc += 13;
				 break;
			case 3 : loc += 26;
				 break;
			case 4 : loc += 39;
				 break;
		}
		if(loc > 52){
			loc -= 52;
		}
	}	
	return loc;

}

void mapCoordinatePointer(short location){

	short row,column;

	if(location > 0 && location <= 5){
		row = 14;
		column = 3 + (location * 4);
		
	}else if(location <= 11 ){
		row = 14 - ((location - 5) * 2);
		column = 27;
	}else if(location == 12){
		row = 2;
		column = 31;
	}else if(location <= 18){
		row = ((location - 12)*2);
		column = 35;
	}else if(location <= 24){
		row = 14;
		column = 35 + ((location  - 18) * 4);
	}else if(location == 25){
		row = 16;
		column = 59;
	}else if(location <= 31){
		row = 18;
		column = 35 + ((32 - location) * 4);
	}else if(location <= 37){
		column = 35;
		row = 18 + ((location - 31) * 2);
	}else if(location == 38){
		row = 30;
		column = 31;
	}else if(location <= 44){
		row = 18 + ((45 - location) * 2);
		column = 27;
	}else if(location <= 50){
		row = 18;
		column = 3 + ((50 - location) * 4);
	}else if(location == 51){
		row = 16;
		column = 3;
	}else if(location == 52){
		row = 14;
		column = 3;
	}else if(location <= 57){
		row = 16;
		column = 3 + ((location - 52) * 4);
	}else if(location == 58){
		row = 15;
		column = 26;
	}else if(location == 59){
                row = 16;
                column = 26;
        }else if(location == 60){
                row = 17;
                column = 26;
        }else if(location == 61){
                row = 16;
                column = 28;
        }else if(location <= 66){
                row = (location - 60) * 2;
                column = 31;
        }else if(location == 67){
                row = 14;
                column = 28;
        }else if(location == 68){
                row = 14;
                column = 30;
        }else if(location == 69){
                row = 14;
                column = 32;
        }else if(location == 70){
                row = 14;
                column = 34;
        }else if(location <= 75){
                row = 16;
                column = 35 + ((76 - location) * 4);
        }else if(location == 76){
                row = 15;
                column = 36;
        }else if(location == 77){
                row = 16;
                column = 36;
        }else if(location == 78){
                row = 17;
                column = 36;
        }else if(location == 79){
                row = 16;
                column = 34;
	}else if(location <= 84){
		row = 18 + ((85 - location) * 2);
		column = 31;
        }else if(location == 85){
                row = 18;
                column = 28;
        }else if(location == 86){
                row = 18;
                column = 30;
        }else if(location == 87){
                row = 18;
                column = 32;
        }else if(location == 88){
                row = 18;
                column = 34;
        }
	//printf("%d %d %d\n",location ,row , column);
	moveCsr(row,column);

}

void drawPiece(short player, short piece, short currentLoc, short newLoc){
	
	if(currentLoc == 0){
		moveHomeLoc(piece);
	}else{
		mapCoordinatePointer(toMainMap(currentLoc,player,piece));
	}
	
	printf(" ");
	
	if(newLoc == 0){
                moveHomeLoc(piece);
        }else{
                mapCoordinatePointer(toMainMap(newLoc,player,piece));
        }

	setForColor(player);
	printf("%d",(piece % 4) + 1);
	
	setForColor(7);

}

short checkAvailableMoves(short piecesCurrentLoc[], short player, short piece, short dice){
	
	short i = 0;
	
	piece = ((player - 1) * 4) + piece - 1;
	
	if(piecesCurrentLoc[piece] + dice == 57){
		return 1;
	}

	if(piecesCurrentLoc[piece] > 51){
		if(piecesCurrentLoc[piece] + dice > 57){
			return 0;
		}
	}


	if (piecesCurrentLoc[piece] == 0){
		if(dice == 6){
			for(i = (player - 1) * 4; i < (player * 4); i++){
				if(piecesCurrentLoc[i] == 1){
					return 0;
				}
			}
			return 1;
		}else{
			return 0;
		}
	}
	
	for(i = 0; i < 16; i++){
		
		if(toMainMap(piecesCurrentLoc[piece] + dice, player, piece) == toMainMap(piecesCurrentLoc[i], givePlayer(i),piece)){	
			
			if(givePlayer(i) == player){
				return 0;
			}
		}
	}
	return 1;
}

void gameLogic(short piecesCurrentLoc[], short piecesNewLoc[], short player){

	short i = 0;
	
	for(i = 0; i < 16 ; i++){
		if (piecesCurrentLoc[i] != piecesNewLoc[i]){
			break;
		}
	}
	short pieceToMove = i;
	
	

	for(i = 0; i < 16 ; i++){
		if(i != pieceToMove && piecesNewLoc[i] < 52){
			if(toMainMap(piecesNewLoc[pieceToMove],player,pieceToMove) == toMainMap(piecesCurrentLoc[i], givePlayer(i),pieceToMove)){
				piecesNewLoc[i] = 0;
				piecesCurrentLoc[i] = 0;
			}
		}
	}

	for(i = 0; i < 16; i++){
		drawPiece(givePlayer(i), i, piecesCurrentLoc[i], piecesNewLoc[i]);
		piecesCurrentLoc[i] = piecesNewLoc[i];
	}
	
}

int main(){
	srand(time(0));
	
	short piecesCurrentLoc[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	short piecesNewLoc[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	system("clear");
	setForColor(7);
	drawBoard();
	
	moveCsr(33,0);
	short playerCount = 4;
	drawDice(3);
	short currentPlayer = 1;
	char inp = 's';

	short sixes = 0;

	for(int i = 0; i < 16 ; i++){

		drawPiece(givePlayer(i), i , piecesCurrentLoc[i], piecesNewLoc[i]);

	}


	while(1){
		
		moveCsr(33,0);
		printf("\e[2K");
		setForColor(currentPlayer);
		printf("Player %d> ",currentPlayer);
		
		if(playerCount >= currentPlayer){
			if(scanf("%c",&inp) < 1){
				flush();
				continue;
			}
			flush();
		}
		if(inp == 'x' || inp == 'X'){
			return 0;
		}
	
		short dice = (rand() % 6) + 1;
		short diceT = dice;
		short pieceToMove = 1;
		char tmp = 0;

		drawDice(dice);

		if(
			checkAvailableMoves(piecesCurrentLoc, currentPlayer, 1,dice) == 1 ||
			checkAvailableMoves(piecesCurrentLoc, currentPlayer, 2,dice) == 1 ||
			checkAvailableMoves(piecesCurrentLoc, currentPlayer, 3,dice) == 1 ||
			checkAvailableMoves(piecesCurrentLoc, currentPlayer, 4,dice) == 1 )
		{
			short moveComplete = 0;
			do{
				moveCsr(33,0);
                		printf("\e[2K");
				printf("Piece to Move > ");
				
				if(playerCount >= currentPlayer){

					if(scanf("%hd",&pieceToMove) < 1){
						flush();
						continue;
					}
                			flush();
				}else{
					for (int i = 1; i < 5; i++){
						if(checkAvailableMoves(piecesCurrentLoc, currentPlayer, i,dice) == 1){
							pieceToMove = i;
						}
					}
					scanf("%c",&tmp);
                                                flush();

					
				}
				if(pieceToMove < 1){
					pieceToMove = 1;
				}else if (pieceToMove > 4){
					pieceToMove = 4;
				}
				
				if(checkAvailableMoves(piecesCurrentLoc, currentPlayer, pieceToMove,dice) == 1){
					
					if(dice == 6 && piecesCurrentLoc[pieceToMove + ((currentPlayer - 1) * 4) - 1] == 0){
						dice = 1;
					}
					piecesNewLoc[pieceToMove + ((currentPlayer - 1) * 4) - 1] += dice;

					gameLogic(piecesCurrentLoc, piecesNewLoc, currentPlayer);
					moveComplete = 1;

				}else{
					continue;
				}
			}while(moveComplete == 0);

			moveComplete = 0;

		}else{
			moveCsr(34,0);
			printf("\e[2K");
			printf("No available moves");
		}
		if(diceT == 6){
                        if (sixes == 2){
                                moveCsr(34,0);
                                printf("\e[2K");
				setForColor(currentPlayer);
                                printf("Skipping to the next player");
				
				setForColor(7);

                                moveCsr(33,0);
                                printf("\e[2K");

				sixes = 0;

                                if (currentPlayer == 4){
                                        currentPlayer = 1;
                                }else{
                                        currentPlayer ++;
                                }
                                continue;
                        }else{
                                sixes ++;
                        }
                }else{

			moveCsr(33,0);
			printf("\e[2K");
			if (currentPlayer == 4){
				currentPlayer = 1;
			}else{
				currentPlayer ++;
			}
		}
	}
	return 0;
}
