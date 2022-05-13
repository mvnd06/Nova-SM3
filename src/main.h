//include supporting libraries
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <T4_PowerButton.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <RF24.h>

#include "MPU6050_conf.h"
#include "NovaServos.h"           //include motor setup vars and data arrays
#include "AsyncServo.h"           //include motor class

//MP3 Setup
//#if MP3_PLAYER_TYPE > 0
//  #include <DFRobot_PLAY.h>
//  DFRobot_PLAY DFPlayer;
//#else
  #include <DFRobotDFPlayerMini.h>
  DFRobotDFPlayerMini DFPlayer;
//#endif

void update_servos();
bool nrf_check();
void nrf_ack();
void remote_check();
void pir_check();
void follow();
void uss_check();
void get_mpu();
void amperage_check(int aloop);
void battery_check(unsigned char bshow);
void init_home();
void detach_all();
void set_ramp(int servo, float sp, float r1_spd, float r1_dist, float r2_spd, float r2_dist);
void go_home();
void set_home();
void set_stop();
void set_stop_active();
void set_speed();
void set_axis(float roll_step, float pitch_step);
void run_demo();
void funplay();

void set_stay();
void set_sit();
void set_crouch();
void set_lay();
void set_kneel();
void look_left();
void look_right();

void move_kx();
void move_ky();
void roll_x();
void pitch_y();
void yaw();
void yaw_x();
void yaw_y();
void x_axis();
void y_axis();
void roll();
void roll_body();
void pitch(int xdir);
void pitch_body();

void step_march(float xdir, float ydir, float zdir);
void step_trot(int xdir, int ydir, int zdir);
void step_forward(int ydir, int xdir, int zdir);
void step_backward(int ydir, int xdir, int zdir);
void step_left_right(int lorr, int xdir, int ydir);
void wake();
void wman();
void move_debug_servo();
void move_debug_leg();

void run_sequence();
void delay_sequences();
void update_sequencer(int leg, int servo, int sp, float tar, int seq, int del);
int limit_target(int sid, int tar, int thresh);
int limit_speed(float spd_lim);
byte is_stepmove_complete(int ms);
byte is_front_leg(int leg);
byte is_left_leg(int leg);
byte is_femur(int leg);
byte is_tibia(int leg);
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
int degrees_to_pwm(int pangle, int mxw, int mnw, int rng);
int pwm_to_degrees(int pulse_wide, int mxw, int mnw, int rng);

void serial_check();
void serial_command(String cmd);
void test_oled();
void test_rgb();
void rgb_request(char* commands);
void oled_request(char* commands);
int command_slave(char* commands);
void powering_down(void);

void mp3_play(int track);
void mp3_volume(int vol);
void check_mp3();
void add_to_mp3_queue(int track);
void play_mp3_queue(uint8_t type);