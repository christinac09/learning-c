// structs are like classes in python or types/interfaces in ts (?)

enum Day
{
    SUNDAY,  // 0
    MONDAY,  // 1
    TUESDAY, // 2
}; // representing these as integers(?) - in the pokemon thing, it made if statements and stuff simpler
// saving space/memory

union Data
{
    int i;
    float f;
}; // when data is not needed at the same time - loading one data, and then when u need the other, it replaces the previous data (overwriting it) so they use the same space in memory
