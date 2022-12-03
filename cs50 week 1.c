#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// get name from user
/*
int main(){

char name[20];
printf("please enter your name\n");
gets(name);
printf("hello,%s",name);
return 0;
}*/


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// mario walkthrough
/*
int main(){

int height;
 printf("please enter height:\n");
 scanf("%d",&height);
 for(int i=1; i<=height; i++){
   for(int j=height; j>i; j--){
    printf(" ");
   }  
   for(int k=1; k<=i; k++){
    printf("#");
   }
   printf("\n");
 }
 retun 0;

}*/



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// mario walkthrough V2
/*
int main(){

int height;
int limit,line,space;
 printf("please enter height:\n");
 scanf("%d",&height);
 for( line=0; line<height; line++){
    for( space=0; space<height-line-1; space++){
        printf(" ");
    }
    for( limit=0; limit<=line; limit++){
        printf("#");
    }
    printf("  ");
    for( limit=0; limit<=line; limit++){
        printf("#");
    }
    printf("\n");
 }
}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// credit
 void Mastercard(int mastercard[16]){
    int toplam=0;
    int toplam2=0;
    int a,b;
    srand(time(NULL));
    printf("pls enter card numbers\n");
    printf("numbers:");
    for(int i=0;i<16;i++){
     mastercard[i]=rand()%9;
     printf("%d",mastercard[i]);

    }

      for(int i=14;i>=0;i-=2){
        a=2*mastercard[i];
        toplam+=a;
      }
      for(int i=15;i>=0;i-=2){
        b=mastercard[i];
        toplam2+=b;
      }
   if((a+b)%10==0)
   printf("\ncard is valid");
   else
   printf("\ncart is not valid");
   printf("\nMasterCard");
}

void VisaCard(int visacard[16]){
    int toplam=0;
    int toplam2=0;
    int a,b;
    srand(time(NULL));
    printf("pls enter card numbers\n");
    printf("numbers:");
    for(int k=0;k<16;k++){


     visacard[k]=rand()%9;

     printf("%d",visacard[k]);


    }


      for(int i=14;i>=0;i-=2){
        a=2*visacard[i];
        toplam+=a;
      }
      for(int i=15;i>=0;i-=2){
        b=visacard[i];
        toplam2+=b;
      }
   if((a+b)%10==0)
   printf("\ncard is valid");
   else
   printf("\ncart is not valid");
   printf("\nMasterCard");
}




int main(){
  int mastercard[16];
  
  int visacard[16];
  


  char a;


  printf("which card are you using\n Masterd=m Visa=v pls enter your card:\n");
  scanf("%c",&a);

  if(a=='m')
  Mastercard(mastercard);
  else if(a=='v')
  VisaCard(visacard);

 return 0;

}