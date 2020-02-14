#include "STD_TYPES.h"
#include "Utils.h"
#include "RegMap.h"
#include "ADC_DRV.h"

void ADC_voidInit(ADC_MOD_t module, ADC_CH_t channel, SS_t sampler)
{
    //setting clk for ADC
    if (module == ADC0)
    {
        SET_BIT(RCGCADC, 0);

        //setting clk for GPIO GPIO_Port according to the AINx PIN
        if (channel == AIN0 || channel == AIN1 || channel == AIN2
                || channel == AIN3 || channel == AIN8 || channel == AIN9)
            SET_BIT(GPIO_RCGC, 4); //GPIO_Port E
        else if (channel == AIN4 || channel == AIN5 || channel == AIN6
                || channel == AIN7)
            SET_BIT(GPIO_RCGC, 3); //GPIO_Port D
        else if (channel == AIN10 || channel == AIN11)
            SET_BIT(GPIO_RCGC, 1); //GPIO_Port B

        //initializing the analong input to the GPIO GPIO_Port
        if (channel == AIN0) //PE3
        {
            SET_BIT(GPIO_PortEAFSEL, 3); //enabling alternate function to pin 3 in GPIO_Port E
            CLR_BIT(GPIO_PortEDEN, 3); //disabling the digital functions to pin 3 in GPIO_Port E which enables the analog input
            SET_BIT(GPIO_PortEAMSEL, 3); //disabling the analong isolation which enables the analog functions to pin 3 in GPIO_Port E
        }
        else if (channel == AIN1) //PE2
        {
            SET_BIT(GPIO_PortEAFSEL, 2);
            CLR_BIT(GPIO_PortEDEN, 2);
            SET_BIT(GPIO_PortEAMSEL, 2);
        }
        else if (channel == AIN2) //PE1
        {
            SET_BIT(GPIO_PortEAFSEL, 1);
            CLR_BIT(GPIO_PortEDEN, 1);
            SET_BIT(GPIO_PortEAMSEL, 1);
        }
        else if (channel == AIN3) //PE0
        {
            SET_BIT(GPIO_PortEAFSEL, 0);
            CLR_BIT(GPIO_PortEDEN, 0);
            SET_BIT(GPIO_PortEAMSEL, 0);
        }
        else if (channel == AIN4) //PD3
        {
            SET_BIT(GPIO_PortDAFSEL, 3);
            CLR_BIT(GPIO_PortDDEN, 3);
            SET_BIT(GPIO_PortDAMSEL, 3);
        }
        else if (channel == AIN5) //PD2
        {
            SET_BIT(GPIO_PortDAFSEL, 2);
            CLR_BIT(GPIO_PortDDEN, 2);
            SET_BIT(GPIO_PortDAMSEL, 2);
        }
        else if (channel == AIN6) //PD1
        {
            SET_BIT(GPIO_PortDAFSEL, 1);
            CLR_BIT(GPIO_PortDDEN, 1);
            SET_BIT(GPIO_PortDAMSEL, 1);
        }
        else if (channel == AIN7) //PD0
        {
            SET_BIT(GPIO_PortDAFSEL, 0);
            CLR_BIT(GPIO_PortDDEN, 0);
            SET_BIT(GPIO_PortDAMSEL, 0);
        }
        else if (channel == AIN8) //PE5
        {
            SET_BIT(GPIO_PortEAFSEL, 5);
            CLR_BIT(GPIO_PortEDEN, 5);
            SET_BIT(GPIO_PortEAMSEL, 5);
        }

        else if (channel == AIN9) //PE4
        {
            SET_BIT(GPIO_PortEAFSEL, 4);
            CLR_BIT(GPIO_PortEDEN, 4);
            SET_BIT(GPIO_PortEAMSEL, 4);
        }
        else if (channel == AIN10) //PB4
        {
            SET_BIT(GPIO_PortBAFSEL, 4);
            CLR_BIT(GPIO_PortBDEN, 4);
            SET_BIT(GPIO_PortBAMSEL, 4);
        }
        else if (channel == AIN11) //PB5
        {
            SET_BIT(GPIO_PortBAFSEL, 5);
            CLR_BIT(GPIO_PortBDEN, 5);
            SET_BIT(GPIO_PortBAMSEL, 5);
        }

        //intilization of the sample sequencer
        if (sampler == SS3)
        {
            CLR_BIT(ADC0ACTSS, 3); // first we disable the SS bit before configuretion to avoid errors

            CLR_BIT(ADC0EMUX, 15); //choosing the trigger for the approriate SS (choosing it as default (processor)
            CLR_BIT(ADC0EMUX, 14);
            CLR_BIT(ADC0EMUX, 13);
            CLR_BIT(ADC0EMUX, 12);

            if (channel == AIN0) // choosing the channel to operate
                ADC0SSMUX3 |= 0;
            else if (channel == AIN1)
                ADC0SSMUX3 |= 1;
            else if (channel == AIN2)
                ADC0SSMUX3 |= 2;
            else if (channel == AIN3)
                ADC0SSMUX3 |= 3;
            else if (channel == AIN4)
                ADC0SSMUX3 |= 4;
            else if (channel == AIN5)
                ADC0SSMUX3 |= 5;
            else if (channel == AIN6)
                ADC0SSMUX3 |= 6;
            else if (channel == AIN7)
                ADC0SSMUX3 |= 6;
            else if (channel == AIN7)
                ADC0SSMUX3 |= 7;
            else if (channel == AIN8)
                ADC0SSMUX3 |= 8;
            else if (channel == AIN9)
                ADC0SSMUX3 |= 9;
            else if (channel == AIN10)
                ADC0SSMUX3 |= 10;
            else if (channel == AIN11)
                ADC0SSMUX3 |= 11;

            ADC0SSCTL3 |= 6; //setting the SS to single ended(bit0) and one sample then stop(SS3)(bit1)  and connecting the interupt flag to the isr (bit3)

            SET_BIT(ADC0ACTSS, 3); //enabling the sample sequneser
        }
        else if (sampler == SS2)
        {
            CLR_BIT(ADC0ACTSS, 2); // first we disable the SS bit before configuretion to avoid errors

            CLR_BIT(ADC0EMUX, 11); //choosing the trigger for the approriate SS (choosing it as default (processor)
            CLR_BIT(ADC0EMUX, 10);
            CLR_BIT(ADC0EMUX, 9);
            CLR_BIT(ADC0EMUX, 8);

            if (channel == AIN0) // choosing the channel to operate
                ADC0SSMUX2 |= 0;
            else if (channel == AIN1)
                ADC0SSMUX2 |= 1;
            else if (channel == AIN2)
                ADC0SSMUX2 |= 2;
            else if (channel == AIN3)
                ADC0SSMUX2 |= 3;
            else if (channel == AIN4)
                ADC0SSMUX2 |= 4;
            else if (channel == AIN5)
                ADC0SSMUX2 |= 5;
            else if (channel == AIN6)
                ADC0SSMUX2 |= 6;
            else if (channel == AIN7)
                ADC0SSMUX2 |= 6;
            else if (channel == AIN7)
                ADC0SSMUX2 |= 7;
            else if (channel == AIN8)
                ADC0SSMUX2 |= 8;
            else if (channel == AIN9)
                ADC0SSMUX2 |= 9;
            else if (channel == AIN10)
                ADC0SSMUX2 |= 10;
            else if (channel == AIN11)
                ADC0SSMUX2 |= 11;

            ADC0SSCTL2 |= 0b100; //setting the SS to single ended(bit0) and more than one sample(SS2)(bit1)  and connecting the interupt flag to the isr (bit3)

            SET_BIT(ADC0ACTSS, 2); //enabling the sample sequneser

        }
        else if (sampler == SS1)
        {
            CLR_BIT(ADC0ACTSS, 1); // first we disable the SS bit before configuretion to avoid errors

            CLR_BIT(ADC0EMUX, 7); //choosing the trigger for the approriate SS (choosing it as default (processor)
            CLR_BIT(ADC0EMUX, 6);
            CLR_BIT(ADC0EMUX, 5);
            CLR_BIT(ADC0EMUX, 4);

            if (channel == AIN0) // choosing the channel to operate
                ADC0SSMUX1 |= 0;
            else if (channel == AIN1)
                ADC0SSMUX1 |= 1;
            else if (channel == AIN2)
                ADC0SSMUX1 |= 2;
            else if (channel == AIN3)
                ADC0SSMUX1 |= 3;
            else if (channel == AIN4)
                ADC0SSMUX1 |= 4;
            else if (channel == AIN5)
                ADC0SSMUX1 |= 5;
            else if (channel == AIN6)
                ADC0SSMUX1 |= 6;
            else if (channel == AIN7)
                ADC0SSMUX1 |= 6;
            else if (channel == AIN7)
                ADC0SSMUX1 |= 7;
            else if (channel == AIN8)
                ADC0SSMUX1 |= 8;
            else if (channel == AIN9)
                ADC0SSMUX1 |= 9;
            else if (channel == AIN10)
                ADC0SSMUX1 |= 10;
            else if (channel == AIN11)
                ADC0SSMUX1 |= 11;

            ADC0SSCTL1 |= 0b100; //setting the SS to single ended(bit0) and more than one sample(SS2)(bit1)  and connecting the interupt flag to the isr (bit3)

            SET_BIT(ADC0ACTSS, 1); //enabling the sample sequneser
        }
        else if (sampler == SS0)
        {
            CLR_BIT(ADC0ACTSS, 0); // first we disable the SS bit before configuretion to avoid errors

            CLR_BIT(ADC0EMUX, 3); //choosing the trigger for the approriate SS (choosing it as default (processor)
            CLR_BIT(ADC0EMUX, 2);
            CLR_BIT(ADC0EMUX, 1);
            CLR_BIT(ADC0EMUX, 0);

            if (channel == AIN0) // choosing the channel to operate
                ADC0SSMUX0 |= 0;
            else if (channel == AIN1)
                ADC0SSMUX0 |= 1;
            else if (channel == AIN2)
                ADC0SSMUX0 |= 2;
            else if (channel == AIN3)
                ADC0SSMUX0 |= 3;
            else if (channel == AIN4)
                ADC0SSMUX0 |= 4;
            else if (channel == AIN5)
                ADC0SSMUX0 |= 5;
            else if (channel == AIN6)
                ADC0SSMUX0 |= 6;
            else if (channel == AIN7)
                ADC0SSMUX0 |= 6;
            else if (channel == AIN7)
                ADC0SSMUX0 |= 7;
            else if (channel == AIN8)
                ADC0SSMUX0 |= 8;
            else if (channel == AIN9)
                ADC0SSMUX0 |= 9;
            else if (channel == AIN10)
                ADC0SSMUX0 |= 10;
            else if (channel == AIN11)
                ADC0SSMUX0 |= 11;

            ADC0SSCTL0 |= 0b100; //setting the SS to single ended(bit0) and more than one sample(SS2)(bit1)  and connecting the interupt flag to the isr (bit3)

            SET_BIT(ADC0ACTSS, 0); //enabling the sample sequneser
        }

    }

// if adc mode =ADC1 repeat all again but with ADC1 ***********************************************************************************************************************************	

    else if (module == ADC1)
    {
        SET_BIT(RCGCADC, 1);

        //setting clk for GPIO GPIO_Port according to the AINx PIN
        if (channel == AIN0 || channel == AIN1 || channel == AIN2
                || channel == AIN3 || channel == AIN8 || channel == AIN9)
            SET_BIT(GPIO_RCGC, 4); //GPIO_Port E
        else if (channel == AIN4 || channel == AIN5 || channel == AIN6
                || channel == AIN7)
            SET_BIT(GPIO_RCGC, 3); //GPIO_Port D
        else if (channel == AIN10 || channel == AIN11)
            SET_BIT(GPIO_RCGC, 1); //GPIO_Port B

        //initializing the analong input to the GPIO GPIO_Port
        if (channel == AIN0) //PE3
        {
            SET_BIT(GPIO_PortEAFSEL, 3); //enabling alternate function to pin 3 in GPIO_Port E
            CLR_BIT(GPIO_PortEDEN, 3); //disabling the digital functions to pin 3 in GPIO_Port E which enables the analog input
            SET_BIT(GPIO_PortEAMSEL, 3); //disabling the analong isolation which enables the analog functions to pin 3 in GPIO_Port E
        }
        else if (channel == AIN1) //PE2
        {
            SET_BIT(GPIO_PortEAFSEL, 2);
            CLR_BIT(GPIO_PortEDEN, 2);
            SET_BIT(GPIO_PortEAMSEL, 2);
        }
        else if (channel == AIN2) //PE1
        {
            SET_BIT(GPIO_PortEAFSEL, 1);
            CLR_BIT(GPIO_PortEDEN, 1);
            SET_BIT(GPIO_PortEAMSEL, 1);
        }
        else if (channel == AIN3) //PE0
        {
            SET_BIT(GPIO_PortEAFSEL, 0);
            CLR_BIT(GPIO_PortEDEN, 0);
            SET_BIT(GPIO_PortEAMSEL, 0);
        }
        else if (channel == AIN4) //PD3
        {
            SET_BIT(GPIO_PortDAFSEL, 3);
            CLR_BIT(GPIO_PortDDEN, 3);
            SET_BIT(GPIO_PortDAMSEL, 3);
        }
        else if (channel == AIN5) //PD2
        {
            SET_BIT(GPIO_PortDAFSEL, 2);
            CLR_BIT(GPIO_PortDDEN, 2);
            SET_BIT(GPIO_PortDAMSEL, 2);
        }
        else if (channel == AIN6) //PD1
        {
            SET_BIT(GPIO_PortDAFSEL, 1);
            CLR_BIT(GPIO_PortDDEN, 1);
            SET_BIT(GPIO_PortDAMSEL, 1);
        }
        else if (channel == AIN7) //PD0
        {
            SET_BIT(GPIO_PortDAFSEL, 0);
            CLR_BIT(GPIO_PortDDEN, 0);
            SET_BIT(GPIO_PortDAMSEL, 0);
        }
        else if (channel == AIN8) //PE5
        {
            SET_BIT(GPIO_PortEAFSEL, 5);
            CLR_BIT(GPIO_PortEDEN, 5);
            SET_BIT(GPIO_PortEAMSEL, 5);
        }

        else if (channel == AIN9) //PE4
        {
            SET_BIT(GPIO_PortEAFSEL, 4);
            CLR_BIT(GPIO_PortEDEN, 4);
            SET_BIT(GPIO_PortEAMSEL, 4);
        }
        else if (channel == AIN10) //PB4
        {
            SET_BIT(GPIO_PortBAFSEL, 4);
            CLR_BIT(GPIO_PortBDEN, 4);
            SET_BIT(GPIO_PortBAMSEL, 4);
        }
        else if (channel == AIN11) //PB5
        {
            SET_BIT(GPIO_PortBAFSEL, 5);
            CLR_BIT(GPIO_PortBDEN, 5);
            SET_BIT(GPIO_PortBAMSEL, 5);
        }

        //intilization of the sample sequencer
        if (sampler == SS3)
        {
            CLR_BIT(ADC1ACTSS, 3); // first we disable the SS bit before configuretion to avoid errors

            CLR_BIT(ADC1EMUX, 15); //choosing the trigger for the approriate SS (choosing it as default (processor)
            CLR_BIT(ADC1EMUX, 14);
            CLR_BIT(ADC1EMUX, 13);
            CLR_BIT(ADC1EMUX, 12);

            if (channel == AIN0) // choosing the channel to operate
                ADC1SSMUX3 |= 0;
            else if (channel == AIN1)
                ADC1SSMUX3 |= 1;
            else if (channel == AIN2)
                ADC1SSMUX3 |= 2;
            else if (channel == AIN3)
                ADC1SSMUX3 |= 3;
            else if (channel == AIN4)
                ADC1SSMUX3 |= 4;
            else if (channel == AIN5)
                ADC1SSMUX3 |= 5;
            else if (channel == AIN6)
                ADC1SSMUX3 |= 6;
            else if (channel == AIN7)
                ADC1SSMUX3 |= 6;
            else if (channel == AIN7)
                ADC1SSMUX3 |= 7;
            else if (channel == AIN8)
                ADC1SSMUX3 |= 8;
            else if (channel == AIN9)
                ADC1SSMUX3 |= 9;
            else if (channel == AIN10)
                ADC1SSMUX3 |= 10;
            else if (channel == AIN11)
                ADC1SSMUX3 |= 11;

            ADC1SSCTL3 |= 6; //setting the SS to single ended(bit0) and one sample then stop(SS3)(bit1)  and connecting the interupt flag to the isr (bit3)

            SET_BIT(ADC1ACTSS, 3); //enabling the sample sequneser
        }
        else if (sampler == SS2)
        {
            CLR_BIT(ADC1ACTSS, 2); // first we disable the SS bit before configuretion to avoid errors

            CLR_BIT(ADC1EMUX, 11); //choosing the trigger for the approriate SS (choosing it as default (processor)
            CLR_BIT(ADC1EMUX, 10);
            CLR_BIT(ADC1EMUX, 9);
            CLR_BIT(ADC1EMUX, 8);

            if (channel == AIN0) // choosing the channel to operate
                ADC1SSMUX2 |= 0;
            else if (channel == AIN1)
                ADC1SSMUX2 |= 1;
            else if (channel == AIN2)
                ADC1SSMUX2 |= 2;
            else if (channel == AIN3)
                ADC1SSMUX2 |= 3;
            else if (channel == AIN4)
                ADC1SSMUX2 |= 4;
            else if (channel == AIN5)
                ADC1SSMUX2 |= 5;
            else if (channel == AIN6)
                ADC1SSMUX2 |= 6;
            else if (channel == AIN7)
                ADC1SSMUX2 |= 6;
            else if (channel == AIN7)
                ADC1SSMUX2 |= 7;
            else if (channel == AIN8)
                ADC1SSMUX2 |= 8;
            else if (channel == AIN9)
                ADC1SSMUX2 |= 9;
            else if (channel == AIN10)
                ADC1SSMUX2 |= 10;
            else if (channel == AIN11)
                ADC1SSMUX2 |= 11;

            ADC1SSCTL2 |= 0b100; //setting the SS to single ended(bit0) and more than one sample(SS2)(bit1)  and connecting the interupt flag to the isr (bit3)

            SET_BIT(ADC1ACTSS, 2); //enabling the sample sequneser

        }
        else if (sampler == SS1)
        {
            CLR_BIT(ADC1ACTSS, 1); // first we disable the SS bit before configuretion to avoid errors

            CLR_BIT(ADC1EMUX, 7); //choosing the trigger for the approriate SS (choosing it as default (processor)
            CLR_BIT(ADC1EMUX, 6);
            CLR_BIT(ADC1EMUX, 5);
            CLR_BIT(ADC1EMUX, 4);

            if (channel == AIN0) // choosing the channel to operate
                ADC1SSMUX1 |= 0;
            else if (channel == AIN1)
                ADC1SSMUX1 |= 1;
            else if (channel == AIN2)
                ADC1SSMUX1 |= 2;
            else if (channel == AIN3)
                ADC1SSMUX1 |= 3;
            else if (channel == AIN4)
                ADC1SSMUX1 |= 4;
            else if (channel == AIN5)
                ADC1SSMUX1 |= 5;
            else if (channel == AIN6)
                ADC1SSMUX1 |= 6;
            else if (channel == AIN7)
                ADC1SSMUX1 |= 6;
            else if (channel == AIN7)
                ADC1SSMUX1 |= 7;
            else if (channel == AIN8)
                ADC1SSMUX1 |= 8;
            else if (channel == AIN9)
                ADC1SSMUX1 |= 9;
            else if (channel == AIN10)
                ADC1SSMUX1 |= 10;
            else if (channel == AIN11)
                ADC1SSMUX1 |= 11;

            ADC1SSCTL1 |= 0b100; //setting the SS to single ended(bit0) and more than one sample(SS2)(bit1)  and connecting the interupt flag to the isr (bit3)

            SET_BIT(ADC1ACTSS, 1); //enabling the sample sequneser
        }
        else if (sampler == SS0)
        {
            CLR_BIT(ADC1ACTSS, 0); // first we disable the SS bit before configuretion to avoid errors

            CLR_BIT(ADC1EMUX, 3); //choosing the trigger for the approriate SS (choosing it as default (processor)
            CLR_BIT(ADC1EMUX, 2);
            CLR_BIT(ADC1EMUX, 1);
            CLR_BIT(ADC1EMUX, 0);

            if (channel == AIN0) // choosing the channel to operate
                ADC1SSMUX0 |= 0;
            else if (channel == AIN1)
                ADC1SSMUX0 |= 1;
            else if (channel == AIN2)
                ADC1SSMUX0 |= 2;
            else if (channel == AIN3)
                ADC1SSMUX0 |= 3;
            else if (channel == AIN4)
                ADC1SSMUX0 |= 4;
            else if (channel == AIN5)
                ADC1SSMUX0 |= 5;
            else if (channel == AIN6)
                ADC1SSMUX0 |= 6;
            else if (channel == AIN7)
                ADC1SSMUX0 |= 6;
            else if (channel == AIN7)
                ADC1SSMUX0 |= 7;
            else if (channel == AIN8)
                ADC1SSMUX0 |= 8;
            else if (channel == AIN9)
                ADC1SSMUX0 |= 9;
            else if (channel == AIN10)
                ADC1SSMUX0 |= 10;
            else if (channel == AIN11)
                ADC1SSMUX0 |= 11;

            ADC1SSCTL0 |= 0b100; //setting the SS to single ended(bit0) and more than one sample(SS2)(bit1)  and connecting the interupt flag to the isr (bit3)

            SET_BIT(ADC1ACTSS, 0); //enabling the sample sequneser
        }

    }
}

