
#include <stdio.h> /* Includes printf, scanf */
#include <string.h> /* Includes strcmp */

#define MAX_NAME_LEN 10 /* Max nickname length */
#define MAX_ADDR 100 /* Max number of addresses to read */
/* Sentinal nickname to stop reading file */
#define NICKNAME_SENTINEL "none"

/* Structure for holding a computer address */
typedef struct{
  int xx;
  int yy;
  int zz;
  int mm;
  char nickname[MAX_NAME_LEN];
} address_t;

/* Reads in computer address */
int scan_address(address_t *computer);
/* Checks if two computers are one the same network */
int local_address(address_t computer1, address_t computer2);
/* Prints computer address */
void print_address(address_t computer1, address_t computer2);

int
main(void)
{
  int num_of_computers = 0; /* Number of computers read */
  address_t computers[MAX_ADDR]; /* Holds computer addresses */

  /* Reads computers while sentinel value hasn't been reached */
  while(scan_address(&computers[num_of_computers]))
  {
    num_of_computers++;
  }
 
  /* Reads through each computer in the list computers and checks if they
   * are in the same network */
  for(int i = 0; i < num_of_computers; i++)
  {
    /* j = i + 1 skips over already compared computers and stop comparison
     * between the same compute */
    for(int j = i + 1; j < num_of_computers; j++)
    {
     if(local_address(computers[i], computers[j]))
     {
       print_address(computers[i], computers[j]);
     }
    }
  }

  return 0;
}

/* Reads in computer address */
int
scan_address(address_t *computer)
{

 /* Reads in computer information */
 printf("Enter IP address and name: ");
 scanf("%d.%d.%d.%d %s", &computer->xx, &computer->yy,
                         &computer->zz, &computer->mm, computer->nickname);

 /* Checks if sentinel values were reached */
 if(computer->xx == 0 && computer->yy == 0 && computer->zz == 0 &&
     !strcmp(computer->nickname, NICKNAME_SENTINEL))
 {
   return 0; /* Returns 0 if sentinel values were read */
 }
 else /* Returns 1 if read successfully */
 {
   return 1;
 }
 
}

/* Checks if two computers are on the same network */
int
local_address(address_t computer1, address_t computer2)
{
  return(computer1.xx == computer2.xx && computer1.yy == computer2.yy);
}

/* Prints that two machines are on the same network */
void
print_address(address_t computer1, address_t computer2)
{
  printf("Machines %s and %s are on the same local network.\n",
      computer1.nickname, computer2.nickname);
}
