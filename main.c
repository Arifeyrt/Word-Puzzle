#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

void wordarea(char words[7][15]); //we get a random direction and we puts the word the table

int main(){
    srand(time(NULL));
char words[7][15];
	
int randnum;
int a,b;
int i;
int j,k;
int a1,a2,a3,a4,a5,a6,a7;
char randomword[50][50];

FILE *wordlist;
wordlist=fopen("wordlist.txt","r");
for(i=0;i<50;i++){
fscanf(wordlist,"%s ",randomword[i]);/*this part get in txt words,and put in the wordlist array*/
}
fclose(wordlist);


a1=rand()%50;
strcpy(words[0],randomword[a1]); /*this part translete the random word in the words array*/
printf("%s\n",words[0]);

a2=rand()%50;
strcpy(words[1],randomword[a2]);
while(a1==a2){
a2=rand()%50;}
strcpy(words[1],randomword[a2]); /*this part translete the random word in the words array*/
printf("%s\n",words[1]);


a3=rand()%50;
strcpy(words[2],randomword[a3]);
while(a3==a2 || a1==a3){
a3=rand()%50;}
strcpy(words[2],randomword[a3]); /*this part translete the random word in the words array*/
printf("%s\n",words[2]);


a4=rand()%50;
strcpy(words[3],randomword[a4]);
while(a4==a1 || a4==a2 || a4==a3 ){
a4=rand()%50;}
strcpy(words[3],randomword[a4]);/*this part translete the random word in the words array*/
printf("%s\n",words[3]);

a5=rand()%50;
strcpy(words[4],randomword[a5]);
while(a5==a1 || a5==a2 || a5==a3 || a5==a4 ){
a5=rand()%50;}
strcpy(words[4],randomword[a5]); /*this part translete the random word in the words array*/
printf("%s\n",words[4]);

a6=rand()%50;
strcpy(words[5],randomword[a6]);
while(a6==a1 || a6==a2 || a6==a3 || a6==a4 || a6==a5 ){
a6=rand()%50;}
strcpy(words[5],randomword[a6]); /*this part translete the random word in the words array*/
printf("%s\n",words[5]);

a7=rand()%50;
strcpy(words[6],randomword[a7]);
while(a7==a1 || a7==a2 || a7==a3 || a7==a4 || a7==a5 || a7==a6){
a7=rand()%50;}
strcpy(words[6],randomword[a7]);
printf("%s\n",words[6]);

	wordarea(words);
	
    return 0;
}

	

