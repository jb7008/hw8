/*
 * Programmer : Josh Booth      Date : Apr 11 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Reads and performs calculations on values in scientific notation
 */

#include <stdio.h> /* Includes printf, scanf */
#include <math.h> /* Includes pow */

#define MAX_STR_LEN 80 /* Max string length */

/* Struct representing a number in scientific notation */
typedef struct{
  double mantissa;
  int exponent;
} sci_not_t;

/* Scans in sci_not_t */
sci_not_t scan_sci(void);
/* Adds two sci_not_t values */
sci_not_t sci_sum(sci_not_t value1, sci_not_t value2);
/* Subtracts two sci_not_t values */
sci_not_t sci_diff(sci_not_t value1, sci_not_t value2);
/* Multiplies two sci_not_t values */
sci_not_t sci_multiply(sci_not_t value1, sci_not_t value2);
/* Divides two sci_not_t values */
sci_not_t sci_divide(sci_not_t value1, sci_not_t value2);
/* Prints sci_not_t */
void print_sci(sci_not_t value);
/* Converts from sci_not_t to double */
double from_sci(sci_not_t value);
/* Converts from double to sci_not_t */
sci_not_t to_sci(double value);

int
main(void)
{
  /* Gets sci_not_t values from input */
  printf("Enter value1: ");
  sci_not_t value1 = scan_sci();
  printf("Enter value2: ");
  sci_not_t value2 = scan_sci();

  /* Prints values input */
  printf("\nValues input: ");
  print_sci(value1);
  printf(" ");
  print_sci(value2);
  printf("\n");

  /* Prints sum of values */
  printf("Sum: ");
  print_sci(sci_sum(value1, value2));
  printf("\n");

  /* Prints difference of values */
  printf("Difference: ");
  print_sci(sci_diff(value1, value2));
  printf("\n");

  /* Prints product of values */
  printf("Product: ");
  print_sci(sci_multiply(value1, value2));
  printf("\n");

  /* Prints quotients of values */
  printf("Quotient: ");
  print_sci(sci_divide(value1, value2));
  printf("\n");

  return 0;
}

/* Scans in sci_not_t */
sci_not_t
scan_sci(void)
{
  double mantissa; /* Value for holding the entire input value */
  int exponent = 0; /* Temporary exponent */
  sci_not_t temp; /* Temporary variable for return structure */

  /* Gets input string */
  scanf("%lf", &mantissa);

  /* Breaks up input into mantissa and exponent */
  while(mantissa >= 1)
  {
    mantissa /= 10;
    exponent++;
  }
  
  /* Assigns broken up parts to struct */
  temp.mantissa = mantissa;
  temp.exponent = exponent;

  /* Checks if mantissa is in valid range */
  if(temp.mantissa < 0.1 || temp.mantissa > 1.0)
  {
    printf("Mantissa not in valid range\n");
  }

  return temp; /* Returns result */
}

/* Adds two sci_not_t values */
sci_not_t
sci_sum(sci_not_t value1, sci_not_t value2)
{
  /* Copies two values to temp variables in regular notation */
  double val1 = from_sci(value1);
  double val2 = from_sci(value2);

  /* Struct holding added sums */
  sci_not_t sum;

  /* Adds values */
  sum = to_sci(val1 + val2);

  /* Returns added struct */
  return(sum);
}


/* Subtracts two sci_not_t values */
sci_not_t
sci_diff(sci_not_t value1, sci_not_t value2)
{
  /* Copies two values to temp variables in regular notation */
  double val1 = from_sci(value1);
  double val2 = from_sci(value2);

  /* Struct holding added sums */
  sci_not_t sum;

  /* Subtracts values */
  sum = to_sci(val1 - val2);

  /* Returns added struct */
  return(sum);
}

/* Multiplies two sci_not_t values */
sci_not_t
sci_multiply(sci_not_t value1, sci_not_t value2)
{
  /* Copies two values to temp variables in regular notation */
  double val1 = from_sci(value1);
  double val2 = from_sci(value2);

  /* Struct holding added sums */
  sci_not_t sum;

  /* Multiplies values */
  sum = to_sci(val1 * val2);

  /* Returns added struct */
  return(sum);
}

/* Divides two sci_not_t values */
sci_not_t
sci_divide(sci_not_t value1, sci_not_t value2)
{
  /* Copies two values to temp variables in regular notation */
  double val1 = from_sci(value1);
  double val2 = from_sci(value2);

  /* Struct holding added sums */
  sci_not_t sum;

  /* Divides values */
  sum = to_sci(val1 / val2);

  /* Returns added struct */
  return(sum);
}


/* Prints sci_not_t value */
void
print_sci(sci_not_t value)
{
  printf("%fe%d", value.mantissa, value.exponent);
}

/* Converts value from sci_not_t to double */
double
from_sci(sci_not_t value)
{
  /* If value > 1 */
  while(value.exponent > 0)
  {
    value.mantissa *= 10; /* Increase mantissa */
    value.exponent--; /* Decrease exponent */
  }
  /* If value < 1 */
  while(value.exponent < 0)
  {
    value.mantissa /= 10; /* Decrease mantissa */
    value.exponent++; /* Increase exponent */
  }

  /* Return adjusted mantissa */
  return value.mantissa;
}

/* Converts value from double to sci_not_t */
sci_not_t
to_sci(double value)
{
  sci_not_t temp; /* Temp variable for converted value */
  temp.exponent = 0; /* Initializes exponent */
  /* Reduces value if higher than 1 */
  while(value > 1)
  {
    value /= 10;
    temp.exponent++;
  }
  /* Decreases value if lower than 1 */
  while(value <= 0.1)
  {
     value *= 10;
     temp.exponent--;
  }
  /* Assigns adjusted mantissa to temp */
  temp.mantissa = value;

  /* Returns struct */
  return temp;
}
