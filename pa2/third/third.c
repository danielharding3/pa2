#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	unsigned short num;
	num = atoi(argv[1]);
	
	int i;
	int j;
	int result = 1;
	
	int x = 15;
	unsigned short bin[16] = {0};
	
	
	while (num != 0) {
		
		bin[x--] = num & 1;
		
		num = num >> 1;
	}
	
	for (i = 0, j = 15; i < j; i++, j--) {
		
			if (bin[i] != bin[j]) {
				result = 0;
			}
		
	}
	
	if (result == 0) {
		printf("Not-Palindrome\n");
		return 0;
	}
	
	printf("Is-Palindrome\n");


	return 0;

/*	
	unsigned short num;
	unsigned short num2;
	num = atoi(argv[1]);
	
	int i;
	int j;
	int result = 0;

	
		for (i = 0, j = 15; i < j; i++, j--) {

			
			if ( (((num & 1) == 1) && ((num2 & 1) == 1)) || (((num & 0) == 0) && ((num2 & 0) == 0)) ) {
				result = 1;
			}
			
	}
	
	if (result == 1) {
		printf("Is-Palindrome\n");
		return 0;
	}
	
	printf("Not-Palindrome\n");

	return 0;
*/

}
