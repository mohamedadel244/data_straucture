#include<stdlib.h>
#include<string.h>
#include<stdio.h>
 
struct student
    {
    char name[50];
	int id;
	int day, month, year;
	int lyscore;
    };
struct student a;

void dynamic_array()
{
    int n=0;
    struct student* darr=malloc(sizeof(struct student));

    void read_data()
    {
        printf("Enter the name of the student \n");
        fflush(stdin);
        gets(a.name);

        printf("Enter the day of birth of the student \n");
        scanf("%d",&a.day);

        printf("Enter the month of birth of the student \n");
        scanf("%d",&a.month);

        printf("Enter the year of birth of the student \n");
        scanf("%d",&a.year);

        printf("Enter the Id of the student \n");
        scanf("%d",&a.id);

        printf("Enter the last year mark of the student \n");
        scanf("%d",&a.lyscore);
    }

    void printarray ()
    {
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0;i<n;i++)
        {
            printf("Name: %s",darr[i].name);
            printf("\nID: %d",darr[i].id);
            printf("\nDate: %d/%d/%d",darr[i].day,darr[i].month,darr[i].year);
            printf("\nLast year score: %d",darr[i].lyscore);
            printf("\n--------------------------------------------------------------------------------\n");
        }
            printf("Number of elements in the array = %d",n);
}

    void insert_beginning(struct student w)
    {
        n++;
        realloc(darr,sizeof(struct student) * (n));
        int i;
        for ( i =n-1 ;i>0;i--)
        {
            darr[i]=darr[i-1];
        }
        darr[i]=w;
    }

    void insert_end(struct student w)
    {
        n++;
        realloc(darr,sizeof(struct student) * (n));
        darr[n-1]=w;
    }

    void insert_middle(struct student w,int loc)
    {
        if (loc <1)
        {
            printf("\nWrong location enter a valid number\n");
        }
        else if(loc > n+1)
            printf("\nWrong location total length of the array is %d\n",n);
        else
        {
            n++;
            realloc(darr,sizeof(struct student) * (n));
            int i;
            for ( i =n-1 ;i> (loc-1) ; i--)
            {
                darr[i]=darr[i-1];
            }
            darr[i]=w;
}
}

    int choice,loc;
     while(1)
     {
        printf("\n\n**Array MENU **\n");
        printf("1. insert beginning\n2. insert end\n3. insert middle\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:     read_data();
                        insert_beginning (a);
                        printarray ();
                        break;

            case 2:     read_data();
                        insert_end (a);
                        printarray ();
                        break;

            case 3:     printf("Enter the location of the student \n");
                        scanf("%d",&loc);
                        read_data();
                        insert_middle (a,loc);
                        printarray ();
                        break;

            case 4:     return;
            default:    printf("\nWrong selection!!! Please try again!!!\n");
            }
    }
}

int main()
{
 printf("welcome.let's start the program")
      int choice;
    while(1)
    {
        printf("Welcome. Let's start the program");
        printf("\n\n**MAIN MENU **\n");
        printf("1. linked list\n2. dynamic array\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 2:  dynamic_array(); break;
            case 3:  goto label;
            default: printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
    label:  
    return 0;
}
