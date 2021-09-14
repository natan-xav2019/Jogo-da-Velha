#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#define AREA 3

void line() {
	int cont;
	
	for( cont=0 ; cont<= 31 ; cont++ ) {
		printf("-");
		if(cont==31) {
			printf("\n");
		}
	}
}

void VectorCharacterInitiatorGame(char init[AREA][AREA]) {
	int i,j;
	
	for( i=0 ; i<AREA ; i++ )
	{
		for( j=0 ; j<AREA ; j++ )
		{
			init[i][j]=' ';
		}
	}
}

void BoardGame(char position[AREA][AREA]) {
	printf("\t %c | %c | %c\n",position[0][0],position[0][1],position[0][2]);
	printf("\t------------\n");
	printf("\t %c | %c | %c\n",position[1][0],position[1][1],position[1][2]);
	printf("\t------------\n");
	printf("\t %c | %c | %c\n",position[2][0],position[2][1],position[2][2]);
}

int trade(int x) {
	return x ? 0 : 1;
}

int CheckMovinemts(char position[3][3], char symbol[2], int letter)
{
	int i,j,point;
	//pontuação horizontal
	for(i=0;i<=2;i++)
	{
		point=0;
		for(j=0;j<=2;j++)
		{
			if(position[i][j]==symbol[letter])
			{
				point++;
				if(point==3)
					return 1;
			}
			else
				point=0;
		}
	}
	
	point=0;
	
	//potuação vertical
	for(i=0;i<=2;i++)
	{
		point=0;
		for(j=0;j<=2;j++)
		{
			if(position[j][i]==symbol[letter])
			{
				point++;
				if(point==3)
					return 1;
			}
			else
				point=0;
		}
	}
	
	point=0;
	//potuação diagonal esquerda para a direita
	for(i=0;i<=2;i++)
	{
		if(position[i][i]==symbol[letter])
		{
			point++;
			if(point==3)
				return 1;
		}
		else
			point=0;	
	}
	
	//potuação diagonal direita para a esquerda
	j=2;
	i=point=0;
	while(i<=2)
	{
		if(position[i][j]==symbol[letter])
		{
			point++;
			if(point==3)
				return 1;
		}
		else
			point=0;
		
		j--;
		i++;
	
	}
	return 0;	
}

int main() {
	char name[2][20],position[AREA][AREA], symbol[2]= {'X','O'};
	int point[2]={0,0}, move= 0, movimentLine = 0,movimentColumn = 0, turn;
	
	setlocale(LC_ALL,"");
	
	printf("\tJogo da Velha\n");
	line();
	printf("\n\tCOMO JOGAR\nIniciada a partida escolhendo dois \nnúmeros de 1 a 3 para ocupar a \nposição da esquerda para direita \nde cima para baixo respectivamente\n\n");
	line();
	
	//Cadastro dos jogadores.
	for( turn=0; turn<2 ; turn++ ) {
		printf("digite o nome do jogador %i: ",turn+1);
		scanf("%s",&name[turn]);
		fflush(stdin);
		
	}
	
	system("cls");
	VectorCharacterInitiatorGame(position);
	
	
	if(point[0]==0 && point[1]==0) {
		srand(time(NULL));
		turn=rand()%2;
			
	}
	
	for( move=0; move < 9 ; move++ ) {
		
		turn=trade(turn);
		
		if(move==0) {
			BoardGame(position);
		}
		
		printf("jogue %s jogando com \"%c\"\n",name[turn], symbol[turn]);
		do {
			//printf("Linha: ")
			scanf("%i %i",&movimentColumn, &movimentLine);
			//printf("coluna: ")
			fflush(stdin);
		}while(position[movimentColumn-1][movimentLine-1]!=' ' || isdigit(movimentColumn) || isdigit(movimentLine) );
		
		system("cls");
		
		position[movimentColumn-1][movimentLine-1]=symbol[turn];
		
		BoardGame(position);
		
		if(CheckMovinemts(position,symbol,turn)) {
			move=9;
			point[turn]++;
			printf("\nVencedor da rodada %s!\n",name[turn]);
			system("pause");
			system("cls");
		}
	}
	
	return 0;
} 