void wordarea(char words[7][15]){
	int i,j;
	char wordtable[15][15];
	char randchar;
	int direction;
	srand(time(NULL));

	for(i=0;i<15;i++){ //first the we added speace character without each of the  elements
		for(j=0;j<15;j++){
		wordtable[i][j]=' ';
		}
	}

    int t,k;
	int rand_x,rand_y; // random locations and direction.

	for(i=0;i<7;i++){ //this operation continiou 7 times
		direction=rand()%8; //random direction

        rand_x=rand()%15;
	    rand_y=rand()%15;

        switch(direction){


			case 0:

		for(j=0;j<15;j++){ //y axis
			for(t=0;t<15;t++){ //x axis
				for(k=0;k<strlen(words[i]);k++){
					
					while(wordtable[rand_y][rand_x+k]!=' '||(rand_x+strlen(words[i]))>15){
							rand_x=rand()%15;
							rand_y=rand()%15;
			}
				}
				if(j==rand_y && t==rand_x){
					
					for(k=0;k<strlen(words[i]);k++){
							wordtable[j][t+k]=words[i][k];
					}
					j=15;
					t=15;
				}
			}
		}
				break;
			case 1:

				
			for(j=0;j<15;j++){ //y axis
			for(t=0;t<15;t++){ //x axis
				
				for(k=0;k<strlen(words[i]);k++){
					while(wordtable[rand_y][rand_x-k]!=' '||(rand_x+strlen(words[i]))<=15){
					
							rand_x=rand()%15;
							rand_y=rand()%15;
					}
				}
				if(j==rand_y && t==rand_x){
					
					for(k=0;k<strlen(words[i]);k++){
							
							wordtable[j][t-k]=words[i][k];
					}
					j=15;
					t=15;
				}
			}
		}
				break;
			case 2:

				
				for(j=0;j<15;j++){ //y axis
			 for(t=0;t<15;t++){ //x axis
				
				for(k=0;k<strlen(words[i]);k++){
					while(wordtable[rand_y+k][rand_x]!=' '||(rand_x+strlen(words[i]))>=15){
							rand_x=rand()%15;
							rand_y=rand()%15;
					}
				}
				if(j==rand_y && t==rand_x){
				for(k=0;k<strlen(words[i]);k++){
							
							wordtable[j+k][t]=words[i][k];
					}
					j=15;
					t=15;
				}
			}
		}
				break;
			case 3:

				for(j=0;j<15;j++){ //y axis
			     for(t=0;t<15;t++){ //x axis
				for(k=0;k<strlen(words[i]);k++){
					
					while(wordtable[rand_y-k][rand_x]!=' '||(rand_x+strlen(words[i]))<=15){
							rand_x=rand()%15;
							rand_y=rand()%15;
					}
				}
				if(j==rand_y && t==rand_x){
					
					for(k=0;k<strlen(words[i]);k++){
					wordtable[j-k][t]=words[i][k];
					}
					j=15;
					t=15;
				}
			}
		}
				break;
			case 4:

				for(j=0;j<15;j++){ //y axis
			for(t=0;t<15;t++){ //x axis
				
				for(k=0;k<strlen(words[i]);k++){
					
					while(wordtable[rand_y+k][rand_x+k]!=' '||(rand_x+strlen(words[i]))>=15){
							
							rand_x=rand()%15;
							rand_y=rand()%15;
					}
				}
				if(j==rand_y && t==rand_x){
					for(k=0;k<strlen(words[i]);k++){
							wordtable[j+k][t+k]=words[i][k];
					}
					j=15;
					t=15;
				}
			}
		}
				break;

			case 5:

				for(j=0;j<15;j++){ //y axis
			for(t=0;t<15;t++){ //x axis
				for(k=0;k<strlen(words[i]);k++){
				
					while(wordtable[rand_y-k][rand_x+k]!=' '||(rand_x+strlen(words[i]))>=15){
							rand_x=rand()%15;
							rand_y=rand()%15;
					}
				}
				if(j==rand_y && t==rand_x){
					
					for(k=0;k<strlen(words[i]);k++){
							wordtable[j-k][t+k]=words[i][k];
					}
					j=15;
					t=15;
				}
			}
		}
				break;
			case 6:

				for(j=0;j<15;j++){ //y axis
			for(t=0;t<15;t++){ //x axis
			
				for(k=0;k<strlen(words[i]);k++){
				
					while(wordtable[rand_y-k][rand_x-k]!=' '||(rand_x+strlen(words[i]))<=15){
							
							rand_x=rand()%15;
							rand_y=rand()%15;
					}
				}
				if(j==rand_y && t==rand_x){
				
					for(k=0;k<strlen(words[i]);k++){
					
							wordtable[j-k][t-k]=words[i][k];
					}
					j=15;
					t=15;
				}
			}
		}
				break;
			case 7:

			for(j=0;j<15;j++){ //y axis
			for(t=0;t<15;t++){ //x axis
			
				for(k=0;k<strlen(words[i]);k++){
				
					while(wordtable[rand_y+k][rand_x-k]!=' '||(rand_x+strlen(words[i]))<=15){
							rand_x=rand()%15;
							rand_y=rand()%15;
					}
				}
				if(j==rand_y && t==rand_x){
				
					for(k=0;k<strlen(words[i]);k++){
					
							wordtable[j+k][t-k]=words[i][k];
					}
					
					j=15;
					t=15;
				}
			}
		}
				break;
		}
	}
	 for(i=0;i<15;i++){ //fills the empty places with random chars.    rastgele karakter atan kisim
		for(j=0;j<15;j++){
		
			randchar=97+rand()%25+1;
			
			if(wordtable[i][j]==' ') wordtable[i][j]=randchar;
		}
	}

	//this part , print at the gameboard
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			printf("%c ",wordtable[i][j]);
		}
		printf("\n");
    }
}






//there is no game because i didn't have enough time
















