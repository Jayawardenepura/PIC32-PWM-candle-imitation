
#include "config.h"
#include <xc.h>          /* Defines special function registers, CP0 regs  */

#include <stdint.h>         /* For uint32_t definition                        */
#include <stdbool.h>        /* For true/false definition                      */

#include "user.h"           /* User funct/params, such as InitApp             */

uint16_t __seed = 1;
/* random generation */
#define random() ({__seed = 5 * __seed + 3;})
uint16_t r;
uint8_t lower;

int32_t main(void)
{

    InitTimer2AndOC8();

    while (1) {
	r = random();
	lower = r;
	if (r > 50461) {
	    OC8RS = (15 << 4) | lower;  /* var = 240 + [0..15] */
	} else if (r > 39976) {
	    OC8RS = (14 << 4) | lower;
	} else if (r > 34078) {
	    OC8RS = (13 << 4) | lower;
	} else if (r > 30801) {
	    OC8RS = (12 << 4) | lower;
	} else if (r > 27524) {
	    OC8RS = (11 << 4) | lower;
	} else if (r > 24247) {
	    OC8RS = (10 << 4) | lower;
	} else if (r > 20971) {
	    OC8RS = (9 << 4) | lower;
	} else if (r > 17694) {
	    OC8RS = (8 << 4) | lower;
	} else if (r > 14417) {
	    OC8RS = (7 << 4) | lower;
	} else if (r > 11140) {
	    OC8RS = (6 << 4) | lower;
	} else if (r > 7863) {
	    OC8RS = (5 << 4) | lower;
	} else if (r > 4587) {
	    OC8RS = (4 << 4) | lower;
	} else if (r > 1965) {
	    OC8RS = (3 << 4) | lower;
	} else if (r > 1310) {
	    OC8RS = (2 << 4) | lower;
	} else if (r > 654) {
	    OC8RS = (1 << 4) | lower;
	} else 
	    OC8RS = lower;  
    }

	return 0;
}
