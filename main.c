#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numberOfBedrooms;
    int numberOfBathrooms;
    int squareFootage;
} House;

int getBedrooms(House *house) { return house->numberOfBedrooms; }

void setBedrooms(House *house, int bedrooms) {
    house->numberOfBedrooms = bedrooms;
}

// Not working because we instantiate a new house and do not pass the memory
// address to the function.
// So I should return a new house with the new value.
// HACK: Bad for Memory
void noPointerSet(House house, int bedrooms) {
    house.numberOfBedrooms = bedrooms;
}

int noPointerGet(House house) { return house.numberOfBedrooms; }

int main(int argc, char *argv[]) {
    House myHouse = {4, 2, 2000};
    House youHouse = {8, 2, 1500};
    int bedrooms = getBedrooms(&myHouse);

    printf("Bedrooms: %d\n", bedrooms);
    setBedrooms(&myHouse, 3);
    bedrooms = getBedrooms(&myHouse);
    printf("Bedrooms: %d\n", bedrooms);

    printf("----------------------------------\n");
    
    bedrooms = noPointerGet(youHouse);
    printf("Bedrooms: %d\n", bedrooms);
    noPointerSet(youHouse, 3);
    bedrooms = noPointerGet(youHouse);
    printf("Bedrooms: %d\n", bedrooms);

    return EXIT_SUCCESS;
}
