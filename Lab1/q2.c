#include<stdio.h>
#include<unistd.h>
#include<math.h>

int main()
{
	int n, initial, end, next, i, c, half_mark;
	float num;
	int fib[2];
	fib[0] = 0;
	fib[1] = 1;
	pid_t pid;
	c=0;
	printf("Enter the intial and final index of Fibonacci desired, separated by space.\n");
	scanf("%d %d",&initial, &end);

	printf("The %dth to %dth terms of Fibonacci series are:\n",initial, end);
	num = end-initial;

	half_mark = initial + floor(num/2);

	pid = fork();
	
	if (pid == 0) { //child node calculates the fib and passes it to father using pipe.
		for ( i=0 ; i < end ; i++) {
			if ( i <= 1 )
				next = i;
			else {
			 	next = fib[0] + fib[1];
			 	fib[0] = fib[1];
			 	fib[1] = next;
			}

			if ((i >= initial-1) && (i < half_mark)) {
				printf("%d\n", next);
			}

		}
	}
   	  
	else {
		wait(5);
		for ( i=0 ; i < end ; i++) {
			if ( i <= 1 )
				next = i;
			else {
			 	next = fib[0] + fib[1];
			 	fib[0] = fib[1];
			 	fib[1] = next;
			}

			if (i >= half_mark) {
				printf("%d\n", next);
			}

		}
	}
		

   return 0;
}