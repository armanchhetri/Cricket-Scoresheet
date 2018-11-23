/*DATE:2074/11/01
Project on Cricket Score Board*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>
COORD coord={0,0};
typedef struct batsman
{
    char pnam[20];
   int runbal,runbat,fours,sixes;
   float strike;
}batsman;
typedef struct bowlar
{
    char name[20];
   int run,ball,nob,wd,wckt,over;
   float economy;
}bowlar;
typedef struct games
{
    int teamrun,extra,overs;
    float runrate;
    char name[20],venue[20],teambat[20],teambowl[20];
    batsman bat[11];
    bowlar bowler[11];
}games;
games game={0};
int bats=2;
char c,t;
    int p[11]={0},over[50],ball[15],m;
    int s=0;
   // float runrate;
    //int extra;
int b=0,nb=1;
//char mnam[50];

void welcome1();
void welcome2();
void players();
void greater();
void smaller();
void wgreater();
void wsmaller();
void card(int*,int*);
void gotoxy(int x,int y);
void delay(unsigned int mseconds);
void displayscore(void);
void displaycard();
int main()
{
    int act;
    fflush(stdin);
    system("color 6");
    system("color e0");
    int extra=0;
    welcome1();
    system("cls");
    printf ("\n\n\t\tCHOOSE ANY ACTION:\n");
    printf("\t\t1.NEW SCORESHEET!!\n\t\t2.EXISTING SCORESHEET!!\n\t\t3.EXIT!!\n");
    scanf("%d",&act);
    if(act==3)
        exit(0);
    else if(act==2)
        {displayscore();
        exit(0);
        }
     static int v=0;
    system("cls");
    welcome2();
    system("cls");
    players();
    //players(&teamB);
    system("cls");
    printf("\n\n\n\t\t\t%c%cTHE GAME BEGINS HERE!%c%c\n\n\n",178,178,178,178);
    int i,j,k,a,l,x=6;
   printf("\t\t\t!!PRESS 'w' for wide!!\n\t\t\t!!PRESS 'x' for wicket!!\n\t\t\t!!PRESS 'n' for no ball!!\n");
    //printf("\n\t\t\tEnter the runs:\n");
    char tempname[20];
    int nt;
    fflush(stdin);
    printf("\t\t\tEnter the number of overs:");
    scanf("%d",&nt);                //Taking the overs and further calculation
    //fflush(stdin);
     game.overs=nt;
    for(j=1;j<=nt;j++)
    {
        x=6;
        int overrun=0;
        static int z=0,h=0;
        fflush(stdin);
        printf("\n\t\t\tEnter the bowler name:");
        gets(tempname);
        for(h=0;h<=z;h++)
        {
            if(strcmp(tempname,game.bowler[h].name)==0)
                goto atish;
        }
       strcpy(game.bowler[z].name,tempname);
        h=z;
        z++;


        atish:
       printf("\n\t\t\tEnter the runs:\n");
    for(i=1;i<=x;i++)
    {

        printf("\n\t\t\tball %d:",i);
    //scanf("%c",&c);
    c=getche();
    fflush(stdin);
        switch(c)
        {
    case '1':
    case '3':
        {
            p[b]+=(c-48);
            game.bat[b].runbal++;
            overrun+=(c-48);
            game.teamrun+=(c-48);
            if(b>nb)
                greater();
            else
                smaller();

                break;
        }
    case '2':
    case '4':
    case '6':
    case '0':

        {
           if(c=='4')
              game.bat[b].fours++;
           if(c=='6')
             game.bat[b].sixes++;
            p[b]+=(c-48);
             game.bat[b].runbal++;
            overrun+=(c-48);
            game.teamrun+=(c-48);
            break;
        }
    case 'w':

        {

            game.bowler[h].wd++;

            int v;
            printf("\n\t\t\tEnter the run:");
            scanf("%d",&v);
            game.teamrun+=(v+1);
            game.extra+=(v+1);
            overrun+=(v+1);
            x++;
            if (v==1 || v==3)
            {
                if(b>nb)
                greater();
            else
                smaller();
            }
            break;
        }
    case 'x':
        {
            bats++;
           game.bowler[h].wckt++;
              game.bat[b].runbal++;
          //  teamA.play[b].strike=(float)(teamA.play[b].runbat*100)/(teamA.play[b].runbal);
            printf("\n\t\t\t%s is out scoring %d run.",  game.bat[b].pnam,p[b]);
            if(b>nb)
                wgreater();
            else
                wsmaller();
            break;
        }
case 'n':

        {
            game.bowler[h].nob++;

            int v;
            printf("\n\t\t\tEnter the run:");
            scanf("%d",&v);
            game.teamrun+=1;
            game.extra+=1;

            p[b]+=v;
            overrun+=(v+1);
            game.teamrun+=v;
            x++;
            if (v==1 || v==3)
            {
                if(b>nb)
                greater();
            else
                smaller();
            }
            break;
        }




    }
    }
    if(b>nb)
                greater();
            else
                smaller();
    game.bowler[h].run+=overrun;
   game.bowler[h].over++;
   game.runrate=((float)game.teamrun/j);
    for(m=0;m<11;m++){
        game.bat[m].runbat=p[m];
        if(game.bat[m].runbal!=0)
        game.bat[m].strike=(float)(game.bat[m].runbat*100)/(game.bat[m].runbal);
        else
          game.bat[m].strike=0;
    }


     game.bowler[h].economy=(float)game.bowler[h].run/game.bowler[h].over;
    card(&z,&bats);

   }
FILE *fptr;                                            //Saving the data to the file
fptr=fopen("cricbuz.DAT","rb+");
if(fptr==NULL)
{
    fptr=fopen("cricbuz.DAT","wb+");
    if(fptr==NULL)
    {
        puts("Cannot open file");
    }
}
fseek(fptr,0,SEEK_END);
fwrite(&game,sizeof(game),1,fptr );

    return 0;
}
void welcome1()       //To display the welcome screen
{
    delay(1000);
     int i,j;
  gotoxy(35+25,5);
  printf("%c",218);
  for(i=0;i<35;i++)
  printf("%c",205);

  printf("%c",191);
  for(i=0;i<10;i++){
  gotoxy(35+25,6+i);
    printf("%c",206);
    gotoxy(71+25,6+i);
    printf("%c",206);
  }
  gotoxy(35+25,16);
  printf("%c",192);
for(i=0;i<35;i++)
      printf("%c",205);
    printf("%c",217);
     gotoxy(44+25,7);
    for(i=0;i<20;i++){
   printf("%c",244);
    }
    delay(1000);
gotoxy(37+25,9);printf("\t\t!!!WELCOME!!!");
delay(1000);
gotoxy(43+25,10);printf("@\t\t\t@");
gotoxy(53+25,10);printf("TO");
delay(1000);
gotoxy(42+25,12);printf("%c\t\t\t %c",178,178);
gotoxy(44+25,12);printf("!CRICKET SCORESHEET!");
delay(1000);
gotoxy(25+25,20);printf("Project by:");
gotoxy(25+25,22);printf("074BCT506");
gotoxy(25+25,23);printf("074BCT508");
gotoxy(25+25,24);printf("074BCT521");
printf("\n\n");
for(i=0;i<39;i++)
{
    printf("\n");
    delay(200);
}
}
void welcome2()
{                                              //To input the match information
    fflush(stdin);
    printf("\n\n\t\tEnter the match name:");
    gets(game.name);
    printf("\n\t\tEnter venue:");
    gets(game.venue);
    printf("\n\n\t\tEnter batting team name:");
    gets(game.teambat);
    printf("\n\t\tEnter balling team name:");
    gets(game.teambowl);
}
void players()              //To input the players name
{

    int i;
    printf("\n\n\t\t\t%cTEAM SQUAD%c",175,174);
    printf("\n\n\t\t\t%cEnter the names of players of team %s:\n",190,game.teambat);
    for(i=0;i<11;i++)
    {
        printf("\t\t\tplayer %d:",i+1);
        gets(game.bat[i].pnam);
    }
}
void greater()
{
    int temp=b;
    b-=(b-nb);
    nb+=(temp-nb);
}
void smaller()
{
    int temp=b;

    b+=(nb-b);                                 //These functions are for changing the strike
    nb-=(nb-temp);
}
void wgreater()
{
    b++;
}
void wsmaller()
{

    b+=1+(nb-b);
}
 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void delay(unsigned int mseconds)
{                                                             //These are for time and for proper displaying of the datas on the console
   clock_t time;
   time=mseconds +clock();
   while(time>clock());

}
void card(int *z,int *bats)   //Displays the score in each over
{
    int i;
    printf("\n\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
   printf("\t\t|BATSMAN\t\tRUNS\tBALLS\tSTRIKE RATE\t4S\t6S|\n");
   printf("\t\t|-----------------------------------------------------------------|\n");
   for(i=0;i<*bats;i++){

     printf("\t\t|%-23s%d\t%d\t%1.2f\t\t%d\t%d |\n",game.bat[i].pnam,game.bat[i].runbat,game.bat[i].runbal,game.bat[i].strike,game.bat[i].fours,game.bat[i].sixes);
   }
   printf("\t\t|-----------------------------------------------------------------|\n\t\t|TEAMRUN:%d\t\tRUNRATE:%f\tEXTRARUN:%-4d     |\n\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n",game.teamrun,game.runrate,game.extra);
   printf("\n\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("\t\t|BOWLER\t\t\tRUNS\tECONOMY\t  WCKT\t NOBALL\t  WIDE\t  |\n");
    printf("\t\t|-----------------------------------------------------------------|\n");
    for(i=0;i<*z;i++){

     printf("\t\t|%-23s%d\t%1.2f\t  %-4d\t %-6d\t   %d\t  |\n",game.bowler[i].name,game.bowler[i].run,game.bowler[i].economy,game.bowler[i].wckt,game.bowler[i].nob,game.bowler[i].wd);
   }
   printf("\t\t|-----------------------------------------------------------------|\n\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");

}

void displayscore(void)          //Takes the existing score board from file
{
    char temp[30];
    printf("Enter the name of the game:");
    fflush(stdin);
    gets(temp);
    FILE *fptr;
fptr=fopen("cricbuz.DAT","rb+");
if(fptr==NULL)
    puts("File cannot be opened.");
    fseek(fptr,0,SEEK_SET);
    while(fread(&game,sizeof(game),1,fptr )==1)
    {
        if(strcmp(temp,game.name)==0)
            displaycard();


    }
     printf("Game doesn't exist in our list.");

    getch();
}

void displaycard()                                  //Displays the data of the file in proper manner
{
    system("cls");
      int i;
      gotoxy(16,9);printf("\t\t\t!!SCORE SHEET!!");
      gotoxy(16,10);
      for(i=0;i<66;i++)
      printf("%c",196);
      gotoxy(16,11);printf("Match name:%s\t||Venue:%s",game.name,game.venue);
      gotoxy(16,12);
      for(i=0;i<66;i++)
      printf("%c",196);
     gotoxy(16,13); printf("%sVS%s",game.teambat,game.teambowl);
       gotoxy(16,14);
      for(i=0;i<66;i++)
      printf("%c",196);
   printf("\n\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
   printf("\t\t|BATSMAN\t\tRUNS\tBALLS\tSTRIKE RATE\t4S\t6S|\n");
   printf("\t\t|-----------------------------------------------------------------|\n");
   for(i=0;i<11;i++){
      if(game.bat[i].runbal!=0)
    printf("\t\t|%-23s%d\t%d\t%1.2f\t\t%d\t%d |\n",game.bat[i].pnam,game.bat[i].runbat,game.bat[i].runbal,game.bat[i].strike,game.bat[i].fours,game.bat[i].sixes);
   }
   printf("\t\t|-----------------------------------------------------------------|\n\t\t|TEAMRUN/OVER:%d/%d\tRUNRATE:%f\tEXTRARUN:%-4d     |\n\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n",game.teamrun,game.overs,game.runrate,game.extra);
   printf("\n\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("\t\t|BOWLER\t\t\tRUNS\tECONOMY\t  WCKT\t NOBALL\t  WIDE\t  |\n");
    printf("\t\t|-----------------------------------------------------------------|\n");
    for(i=0;i<8;i++){
    if(strlen(game.bowler[i].name)!=0)
     printf("\t\t|%-23s%d\t%1.2f\t  %-4d\t %-6d\t   %d\t  |\n",game.bowler[i].name,game.bowler[i].run,game.bowler[i].economy,game.bowler[i].wckt,game.bowler[i].nob,game.bowler[i].wd);

   }
   printf("\t\t|-----------------------------------------------------------------|\n\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
getch();
exit(0);
}

