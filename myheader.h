#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>



struct user
{
    char fullname[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
    char dob[50];
    char address[50];
    
}search,input;

typedef struct footwear
{
  int item_id;
  char item_name[20];
   float price;
   char pricers[20];
   char discount[20];
   char gst[20];
   float buy_price;
}footwear;

extern int sign_in=0;

//prototypes of functions used
void firstpage(void);
int displaymenu(void);
//void switchcase(int);
int men(void);
int women(void);
void signin(void);
void signup(void);
void clothesmen_discount(void);
void clothesmen(void);
void footwearmen_discount(void);
void footwearmen(void);
void clotheswomen(void);
void footwearwomen(void);
int displaymenulogin();
void cartfinal();

//void takeinput(char *);




void signin()
{
 system("cls");
    printf("\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**           SIGN IN             **");
    printf("\n\t**        ---------------        **");
    printf("\n\t**                               **");
    printf("\n\t** CUSTOMER CARE:18001800102     **");
    printf("\n\t**                               **");
    printf("\n\t**                               **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
}

void takeinput(char ch[30])
{
  fgets(ch,30,stdin); // taking input string
  ch[strlen(ch) - 1] = 0; 
  //removing null character and adding 0 at end of the line
  
}

void signup()
{
     system("cls");
    printf("\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**           SIGN UP             **");
    printf("\n\t**        ---------------        **");
    printf("\n\t**                               **");
    printf("\n\t** CUSTOMER CARE:18001800102     **");
    printf("\n\t**                               **");
    printf("\n\t**                               **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
}



void firstpage()
{
    system("cls");
    printf("\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**         sari shopping         **");
    printf("\n\t**        ---------------        **");
    printf("\n\t**     A place to buy clothes    **");
    printf("\n\t**              and              **");
    printf("\n\t**           Footwears           **");
    printf("\n\t**                               **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\nPress Key To continue .. !!");
   
    
}


int displaymenu()
{
 int n;
    printf("\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**     Option | Function         **");
    printf("\n\t**                               **");
    printf("\n\t**       1.     Men              **");
    printf("\n\t**       2.     Women            **");
    printf("\n\t**       3.     SignIn           **");
    printf("\n\t**       4.     SignUp           **");
    printf("\n\t**       5.     Exit             **");
    printf("\n\t**                               **");
    printf("\n\t** CustomerCare: 18001800102     **");
    printf("\n\t**                               **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\nEnter option: ");
    scanf("%d",&n);
    fgetc(stdin);
    
    system("cls");
return n;

}

int displaymenulogin()
{
 int n;
    printf("\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**     Option | Function         **");
    printf("\n\t**                               **");
    printf("\n\t**       1.     Men              **");
    printf("\n\t**       2.     Women            **");
    printf("\n\t**       3.     Cart             **");
    printf("\n\t**       4.     Signout          **");
    printf("\n\t**       5.     Exit             **");
    printf("\n\t**                               **");
    printf("\n\t** CustomerCare: 18001800102     **");
    printf("\n\t**                               **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    if(sign_in==1)
    {
        printf("\n\n\tWelcome, %s",search.fullname);
        printf("\n\tUser Name: %s",search.email);
        printf("\n\tMobile No: %s",search.phone);
    }
    printf("\n\n\tEnter option: ");
    scanf("%d",&n);
    fgetc(stdin);
    
    system("cls");
return n;

}

void switchcaselogin(int n)
{
    switch(n)
    {
         FILE *name;
    
        int l;
        case 1:

        //case men
        l=men();

         //submenu
        switch(l)
        {
           case 1:
           {
            clothesmen();
            break;
           }
           case 2:
           {
             footwearmen();
             break;
           }
            case 3:
            {
             if(sign_in==1)
            {
              n=displaymenulogin(search);
              switchcaselogin(n);
            }
            else
            {
            n=displaymenu();
            switchcase(n);
            }
            break;
            }

            default:
            printf("enter valid output");

        }
        break;

        case 2:
        // women
        l=women();
         switch(l)
        {
            //submenu
           case 1:
            clotheswomen();
            break;
           case 2:
             footwearwomen();
             break;
            case 3:
            if(sign_in==1)
            {
              n=displaymenulogin(search);
              switchcaselogin(n);
            }
            else
            {
            n=displaymenu();
            switchcase(n);
            }
            break;

            default:
            printf("enter valid output");

        }
        break;

        case 3:
        {
          //cart
          cartfinal();
          break;
        }

    //signout module
       case 4:
       sign_in=0;
        n=displaymenu();
        switchcase(n);
        break;
       
        case 5:
        exit(1);
        break;

        default:
        printf("enter a valid option");


    }
}

 

int men()
{
int n;
printf("\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**     Option | Function         **");
    printf("\n\t**                               **");
    printf("\n\t**       1.     Clothes          **");
    printf("\n\t**       2.     FootWear         **");
    printf("\n\t**       3.     Back             **");
    printf("\n\t**                               **");
    printf("\n\t** CustomerCare: 18001800102     **");
    printf("\n\t**                               **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\nEnter option: ");
    scanf("%d",&n);
    system("cls");
return n;
}
int women()
{
    int n;
printf("\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**     Option | Function         **");
    printf("\n\t**                               **");
    printf("\n\t**       1.     Clothes          **");
    printf("\n\t**       2.     FootWear         **");
    printf("\n\t**       3.     Back             **");
    printf("\n\t**                               **");
    printf("\n\t** CustomerCare: 18001800102     **");
    printf("\n\t**                               **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\nEnter option: ");
    scanf("%d",&n);
    system("cls");
return n;
}

int discount()
{
    int n;
printf("\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**         Shopping Items        **");
    printf("\n\t**                               **");
    printf("\n\t**       1.     Discount         **");
    printf("\n\t**       2.     Non-discount     **");
    printf("\n\t**       3.     Back             **");
    printf("\n\t**                               **");
    printf("\n\t** CustomerCare: 18001800102     **");
    printf("\n\t**                               **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\nEnter option: ");
    scanf("%d",&n);
    system("cls");
return n;
}

void shopping_item()
{
  system("cls");
                       printf("\t***********************************");
                       printf("\n\t***********************************");
                       printf("\n\t**                               **");
                       printf("\n\t**         shopping item         **");
                       printf("\n\t**        ---------------        **");
                       printf("\n\t**                               **");
                       printf("\n\t** CUSTOMER CARE:18001800102     **");
                       printf("\n\t**                               **");
                       printf("\n\t**                               **");
                       printf("\n\t***********************************");
                       printf("\n\t***********************************");
                      printf("\n\t***********************************");

                     printf("\n%-5s %-20s%-20s%-20s%-20s%-10s  \n","itemid","item name","price","discount","gst","buy_price");
}
/*
void clothesmen()
{ int n;
 


       if(sign_in==0)
                {
                  int p;
                  p=discount();
                  switch(p)
                  {
                      case 1:
                       {
                        //discount
                        shopping_item();
                        FILE *fp;
                        footwear s1;
                        fp=fopen("shirt_discount.txt","r");
                         rewind(fp);
                         if(fp==NULL)
                         {
                            printf("\nsomething went wrong");
                            exit(1);
                        }
                       while(fread(&s1,sizeof(footwear),1,fp)==1)
                       {
                           printf("\n%-5d%-20s%-20s%-20s%-20s%-5.2f  %-10.2f\n",s1.item_id,s1.item_name,s1.pricers,s1.discount,s1.gst,s1.buy_price,s1.price);

                       }
                      fclose(fp);
                      printf("\nPlease Login To Add Item in Cart!!");
                      printf("\npress Key to continue");
                      getch();
                      system("cls");
                       n=displaymenu();
                      switchcase(n);

                     break;
                    }

                    case 2:
                    //non-discount
                    {
                      FILE *fp;
                      footwear s1;
                      shopping_item();
                      fp=fopen("shirt_nondiscount.txt","r");
                      rewind(fp);
                      if(fp==NULL)
                       {
                         printf("\nsomething went wrong");
                         exit(1);
                       }
                       while(fread(&s1,sizeof(footwear),1,fp)==1)
                       {
                          printf("\n%-5d%-20s%-20s%-20s%-20s%-5.2f  %-10.2f\n",s1.item_id,s1.item_name,s1.pricers,s1.discount,s1.gst,s1.buy_price,s1.price);

                       }
                       fclose(fp);

                        printf("\nPlease Login To Add Item in Cart!!");
                      printf("\npress Key to continue");
                      getch();
                      system("cls");
                       n=displaymenu();
                      switchcase(n);
                      break;
                    }
        
                   case 3:
                   {
                    n=displaymenu();
                    switchcase(n);
                    break;
                   }

                   default:
                      printf("\n\tenter valid ouput");
                      break;

     }
    }

   
   
   
}
void footwearmen()
{

     int n;
       if(sign_in==0)
                {
                  int p;
                  p=discount();
                  switch(p)
                  {
                      case 1:
                       {
                        //discount
                        FILE *fp;
                        footwear s1;
                        shopping_item();
                        fp=fopen("footwear_discount.txt","r");
                         rewind(fp);
                         if(fp==NULL)
                         {
                            printf("\nsomething went wrong");
                            exit(1);
                        }
                       while(fread(&s1,sizeof(footwear),1,fp)==1)
                       {
                           printf("\n%-5d%-20s%-20s%-20s%-20s%-5.2f  %-10.2f\n",s1.item_id,s1.item_name,s1.pricers,s1.discount,s1.gst,s1.buy_price,s1.price);

                       }
                      fclose(fp);
                       printf("\nPlease Login To Add Item in Cart!!");
                      printf("\npress Key to continue");
                      getch();
                      system("cls");
                       n=displaymenu();
                      switchcase(n);
                     break;
                    }

                    case 2:
                    //non-discount
                    {
                      FILE *fp;
                      footwear s1;
                      shopping_item();
                      fp=fopen("footwear_nondiscount.txt","r");
                      rewind(fp);
                      if(fp==NULL)
                       {
                         printf("\nsomething went wrong");
                         exit(1);
                       }
                       while(fread(&s1,sizeof(footwear),1,fp)==1)
                       {
                          printf("\n%-5d%-20s%-20s%-20s%-20s%-5.2f  %-10.2f\n",s1.item_id,s1.item_name,s1.pricers,s1.discount,s1.gst,s1.buy_price,s1.price);

                       }
                       fclose(fp);
                        printf("\nPlease Login To Add Item in Cart!!");
                      printf("\npress Key to continue");
                      getch();
                      system("cls");
                       n=displaymenu();
                      switchcase(n);
                      break;
                    }
        
                   case 3:
                   {
                    n=displaymenu();
                    switchcase(n);
                    break;
                   }

                   default:
                      printf("\n\tenter valid ouput");
                      break;

     }
    }

}
void clotheswomen()
{
     int n;
       if(sign_in==0)
                {
                  int p;
                  p=discount();
                  switch(p)
                  {
                      case 1:
                       {
                        //discount
                        FILE *fp;
                        footwear s1;
                        shopping_item();
                        fp=fopen("shirt_discount.txt","r");
                         rewind(fp);
                         if(fp==NULL)
                         {
                            printf("\nsomething went wrong");
                            exit(1);
                        }
                       while(fread(&s1,sizeof(footwear),1,fp)==1)
                       {
                           printf("\n%-5d%-20s%-20s%-20s%-20s%-5.2f  %-10.2f\n",s1.item_id,s1.item_name,s1.pricers,s1.discount,s1.gst,s1.buy_price,s1.price);

                       }
                      fclose(fp);
                       printf("\nPlease Login To Add Item in Cart!!");
                      printf("\npress Key to continue");
                      getch();
                      system("cls");
                       n=displaymenu();
                      switchcase(n);
                     break;
                    }

                    case 2:
                    //non-discount
                    {
                      FILE *fp;
                      footwear s1;
                      shopping_item();
                      fp=fopen("shirt_nondiscount.txt","r");
                      rewind(fp);
                      if(fp==NULL)
                       {
                         printf("\nsomething went wrong");
                         exit(1);
                       }
                       while(fread(&s1,sizeof(footwear),1,fp)==1)
                       {
                          printf("\n%-5d%-20s%-20s%-20s%-20s%-5.2f  %-10.2f\n",s1.item_id,s1.item_name,s1.pricers,s1.discount,s1.gst,s1.buy_price,s1.price);

                       }
                       fclose(fp);
                        printf("\nPlease Login To Add Item in Cart!!");
                      printf("\npress Key to continue");
                      getch();
                      system("cls");
                       n=displaymenu();
                      switchcase(n);
                      break;
                    }
        
                   case 3:
                   {
                    n=displaymenu();
                    switchcase(n);
                    break;
                   }

                   default:
                      printf("\n\tenter valid ouput");
                      break;

     }
    }

}
void footwearwomen()
{
    int n;
       if(sign_in==0)
                {
                  int p;
                  p=discount();
                  switch(p)
                  {
                      case 1:
                       {
                        //discount
                        FILE *fp;
                        footwear s1;
                        shopping_item();
                        fp=fopen("footwear_discount.txt","r");
                         rewind(fp);
                         if(fp==NULL)
                         {
                            printf("\nsomething went wrong");
                            exit(1);
                        }
                       while(fread(&s1,sizeof(footwear),1,fp)==1)
                       {
                           printf("\n%-5d%-20s%-20s%-20s%-20s%-5.2f  %-10.2f\n",s1.item_id,s1.item_name,s1.pricers,s1.discount,s1.gst,s1.buy_price,s1.price);

                       }
                      fclose(fp);
                       printf("\nPlease Login To Add Item in Cart!!");
                      printf("\npress Key to continue");
                      getch();
                      system("cls");
                       n=displaymenu();
                      switchcase(n);
                     break;
                    }

                    case 2:
                    //non-discount
                    {
                      FILE *fp;
                      footwear s1;
                      shopping_item();
                      fp=fopen("footwear_nondiscount.txt","r");
                      rewind(fp);
                      if(fp==NULL)
                       {
                         printf("\nsomething went wrong");
                         exit(1);
                       }
                       while(fread(&s1,sizeof(footwear),1,fp)==1)
                       {
                          printf("\n%-5d%-20s%-20s%-20s%-20s%-5.2f  %-10.2f\n",s1.item_id,s1.item_name,s1.pricers,s1.discount,s1.gst,s1.buy_price,s1.price);

                       }
                       fclose(fp);
                        printf("\nPlease Login To Add Item in Cart!!");
                      printf("\npress Key to continue");
                      getch();
                      system("cls");
                       n=displaymenu();
                      switchcase(n);
                      break;
                    }
        
                   case 3:
                   {
                    n=displaymenu();
                    switchcase(n);
                    break;
                   }

                   default:
                      printf("\n\tenter valid ouput");
                      break;

     }
    }
}

*/


