/*
###
Simple Hashing Functions
###

Description:
For different data types: float & int

*/

inline hashFloat(Key v, int M)
// Generating values in range s and t
{ return (int) M*(v-s)/(t-s); }

inline hashInt(Key v, int M)
// Using the golden ratio
{ return (int) (.618033 * (float) v) % M; }

inline int hashFast(Key, int M)
// choosing M = multiple of 2 (incl. collisions)
{ return v & (M-1); }
