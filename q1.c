/*
 * Programmer : Josh Booth      Date : Apr 11 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Creates a structure to hold the properties of an automobile and functions
 * to read and print its values
 */

#include <stdio.h> /* Includes printf, scanf */

#define MAX_STR_LEN 80 /* Max length of a string */
#define TO_PERCENT 100.0 /* Converts float to percent */
#define ERROR 1 /* Value to return if error reading

/* Structure for holding a date */
  typedef struct {
    int year;
    int month;
    int day;
  } date_t;

/* Structure for the properties of a gas tank */
  typedef struct{
    float capacity;
    float level;
  } tank_t;

/* Structures for the properties of a car */
  typedef struct {
    char make[MAX_STR_LEN];
    char model[MAX_STR_LEN];
    int odometer;
    date_t manufacture_date;
    date_t purchase_date;
    tank_t gas_tank;
  } auto_t;

int scan_and_print(void); /* Driver function scans and prints cars until EOF */
void scan_date(date_t *date); /* Fills date struct */
void scan_tank(tank_t *tank); /* Fills tank struct */
int scan_auto(auto_t *car); /* Fills auto struct */
void print_auto(auto_t *car); /* Prints auto struct */
void print_tank(tank_t *tank); /* Prints tank struct */
void print_date(date_t *date); /* Prints date struct */

int
main(void)
{
  /* Runs while the EOF hasn't been hit */
  while(scan_and_print() != ERROR);

  return 0;
}

/* Fills date struct */
void
scan_date(date_t *date)
{
  scanf("%d %d %d", &date->year, &date->month, &date->day);
}

/* Fills tank struct */
void
scan_tank(tank_t *tank)
{
  printf("Enter tank capacity and level: ");
  scanf("%f %f", &tank->capacity, &tank->level);
}

/* Fills auto struct */
int
scan_auto(auto_t *car)
{
  int test;
  printf("Enter make: ");
  /* Returns 0 if EOF has been reached */
  if(scanf("%s", car->make) == EOF)
  {
    return ERROR;
  }
  printf("Enter model: ");
  scanf("%s", car->model);
  printf("Enter odometer: ");
  scanf("%d", &car->odometer);
  return 0;
}

/* Prints date in YYYY/MM/DD */
void print_date(date_t *date)
{
  printf("%04d/%02d/%02d\n", date->year, date->month, date->day);
}

void print_tank(tank_t *tank)
{
  /* Calculates percent of tank filled */
  float tank_percent;
  tank_percent = (tank->level / tank->capacity) * TO_PERCENT;
  printf("Tank: %.1f/%.1f (%.1f%%)\n",
          tank->level, tank->capacity, tank_percent);
}

/* Prints car's information */
void print_auto(auto_t *car)
{
  printf("Make: %s\n", car->make);
  printf("Model: %s\n", car->model);
  printf("Odometer: %d\n", car->odometer);
}

/* Driver function scans and prints cars until EOF */
int
scan_and_print(void)
{
  auto_t car; /* Car struct */

  /* Fills car struct, but returns 1 if EOF is encountered */
  if(scan_auto(&car) == ERROR)
  {
    return ERROR;
  }
  /* Fills date struct for manufacture date */
  printf("Enter manufacture date (Y M D): ");
  scan_date(&car.manufacture_date);
  /* Fills date struct for purchase date */
  printf("Enter purchase date (Y M D): ");
  scan_date(&car.purchase_date);
  /* Fills tank struct for gas tank */
  scan_tank(&car.gas_tank);

  /* Prints car data */
  print_auto(&car);
  /* Prints manufacture date */
  printf("Manufacture date: ");
  print_date(&car.manufacture_date);
  /* Prints purchase date */
  printf("Purchase date: ");
  print_date(&car.purchase_date);
  /* Prints tank info */
  print_tank(&car.gas_tank);

  return 0;
}


