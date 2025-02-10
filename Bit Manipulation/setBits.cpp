// C++ Program to Set a given bit of a binary number
#include <iostream>

using namespace std;

int main()
{
    // Binary: 01100111
    unsigned int num = 103;
    cout << "Num: " << num << endl;

    // Setting the 5th bit (0-based index)
    unsigned int bit_position = 4;

    // Create a mask with only the 5th bit set to 1
    unsigned int mask = 1 << bit_position;

    // Set the bit using OR
    num = num | mask;

    // Print the result
    cout << "Result: " << num << endl;

    return 0;
}