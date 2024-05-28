#include "SerialWombat18ABVGADriver.h"

SerialWombat18ABVGADriver::SerialWombat18ABVGADriver(SerialWombat18ABVGA& vga):_vga(vga),Adafruit_GFX(160,120)
{	
}

void SerialWombat18ABVGADriver::drawPixel(int16_t x, int16_t y, uint16_t color)
{
	_vga.writePixel((uint8_t)x, (uint8_t)y, (uint8_t)((color > 0) ? 1 : 0));
	++pixelsSinceYield;
	if (pixelsSinceYield > 100)
	{
		yield();
		pixelsSinceYield = 0;
	}
}

void SerialWombat18ABVGADriver::fillScreen(uint16_t color)
{
	_vga.fillScreen((uint8_t)(color>0?1:0));
}

void SerialWombat18ABVGADriver::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
	_vga.fillRect((uint8_t)x, (uint8_t)y, (uint8_t)w, (uint8_t)h, (uint8_t)(color > 0 ? 1 : 0));
}
