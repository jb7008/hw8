
#include <stdio.h> /* Includes printf, scanf */

#define MAX_STR_LEN 80 /* Max length of string */
#define SHELLS 7 /* Number of electron shells around an atom */

/* Structure for an element on the periodic table */
typedef struct{
  int atomic_num;
  char name[MAX_STR_LEN];
  char class[MAX_STR_LEN];
  double atomic_weight;
  int electrons[SHELLS]; /* Electrons in each electron shell */
} element_t;

void scan_element(element_t *atom); /* Fills element_t struct */
void print_element(element_t atom); /* Prints elements of element_t struct */

int
main(void)
{
  element_t atom; /* Declares atom struct */

  scan_element(&atom); /* Gets elements of atom */
  print_element(atom); /* Prints element of atom */

  return 0;
}

/* Fills element_t struct */
void
scan_element(element_t *atom)
{
  /* Gets atomic number */
  printf("Enter atomic #: ");
  scanf("%d", &atom->atomic_num);
  /* Gets atom's name */
  printf("Enter name: ");
  scanf("%s", atom->name);
  /* Gets class of atom */
  printf("Class: ");
  scanf("%s", atom->class);
  /* Gets weight of atom */
  printf("Weight: ");
  scanf("%lf", &atom->atomic_weight);
  /* Gets number of shells in each electron */
  printf("Enter electron shell: ");
  for(int i = 0; i < SHELLS; i++)
  {
    scanf("%d", &atom->electrons[i]);
  }
}

/* Prints elements of the element_t struct */
void
print_element(element_t atom)
{
  printf("\n");
  printf("%d  - %s\n", atom.atomic_num, atom.name);
  printf("Weight: %.1f\n", atom.atomic_weight);
  printf("Class: %s\n", atom.class);
  printf("Shells: ");
  /* Prints num of electrons in each electron shell */
  for(int i = 0; i < SHELLS; i++)
  {
    printf("%d ", atom.electrons[i]);
  }
  printf("\n");
}
