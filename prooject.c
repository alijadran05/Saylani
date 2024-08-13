#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
void home();
void SetColor(int ForgC);
void gotoxy (int x,int y);
int log_inpage();
int wait();
void menu();
void Enroll_data();
void viewList();
void Edit();
void delete();
int ext();
char hswitch;
int roll,choices,choice;
int date,month,year,eDate,eMonth,eYear;
int date0,month0,year0,eDate0,eMonth0,eYear0;
char name0[100],f_name0[100],depart0[100],gender0[20];
char name[100],f_name[100],depart[100],gender[20];
int main ()
{
	home();
}
void home()
{	char hswitch;
	SetColor(8);
	gotoxy(45,6);
	printf("Welcome to ") ;
	SetColor(8);
	gotoxy(38,7);
	printf("SMIU Students Managment System") ;
	SetColor(8);
	gotoxy(45,13);
	printf("=> 1: Log in");
	SetColor(8);
	gotoxy(45,14);
	printf("=> 2: Exit");
	SetColor(11);
	gotoxy(45,15);
	printf("Select an Option");
	SetColor(12);
  	gotoxy(70, 25);
  	printf("© Developed By Ali Jadran");
	SetColor(14);
	gotoxy(45,16);
	hswitch=getch();	
	switch(hswitch)	
	{
		case '1':
		log_inpage();
		break;
		
		case'2':
		ext();
		break;
		default:
		printf("Invalid Number Please Enter a Valid Number\n");
		sleep(1000);
		home();
		break;
		
	}
	
	
}
void SetColor(int ForgC)
{	
	HANDLE hStdOut =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	WORD wColor;
	
	if(GetConsoleScreenBufferInfo(hStdOut, & csbi))
	{ wColor = (csbi.wAttributes & 0xF0) +(ForgC & 0x0F);
	SetConsoleTextAttribute(hStdOut, wColor);
	} 
	return;
	
}

