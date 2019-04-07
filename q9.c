
#include <stdio.h> /* Includes printf, scanf */

#define VOLTAGE 12 /* Model voltage of battery */
#define MAX_JOULES 5000000 /* Max energy for the model battery */
#define SAMPLE_AMPS 8 /* Number of amps to test the battery with */
/* Smaller number of amps to test the battery with */
#define SMALL_SAMPLE_AMPS 4
#define LIGHT_TIME 15 /* Number of minutes to use the light for */
#define MIN_TO_SEC 60.0

/* Structure for the properties of a battery */
typedef struct{
  double voltage;
  double joules_max;
  double joules;
} battery_t;

/* Determines if the battery can power the device */
int power_device(battery_t *battery, double current, double time);
/* Determines how long the battery at max energy can provide power */
double max_time(battery_t battery, double current);
/* Sets battery's joules to joules_max */
void recharge(battery_t *battery);

int
main(void)
{
  double use_time; /* Time the battery can use a device */

  battery_t battery; /* Model battery */
  battery.voltage = VOLTAGE; /* Sets battery voltage */
  battery.joules_max = MAX_JOULES; /* Sets max battery energy */
  recharge(&battery); /* Recharges battery to max energy */

  /* Battery uses 4 amp device for 15 mins */
  if(power_device(&battery, SMALL_SAMPLE_AMPS, LIGHT_TIME) == 0)
  {
    printf("The battery can not power the device\n");
  }
  else
  {
    printf("The battery has %.1f joules remaining\n", battery.joules);
  }

  /* Finds time the battery can power an 8 amp device with remaining charge */
  use_time = max_time(battery, SAMPLE_AMPS);

  printf("and can power an %dA device for %.1f s\n", SAMPLE_AMPS, use_time);

  /* Recharges the battery */
  recharge(&battery);

  /* Finds time the battery can power an 8 amp device fully charged */
  use_time = max_time(battery, SAMPLE_AMPS);

  printf("Recharged, it can power an %dA device for %.1f s\n",
      SAMPLE_AMPS, use_time);

  return 0;
}

/* Determines if the battery can power the device */
int
power_device(battery_t *battery, double current, double time)
{
  /* Finds energy required with formula w = v*i*t */
  double energy_required = current * (time * MIN_TO_SEC) * battery->voltage;

  /* If too much energy is required */
  if(energy_required > battery->joules)
  {
    return 0;
  }
else /* Otherwise, subtract the energy */
  {
    battery->joules -= energy_required;
    return 1;
  }
}

/* Returns the time a battery at max energy can power a device */
double
max_time(battery_t battery, double current)
{
  /* Uses formula t = w / vi */
  return(battery.joules / (battery.voltage * current));
}

/* Sets joules to joules_max */
void
recharge(battery_t *battery)
{
  battery->joules = battery->joules_max;
}
