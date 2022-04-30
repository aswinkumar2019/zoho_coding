#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count = 0;

struct employee {
    int level;
    char role[20];
    char master[20];
    char names[200];
}e[100];

void swap(char *str1, char *str2)
{
    char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    free(temp);
}
void bubbleSort() {

    // loop to access each array element
    for (int step = 0; step < count ; ++step) {

        // loop to compare array elements
        for (int i = 0; i < count - step ; ++i) {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (e[i].level > e[i + 1].level) {

                // swapping occurs if elements
                // are not in the intended order
                int level_temp = e[i].level;
                e[i].level = e[i + 1].level;
                e[i + 1].level = level_temp;
                swap(e[i].role,e[i+1].role);
                swap(e[i].master,e[i+1].master);
            }
        }
    }
}

void createroot(char data[])
{
    e[0].level = 1;
    strcpy(e[0].role,data);
    strcpy(e[0].master,"Nobody");
}

void addrole(char data1[],char data2[])
{
    int check = 0;
    for(int i=0;i<20;i++)
    {
        if(strcmp(e[i].role,data1) == 0)
        {
            check = 1;
            count++;
            printf("Adding role");
            strcpy(e[count].role,data2);
            e[count].level = e[i].level + 1;
            strcpy(e[count].master,data1);
            bubbleSort();
        }else {
            if(check == 0) {
                printf("Not found\n");
            }
        }
    }
}

void replacerole(char data1[],char data2[])
{
    int check = 0;
    for(int i=0;i<=count;i++)
    {
        if(strcmp(e[i].role,data1) == 0)
        {
            check = 1;
            printf("Replacing role");
            strcpy(e[i].role,data2);
        }else {
            if(check == 0) {
                printf("Not found\n");
            }
        }
    }
}

void adduser(char data1[],char data2[])
{
    int check = 0;
    for(int i=0;i<=count;i++)
    {
        if(strcmp(e[i].role,data1) == 0)
        {
            check = 1;
            strcat(e[i].names, " ");
            strcat(e[i].names, data2);
            //strcat(e[i].names,' ');
        }else {
            if(check == 0) {
                printf("Not found\n");
            }
        }
    }
}
void finduser(char data1[] ) {
    int check = 0;
    for(int i=0;i<=count;i++)
    {
        if(strcmp(e[i].role,data1) == 0)
        {
            check = 1;
            puts(e[i].names);
        }else {
            if(check == 0) {
                printf("Not found\n");
            }
        }
    }
}

void countusers(char data1[])
{
    char users[200];
    int i;
    int level;
    char *found = 0;
    int check = 0;
for(i = 0;i<=count;i++)
{
    found = strstr(e[i].names,data1);
    printf("found = %s\n",found);
    //strcpy(temp,found);
    if (found) {
        check = 1;
        printf("Found the string at count %d",i);
        break;
    }
    else
    {
        printf("c is empty\n");
    }
    /*if(*found != '\0') {
        check = 1;
        break;
    }*/
}
    if(check == 1) {
     //   printf("Found user at role number %d",i);
        printf("We need to print users above the level of this role");
        level = e[i].level - 1;
        for(int j = 0;j<=count;j++) {
            if(e[j].level<=level) {
                strcat(users, " ");
                strcat(users,e[j].names);
            }
        }
        printf("The users are");
        puts(users);

    }
}
int main()
{
    int option = 10;
    int max;
    char data1[10],data2[10];
    while(option!=0) {
        printf("Operations available :\n1.Add root role\n2.Add a subrole\n3.Delete and replace a role\n4.Add user\n5.Total employees in the company\n6.Display persons working under them\n7.Height of the tree(number of levels in a company)\n8.Print\n9.Print users with a particular role\n10.Find the number of users between top user and entered user");
        scanf("%d",&option);
        switch(option) {
            case 1:
                printf("Enter the root role");
                scanf("%s",data1);
                createroot(data1);
                break;
            case 2:
                printf("Enter the master role");
                scanf("%s",data1);
                printf("Enter the sub role");
                scanf("%s",data2);
                addrole(data1,data2);
                break;
            case 3:
                printf("Enter the role to be deleted");
                scanf("%s",data1);
                printf("Enter the role to be replaced with");
                scanf("%s",data2);
                replacerole(data1,data2);
                for (int i = 0; i <= count; i++) {
                    if (strcmp(e[i].master, data1) == 0) {
                        strcpy(e[i].master,data2);
                    }
                }
                break;
            case 4:
                printf("Enter the user name");
                scanf("%s",data1);
                printf("Enter his role");
                scanf("%s",data2);
                adduser(data2,data1);
                break;
            case 5:
                printf("The total number of employees in the company is %d",count+1);
            case 6:
                printf("Give the role for which employees under them need to be found");
                scanf("%s",data1);
                for (int i = 0; i <= count; i++) {
                    if (strcmp(e[i].master, data1) == 0) {
                        printf("%s\t", e[i].role);
                    }
                }
                break;
            case 7:

                // Initialize maximum element
                max = e[0].level;

                // Traverse array elements from second and
                // compare every element with current max
                for (int i = 1; i <= count; i++) {
                    if (e[i].level > max)
                        max = e[i].level;
                }
                printf("The number of levels in the company is %d",max);
                break;
            case 8:
                int level = e[0].level;
                for(int i = 0;i<=count;i++)
                {
                    if(level != e[i].level) {
                        printf("\nLEVEL %d\n",e[i].level);
                        level = e[i].level;
                    }
                    //printf("%d",e[i].level);
                    printf("Role: %s\t",e[i].role);
                    printf("Master of this role is: %s",e[i].master);
                    printf("Users with this role is %s",e[i].names);
                    printf("\n");

                }

                printf("In short form the roles are as below order");
                for(int j=0;j<=count;j++)
                {
                    printf("%s-> ",e[j].role);
                }
                printf("\n");
                break;
            case 9:
                printf("Enter the role for which you need to find the users");
                scanf("%s",data1);
                finduser(data1);
                break;
            case 10:
                printf("Enter the user name");
                scanf("%s",data1);
                countusers(data1);
                break;

        }
    }
}