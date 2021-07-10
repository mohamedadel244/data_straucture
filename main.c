//عمر ايمن عبد المتعال عبد الحليم
//Sec 3 BN 13
// رقم الجلوس 32124
//محمد عادل كامل سيد
//Sec 3 BN 39
//رقم الجلوس 32150
//هشام مدحت محمد طاهر
//Sec 4 BN 41
//رقم الجلوس 32207

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <time.h>
 
struct student
    {
    char name[50];
	int id;
	int day, month, year;
	int lyscore;
    };
struct student a;


void linked_list()
{
    int list_count=0;

    struct node
    {
        struct student data;
        struct node* next;
    };

    struct node* head = NULL;
    struct node* tail = NULL;
  
  void read_data()
    {
        printf("Enter the name of the student \n");
        scanf("%s",a.name);

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

    void printlist ()
    {
        struct node* ptr = NULL;
        ptr = head;
        printf("-----------------------------------------------------------------------------------\n");
        while (ptr != NULL)
        {
            printf("Name: %s",ptr->data.name);
            printf("\nID: %d",ptr->data.id);
            printf("\nBirth Date: %d/%d/%d",ptr->data.day,ptr->data.month,ptr->data.year);
            printf("\nLast year score: %d",ptr->data.lyscore);
            ptr = ptr->next;
            printf("\n-----------------------------------------------------------------------------------\n");
        }
        printf("Number of elements in list = %d",list_count);
    }

    void insert_beginning (struct student a)
    {
       struct node* temp = NULL;
       temp = (struct node*)malloc(sizeof (struct node));
       temp->data = a;
       temp->next=NULL;

       if(head == NULL)
       {
           temp->next = head;
           head=temp;
           tail=temp;
       }
       else
       {
           temp->next = head;
           head=temp;
       }
       list_count++;
    }

    void insert_end (struct student a)
    {
        struct node* temp = NULL;
        temp = (struct node*)malloc(sizeof (struct node));
        temp->data = a;
        temp->next=NULL;

        if(head == NULL)
       {
            tail = temp;
            head = temp;
       }
       else
       {
            tail->next = temp;
            tail=temp;
       }
       list_count++;
    }

    void insert_middle (int l,struct student a)
    {
     
            struct node* temp = NULL;
            temp = (struct node*)malloc(sizeof (struct node));
            temp->data = a;
            temp->next=NULL;

        if(l == 1)
        {
            insert_beginning (a);
        }
        else
        {
            struct node* pre = NULL;
            pre = head;
            int i;
            for (i=0; i<l-2 ;i++)
            {
                pre=pre->next;
            }
            struct node* aft = pre->next;
            temp->next=aft;
            pre->next=temp;
            list_count++;
        }  
    }
	void size_time_complexitiy()
{
    printf("the size of struct student %d\n",sizeof(struct student));
    printf("the size of struct node %d\n",sizeof(struct node));
    int N,x;
        printf("1. small N\n2. medium N\n3. large N\n");
        printf("Enter your choice: ");
        scanf("%d",&x);
       
        switch(x)
        {
            case 1:  N = 50;  break;

            case 2:  N = 500; break;
            
            case 3:  N = 1200; break;
            
            default: printf("\nWrong selection!!!");
        }
    for (int k=0; k<N; k++)
    {
        struct student w1;
        strcpy(w1.name,"Hesham medhat");
        w1.id=100;
        w1.day=5;
        w1.month=12;
        w1.year=2000;
        w1.lyscore=90;
        insert_end(w1);
    }
    struct student w2;
        strcpy(w2.name,"omar ayman");
        w2.id=100;
        w2.day=5;
        w2.month=12;
        w2.year=2000;
        w2.lyscore=90;
        clock_t t1;
        t1 = clock();
        insert_beginning (w2);
        t1 = clock() - t1;
        double time_taken = ((double)t1)/CLOCKS_PER_SEC; // in seconds
        printf("fun(insert_beginning) took %f seconds to execute \n", time_taken);
        clock_t t2;
        t2 = clock();
        insert_end (w2);
        t2 = clock() - t2;
        double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds
        printf("fun(insert_end) took %f seconds to execute \n", time_taken2);
        int location = N/2;
        clock_t t3;
        t3 = clock();
        insert_middle (location,w2);
        t3 = clock() - t3;
        double time_taken3 = ((double)t3)/CLOCKS_PER_SEC; // in seconds
        printf("fun(insert_middle) took %f seconds to execute \n", time_taken3);

}
	
	
int choice,loc;
while(1)
{
    printf("\n\n**LIST MENU **\n");
     printf("1. insert beginning\n2. insert end\n3. insert middle\n4. size and time complexitiy\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:     read_data();
                    insert_beginning (a);
                    printlist();
                    break;

        case 2:     read_data();
                    insert_end (a);
                    printlist();
                    break;

        case 3:     printf("Enter the location of the student \n");
                    scanf("%d",&loc);
                    if (loc <1)
                    {
                    printf("\nWrong location enter a valid number\n");
                    printlist();
                    break;
                    }
                    else if(loc > list_count+1)
                    {printf("\nWrong location total length of the array is %d\n",list_count);
                    printlist();
                    break;}
                    read_data();
                    insert_middle (loc,a);
                    printlist();
                    break;

        case 4:     size_time_complexitiy();
                    break;

        case 5:    return;


        default: printf("\nWrong selection!!! Please try again!!!\n");
 
   }
}
}

void dynamic_array()
{
    int n=0;
    struct student* darr=malloc(sizeof(struct student));
  
 

    void read_data()
    {
        printf("Enter the name of the student \n");
        scanf("%s",a.name);

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
            printf("\nBirth Date: %d/%d/%d",darr[i].day,darr[i].month,darr[i].year);
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
            n++;
            realloc(darr,sizeof(struct student) * (n));
            int i;
            for ( i =n-1 ;i> (loc-1) ; i--)
            {
                darr[i]=darr[i-1];
            }
            darr[i]=w;
}
	
	void size_time_complexitiy()
{
    printf("the size of struct student %d\n",sizeof(struct student));
    int N,x;
        printf("1. small N\n2. medium N\n3. large N\n");
        printf("Enter your choice: ");
        scanf("%d",&x);
       
        switch(x)
        {
            case 1:  N = 50;  break;

            case 2:  N = 500; break;
            
            case 3:  N = 1200; break;
            
            default: printf("\nWrong selection!!!");
        }
    for (int k=0; k<N; k++)
    {
        struct student w1;
        strcpy(w1.name,"Hesham medhat");
        w1.id=100;
        w1.day=5;
        w1.month=12;
        w1.year=2000;
        w1.lyscore=90;
        insert_end(w1);
    }
    struct student w2;
        strcpy(w2.name,"omar ayman");
        w2.id=100;
        w2.day=5;
        w2.month=12;
        w2.year=2000;
        w2.lyscore=90;
        clock_t t1;
        t1 = clock();
        insert_beginning (w2);
        t1 = clock() - t1;
        double time_taken = ((double)t1)/CLOCKS_PER_SEC; // in seconds
        printf("fun(insert_beginning) took %f seconds to execute \n", time_taken);
        clock_t t2;
        t2 = clock();
        insert_end (w2);
        t2 = clock() - t2;
        double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds
        printf("fun(insert_end) took %f seconds to execute \n", time_taken2);
        int location = N/2;
        clock_t t3;
        t3 = clock();
        insert_middle (w2,location);
        t3 = clock() - t3;
        double time_taken3 = ((double)t3)/CLOCKS_PER_SEC; // in seconds
        printf("fun(insert_middle) took %f seconds to execute \n", time_taken3);

}

    int choice,loc;
     while(1)
     {
        printf("\n\n**Array MENU **\n");
         printf("1. insert beginning\n2. insert end\n3. insert middle\n4. size and time complexitiy\n5. Exit\n");
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
                        if (loc <1)
                        {
                        printf("\nWrong location enter a valid number\n");
                        printarray ();
                        break;
                        }
                        else if(loc > n+1)
                        {printf("\nWrong location total length of the array is %d\n",n);
                        printarray ();
                        break;}
                        read_data();
                        insert_middle (a,loc);
                        printarray ();
                        break;
                        
            case 4:     size_time_complexitiy();
                        break;

            case 5:     return;
            default:    printf("\nWrong selection!!! Please try again!!!\n");
            }
    }
}
  
  
int main()
{
 printf("welcome.let's start the program");

      int choice;

    while(1)
    {
        printf("\n\n*MAIN MENU *\n");
        printf("1. linked list\n2. dynamic array\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:  linked_list();  break;

            case 2:  dynamic_array(); break;
            
            case 3:  goto label;
            
            default: printf("\nWrong selection!!! Please try again!!!\n");
        }
    }

    label:  
	
    return 0;
}
