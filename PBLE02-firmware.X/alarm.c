#include "alarm.h"
#include "../inttypes.h"
#include "adc.h"
#include "var.h"
#include "Utils.h"

uint8_t timerSet;

void initAlarms(void){
    timerSet = 0;
}

uint8_t updateAlarmsStatus(uint32_t m){
    uint8_t o = 0;
    
    uint16_t high1 = getAlarmHigh1();
    uint16_t low1 = getAlarmLow1();
    uint16_t high2 = getAlarmHigh2();
    uint16_t low2 = getAlarmLow2();
    uint32_t timer = getTimer();
    
    uint16_t pot = readPOTADC();
    int diff = readDiff();
    
    if(pot <= low1){
        bitSet(o, 0);
    }
    if(pot >= high1){
        bitSet(o, 1);
    }
    
    if(diff <= low2){
        bitSet(o, 2);
    }
    if(diff >= high2){
        bitSet(o, 3);
    }
    
    //if(timerSet){
        if(m >= timer){
            bitSet(o, 4);
            timerSet = 0;
        }
    //}
    
    
    return o;
    
}
