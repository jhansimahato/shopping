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
void display()
{
FILE *fp;
footwear s1;
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

}
int main()
{
    display();
    return 0;
}