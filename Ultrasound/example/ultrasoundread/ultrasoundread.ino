/*!
 * @file ultrasoundread.ino
 * @brief DFRobot's ultrasound
 * @n [Get the module here](http://www.dfrobot.com/index.php?route=product/product&product_id=1088)
 * @n This example get the four lightest positions of the IR sources.
 * @n [Connection and Diagram](http://www.dfrobot.com/wiki/index.php/Positioning_ir_camera#Connection_Diagram)
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @author [carl](carl.xu@dfrobot.com)
 * @version  V1.0
 * @date  2016-05-27
 */
#include <Ultrasound.h>
#define DISCOVERY_SINGLE_BUS_PIN 2
SoftwareSinglebus  mySingleBus(DISCOVERY_SINGLE_BUS_PIN);
Ultrasound u(&mySingleBus,0x03);

void UltrasoundCB( void* p_ ){
    Ultrasound* ultra = (Ultrasound*)p_;
    //int16_t data = ultra->readDistance();
    //if(data != -1)
    //   Serial.println(data);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(100);
 u.setCB(UltrasoundCB);
 u.start();
// u.modifyAddr(0x01);
}

void loop() {
  // put your main code here, to run repeatedly:
  int16_t data = u.readDistance();
  if(data != -1)
  Serial.println(data);
  //  mySingleBus.callbackfun[0].callback_t( mySingleBus.callbackfun[0].arg);
  delay(100); 
}

