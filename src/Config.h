//debug vars for displaying operation runtime data for debugging
#include <Arduino.h>

#define uint8_t byte

const byte debug  = 0;            //general messages
const byte debug1 = 0;            //remote commands and pir sensors
const byte debug2 = 0;            //debug servo steps
const byte debug3 = 0;            //ramping and sequencing
const byte debug4 = 0;            //amperage and battery 
const byte debug5 = 0;            //mpu
const byte debug6 = 0;            //serial communication output/response and serial terminal commands
const byte debug7 = 0;            //uss sensors
const byte debug8 = 0;            //NRF24 comm
const byte plotter = 0;           //plot servo steps, turn off debug1

byte debug_leg = 0;               //default debug leg (3 servos) (changed by serial command input)
int debug_servo = 2;              //default debug servo (changed by serial command input)
int debug_loops = 3;              //default loops for debug movements
int debug_loops2 = 3;             //movement decremented loop
int debug_spd = 10;               //default speed for debug movements

//DEVWORK
int  test_loops = 0;  
int  test_steps = 0;  

//set Nova SM3 version
#define VERSION 5.2

//activate/deactivate devices
byte slave_active = 1;            //activate slave arduino nano
byte pwm_active = 1;              //activate pwm controller / servos
byte nrf_active = 0;              //activate NRF24 remote control
byte serial_active = 1;           //activate serial monitor command input
byte mpu_active = 0;              //activate MPU6050 
byte rgb_active = 0;              //activate RGB modules
byte oled_active = 1;             //activate OLED display
byte pir_active = 1;              //activate PIR motion sensor
byte uss_active = 1;              //activate Ultra-Sonic sensors
byte amp_active = 0;              //activate amperate monitoring
byte batt_active = 0;             //activate battery level monitoring
byte buzz_active = 0;             //activate simple tone sounds 
byte melody_active = 0;           //activate melodic tone sounds 
byte mp3_active = 0;              //activate if mp3 player installed
byte splash_active = 0;           //show all loading graphics & sounds
byte quick_boot = 1;              //skip most loading graphics & sounds

byte use_ramp = 0;                //boolean to enable / disable ramping function
