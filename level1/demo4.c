#include <stdio.h>
#include <string.h>

typedef struct
{
    char flight_number[10];
    char destination[50];
    int available_seats;
} Flight_t;

void readFlights(int n, Flight_t f[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for Flight %d:\n", i + 1);
        printf("Flight Number: \n");
        scanf("%s", f[i].flight_number);
        printf("Destination: \n");
        scanf("%s", f[i].destination);
        printf("Available Seats: \n");
        scanf("%d", &f[i].available_seats);
    }
}

void searchByDestination(int n, Flight_t f[], char searchDest[])
{
    int found = 0;
    printf("\nFlights to %s:\n", searchDest);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(f[i].destination, searchDest) == 0)
        {
            printf("Flight %s available (%d seats)\n",
                   f[i].flight_number, f[i].available_seats);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No flights available to %s\n", searchDest);
    }
}

int main()
{
    Flight_t flights[4];

    // Read 4 flights
    readFlights(4, flights);

    // Search for destination
    char searchDest[50];
    printf("\nEnter destination to search: ");
    scanf("%s", searchDest);

    // Search and display
    searchByDestination(4, flights, searchDest);

    return 0;
}