void ADC_voidStartConversion(ADC_MOD_t module, SS_t sample)
{
    if (module == ADC0)
    {
        if (sample == SS3) // setting the trigger for the conversion for each sampler sequencer
            SET_BIT(ADC0PSSI, 3);
        else if (sample == SS2)
            SET_BIT(ADC0PSSI, 2);
        else if (sample == SS1)
            SET_BIT(ADC0PSSI, 1);
        else if (sample == SS0)
            SET_BIT(ADC0PSSI, 0);
    }
    else if (module == ADC1)
    {
        if (sample == SS3) // setting the trigger for the conversion for each sampler sequencer
            SET_BIT(ADC1PSSI, 3);
        else if (sample == SS2)
            SET_BIT(ADC1PSSI, 2);
        else if (sample == SS1)
            SET_BIT(ADC1PSSI, 1);
        else if (sample == SS0)
            SET_BIT(ADC1PSSI, 0);
    }
}

uint16 ADC_uint16GetData(ADC_MOD_t module, SS_t sample)
{
    //uint16 data1;//12 bit
    //uint64 data4;//48bit
    //uint128 data8;//96bit
    if (module == ADC0)
    {
        if (sample == SS3)
        {
            SET_BIT(ADC0ISC, 3);// setting the 3 bit (SS3) of this register clears the interrupt flag in ADCRIS so we can
                                //make another conversion by polling that flag
            return ADC0SSFIFO3;
        }
    }
    else if (module == ADC1)
    {
        if (sample == SS3)
        {

            SET_BIT(ADC1ISC, 3);// setting the 3 bit (SS3) of this register clears the interrupt flag in ADCRIS so we can
                                //make another conversion by polling that flag
            return ADC1SSFIFO3;
        }
    }

}

