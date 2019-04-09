#include <stdio.h>

/*short decimalToBinary(short num) {
	short i;
	for (i = 15; i >= 0; i--) {
		int k = num >> i;
		if (k & 1) {
			cout << "1";
		} else {
			cout << "0";
		}
	}
}
*/
	

unsigned short get(unsigned short num, unsigned short x) {
	
	unsigned short bit;
	bit = (num >> x) & 1;
	
	return bit;
}

unsigned short set(unsigned short num, unsigned short x, unsigned short y) {
	
	unsigned short bin = 1 << x;
	unsigned short result;
	
	result = (num & ~bin) | ((y << x) & bin);
	
	return result;
}

unsigned short comp(unsigned short num, unsigned short x) {
	
	unsigned short bit;
	bit = get(num, x);
	
	if (bit == 1) {
		bit = 0;
		
		} else {
			
		bit = 1;
		}
		
		num = set(num, x, bit);
		return num;
}



int main(int argc, char **argv) {
	
	FILE *fptr;
	fptr = fopen(argv[1], "r");
	
	if (fptr == NULL) {
		return 0;
	}
	
	unsigned short num;
	fscanf(fptr, "%hu", &num);
	//short position;
	//short bitValue;
	
	//fscanf(fptr, "%hu\t%hu\t%hu\n", &num, &position, &bitValue);
	
	unsigned short x;
	unsigned short y;
	char operation[5];
	
	while (fscanf(fptr, "%s\t%hu\t%hu", operation, &x, &y) != EOF) {
		
		if (operation[0] == 's') {
			num = set(num, x, y);
			printf("%hu\n", num);
		}
		
		if (operation[0] == 'g') {
			printf("%hu\n", get(num, x));
		}
		
		if (operation[0] == 'c') {
			num = comp(num, x);
			printf("%hu\n", num);
		}
		
	}
	
	//num = changeBit(num, position, bitValue);
	//printf("%hu\n", num);
	
	fclose(fptr);
	return 0;
}
