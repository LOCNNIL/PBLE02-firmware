#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/system.h"
#include "adc.h"

uint16_t readPOTADC(void){
    uint32_t potSum = 0;
    for(uint8_t i = 0; i < (1 << POTSAMPLES); i++){
        ADC1_Enable();
        ADC1_ChannelSelect(POT);
        ADC1_SoftwareTriggerEnable();
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(POT));
        potSum += ADC1_ConversionResultGet(POT);
        ADC1_Disable();
    }
    return (uint16_t)(potSum >> POTSAMPLES);
}

int readDiff(void){
   uint32_t difPSum = 0;
   uint32_t difNSum = 0;
    for(uint8_t i = 0; i < (1 << DIFSAMPLES); i++){
        ADC1_Enable();
        ADC1_ChannelSelect(AnN);
        ADC1_SoftwareTriggerEnable();
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(AnN));
        difNSum += ADC1_ConversionResultGet(AnN);
        ADC1_Disable();
        
        ADC1_Enable();
        ADC1_ChannelSelect(AnP);
        ADC1_SoftwareTriggerEnable();
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(AnP));
        difPSum += ADC1_ConversionResultGet(AnP);
        ADC1_Disable();
    }
    
    return (((int)(difPSum >> DIFSAMPLES)) - ((int)(difNSum >> DIFSAMPLES)));
}