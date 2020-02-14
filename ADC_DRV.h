/*
 * ADC_DRV1.h
 *
 *  Created on: Dec 7, 2019
 *      Author: ali zewail
 */

#ifndef ADC_DRV_H_
#define ADC_DRV_H_





typedef enum{
    ADC0=0,
    ADC1=1

}ADC_MOD_t;

typedef enum{
    AIN0=0,
    AIN1,
    AIN2,
    AIN3,
    AIN4,
    AIN5,
    AIN6,
    AIN7,
    AIN8,
    AIN9,
    AIN10,
    AIN11
}ADC_CH_t;

typedef enum{
    SS0=0,
    SS1,
    SS2,
    SS3
}SS_t;








void ADC_voidInit(ADC_MOD_t module,ADC_CH_t channel,SS_t sampler);
void ADC_voidStartConversion(ADC_MOD_t module ,SS_t sampler);
uint16 ADC_uint16GetData(ADC_MOD_t module,SS_t sampler);
void ADC_voidChangeChannel(ADC_CH_t);





#endif /* ADC_DRV_H_ */
