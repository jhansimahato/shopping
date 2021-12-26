

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include"myheader.h"

void cartfinal()
{
    system("cls");
    int n;
    FILE *fp,*fp1;
    float total_bill=0;
    struct footwear s1;
    struct footwear s2;\
    int found=0;
    int option;
    char usercarts[50];
    char ordercart[50];
    int p;
    
    printf("\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**         shopping cart         **");
    printf("\n\t**        ---------------        **");
    printf("\n\t**                               **");
    printf("\n\t** Customer Care: 18001800102    **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    
    printf("\n\t%-10s%-20s%-20s","item id","item name","price");
    if(sign_in==1)
    {
    strcpy(usercarts,search.email);
     strcat(usercarts,".txt");
     fp=fopen(usercarts,"r");
     rewind(fp);
    if(fp==NULL)
    {
     printf("\nsomething went wrong");
     exit(1);
     }
     while(fread(&s1,sizeof(footwear),1,fp)==1)
     {
         printf("\n\t%-10d%-20s%-20s\n",s1.item_id,s1.item_name,s1.pricers);
        total_bill += s1.price;
     }
    
    printf("\n\n\tTotal Bill: %.2f",total_bill);
    }
    fclose(fp);
    printf("\n\n\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**     Option | Function         **");
    printf("\n\t**                               **");
    printf("\n\t**       1.     PlaceOrder       **");
    printf("\n\t**       2.     Delete Item      **");
    printf("\n\t**       3.     Back             **");
    printf("\n\t**                               **");
    printf("\n\t** CustomerCare: 18001800102     **");
    printf("\n\t**                               **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\n\tEnter option: ");
    scanf("%d",&n);

    switch(n)
    {
      case 1:
      {
        //place order
        //creating a new file for final order
        system("cls");
     printf("\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**         placing order         **");
    printf("\n\t**        ---------------        **");
    printf("\n\t**                               **");
    printf("\n\t** Customer Care: 18001800102    **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
         strcpy(ordercart,search.email);
         strcat(ordercart,"order.txt");
         fp=fopen(usercarts,"r");
        rewind(fp);
        fp1=fopen(ordercart,"w");
        while(fread(&s1,sizeof(footwear),1,fp))
        {
            fwrite(&s1,sizeof(footwear),1,fp1);
        }
        fclose(fp);
        fclose(fp1);

        //end of final new file

         fp1=fopen(ordercart,"r");
         rewind(fp1);
         while(fread(&s1,sizeof(footwear),1,fp)==1)
     {
         printf("\n\t%-10d%-20s%-20s\n",s1.item_id,s1.item_name,s1.pricers);
       
     }
    
      printf("\n\n\tTotal Bill: %.2f",total_bill);
      fclose(fp1);
      
      printf("\n\npress any key to continue..!!");
      getch();
                      system("cls");
                       p=displaymenulogin();
                      switchcaselogin(p);


        break;
      }
      case 2:
      {
        //delete item
        system("cls");
     printf("\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t**                               **");
    printf("\n\t**         Delete item           **");
    printf("\n\t**        ---------------        **");
    printf("\n\t**                               **");
    printf("\n\t** Customer Care: 18001800102    **");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
    printf("\n\t***********************************");
        printf("\nEnter Item id: ");
        scanf("%d",&option);
        fp=fopen(usercarts,"r");
        fp1=fopen("temp.txt","w");
         while(fread(&s1,sizeof(footwear),1,fp))
    {
        if(s1.item_id == option)
        {
            found=1;
       
        }
        else
        {
        fwrite(&s1,sizeof(footwear),1,fp1);
        }
    }

    
    fclose(fp);
    fclose(fp1);

        if(found)
    {
        fp1=fopen("temp.txt","r");
        fp=fopen(usercarts,"w");
        while(fread(&s1,sizeof(footwear),1,fp1))
        {
            fwrite(&s1,sizeof(footwear),1,fp);
        }
        fclose(fp);
        fclose(fp1);
        printf("\npress any key to continue..!!");
        system("cls");
        cartfinal();

        //printf("\nThe record not found\n");

    }
    else
    {
        printf("\nItem not found");
        printf("\npress any key to continue..!!");
        system("cls");
        cartfinal();
    }

    

        break;
      }
      case 3:
      {
        //back
        system("cls");
        n=displaymenulogin(search);
        switchcaselogin(n);

             break;       
        }
        default:
        printf("enter a valid option");
        break;
    }
   
}
void signinfinal()
{
  //struct user search;
        FILE *fp;
        int n;
        char email1[30];
        char pword[30];
        long int size;
        size = sizeof(search);
        signin();
        printf("\nEnter Email:\t");
        scanf("%s",&email1);
        printf("\nEnter Password:\t");
        scanf("%s",&pword);
        fp=fopen("name.txt","r");
        rewind(fp);
        if(fp==NULL)
        {
            printf("\n\nUser Not registered..");
            printf("\nplease enter any key to continue..!!");
            getch();
             Beep(800,300);
                  system("cls");
                   n=displaymenu();
                   switchcase(n);

        }
        while(fread(&search,size,1,fp))
        {
            if(strcmp(search.email,email1)==0 && strcmp(search.password,pword)==0)
            {
                sign_in=1;
                //printf("\nsigned in");
                 printf("\nPress Key To continue .. !!");
                    getch();
                    system("cls");
                     n=displaymenulogin(search);
                    //  printf("\n\nWelcome, %s",search.fullname);
                    //  printf("\nUser: %s",search.email);
                    //  printf("\nMobile: %s",search.phone);

                    switchcaselogin(n);
                    break;
            }
        }

           if(sign_in==0)
           {
             printf("\nCredentials incorrect");
                    
                
                 Beep(800,300);
                  system("cls");
                   n=displaymenu();
                   switchcase(n);
        }
        fclose(fp);
}
void signupfinal()
{
FILE *fp,*cart;
int n;
    char username[50];
    char useremail[50];
    char userpassword[50];
    char userdob[50];
    char usermobile[50];
    char useraddress[50];
    char usercart[50];
    long int size;
    size = sizeof(input);
       signup();
       fp=fopen("name.txt","a");
        if(fp==NULL)
        {
            printf("\n\tOops, something went wrong");
             Beep(800,300);
                  system("cls");
                   n=displaymenu();
                   switchcase(n);

        }
        fflush(stdin);
        printf("\nEnter Name:\t");
        scanf("%[^\n]%*c",&username);
        printf("\nEnter Email:\t");
        scanf("%s",&useremail);
        printf("\nEnter password:\t");
       scanf("%s",&userpassword);
        printf("\nEnter DOB:\t");
        scanf("%s",&userdob);
        printf("\nEnter Mobile:\t");
        scanf("%s",&usermobile);
        fflush(stdin);
        printf("\nEnter Address:\t");
         scanf("%[^\n]%*c",&useraddress);
         fflush(stdin);
         
        //fprintf(fp,"\n",1);
         strcpy(input.fullname,username);
        strcpy(input.email,useremail);
        strcpy(input.password,userpassword);
        strcpy(input.dob,userdob);
        strcpy(input.phone,usermobile);
        strcpy(input.address,useraddress);
        fwrite(&input,size,1,fp);
          
         fwrite(&input,sizeof(struct user),1,fp);
         if(fwrite!=0)
         {
         printf("\nRegistration Successful");
         strcat(useremail,".txt");
         cart=fopen(useremail,"a");
         fclose(cart);
         Beep(800,300);

         }
         else
         {
             printf("\nSorry, Something went wrong.");
             Beep(800,300);
         }
       
         fclose(fp);
         printf("\nsignedup continue");
         printf("\nPress Key To continue .. !!");
         getch();
         system("cls");
         n=displaymenu();
        switchcase(n);
}
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
    else
    {
       int p;
                  p=discount();
                  switch(p)
                  {
                      case 1:
                       {
                        //discount

                        shopping_item();
                        //FILE *fp;
                        footwear s1;
                        
                          int id;
                          char usercart[50];
                          struct footwear s2;
                          int found;
                          FILE *fp,*cart;
                          int n;
                           char ch;

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
                      // printf("\nPlease Login To Add Item in Cart!!");
                      // printf("\npress Key to continue");
                      // getch();
                      // system("cls");
                      //  n=displaymenu();
                      // switchcase(n);
                       printf("\n\nADD TO CART");
                      printf("\nEnter option: ");
                      scanf("%d",&id);
                      printf("\nChosen Id: %d",id);
                      //enter id into cart
                      fp=fopen("shirt_discount.txt","r");
                      rewind(fp);
                      while(fread(&s2,sizeof(footwear),1,fp)==1)
                       {
                           if( s2.item_id == id)
                           {

                             found=1;
                            strcpy(usercart,search.email);
                            strcat(usercart,".txt");
                             cart=fopen(usercart,"a");
                             fwrite(&s2,sizeof(footwear),1,cart);
                             fclose(cart);
                            

                           }
                         
                      
                       }
                         fclose(fp);
                       //end of module enter id into cart
                   
                      printf("\nDo you want to Continue Shopping? [y/n]");
                      scanf("\t%c",&ch);
                      fgetc(stdin);
                      if(ch=='y' || ch == 'Y')
                      {
                        system("cls");
                          n=displaymenulogin(search);
                          switchcaselogin(n);
                      }
                      if(ch=='n' || ch=='N')
                      {
                        system("cls");
                          cartfinal();
                      }
                      break;

                     //END OF DISCOUNT CLOTHES OF MEN

                     
                    }
                     case 2:
                    //non-discount
                    {
                      int id;
                     char usercart[50];
                      struct footwear s2;
                      int found;
                      FILE *fp,*cart;
                      int n;
                     char ch;

                     // FILE *fp;
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

                      //   printf("\nPlease Login To Add Item in Cart!!");
                      // printf("\npress Key to continue");
                      // getch();
                      // system("cls");
                      //  n=displaymenu();
                      // switchcase(n);
                      printf("\n\nADD TO CART");
                      printf("\nEnter option: ");
                      scanf("%d",&id);
                      printf("\nChosen Id: %d",id);
                      //enter id into cart
                      fp=fopen("shirt_nondiscount.txt","r");
                      rewind(fp);
                      while(fread(&s2,sizeof(footwear),1,fp)==1)
                       {
                           if( s2.item_id == id)
                           {

                             found=1;
                            strcpy(usercart,search.email);
                            strcat(usercart,".txt");
                             cart=fopen(usercart,"a");
                             fwrite(&s2,sizeof(footwear),1,cart);
                             fclose(cart);
                            

                           }
                         
                      
                       }
                         fclose(fp);
                       //end of module enter id into cart
                   
                      printf("\nDo you want to Continue Shopping? [y/n]");
                      scanf("\t%c",&ch);
                      fgetc(stdin);
                      if(ch=='y' || ch == 'Y')
                      {
                        system("cls");
                          n=displaymenulogin(search);
                          switchcaselogin(n);
                      }
                      if(ch=='n' || ch=='N')
                      {
                        system("cls");
                          cartfinal();
                      }
                      
                      break;


                      //CASE NON_DISCOUNTED CLOTHES MEN COMPLETED
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
    else
    {
           int p;
                  p=discount();
                  switch(p)
                  {
                      case 1:
                       {
                        //discount
                        int id;
                      char usercart[50];
                        struct footwear s2;
                          int found;
                         FILE *fp,*cart;
                        int n;
                        char ch;
                         

                        //FILE *fp;
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
                      //  printf("\nPlease Login To Add Item in Cart!!");
                      // printf("\npress Key to continue");
                      // getch();
                      // system("cls");
                      //  n=displaymenu();
                      // switchcase(n);

                      printf("\n\nADD TO CART");
                      printf("\nEnter option: ");
                      scanf("%d",&id);
                      printf("\nChosen Id: %d",id);
                      //enter id into cart
                      fp=fopen("footwear_discount.txt","r");
                      rewind(fp);
                      while(fread(&s2,sizeof(footwear),1,fp)==1)
                       {
                           if( s2.item_id == id)
                           {

                             found=1;
                            strcpy(usercart,search.email);
                            strcat(usercart,".txt");
                             cart=fopen(usercart,"a");
                             fwrite(&s2,sizeof(footwear),1,cart);
                             fclose(cart);
                            

                           }
                         
                      
                       }
                         fclose(fp);
                       //end of module enter id into cart
                   
                      printf("\nDo you want to Continue Shopping? [y/n]");
                      scanf("\t%c",&ch);
                      fgetc(stdin);
                      if(ch=='y' || ch == 'Y')
                      {
                        system("cls");
                          n=displaymenulogin(search);
                          switchcaselogin(n);
                      }
                      if(ch=='n' || ch=='N')
                      {
                        system("cls");
                          cartfinal();
                      }

                      //FOOTWEAR MEN DISCOUNT COMPLETED
                     break;
                    }

                    case 2:
                    //non-discount
                    {
                      //FILE *fp;
                      footwear s1;
                       int id;
                    char usercart[50];
                     struct footwear s2;
                    int found;
                    FILE *fp,*cart;
                    int n;
                    char ch;
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
                      //   printf("\nPlease Login To Add Item in Cart!!");
                      // printf("\npress Key to continue");
                      // getch();
                      // system("cls");
                      //  n=displaymenu();
                      // switchcase(n);
                      printf("\n\nADD TO CART");
                      printf("\nEnter option: ");
                      scanf("%d",&id);
                      printf("\nChosen Id: %d",id);
                      //enter id into cart
                      fp=fopen("footwear_nondiscount.txt","r");
                      rewind(fp);
                      while(fread(&s2,sizeof(footwear),1,fp)==1)
                       {
                           if( s2.item_id == id)
                           {

                             found=1;
                            strcpy(usercart,search.email);
                            strcat(usercart,".txt");
                             cart=fopen(usercart,"a");
                             fwrite(&s2,sizeof(footwear),1,cart);
                             fclose(cart);
                            

                           }
                         
                      
                       }
                         fclose(fp);
                       //end of module enter id into cart
                   
                      printf("\nDo you want to Continue Shopping? [y/n]");
                      scanf("\t%c",&ch);
                      fgetc(stdin);
                      if(ch=='y' || ch == 'Y')
                      {
                        system("cls");
                          n=displaymenulogin(search);
                          switchcaselogin(n);
                      }
                      if(ch=='n' || ch=='N')
                      {
                        system("cls");
                          cartfinal();
                      }
                      break;

                      //MEN FOOTWEAR DISCOUNT COMPLETE
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
    else
    {
      int p;
                  p=discount();
                  switch(p)
                  {
                      case 1:
                       {
                        //discount
                        //FILE *fp;
                        
                     int id;
                    char usercart[50];
                     struct footwear s2;
                    int found;
                    FILE *fp,*cart;
                    int n;
                    char ch;

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
                      //  printf("\nPlease Login To Add Item in Cart!!");
                      // printf("\npress Key to continue");
                      // getch();
                      // system("cls");
                      //  n=displaymenu();
                      // switchcase(n);
                      printf("\n\nADD TO CART");
                      printf("\nEnter option: ");
                      scanf("%d",&id);
                      printf("\nChosen Id: %d",id);
                      //enter id into cart
                      fp=fopen("shirt_discount.txt","r");
                      rewind(fp);
                      while(fread(&s2,sizeof(footwear),1,fp)==1)
                       {
                           if( s2.item_id == id)
                           {

                             found=1;
                            strcpy(usercart,search.email);
                            strcat(usercart,".txt");
                             cart=fopen(usercart,"a");
                             fwrite(&s2,sizeof(footwear),1,cart);
                             fclose(cart);
                            

                           }
                         
                      
                       }
                         fclose(fp);
                       //end of module enter id into cart
                   
                      printf("\nDo you want to Continue Shopping? [y/n]");
                      scanf("\t%c",&ch);
                      fgetc(stdin);
                      if(ch=='y' || ch == 'Y')
                      {
                        system("cls");
                          n=displaymenulogin(search);
                          switchcaselogin(n);
                      }
                      if(ch=='n' || ch=='N')
                      {
                        system("cls");
                          cartfinal();
                      }
                      //WOMEN CLOTHES DISCOUNT COMPLETE
                     break;
                    }

                    case 2:
                    //non-discount
                    {
                      //FILE *fp;
                      footwear s1;
                       int id;
                    char usercart[50];
                     struct footwear s2;
                    int found;
                    FILE *fp,*cart;
                    int n;
                    char ch;

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
                      //   printf("\nPlease Login To Add Item in Cart!!");
                      // printf("\npress Key to continue");
                      // getch();
                      // system("cls");
                      //  n=displaymenu();
                      // switchcase(n);
                       printf("\n\nADD TO CART");
                      printf("\nEnter option: ");
                      scanf("%d",&id);
                      printf("\nChosen Id: %d",id);
                      //enter id into cart
                      fp=fopen("shirt_nondiscount.txt","r");
                      rewind(fp);
                      while(fread(&s2,sizeof(footwear),1,fp)==1)
                       {
                           if( s2.item_id == id)
                           {

                             found=1;
                            strcpy(usercart,search.email);
                            strcat(usercart,".txt");
                             cart=fopen(usercart,"a");
                             fwrite(&s2,sizeof(footwear),1,cart);
                             fclose(cart);
                            

                           }
                         
                      
                       }
                         fclose(fp);
                       //end of module enter id into cart
                   
                      printf("\nDo you want to Continue Shopping? [y/n]");
                      scanf("\t%c",&ch);
                      fgetc(stdin);
                      if(ch=='y' || ch == 'Y')
                      {
                        system("cls");
                          n=displaymenulogin(search);
                          switchcaselogin(n);
                      }
                      if(ch=='n' || ch=='N')
                      {
                        system("cls");
                          cartfinal();
                      }
                      break;

                      //NON DISCOUNTED CLOTHES WOMEN COMPLETED
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
      else
    {
           int p;
                  p=discount();
                  switch(p)
                  {
                      case 1:
                       {
                        //discount
                        int id;
                      char usercart[50];
                        struct footwear s2;
                          int found;
                         FILE *fp,*cart;
                        int n;
                        char ch;
                         

                        //FILE *fp;
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
                      //  printf("\nPlease Login To Add Item in Cart!!");
                      // printf("\npress Key to continue");
                      // getch();
                      // system("cls");
                      //  n=displaymenu();
                      // switchcase(n);

                      printf("\n\nADD TO CART");
                      printf("\nEnter option: ");
                      scanf("%d",&id);
                      printf("\nChosen Id: %d",id);
                      //enter id into cart
                      fp=fopen("footwear_discount.txt","r");
                      rewind(fp);
                      while(fread(&s2,sizeof(footwear),1,fp)==1)
                       {
                           if( s2.item_id == id)
                           {

                             found=1;
                            strcpy(usercart,search.email);
                            strcat(usercart,".txt");
                             cart=fopen(usercart,"a");
                             fwrite(&s2,sizeof(footwear),1,cart);
                             fclose(cart);
                            

                           }
                         
                      
                       }
                         fclose(fp);
                       //end of module enter id into cart
                   
                      printf("\nDo you want to Continue Shopping? [y/n]");
                      scanf("\t%c",&ch);
                      fgetc(stdin);
                      if(ch=='y' || ch == 'Y')
                      {
                        system("cls");
                          n=displaymenulogin(search);
                          switchcaselogin(n);
                      }
                      if(ch=='n' || ch=='N')
                      {
                        system("cls");
                          cartfinal();
                      }

                      //FOOTWEAR MEN DISCOUNT COMPLETED
                     break;
                    }

                    case 2:
                    //non-discount
                    {
                      //FILE *fp;
                      footwear s1;
                       int id;
                    char usercart[50];
                     struct footwear s2;
                    int found;
                    FILE *fp,*cart;
                    int n;
                    char ch;
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
                      //   printf("\nPlease Login To Add Item in Cart!!");
                      // printf("\npress Key to continue");
                      // getch();
                      // system("cls");
                      //  n=displaymenu();
                      // switchcase(n);
                      printf("\n\nADD TO CART");
                      printf("\nEnter option: ");
                      scanf("%d",&id);
                      printf("\nChosen Id: %d",id);
                      //enter id into cart
                      fp=fopen("footwear_nondiscount.txt","r");
                      rewind(fp);
                      while(fread(&s2,sizeof(footwear),1,fp)==1)
                       {
                           if( s2.item_id == id)
                           {

                             found=1;
                            strcpy(usercart,search.email);
                            strcat(usercart,".txt");
                             cart=fopen(usercart,"a");
                             fwrite(&s2,sizeof(footwear),1,cart);
                             fclose(cart);
                            

                           }
                         
                      
                       }
                         fclose(fp);
                       //end of module enter id into cart
                   
                      printf("\nDo you want to Continue Shopping? [y/n]");
                      scanf("\t%c",&ch);
                      fgetc(stdin);
                      if(ch=='y' || ch == 'Y')
                      {
                        system("cls");
                          n=displaymenulogin(search);
                          switchcaselogin(n);
                      }
                      if(ch=='n' || ch=='N')
                      {
                        system("cls");
                          cartfinal();
                      }
                      break;

                      //MEN FOOTWEAR DISCOUNT COMPLETE
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
void switchcase(int n)
{
    //FILE *fp;
     //struct user input,search;
    
    switch(n)
    {
        int l;
        case 1:
        {
        //case men
        l=men();

         //submenu
        switch(l)
        {
           case 1:
           {
               //sub-sub-menu (for men's clothing)
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
            break;
        }
        break;
        }

        case 2:
        // women
        {
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

            // default:
            // printf("enter valid output");

        }
        break;
        }


       //signin module
        case 3:
        {
        signinfinal();
        break;
    }

        case 4:
        {

            //sign up
            
    // char fullname[50];
    // char email[50];
    // char password[50];
    // char username[50];

    // char phone[50];
    
    signupfinal();
    
        break;
        }

        case 5:
        exit(1);
        break;

        default:
        printf("enter a valid option");
    }
}
int main()
{

   
  system("color 0b");
  int n,l;
   firstpage();
   getch();
   system("cls");
   n=displaymenu();
   switchcase(n);
  
   
    

    
    return 0;
}