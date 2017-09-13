#include<stdio.h>
 
int main()
{
   int n, initial, end, next, i;
   int fib[2];
   fib[0] = 0;
   fib[1] = 1;

   printf("Enter the intial and final index of Fibonacci desired, separated by space.\n");
   scanf("%d %d",&initial, &end);
 
   printf("The %dth to %dth terms of Fibonacci series are:\n",initial, end);
 
   for ( i = 0 ; i < end ; i++ ) {
      if ( i <= 1 )
         next = i;
      else {
         next = fib[0] + fib[1];
         fib[0] = fib[1];
         fib[1] = next;
      }
      if (i >= initial-1)
         printf("%d\n",next);
   }
   return 0;
}