#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user
{
    char fullname[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
    
}user;

// void takeinput(char ch[50])
// {
//   fgets(ch,50,stdin); // taking input string
//   ch[strlen(ch) - 1] = 0; 
//   //removing null character and adding 0 at end of the line
  

// }
void takeinput(char ch[50])
{
  fgets(ch,50,stdin); // taking input string
  ch[strlen(ch) - 1] = 0; 
  //removing null character and adding 0 at end of the line
  

}

void generateusername(char email[50],char username[50])
{
    //abc123@gmail.com --- username generate is : abc123
    for(int i=0;i<strlen(email);i++)
    {
        if(email[i]=='@')
        break;
        else
        username[i]=email[i];
    }
}

void takepassword(char password[50])
{
    int i;
    char ch;
    while(1)
    {
        ch=getch();
        if( ch == ENTER || ch == TAB)
        {
        password[i]='\0';
        break;
        }
        else if(ch == BCKSPC)
        {
         if(i>0)
         {
             i--;
             printf("\b \b");
         }
        }
        else{
            password[i++]=ch;
            printf("* \b");
        }
    }

}

int main()
{
    struct user user1;
    FILE *fp;
    char password2[50];
    printf("\n\t\t\t----welcome to authetication system------");
    printf("\n please chose operation");
    printf("\n1.signup");
    printf("\n2.login");
    printf("\n3.exit");
    printf("\nenter your choice");
    int choice;
    scanf("%d",&choice); 
    //as scanf will produce \n we need to use fgetc(stdin) to consume that 
    fgetc(stdin);
    
    switch(choice)
    {
        case 1:
        printf("\nenter full name:\t");
        takeinput(user1.fullname);
        printf("\nenter email:\t");
        takeinput(user1.email);
        printf("\nenter contact number:\t");
        takeinput(user1.phone);
        printf("enter your password:\t");
        takepassword(user1.password);
        printf("\nconfirm your password:\t");
        takepassword(password2);
        if(!strcmp(user1.password,password2))
        {
            printf("\npassword matched");
            generateusername(user1.email,user1.username);
            // printf("\nyour username is: %s",user1.username);
            fp=fopen("users.txt","a+");
            fprintf(fp , "\n",  1);
            fwrite(&user1,sizeof(struct user),1,fp);

            if(fwrite !=0)
            {
                printf("registration successful,Your username is %s",user1.username);

            }
            else
            {
               printf("\n\n sorry,something went wrong");
            }
            fclose(fp);
        }
        else
        {
            printf("\npassword do not matched");
            Beep(750,300);
        }
        break;

        case 2:
        char username[50],pword[50];
        struct user usr;
      

        printf("\nenter username: ");
        takeinput(username);
        printf("enter your password:\t");
        takepassword(pword);
        fp=fopen("users.txt","r");
        while(fread(&usr,sizeof(struct user),1,fp))
        {
            if(!strcmp(usr.email,username))
            {
                if(!strcmp(usr.password,pword))
                {
                    printf("\nlogged in successfully");
                    break;
                }
                else
                {
                    printf("\npassword didnot match");
                    Beep(750,300);
                    break;
                }
            }
            else{
                printf("\nusername not registered");
                Beep(750,300);
            }
            fclose(fp);
            break;
        }
        
    }

    return 0;
}