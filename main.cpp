#include <iostream>
#include <stdint.h>
#include <netinet/in.h>

int main()
{
    FILE *file1;
    file1 = fopen("/home/kali/Desktop/thousand.bin","r");
    if (file1 == NULL) return -1;
    uint32_t thousand;

    FILE *file2;
    file2 = fopen("/home/kali/Desktop/five-hundred.bin","r");
    if (file2 == NULL) return -1;
    uint32_t five_hundred;

    fread(&thousand, sizeof(uint32_t), 1, file1);
    fread(&five_hundred, sizeof(uint32_t), 1, file2);

    thousand = htonl(thousand);
    five_hundred = htonl(five_hundred);

    uint32_t result;
    result = thousand + five_hundred;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",thousand,thousand,five_hundred,five_hundred,result,result);

    fclose(file1);
    fclose(file2);

}
