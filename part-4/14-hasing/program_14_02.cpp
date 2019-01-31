/*
###
Program 14.2: Universal hash function (for string keys)
###

Description:
One multiplication and one addition per character in the key.
Using pseudorandom coefficient values (a & b) instead of a fixed radix
(e.g. 127 as prime), to approximate the ideal of having a collision 
between two given nonequal keys occur with probability 1/M. We use a 
crude random-number generator to avoid spending excessive time on
computing the hash function.

Properties:
- Approximate chance of having collisions to 1/M by using pseudorandom sequence

*/

int hashU(char* v, int M)
{
    int h, a = 31415, b = 27183;
    for(h=0; *v != 0; v++, a = a*b % (M-1))
        h = (a*h + *v) % M;
    return (h < 0) ? (h + M) : h;
}
