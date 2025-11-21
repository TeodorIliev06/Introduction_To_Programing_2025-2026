#include <iostream>

// checks if bit is 1 or 0
bool checkBit(int n, int ind) {
	return n & (1 << ind);
}

// toggles bit at position ind (1 becomes 0, 0 becomes 1)
int toggleBit(int n, int ind) {
	return n ^ (1 << ind);
}

// makes bit 0 at position ind
int clearBit(int n, int ind) {
	return n & ~(1 << ind);
}

// makes bit 1 at position ind
int turnBit(int n, int ind) {
	return n | (1 << ind);
}

// task2
int countOneBits(int num) {
	int count = 0;

	while (num)
	{
		if (checkBit(num, 0))
		{
			count++;
		}

		num >>= 1;
	}

	return count;
}


// task 3
int toggleFirstOne(int num) {
	if (num == 0)
		return 0;

	int ind = 0;

	while (true)
	{
		if (checkBit(num, ind))
		{
			return toggleBit(num, ind);
		}
		ind++;
	}

	return -1;
}

// task 4
int getLastKBits(int num, int k) {
	int mask = (1 << k) - 1;
	return num & mask;
}

int main()
{
	
}
