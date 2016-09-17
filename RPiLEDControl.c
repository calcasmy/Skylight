/* Controlling LED using BCM2835.h header file on Raspberry Pi. */

/* Note: Before building the program, make sure that the build setting for Geany are changed in 
 * 
 * Build -> Set Build Commands ->
 * 
 * C Commands
 * Compile  : gcc -Wall -c "%f" -l bcm2835
 * Build    : gcc -Wall -o "%e" "%f" -l bcm2835
 * 
 * Execute Commands
 * Execute  : sudo "./%e"
 * 
 * to make sure that the complier knows where to locate the header files
 */
 

#include <bcm2835.h>

int main (int argc, char **argv)
{
  /* Initilizing the bcm2835 library */
  if(!bcm2835_init())
    return 1;

  /* Setting pin direction to Output */    
  bcm2835_gpio_fsel(18, BCM2835_GPIO_FSEL_OUT); /* 18 - RPI_GPIO_P1_12 */
  
  unsigned int _delay = 1000;
  while(1)
  {
    bcm2835_gpio_set(18);   /* Pin 18 = 1 = high = on */
    bcm2835_delay(_delay);  /* delay in Milliseconds */
    bcm2835_gpio_clr(18);   /* Pin 18 = 0 = low = off */
    bcm2835_delay(_delay);  /* delay in Milliseconds */
  }
  return 0;
}
