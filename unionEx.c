//this program demonstrates how to use Union type to show endianness of computer system
#include <stdio.h>

typedef union
{
	int x;
	unsigned char xarr[4];
}U4;

int main(void)
{
	U4 my;
	int i;
	my.x = 0x01020304;	//give a value for x

	for(i=0; i<4; i++)
	{
		printf("byte %d = %d, addr = %p\n", i+1, my.xarr[i], &my.xarr[i]);
	}
	if(my.xarr[0] == 0x01)
		printf("Big endian\n");
	else
		printf("Little endian\n");

	my.x = 0x0A0B0C0D;
	for(i=0; i<4; i++)
        {
                printf("byte %d = %d, addr = %p\n", i+1, my.xarr[i], &my.xarr[i]);
        }

}
