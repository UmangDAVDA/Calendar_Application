#include<stdio.h>
#include<conio.h>
#include<windows.h>
int first_day(int year)
{
    int day;
    day = (((year-1) * 365) + ((year-1)/4)-((year-1) /100)  +((year)/400)+ 1) % 7;
    return day;

}
void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
typedef struct {
  //structure - day month and year and note corresponding to that date
  int day;
  int month;
  int year;
  char time[15];
  char note[255];
} Note;


void AddNote(){
        int year,month, day;


    Note note;
    FILE *fp;
        system("cls");
        printf("\n===================================================\n");
        printf(" \n\n For Adding a Note \n\n\nEnter the ,day,month and year: ");
        printf("\n===================================================\n");

        scanf("%d %d %d", &note.day, &note.month, &note.year);

        //storing the day month and year to append to in "note" derived from the structure note.


        flush();
        printf("\n\nEnter the Entry for this day : ");

        fgets(note.note, 255, stdin);//stores the entered note into the note string which is part of the structure


        fp = fopen("note.txt", "a+");
        if (fp == NULL) {
          printf("\nFile note.txt can not be opened\n");//if file cannot be opened
          exit(1);
        }
        fwrite(&note, sizeof(Note), 1, fp);//sending all the contents of the "note"(struct point) into the file note.txt
        printf("\n\n || Note Added Successfully ||\n\n");

        //to-do-list is appended and file pointer is closed
        fclose(fp);
        printf("press <enter> to quit:");
        getch();
}




int main()
{
    int day,month,year,week, choice;
    FILE *fp;//takes a file pointer
    Note* notes, note;//and pointers to the structure
    int len, j, hasNote = 0;

    printf("\n\n                              CALENDAR APPLICATION                                     ");
    printf("\n   ________________________________________________________________________");
    printf("\n\n     DEVELOPED BY     :      UD Gaming Studios");




    printf("\n\n Enter Month:");
    scanf("%d",&month);
    if(month<1 || month >12){
        printf("\n\n Invalid Month");

    }


    else{
    printf("\n\n Enter Year:");
    scanf("%d",&year);
    while(1){
    int days_months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char *months[12]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
    if(year%4 == 0)
    days_months[1]=29;
    day = first_day(year);
    for(int i=0;i<(month-1);i++)
    {

        for(int j=1;j<=days_months[i];j++)
        {

            if(++day > 6)
                day=0;
        }
    }

    system("cls");
    printf("\n\n                              CALENDAR APPLICATION                                     ");
    printf("\n   ________________________________________________________________________");
    printf("\n\n     DEVELOPED BY     :      UD Gaming Studios");


    printf("\n\n---------------%s,%d---------------------",months[month-1],year);
    printf("\n\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");
    for(int i=0;i<day;i++)
    {
        printf("      ");
    }
    week=day;
    for(int j=1;j<=days_months[month-1];j++){


        if(week >6){
            printf("\n");
            week =0;

        }

            week++;

        printf("%5d ", j);
    }

    k:
    printf("\n\n 1 : Next Month\n 2 : Previous Month\n 3 : Next Year\n 4 : Previous Year\n 5 : Add Note\n 6 : Show Note\n 7 : Exit");
	printf("\n\n Your Choice : ");
	scanf("%d",&choice);
	if(choice == 1)
	{
		month++;
		if(month > 12)
		{
			month=1;
			year++;
		}
    }
	else if(choice == 2)
	{
		month--;
		if(month < 1)
		{
			month=12;
			year--;
		}
	}
	else if(choice == 3)
		year++;
	else if(choice == 4)
		year--;
    else if(choice == 5)

		AddNote();
    else if(choice == 6){

            FILE *fp;//takes a file pointer
    Note* notes, note;//and pointers to the structure
    int len, j, hasNote = 0;

    system("cls");
    fp = fopen("note.txt", "r");
    if (fp == NULL) {
      printf("Couldn't read notes\n");
    }
    len = 0;
    while(fread(&note, sizeof(Note), 1, fp)) {//reads all the notes from the file and stores in "note".(point struct)

    if (note.year == year && note.month == month) {//checking if the month and year is the same as the one we entered.
        len++;
    }
    }

    rewind(fp);
    j = 0;
    //int notess[1000];//rev

    notes = (Note*) malloc (sizeof(Note) * len); //allocating memory the size of the structure for notes that contains the day month year and note

    int t=0;
    int overlap[1000];//here
    while(fread(&note, sizeof(Note), 1, fp)) {//while reading from the file we store the data

      if (note.year == year && note.month == month) {//getting all the notes from the file which have the same day and store into

        //getting ALL the events and storing the dates in the array
        overlap[t] = note.day;//for overlapping event checking

        notes[j] = note;//the "note" array that stores the 'day month year and note'

        j++;
        t++;
      }


    }

    fclose(fp);


      printf("\n\t\t\t\tHere is the TO DO LIST for %d %d\n", month, year);


      for (int j = 0; j < len; j++) {

        printf("Day %d : %s", notes[j].day,notes[j].note);
        //displaying all the notes and thier respective days from the array containg dates and notes.

      }
      printf("press <enter> to quit:");
        getch();
    }
	else if(choice == 7)
	{
		exit(0);
	}
	else
	{
		printf("\n\n Invalid Key...Please Try Again....");
		goto k;
	}

}
}
}
