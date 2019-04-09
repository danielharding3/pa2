#include <stdio.h>
#include <stdlib.h>

/*unsigned short numberOfOnes(unsigned short num) {
	int i;
	int count = 0;
	unsigned short bit;
	for (i = 0; i < 15; i++) {
		bit = num >> i;
		if (bit == 1) {
			count++;
		}
	}
	return count;
}*/

unsigned short numberOfOnes(unsigned short num) {
	/*int i;
	int count;
	for (i = 0; i < 16; i++) {
		if (num & (1 << i)) {
			count++;
		}
	}
	printf("%hu", count);
	return count;*/
unsigned short count = 0;
	
	while (num != 0) {
		
		if ((num & 1) == 1) {
			count++;
		}
		
			num = num >> 1;
	}
	
	return count;
	
}

int main(int argc, char **argv) {
	
	unsigned short num;
	num = atoi(argv[1]);
	int i;
	int pairs = 0;
	int numOnes;
	numOnes = numberOfOnes(num);
	
	for (i = 0; i < 16; i++) {
		if (num & (1 << i)) {
			if (num & (1 << (i + 1))) {
				pairs++;
				i = i + 1;
			}
		}
	}
	
	if (numOnes % 2 == 0) {
		printf("Even-Parity\t%hu\n", pairs);
	} else {
		printf("Odd-Parity\t%hu\n", pairs);
	}
	
	//printf("%hu\n", pairs);
	
	//int numOfOnes = numberOfOnes(num);
	//printf("%hu\n", numOfOnes);
	
	
	
	
	
	return 0;
}
