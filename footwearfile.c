#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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


void create()
{
  footwear *s;
  FILE *fp;
  int i,n;
  printf("enter the no of record to be added: ");
  scanf("%d",&n);
   s = (footwear*)calloc(n,sizeof(footwear));
   fp=fopen("shirt_nondiscount.txt","a");
    if(fp==NULL)
    {
        printf("\nsomething went wrong");
        exit(1);
    }
   for(i=0;i<n;i++)
   {
     fflush(stdin);
     printf("\nenter item id");
     scanf("%d",&s[i].item_id);
     printf("\nenter item name:");
     scanf("%s",&s[i].item_name);
     printf("\nenter price");
     scanf("%f",&s[i].price);
     fflush(stdin);
     printf("\nenter price rs");
     scanf("%[^\n]%*c",&s[i].pricers);
     printf("\nenter discount");
     scanf("%s",&s[i].discount);
     printf("\nenter gst");
     scanf("%s",&s[i].gst);
     printf("\nenter final price");
     scanf("%f",&s[i].buy_price);
     fwrite(&s[i],sizeof(footwear),1,fp);
         if(fwrite!=0)
        {
            printf("registration successfull");
        }
        else
        {
             printf("something went wrong");
        }
       
   }
    fclose(fp);
}

void display()
{
FILE *fp;
footwear s1;
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

}
void main()
{

  int n;
  
  do
  {
    printf("1.create");
  printf("\n2.display");
  printf("\nenter your choice: ");
  scanf("%d",&n);
  switch(n)
  {
    case 1:
    create();
    break;

    case 2:
    display();
    break;

    case 3:
    exit(1);
    break;
  }
  } while (n!=3);
  

}