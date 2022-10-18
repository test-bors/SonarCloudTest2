#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

void printField(int*,long long int*);
char npcMove(int*,int*,int,int);
void move(int*,int*,int*,char,int*,int*,int*);
void changegoal(int,int*,int,int,int,int,int*,int*,int*);
int rdmnum(void);
//void changecolor(int);
//char farbe(int);
void gameover(int,int,int);

int main(void){
	time_t timestart;
	char player[8];
	printf("Gebe deinen Spielernamen ein: ");
	scanf("%s",&player);
	char npczug='0';
	char zug='0';
	int npcpoints=1,mypoints=1,punkte=1,zupunkten=1,npcposX=7,npcposY=6,myposY=0,myposX=0,spielzug=0,x=0,y=0;
	time(&timestart);
	int field[8][8]={0};
	field[myposY][myposX]=1;
	field[npcposY][npcposX]=1;
	while(zug!='x'){
		if(punkte==zupunkten){
			changegoal(punkte,&zupunkten,npcposX,npcposY,myposX,myposY,&x,&y,*field);
			printField(*field,&timestart);
		}
		zug=getch();
		move(*field,&myposX,&myposY,zug,&spielzug,&mypoints,&punkte);
		if(punkte==zupunkten){
			changegoal(punkte,&zupunkten,npcposX,npcposY,myposX,myposY,&x,&y,*field);
		}
		npczug=npcMove(&npcposX,&npcposY,x,y);
		move(*field,&npcposX,&npcposY,npczug,&spielzug,&npcpoints,&punkte);
		printField(*field,&timestart);
		if(punkte>100){
			break;
		}
	}
	gameover(spielzug,mypoints,npcpoints);
}

void printField(int *ptr,long long int *timestart){
	time_t timejetzt;
	int minuten=0,mindiff,diff;
	system("cls");
	printf(" ------------------------\n");
	for(int i=0;i<=7;i++){
		printf("|");
		for(int j=0;j<=7;j++){
			printf("%3d",*ptr);
			ptr+=1;
		}
		printf("|\n");
	}
	printf(" ------------------------\n");
	printf("\n\n");
	time(&timejetzt);
	diff=difftime(timejetzt,*timestart);
	if(diff>=60){
		mindiff=diff/60;
		minuten+=mindiff;
		diff-=60*mindiff;
	}
	printf("Bisherige Zeit %d Minuten %d Sekunden",minuten,diff);
}

char npcMove(int *pX, int *pY,int x,int y){
	char c;
	if((*pX-x<=4&&*pX-x>0)||(*pX-x<-4)){
		c='a';
	}else if(*pX-x>4||(*pX-x>=-4&&*pX-x<0)){
		c='d';
	}else if((*pY-y<=4&&*pY-y>0)||(*pY-y<-4)){
		c='w';
	}else if(*pY-y>4||(*pY-y>=-4&&*pY-y<0)){
		c='s';
	}
	return c;
}

void move(int *field, int *pX, int *pY, char zug,int *spielzug,int *points,int *punkte){
	int sum=(*pX)+(*pY)*8;
	if(*(field+sum)==*points){
		*(field+sum)=0;
	}
	switch(zug){
		case 100:
		*pX+=1;
		*spielzug+=1;
		break;
		case 97:
		*pX-=1;
		*spielzug+=1;
		break;
		case 115:
		*pY+=1;
		*spielzug+=1;
		break;
		case 119:
		*pY-=1;
		*spielzug+=1;
		break;
	}
	if(*pX<0){
		*pX=*pX+8;
	}else if(*pX>7){
		*pX=*pX-8;
	}else if(*pY<0){
		*pY=*pY+8;
	}else if(*pY>7){
		*pY=*pY-8;
	}
	sum=(*pX)+(*pY)*8;
	if(*(field+sum)==1){
		*points+=1;
		*punkte+=1;
	}
	*(field+sum)=*points;
	//usleep(250000);
}

void changegoal(int punkte,int *gepunktet,int npcposX,int npcposY,int myposX,int myposY,int* x,int *y,int *field){
	int rd[]={4,6,0,3,1,5,2,7,3,4,7,0,2,1,5,6,0,4,5,2,7,3,6,1,5,4,1,6,3,2,0,7,0,3,7,5,1,2,6,4,4,0,1,5,3,7,2,6,0,6,3,2,1,7,4,5,5,2,1,6,7,0,3,4};	
	int sum=(*x)+(*y)*8;
	//changecolor(punkte);
	while((*x==npcposX&&*y==npcposY)||(*x==myposX&&*y==myposY)){
		*x=rd[rdmnum()/64];
		*y=rd[rdmnum()%64];
	}
	sum=(*x)+(*y)*8;
	if(*(field+sum)==0){
		*(field+sum)+=1;
		*gepunktet+=1;
	}
}

int rdmnum(void){
	srand(time(NULL));
	int erg =((rand()+45)*1068)%512;
	return erg;
}

/*void changecolor(int Punkte){
	char color[9]={"Color 0F"};
	Punkte=Punkte%16;
	color[7]=farbe(Punkte);
	system(color);
}

char farbe (int zahl){
	switch (zahl){
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			return '0'+zahl;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			return 'A'+zahl-10;
			break;
	}
}*/

void gameover(int spielzug,int punkte,int punkte2){
	system("cls");
	char s='|';
	printf("\n\n ---------------------\n%2c     GAME OVER%6c\n%2c%20c",s,s,s,s);
	printf("\n%2c  Spielzuege:%4d%3c\n",s,spielzug,s);
	printf("%2c  Punkte:%7d%4c\n ---------------------\n",s,punkte-1,s);
	FILE *fp;
	fp=fopen("Scoreboard.txt","a");
	if(fp==NULL){
		printf("oeffnen fehlgeschlagen\n");
	}else{
		fprintf(fp,"\n\nFuer %d Punkte brauchtest du %d Spielzuege\nDer Gegner hatte %d Punkte",punkte,spielzug/2,punkte2);
	}
	fclose(fp);
	system("scoreboard.txt");
}