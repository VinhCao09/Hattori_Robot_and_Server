
//---------------Thu vien Mang hinh TFT-----------
#include <Adafruit_GFX.h>
#include "Adafruit_ILI9341.h"
#include <SPI.h>
//-----------Phan khai bao bien cho mang hinh LCD---------------------------------
//------LCD TFT------ESP32--------------------
#define _cs   0   // 3 goes to TFT CS
#define _dc   2   // 4 goes to TFT DC
#define _mosi 14  // 5 goes to TFT MOSI
#define _sclk 12  // 6 goes to TFT SCK/CLK
#define _rst  13  // ESP RST to TFT RESET
#define _miso     // Not connected
//----------------------------------------------
Adafruit_ILI9341 tft = Adafruit_ILI9341(_cs, _dc, _mosi, _sclk, _rst);
//------------Dinh nghia mau sac----------------
#define BLACK 0x0000    
#define BLUE 0x001F    
#define RED 0xF800      
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F  
#define YELLOW 0xFFE0
#define WHITE 0xFFFF 

#include "FontMaker.h"
void setpx(int16_t x,int16_t y,uint16_t color)
{
  tft.drawPixel(x,y,color); //Thay đổi hàm này thành hàm vẽ pixel mà thư viện led bạn dùng cung cấp
}
MakeFont myfont(&setpx);
