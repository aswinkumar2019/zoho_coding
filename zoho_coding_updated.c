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
        }
    }
    if(check == 0) {
        printf("Master(will report to) role not found,enter it again correctly");
        scanf("%s",data1);
        addrole(data1,data2);
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
        }
    }
    if(check == 0) {
        printf("Role to be deleted is not found,enter it again correctly");
        scanf("%s",data1);
        replacerole(data1,data2);
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
            printf("User added successfully\n");
            //strcat(e[i].names,' ');
        }
        }
    if(check == 0) {
        printf("Role not found,enter the correct role");
        scanf("%s",data1);
        adduser(data1,data2);
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

void countusers(char data1[]) {
    int num = 0;
    char users[200];
    int i;
    int level;
    char *found = 0;
    int check = 0;
    for (i = 0; i <= count; i++) {
        found = strstr(e[i].names, data1);
        printf("found = %s\n", found);
        //strcpy(temp,found);
        if (found) {
            check = 1;
            printf("Found the string at count %d",i);
            break;
  	      }
	}
        if (check == 1) {
            printf("Found user at role number %d", i);
            level = e[i].level - 1;
            printf("We need to print users below the level %d", level);
            for (int j = 0; j <= count; j++) {
                if (e[j].level <= level) {
                    strcat(users, " ");
                    strcat(users, e[j].names);
                }
            }
            printf("The users are\t");
            puts(users);
    }
    	int len=strlen(users);
	for(i=0;i<len;i++)
	{
		if(users[i]!=' ' && users[i+1]==' ')
			num=num+1;
	}
    printf("So,the total count is %d", num);
}


void print()
{
    int level = e[0].level;
    for(int i = 0;i<=count;i++)
    {
        if(level != e[i].level) {
            printf("\nLEVEL %d\n",e[i].level);
            level = e[i].level;
        }
        //printf("%d",e[i].level);
        printf("Role: %s\t",e[i].role);
        printf("Master(will report to) of this role is: %s\t",e[i].master);
        // printf("Level of this role is %d\t",e[i].level);
        if(e[i].names) {
            printf("Users with this role is %s", e[i].names);
            printf("\n");
        }
        else {
            printf("Users with this role is Nobody\n");
        }

    }

    printf("In short form the roles are as below in hierarchical order");
    for(int j=0;j<=count;j++)
    {
        printf("%s-> ",e[j].role);
    }
    printf("\n");
}

int main()
{
    int option = 10;
    int max;
    char data1[10],data2[10];
    printf("Operations available :\n1.Add root role\n2.Add a subrole\n3.Print users with a particular role\n4.Delete and replace a role\n5.Add User\n6.Display persons working under them\n7.Total employees in the company\n8.Find the number of users between top user and entered user\n9.Height of the tree(number of levels in a company)\n10.Print");
    while(option!=0) {
        printf("Enter option");
        scanf("%d",&option);
        switch(option) {
            case 1:
                printf("Enter the root role");
                scanf("%s",data1);
                createroot(data1);
                print();
                break;
            case 2:
                printf("Enter the master(will report to) role");
                scanf("%s",data1);
                printf("Enter the sub role");
                scanf("%s",data2);
                addrole(data1,data2);
                print();
                break;
            case 3:
                printf("Note,this case is used to only print the roles ,use option 5 to add a user");
                int level = e[0].level;
                for(int i = 0;i<=count;i++)
                {
                    if(level != e[i].level) {
                        printf("\nLEVEL %d\n",e[i].level);
                        level = e[i].level;
                    }
                    //printf("%d",e[i].level);
                    printf("Role: %s\t",e[i].role);
                    printf("Master(will report to) of this role is: %s",e[i].master);
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
            case 4:
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
                printf("Data after replacing the role is\n");
                print();
                break;
            case 5:
                printf("Enter the user name");
                scanf("%s",data1);
                printf("Enter his role");
                scanf("%s",data2);
                adduser(data2,data1);
                printf("Data after adding the user is\n");
                print();
                break;
            case 6:
                printf("User and the users working under them");
                //scanf("%s",data1);
                for (int i = 0; i <= count; i++) {
                    if (e[i].names) {
                        printf("User:");
                        puts(e[i].names);
                        printf("Employees under him");
                        printf("-----------------------------------\n");
                        if(i == count) {
                            printf("He belongs to last level and nobody works under them");
                        }
                        else
                        {
                            for(int j = 0;j <= count;j++) {
                                if(strcmp(e[j].master,e[i].role) == 0) {
                                  puts(e[j].names);
                                  printf("\n");
                                }
                            }
                        }
                       // printf("%s\t", e[i].role);
                    }
                }
                break;
                /*printf("Give the role for which employees under them need to be found");
                scanf("%s",data1);
                for (int i = 0; i <= count; i++) {
                    if (strcmp(e[i].master, data1) == 0) {
                        printf("%s\t", e[i].role);
                    }
                }
                break;*/
            case 7:
                printf("The total number of employees in the company is %d",count+1);
                break;
            case 8:
                printf("Enter the user name");
                scanf("%s",data1);
                countusers(data1);
                break;
            case 9:
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
            case 10:
                print();
                break;
                /*
                printf("Enter the role for which you need to find the users");
                scanf("%s",data1);
                finduser(data1);
                break; */
            default:
                printf("option not found");
        }
    }
}
