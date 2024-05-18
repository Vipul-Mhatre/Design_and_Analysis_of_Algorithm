#include<stdio.h>
#include<conio.h>
int main(){
   int z[2][2];
   int i, j;
   int P1, P2, P3, P4 , P5, P6, P7;
   int x[2][2] = {
       {5, 1},
       {4, 3}
       };

   int y[2][2] = {
       {7, 5},
       {3, 2}
   };

   clrscr();

   printf("\n\nThe first matrix is: ");
   for(i = 0; i < 2; i++) {
      printf("\n");
      for(j = 0; j < 2; j++)
	 printf("%d\t", x[i][j]);
   }
   printf("\nThe second matrix is: ");
   for(i = 0; i < 2; i++) {
      printf("\n");
      for(j = 0; j < 2; j++)
	 printf("%d\t", y[i][j]);
   }
   P1= x[0][0] * (y[0][1] - y[1][1]);
   P2= (x[0][0] + x[0][1]) * y[1][1];
   P3= (x[1][0] + x[1][1]) * y[0][0];
   P4= x[1][1] * (y[1][0] - y[0][0]);
   P5= (x[0][0] + x[1][1]) * (y[0][0] + y[1][1]);
   P6= (x[0][1] - x[1][1]) * (y[1][0]+y[1][1]);
   P7= (x[0][0] - x[1][0]) * (y[0][0]+y[0][1]);

   z[0][0] = P5 + P4- P2 + P6;
   z[0][1] = P1 + P2;
   z[1][0] = P3 + P4;
   z[1][1] = P1 + P5 -P3 -P7;
   printf("\nProduct achieved using Strassen's algorithm: ");
   for(i = 0; i < 2 ; i++) {
      printf("\n");
      for(j = 0; j < 2; j++)
	 printf("%d\t", z[i][j]);
   }
   getch();
   return 0;
}