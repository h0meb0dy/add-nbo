#include <iostream>
#include <stdint.h>
#include <arpa/inet.h>

#define NUM_SIZE sizeof(uint32_t) // size of a number

using namespace std;

int main(int argc, char **argv)
{
    /* argv check */

    if (argc != 3)
    {
        cout << "syntax : add-nbo <file1> <file2>" << endl // syntax error
             << "sample : add-nbo a.bin c.bin" << endl;    // usage example
    }

    /* get numbers from input files */

    char num1_arr[NUM_SIZE + 1] = {
        0,
    }; // memory for num1
    char num2_arr[NUM_SIZE + 1] = {
        0,
    }; // memory for num2

    FILE *num1_fp = fopen(argv[1], "r"); // open num1 file
    FILE *num2_fp = fopen(argv[2], "r"); // open num2 file

    fread(num1_arr, NUM_SIZE, 1, num1_fp); // read num1 from num1 file
    fread(num2_arr, NUM_SIZE, 1, num2_fp); // read num2 from num2 file

    fclose(num1_fp); // close num1 file
    fclose(num2_fp); // close num2 file

    /* add num1 and num2 */

    uint32_t num1 = ntohl(*(uint32_t *)num1_arr); // convert num1 to host order
    uint32_t num2 = ntohl(*(uint32_t *)num2_arr); // convert num2 to host order

    printf("%d(%p) + %d(%p) = %d(%p)\n", num1, num1, num2, num2, num1 + num2, num1 + num2); // print result

    return 0;
}