/*
 * myLed.c
 *
 *  Created on: Sep 6, 2023
 *      Author: sinem
 */

#include "main.h"
#include "myLed.h"

// Her LED için bir led_t yapısı tanımlanır
led_t led_1 = {0, 0, 0.0, 1000};
led_t led_2 = {0, 0, 0.0, 1000};
led_t led_3 = {0, 0, 0.0, 1000};
led_t led_4 = {0, 0, 0.0, 1000};

// LED'lerin durumunu ve yanma süresini kontrol eden işlev
void ledHandle(void)
{
// LED1'in yanma süresini kontrol et
	  if((time_count - led_1.count) > led_1.period/2){
			  led_1.count = time_count;
// LED1'in durumunu değiştir (yanıp sönme)
		   if (led_1.durum == 0) {
			   led_1.durum = 1;
		   }
		   else {
			   led_1.durum = 0;
		   }
// LED1'in fiziksel durumunu güncelle
		    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, led_1.durum);

		  }
// Aynı işlemler LED2, LED3 ve LED4 için tekrarlanır
		  if((time_count - led_2.count) > led_2.period/2){
			  led_2.count = time_count;

		   if (led_2.durum == 0) {
			   led_2.durum = 1;
		   }
		   else {
			   led_2.durum = 0;
		   }

		    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, led_2.durum);

		  }

		  if((time_count - led_3.count) > led_3.period/2){
			  led_3.count = time_count;

		   if (led_3.durum == 0) {
			   led_3.durum = 1;
		   }
		   else {
			   led_3.durum = 0;
		   }

		    HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, led_3.durum);

		  }

		  if((time_count - led_4.count) > led_4.period/2){
			  led_4.count = time_count;

		   if (led_4.durum == 0) {
			   led_4.durum = 1;
		   }
		   else {
			   led_4.durum = 0;
		   }

		    HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, led_4.durum);
		  }
// LED'lerin frekansını güncelle
		  led_1.frequency = 1.0/led_1.period;
		  led_2.frequency = 1.0/led_2.period;
		  led_3.frequency = 1.0/led_3.period;
		  led_4.frequency = 1.0/led_4.period;
}
// LED'nin yanma süresini ayarlayan işlev
void setLedPeriyot(led_t *led, int pri)
{
    led->period = pri;
}
