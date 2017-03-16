/*!
 * @file Ultrasound.cpp
 * @brief Ultrasound
 * @n Header file for DFRobot's Ultrasonic sensors
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @author [carl](carl.xu@dfrobot.com)
 * @version  V1.0
 * @date  2016-05-27
 */
#include<Ultrasound.h>
#include<Arduino.h>
int16_t Ultrasound::setCB( void (*cb)( void* p_ ) )
{
    bus->registerCB( addr, cb, this );
    return 0;
}

Ultrasound::Ultrasound(SoftwareSinglebus *bus_,int addr_)
	:bus(bus_),addr(addr_)
{
	
}

int16_t Ultrasound::start(void)	
{
  bus->begin();
  bus->beginTransmission(addr,WRITE);
  bus->write(REG_START);
  bus->write(0x01);
  bus->endTransmission();
  delay(1);
  return 0;
}

int16_t Ultrasound::stop(void)
{
  char stopdata = 0x00;
  bus->beginTransmission(addr,WRITE);
  bus->write(REG_START);
  bus->write(&stopdata);
  bus->endTransmission();
  return 0;
}

int16_t Ultrasound::modifyAddr(uint8_t newAddr)
{
  bus->beginTransmission(addr,WRITE);
  bus->write(REG_ADDR);
  bus->write(newAddr);
  bus->endTransmission();
  addr = newAddr;
  return 0;
}


int16_t Ultrasound::readDistance(void)
{
  int len = 0x02;
  if(REG_DISTANCE == 0x08)
  {
	  len = 0x02;
  }
  if(REG_DISTANCE == 0x09)
  {
	  len = 0x01;
  }
  int16_t data = -1;
  uint8_t temp = 0;
  bus->beginTransmission(addr,READ);
  bus->write(REG_DISTANCE);///<register address
  bus->write(len); ///<read length
  bus->endTransmission();
  bus->requestFrom(addr,len);
  if(bus->available() == 0x02){
    temp = bus->read();
    data = temp<<8|(bus->read());
  }else if(bus->available() == 0x01){
    data = bus->read(); 	
  }else{
  	data = -1;
  }
  bus->endTransmission();
  return data;
}