COORD coord ={0,0};
void gotoxy(int x, int y)
{	
	coord.X =x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int log_inpage()
{system("cls");
  int i, s = 0;
  char name[20], password[20], p;
  char ID[20] = {
    "alijadran"
  };
  char PASS[20] = {
    "1234"
  };
  SetColor(14);
  printf("\n\n\t\t\t\t\t  ===Admin Portal===\n\n\n\n\n");
  SetColor(45);
  SetColor(11);
  printf("\n\n\t\t\t\t\tYou must log in first\n");
  SetColor(6);
  printf("\n\n\t\t\t\t\tAdmin ID: ");
  SetColor(3);
  gets(name);
  SetColor(6);
  printf("\n\n\t\t\t\t\tPassword: ");
  SetColor(45);
  
  while (p != 13) {
    p = _getch();
    if (p != 13) {
      putch('*');
      password[s] = p;
      s++;
    }
  }
  password[s] = '\0';
  if (strcmp(ID, name) == 0) {
    if (strcmp(PASS, password) == 0) {
      SetColor(11);
      printf("\n\n\n\t\t\t\t\tLog In Success\n");
      Sleep(1500);
      system("cls");
      wait();
      system("cls");
	 menu();
    } else {
      SetColor(4);
      printf("\n\n\t\t\t\tPlease Enter Correct ID and Password\n");
      Sleep(3000);
      SetColor(45);
      log_inpage();
    }
  } else {
    SetColor(4);
    printf("\n\n\t\t\t\tPlease Enter Correct ID and Password\n");
    Sleep(3000);
 	 SetColor(45);
    log_inpage();
  }
  

}
int wait()
{
	int i;
  	for ( i = 0; i < 3; i++) {
    SetColor(14);
    system("cls");
	gotoxy(52,14);
    printf("Please Wait.");
    Sleep(150);
    system("cls");
    gotoxy(52,14);
    printf("Please Wait..");
    Sleep(150);
    system("cls");
    gotoxy(52,14);
    printf("Please Wait...");
	Sleep(150);
    system("cls");
    gotoxy(52,14);
	printf("Please Wait....");
	Sleep(150);
    system("cls");
    SetColor(45);
  
	}
	
}


int ext()
{	system("cls");
	printf("EXIT PAGE");
	char c_exit;
	fflush(stdin);
	printf("Press 1 for Cancel Exit:\n");
	printf("Press 0 for Exit");
	c_exit= getche();
	switch(c_exit){
	case'1':
		home();
		break;
	case'2':
		printf("Thanks for USing SMIU Student Managment System:");
		printf("Press any key to Exit............");
		_getch();
		exit(EXIT_SUCCESS);
		break;
	default:
		printf("INVALID KEYWORD");
		sleep(1000);
		ext();
	}
	return 0;
	
}
void menu()
{	
	system("cls");
	int main_exit;
	SetColor(8);
	gotoxy(36,6);
	printf("Welcome to SMIU Students Data Managment System");
	SetColor(8);
	gotoxy(45,7);
	printf("By Ali Jadran & Asiya Abid");
	SetColor(8);
	gotoxy(45,10);
	printf("1==> Enroll Student's Data\n");
	SetColor(8);
	gotoxy(45,11);
	printf("2=> View Data list\n ");
	SetColor(8);
	gotoxy(45,12);
	printf("3=> Edit Student's Data\n");
	SetColor(8);
	gotoxy(45,13);
	printf("4=> Delete Student's Data\n");
	SetColor(8);
	gotoxy(45,14);
	printf("5=> Exit\n");
	SetColor(11);
	gotoxy(45,15);
	printf("Select an Option");
	SetColor(11);
	gotoxy(45,16);
	scanf("%d",&choices);
	SetColor(8);
	gotoxy(45,17);
	choices = getch();
	switch(choices){
		case '1':
			Enroll_data();
		break;
		case'2':
			viewList();
			break;
		case '3':
			Edit();
			break;
		case'4':
			delete();
			break;
		case'5':
			ext();
			break;
		default:
			printf("Invalid choice! Try Again\n");
			
			 printf(" \n\nenter 0 to go to main menu and 1 to exit: ");
         scanf(" %d",&main_exit);

        if (main_exit == 0)
        {
            menu();
        }
        if (main_exit == 1)
        {
            ext();
        }

			
	}
	return;
	
} 
void Enroll_data(void)
{	
	int id;
	int select;
	system("cls");
	int main_exit;
	printf("\n\n\t\tEnter Student's Roll Number: ");
	scanf("%d",&id);
	
	if (2>1)
	{
		
		FILE *ptr;
		ptr = fopen("studentlist.txt","r");
		{
	while(fscanf(ptr,"%d %s %s %s %d/%d/%d %d/%d/%d %s",&roll,name,f_name,gender,&date,&month,&year,&eDate,&eMonth,&eYear,depart)!=EOF)
			if(id==roll)
			{
				printf("The student is Already Enrolled!");
				fclose(ptr);
				printf("For View Students Data List Enter 0 and 1 for Main Menu: ");
				scanf("%d",&select);
				if (select==0){
					viewList();
				}
				if(select==1)
				{
					menu();
				}
			}
		}
	}
	
	printf("\n\t\tEnter Name:");
	scanf("%s",name);
	printf("\n\t\tEnter Father Name:");
	scanf("%s",f_name);
	printf("\n\t\tEnter Gender:");
	scanf("%s",gender);
	printf("\n\t\tEnter Date of Birth:");
	scanf("%d/%d/%d",&date,&month,&year);
	printf("\n\t\tEnter Department:");
	scanf("%s",depart);
	printf("\n\t\tEnter Date of Enrollment:");
	scanf("%d/%d/%d ",&eDate,&eMonth,&eYear);
	puts("\n\n");
	system("cls");
	
	FILE *stdnt;
	stdnt = fopen("studentlist.txt","a+");
	fprintf(stdnt,"\n%d %s %s %s %d/%d/%d %d/%d/%d %s",roll,name,f_name,gender,date,month,year,eDate,eMonth,eYear,depart);
	fclose(stdnt);
	gotoxy(38,5);
	printf("STUDENT DATA IS ENROLLED SUCESSFULL!");
	gotoxy(45,9);
	printf("==>1 Press 1 for Main Menu");
	gotoxy(45,10);
	printf("==>2 press 2 for Exit");
	gotoxy(45,11);
	printf("==>3 Press 3 for View list");
	gotoxy(45,12);
	scanf("%d",&main_exit);
	main_exit=getch();
	switch(main_exit)
	{
		
		case '1':
			menu();
			break;
		case '2':
			ext();
			break;
		case '3':
			viewList();
			break;
			
	}
	
	return;
}

void viewList()
{
	system("cls");
	int exit4;
	FILE *view;
	view = fopen("studentlist.txt","r");
	printf("\n ||ROLL NO||	NAME	||	FATHER NAME	|| GENDER || DATE OF BIRTH || DATE OF ENROLLMENT || DEPARTMENT||");
	while(fscanf(view,"%d %s %s %s %d/%d/%d %d/%d/%d %s",&roll,name,f_name,gender,&date,&month,&year,&eDate,&eMonth,&eYear,depart)!= EOF);
	{
		printf("\n   %d",roll);
		printf("     %s",name);
		printf("\t     %s",f_name);
		printf("\t     %s",gender);
		printf("\t   %d/%d/%d",date,month,year);
		printf("\t   %d/%d/%d",eDate,eMonth,eYear);
		printf("\t     %s",depart);
		
	}
	fclose(view);
	puts("\n\n");
printf("\n\n Enter '1' for Main Menu and '0' for Exit");
scanf("%d",exit4);
if(exit4==1)
{
	system("cls");
	menu();
	
}
if(exit==0)
{
	ext();
}
return;
}
void Edit()
{	
	system("cls");
	int id;
	int exit;
	FILE *edit;
	FILE *tempp;
	edit=fopen("studentlist.txt","r");
	tempp=fopen("student.txt","a+");
	printf("\n\t Enter Roll Number of Student which you want to edit data:");
	printf("\n\t Check Students List by Enter 0");
	scanf("%d",&id);
	if(id==0){
		viewList();
	}
	while(fscanf(edit,	"%d %s %s %s %d/%d/%d %d/%d/%d %s",&roll,name,f_name,gender,&date,&month,&year,&eDate,&eMonth,&eYear,depart)!=EOF);
	{
		if(id==roll)
		{
			printf("\n\nWhich Data You Want To Change:");
			printf("\t\t1.NAME\n\n");
			printf("\t\t2.FATHER NAME\n\n");
			printf("\t\t3.GENDER\n\n");
			printf("\t\t1.DATE OF BIRTH\n\n");
			printf("\t\t1.DATE OF ENROLLMENT\n\n");
			printf("\t\t1.DEPARTMENT NAME\n\n");
			scanf("%d",&choice);
			if(choice== 1)
			{
				printf("Enter New Name:");
				scanf("%s",name0);
				fprintf(tempp," \n %d %s %s %s %d/%d/%d %d/%d/%d %s",roll,name0,f_name,gender,date,month,year,eDate,eMonth,eYear,depart);
			}
			if(choice== 2)
			{
				printf("Enter New Father Name:");
				scanf("%s",f_name0);
				fprintf(tempp,"\n%d %s %s %s %d/%d/%d %d/%d/%d %s",roll,name,f_name0,gender,date,month,year,eDate,eMonth,eYear,depart);
			}
			if(choice== 3)
			{
				printf("Enter Gender:");
				scanf("%s",gender0);
				fprintf(tempp,"\n%d %s %s %s %d/%d/%d %d/%d/%d %s",roll,name,f_name,gender0,date,month,year,eDate,eMonth,eYear,depart);
			}
			if(choice== 4)
			{
				printf("Enter Date of Birth(DD/MM/YYYY):");
				scanf("%d/%d/%d",&date0,&month0,&year0);
				fprintf(tempp,"\n%d %s %s %s %d/%d/%d %d/%d/%d %s",roll,name,f_name,gender,date0,month0,year0,eDate,eMonth,eYear,depart);
			}
			if(choice== 5)
			{
				printf("Enter Date of Enrollment(DD/MM/YYYY):");
				scanf("%d/%d/%d",&eDate0,&eMonth0,&eYear0);
				fprintf(tempp,"\n%d %s %s %s %d/%d/%d %d/%d/%d %s",roll,name,f_name,gender,date,month,year,eDate0,eMonth0,eYear0,depart);
			}
			if(choice== 6)
			{
				printf("Enter New Department Name:");
				scanf("%s",depart0);
				fprintf(tempp,"\n%d %s %s %s %d/%d/%d %d/%d/%d %s",roll,name,f_name,gender,date,month,year,eDate,eMonth,eYear,depart0);
			}
			else{
				fprintf(tempp," \n\n%d %s %s %s %d/%d/%d %d/%d/%d %s",roll,name,f_name,gender,date,month,year,eDate,eMonth,eYear,depart);
			}
		}
	}		fclose(edit);
			fclose(tempp);
			remove("studentlist.txt");
			rename("student.txt","student.txt");
			
			printf("\n\t\tDATA HAS BEEN CHANGED!");
			puts("\n\n");
			
			printf("Enter 1 For Main Menu:");
			printf("Enter 2 For go back to Edit Data:");
			printf("Enter 0 For Exit:");
			scanf("%d",&exit);
			if(exit==1)
				{
					menu();
				}
				
			if(exit== 2)
				{
					Edit();
				}
			if(exit==0)
				{
					ext();
				}
}
void delete()
{
	int del;
	FILE *dlt;
	FILE *temp;
	int exit;
	dlt = fopen("studentlist.txt","r");
	temp = fopen("student.txt","a+");
	printf("\t Enter Roll Number for Delete: ");
	printf("For Check Student's Roll Number Enter 0 to view list: ");
	scanf("%d",&del);
	if (del == 0)
	{
		viewList();
	}
	while (fscanf(dlt,	"%d %s %s %s %d/%d/%d %d/%d/%d %s",&roll,name,f_name,gender,&date,&month,&year,&eDate,&eMonth,&eYear,depart)!=EOF);
	{
		if (del !=roll)
		{
			fprintf(temp,"\n %d %s %s %s %d/%d/%d %d/%d/%d %s",roll,name,f_name,gender,date,month,year,eDate,eMonth,eYear,depart);
			
		}
	}	fclose(dlt);
		fclose(temp);
		remove("studentlist.txt");
		rename("student.txt","studentlist.txt");
		printf("\n\n\n\t\t\t\tREMOVED STUDENT DATA SUCESSFULL!");
		puts("\n\n");
printf("Enter 1 for main menu and 0 for exit:");
scanf("%d",&exit);
if(exit==1)
{	system("cls");
	menu ();
}
if(exit==0)
{	system("cls");
	ext();
}
	}

