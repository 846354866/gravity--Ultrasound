#ifndef Ultrasound_h
#define Ultrasound_h
/*!
 * @file Ultrasound.h
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
#include <SoftwareSinglebus.h>


#define REG_ADDR     0x04
#define REG_START    0x05
#define REG_DISTANCE 0x08


class Ultrasound
{
	public:
	
		/*!
		*  @brief Constructor.
		*  @param bus_  single bus .
		*  @param addr_  Register address.
		*/
		Ultrasound(SoftwareSinglebus *bus_,int addr_=0x01);
		
		/*!
		*  @brief Start the ultrasonic.
		*/
		int16_t start( void ); 
		/*!
		*  @brief Stop the ultrasonic.
		*/
		int16_t stop(void); 
		
		/*!
		*  @brief Modify the ultrasonic register address.
		*  @param id  new  register address.
		*/
		int16_t modifyAddr(uint8_t id); 
		
		/*!
		*  @brief Read distance.
		*  @return the distance between the object.
		*/
		int16_t readDistance(void);  
		
		/*!
		*  @brief Set the interrupt the callback function.
		*  @param cb  callback function.
		*/
		int16_t setCB( void (*cb)( void* p_ ) );
	private:
		SoftwareSinglebus *bus;///<single bus.
		uint8_t addr; ///<ltrasonic register address.
};
#endif
