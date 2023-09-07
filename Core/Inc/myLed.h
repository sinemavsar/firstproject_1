/*
 * myLed.h
 *
 *  Created on: Sep 6, 2023
 *      Author: sinem
 */

#ifndef INC_MYLED_H_
#define INC_MYLED_H_

typedef struct _led {
	int count;
	int durum;
	float frequency;
	int period;
} led_t;

extern led_t led_1;
extern led_t led_2;
extern led_t led_3;
extern led_t led_4;

void ledHandle(void);
void setLedPeriyot(led_t *led, int pri);

#endif /* INC_MYLED_H_ */
