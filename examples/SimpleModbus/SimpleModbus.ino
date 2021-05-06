#include <ModbusRTUSlave.h>

// size of data which will be read and written
#define DATA_SIZE 16

// data array which will be read and written
uint16_t _D[DATA_SIZE] = {3, 1415, 9265, 4, 2, 7182, 28182, 8, 0, 0, 0, 0, 0, 0, 1, 1};
// uint8_t _M[DATA_SIZE];

// address (kind of name) of above data, may be anything
#define VIRTUAL_ADDRESS 0x7000
#define OUR_ID_AS_A_SLAVE 0x20

ModbusRTUSlave rtu(OUR_ID_AS_A_SLAVE, &Serial1);

void setup() {
  // pinMode(3, OUTPUT);
  // pinMode(4, OUTPUT);
  
  rtu.addWordArea(VIRTUAL_ADDRESS, _D, DATA_SIZE);
  // rtu.addBitArea(0x1000, _M, 50);
  rtu.begin(9600);

  // set some value in data array to test if master can read and modify it
  _D[0] = 3;
}

void loop() {
  // waiting for requests from master
  rtu.process();
  // digitalWrite(3, getBit(_M,0));
  // digitalWrite(4, getBit(_M,1));
}
