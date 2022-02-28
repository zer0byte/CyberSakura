#include <mcp_can.h>
#include <SPI.h>
#include <avr/pgmspace.h>

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 9;

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin



#if 1
struct canx {
  uint16_t sid;
  unsigned char data[8];
};

const canx cans[] PROGMEM = {
{0, {18, 131, 73, 73, 73, 73, 73, 73}},
{0, {33, 73, 73, 73, 73, 73, 73, 73}},
{0, {34, 73, 73, 73, 73, 73, 73, 73}},
{0, {35, 73, 73, 73, 73, 73, 73, 73}},
{0, {36, 73, 73, 73, 73, 73, 73, 73}},
{0, {37, 73, 73, 73, 73, 73, 73, 73}},
{0, {38, 73, 73, 73, 73, 73, 73, 73}},
{0, {39, 73, 73, 73, 73, 73, 73, 73}},
{0, {40, 73, 73, 73, 73, 73, 73, 73}},
{0, {41, 73, 73, 73, 73, 73, 73, 73}},
{0, {42, 73, 73, 73, 73, 73, 73, 73}},
{0, {43, 73, 73, 73, 73, 73, 73, 73}},
{0, {44, 73, 73, 73, 73, 73, 73, 73}},
{0, {45, 73, 73, 73, 73, 73, 73, 73}},
{0, {46, 73, 73, 73, 73, 73, 73, 73}},
{0, {47, 73, 73, 73, 73, 73, 73, 73}},
{0, {32, 73, 73, 73, 73, 73, 73, 73}},
{0, {33, 73, 73, 73, 73, 73, 73, 73}},
{0, {34, 73, 73, 73, 73, 73, 73, 73}},
{0, {35, 73, 73, 73, 73, 73, 73, 73}},
{0, {36, 73, 73, 73, 73, 73, 73, 73}},
{0, {37, 73, 73, 73, 73, 73, 73, 73}},
{0, {38, 73, 73, 73, 73, 73, 73, 73}},
{0, {39, 73, 73, 73, 73, 73, 73, 73}},
{0, {40, 73, 73, 73, 73, 73, 73, 73}},
{0, {41, 73, 73, 73, 73, 73, 73, 73}},
{0, {42, 73, 73, 73, 73, 73, 73, 73}},
{0, {43, 73, 73, 73, 73, 73, 73, 73}},
{0, {44, 73, 73, 73, 73, 73, 73, 73}},
{0, {45, 73, 73, 73, 73, 73, 73, 73}},
{0, {46, 73, 73, 73, 73, 73, 73, 73}},
{0, {47, 73, 73, 73, 73, 73, 73, 73}},
{0, {32, 73, 73, 73, 73, 73, 73, 73}},
{0, {33, 73, 73, 73, 73, 73, 73, 73}},
{0, {34, 73, 73, 73, 73, 73, 73, 73}},
{0, {35, 73, 73, 73, 73, 73, 73, 73}},
{0, {36, 73, 73, 73, 73, 73, 73, 73}},
{0, {37, 73, 73, 73, 73, 73, 73, 73}},
{0, {38, 73, 73, 73, 73, 73, 73, 73}},
{0, {39, 73, 73, 73, 73, 73, 73, 73}},
{0, {40, 73, 73, 73, 73, 73, 73, 73}},
{0, {41, 73, 73, 73, 73, 73, 73, 73}},
{0, {42, 73, 73, 73, 73, 73, 73, 73}},
{0, {43, 73, 73, 73, 73, 73, 73, 73}},
{0, {44, 73, 73, 73, 73, 73, 73, 73}},
{0, {45, 73, 73, 73, 73, 73, 73, 73}},
{0, {46, 73, 73, 73, 73, 73, 73, 73}},
{0, {47, 73, 73, 73, 73, 73, 73, 73}},
{0, {32, 73, 73, 73, 73, 73, 73, 73}},
{0, {33, 73, 73, 73, 73, 73, 73, 73}},
{0, {34, 73, 73, 73, 73, 73, 73, 73}},
{0, {35, 73, 73, 73, 73, 73, 73, 73}},
{0, {36, 73, 73, 73, 73, 73, 73, 73}},
{0, {37, 73, 73, 73, 73, 73, 73, 73}},
{0, {38, 73, 73, 73, 73, 73, 73, 73}},
{0, {39, 73, 73, 73, 73, 73, 73, 73}},
{0, {40, 73, 73, 73, 73, 73, 73, 73}},
{0, {41, 73, 73, 73, 73, 73, 73, 73}},
{0, {42, 73, 73, 73, 73, 73, 73, 73}},
{0, {43, 73, 73, 73, 73, 73, 73, 73}},
{0, {44, 73, 73, 73, 73, 73, 73, 73}},
{0, {45, 73, 73, 73, 73, 73, 73, 73}},
{0, {46, 73, 73, 73, 73, 73, 73, 73}},
{0, {47, 73, 73, 73, 73, 73, 73, 73}},
{0, {32, 73, 73, 73, 73, 73, 73, 73}},
{0, {33, 73, 73, 73, 73, 73, 73, 73}},
{0, {34, 73, 73, 73, 73, 73, 73, 73}},
{0, {35, 73, 73, 73, 73, 73, 73, 73}},
{0, {36, 73, 73, 73, 73, 73, 73, 73}},
{0, {37, 73, 73, 73, 73, 73, 73, 73}},
{0, {38, 73, 73, 73, 73, 73, 73, 73}},
{0, {39, 73, 73, 73, 73, 73, 73, 73}},
{0, {40, 73, 73, 73, 73, 73, 73, 73}},
{0, {41, 73, 73, 73, 73, 73, 73, 73}},
{0, {42, 73, 73, 73, 73, 73, 73, 73}},
{0, {43, 73, 73, 73, 73, 73, 73, 73}},
{0, {44, 73, 73, 73, 73, 73, 73, 73}},
{0, {45, 73, 73, 73, 73, 73, 73, 73}},
{0, {46, 73, 73, 73, 73, 73, 73, 73}},
{0, {47, 73, 73, 73, 73, 73, 73, 73}},
{0, {32, 73, 73, 73, 73, 73, 73, 73}},
{0, {33, 73, 73, 73, 73, 73, 73, 73}},
{0, {34, 73, 73, 73, 73, 73, 73, 73}},
{0, {35, 73, 73, 73, 73, 73, 73, 73}},
{0, {36, 73, 73, 73, 73, 73, 73, 73}},
{0, {37, 73, 73, 73, 73, 73, 73, 73}},
{0, {38, 73, 73, 73, 73, 73, 73, 73}},
{0, {39, 73, 73, 73, 73, 73, 73, 73}},
{0, {40, 73, 73, 73, 73, 73, 73, 73}},
{0, {41, 73, 73, 73, 73, 73, 73, 73}},
{0, {42, 73, 73, 73, 73, 73, 73, 73}},
{0, {16, 73, 73, 73, 73, 73, 73, 73}},
{1910, {18, 118, 48, 62, 65, 59, 66, 66}},
{0, {33, 0, 76, 74, 19, 55, 0, 141}},
{0, {34, 145, 33, 9, 73, 73, 0, 76}},
{0, {35, 70, 74, 74, 74, 74, 0, 78}},
{0, {36, 143, 67, 67, 67, 67, 67, 67}},
{0, {37, 67, 67, 67, 67, 67, 67, 67}},
{0, {38, 67, 67, 67, 67, 67, 67, 67}},
{0, {39, 67, 67, 67, 67, 67, 67, 67}},
{0, {40, 67, 67, 67, 67, 67, 67, 67}},
{0, {41, 67, 67, 1, 68, 68, 1, 69}},
{0, {42, 69, 49, 4, 147, 184, 90, 255}},
{0, {43, 255, 255, 255, 255, 255, 255, 255}},
{0, {44, 255, 255, 255, 255, 255, 255, 255}},
{0, {45, 255, 255, 255, 255, 255, 255, 1}},
{0, {46, 0, 0, 0, 0, 0, 0, 0}},
{0, {47, 0, 0, 0, 0, 0, 0, 0}},
{0, {32, 0, 0, 0, 0, 0, 0, 0}},
{0, {33, 0, 0, 70, 70, 70, 70, 70}},
{0, {34, 70, 70, 70, 70, 70, 70, 70}},
{0, {35, 70, 70, 70, 70, 70, 70, 70}},
{0, {36, 70, 70, 70, 70, 70, 70, 70}},
{0, {37, 70, 70, 70, 70, 70, 70, 70}},
{0, {38, 70, 70, 70, 70, 70, 70, 70}},
{0, {39, 70, 70, 70, 70, 70, 70, 70}},
{0, {40, 70, 70, 70, 70, 70, 70, 70}},
{0, {41, 70, 70, 70, 70, 70, 70, 70}},
{0, {42, 70, 70, 70, 70, 70, 70, 70}},
{0, {43, 70, 70, 70, 70, 70, 70, 70}},
{0, {44, 70, 70, 70, 70, 70, 70, 70}},
{0, {45, 70, 70, 70, 70, 70, 70, 70}},
{0, {46, 70, 70, 70, 70, 70, 70, 70}},
{0, {47, 70, 70, 70, 70, 70, 70, 70}},
{0, {32, 70, 70, 70, 70, 70, 70, 70}},
{0, {33, 70, 70, 70, 70, 70, 70, 70}},
{0, {34, 70, 70, 70, 70, 70, 70, 70}},
{0, {35, 70, 70, 70, 70, 70, 70, 70}},
{0, {36, 70, 70, 70, 70, 70, 70, 70}},
{0, {37, 70, 70, 70, 70, 70, 70, 70}},
{0, {38, 70, 70, 70, 70, 70, 70, 70}},
{0, {39, 70, 70, 70, 70, 70, 70, 70}},
{0, {40, 70, 70, 70, 70, 70, 70, 70}},
{0, {41, 70, 70, 70, 70, 70, 70, 70}},
{0, {42, 70, 70, 70, 70, 70, 70, 70}},
{0, {43, 70, 70, 70, 70, 70, 70, 70}},
{0, {44, 70, 70, 70, 70, 70, 70, 70}},
{0, {45, 70, 70, 70, 70, 70, 70, 70}},
{0, {46, 70, 70, 70, 70, 70, 70, 70}},
{0, {47, 70, 70, 70, 70, 70, 70, 70}},
{0, {32, 70, 70, 70, 70, 70, 70, 70}},
{0, {33, 70, 70, 70, 70, 70, 70, 70}},
{0, {34, 70, 70, 70, 70, 70, 70, 70}},
{0, {35, 70, 70, 70, 70, 70, 70, 70}},
{0, {36, 70, 70, 70, 70, 70, 70, 70}},
{0, {37, 70, 70, 70, 70, 70, 70, 70}},
{0, {38, 70, 70, 70, 70, 70, 70, 70}},
{0, {39, 70, 70, 70, 70, 70, 70, 70}},
{0, {40, 70, 70, 70, 70, 70, 70, 70}},
{0, {41, 70, 70, 70, 70, 70, 70, 70}},
{0, {42, 70, 70, 70, 70, 70, 70, 70}},
{0, {43, 70, 70, 70, 70, 70, 70, 70}},
{0, {44, 70, 70, 70, 70, 70, 70, 70}},
{0, {45, 70, 70, 70, 70, 70, 70, 70}},
{0, {46, 70, 70, 70, 70, 70, 70, 70}},
{0, {47, 70, 70, 70, 70, 70, 70, 70}},
{0, {32, 70, 70, 70, 70, 70, 70, 70}},
{0, {33, 70, 70, 70, 70, 70, 70, 70}},
{0, {34, 70, 70, 70, 70, 70, 70, 70}},
{0, {35, 70, 70, 70, 70, 70, 70, 70}},
{0, {36, 70, 70, 70, 70, 70, 70, 70}},
{0, {37, 70, 70, 70, 70, 70, 70, 70}},
{0, {38, 70, 70, 70, 70, 70, 70, 70}},
{0, {39, 70, 70, 70, 70, 70, 70, 70}},
{0, {40, 70, 70, 70, 70, 70, 70, 70}},
{0, {41, 70, 70, 70, 70, 70, 70, 70}},
{0, {42, 70, 70, 70, 70, 70, 70, 70}},
{0, {43, 70, 70, 70, 70, 70, 70, 70}},
{0, {44, 70, 70, 70, 70, 70, 70, 70}},
{0, {45, 70, 70, 70, 70, 70, 70, 70}},
{0, {46, 70, 70, 70, 70, 70, 70, 70}},
{0, {47, 70, 70, 70, 70, 70, 70, 70}},
{0, {32, 70, 70, 70, 70, 70, 70, 70}},
{0, {33, 70, 70, 70, 70, 70, 70, 70}},
{0, {34, 70, 70, 70, 70, 70, 70, 70}},
{0, {35, 70, 70, 70, 70, 70, 70, 70}},
{0, {36, 70, 70, 70, 70, 70, 70, 70}},
{0, {37, 70, 70, 70, 70, 70, 70, 70}},
{0, {38, 70, 70, 70, 70, 70, 70, 70}},
{0, {39, 70, 70, 70, 70, 70, 70, 70}},
{0, {40, 70, 70, 70, 70, 70, 70, 70}},
{0, {41, 70, 70, 70, 71, 71, 71, 71}},
{0, {42, 71, 72, 72, 72, 72, 64, 0}},
};
#else
struct canx {
  uint16_t sid;
  unsigned char data[8];
};

const canx cans[] PROGMEM = {
{1910, {18, 118, 48, 62, 65, 59, 66, 66}},
{0, {33, 0, 76, 74, 19, 55, 0, 141}},
{0, {34, 145, 33, 9, 73, 73, 0, 76}},
{0, {35, 70, 74, 74, 74, 74, 0, 78}},
{0, {36, 143, 67, 67, 67, 67, 67, 67}},
{0, {37, 67, 67, 67, 67, 67, 67, 67}},
{0, {38, 67, 67, 67, 67, 67, 67, 67}},
{0, {39, 67, 67, 67, 67, 67, 67, 67}},
{0, {40, 67, 67, 67, 67, 67, 67, 67}},
{0, {41, 67, 67, 1, 68, 68, 1, 69}},
{0, {42, 69, 49, 4, 50, 43, 110, 255}},
{0, {43, 255, 255, 255, 255, 255, 255, 255}},
{0, {44, 255, 255, 255, 255, 255, 255, 255}},
{0, {45, 255, 255, 255, 255, 255, 255, 1}},
{0, {46, 0, 0, 0, 0, 0, 0, 0}},
{0, {47, 0, 0, 0, 0, 0, 0, 0}},
{0, {32, 0, 0, 0, 0, 0, 0, 0}},
{0, {33, 0, 0, 70, 70, 70, 70, 70}},
{0, {34, 70, 70, 70, 70, 70, 70, 70}},
{0, {35, 70, 70, 70, 70, 70, 70, 70}},
{0, {36, 70, 70, 70, 70, 70, 70, 70}},
{0, {37, 70, 70, 70, 70, 70, 70, 70}},
{0, {38, 70, 70, 70, 70, 70, 70, 70}},
{0, {39, 70, 70, 70, 70, 70, 70, 70}},
{0, {40, 70, 70, 70, 70, 70, 70, 70}},
{0, {41, 70, 70, 70, 70, 70, 70, 70}},
{0, {42, 70, 70, 70, 70, 70, 70, 70}},
{0, {43, 70, 70, 70, 70, 70, 70, 70}},
{0, {44, 70, 70, 70, 70, 70, 70, 70}},
{0, {45, 70, 70, 70, 70, 70, 70, 70}},
{0, {46, 70, 70, 70, 70, 70, 70, 70}},
{0, {47, 70, 70, 70, 70, 70, 70, 70}},
{0, {32, 70, 70, 70, 70, 70, 70, 70}},
{0, {33, 70, 70, 70, 70, 70, 70, 70}},
{0, {34, 70, 70, 70, 70, 70, 70, 70}},
{0, {35, 70, 70, 70, 70, 70, 70, 70}},
{0, {36, 70, 70, 70, 70, 70, 70, 70}},
{0, {37, 70, 70, 70, 70, 70, 70, 70}},
{0, {38, 70, 70, 70, 70, 70, 70, 70}},
{0, {39, 70, 70, 70, 70, 70, 70, 70}},
{0, {40, 70, 70, 70, 70, 70, 70, 70}},
{0, {41, 70, 70, 70, 70, 70, 70, 70}},
{0, {42, 70, 70, 70, 70, 70, 70, 70}},
{0, {43, 70, 70, 70, 70, 70, 70, 70}},
{0, {44, 70, 70, 70, 70, 70, 70, 70}},
{0, {45, 70, 70, 70, 70, 70, 70, 70}},
{0, {46, 70, 70, 70, 70, 70, 70, 70}},
{0, {47, 70, 70, 70, 70, 70, 70, 70}},
{0, {32, 70, 70, 70, 70, 70, 70, 70}},
{0, {33, 70, 70, 70, 70, 70, 70, 70}},
{0, {34, 70, 70, 70, 70, 70, 70, 70}},
{0, {35, 70, 70, 70, 70, 70, 70, 70}},
{0, {36, 70, 70, 70, 70, 70, 70, 70}},
{0, {37, 70, 70, 70, 70, 70, 70, 70}},
{0, {38, 70, 70, 70, 70, 70, 70, 70}},
{0, {39, 70, 70, 70, 70, 70, 70, 70}},
{0, {40, 70, 70, 70, 70, 70, 70, 70}},
{0, {41, 70, 70, 70, 70, 70, 70, 70}},
{0, {42, 70, 70, 70, 70, 70, 70, 70}},
{0, {43, 70, 70, 70, 70, 70, 70, 70}},
{0, {44, 70, 70, 70, 70, 70, 70, 70}},
{0, {45, 70, 70, 70, 70, 70, 70, 70}},
{0, {46, 70, 70, 70, 70, 70, 70, 70}},
{0, {47, 70, 70, 70, 70, 70, 70, 70}},
{0, {32, 70, 70, 70, 70, 70, 70, 70}},
{0, {33, 70, 70, 70, 70, 70, 70, 70}},
{0, {34, 70, 70, 70, 70, 70, 70, 70}},
{0, {35, 70, 70, 70, 70, 70, 70, 70}},
{0, {36, 70, 70, 70, 70, 70, 70, 70}},
{0, {37, 70, 70, 70, 70, 70, 70, 70}},
{0, {38, 70, 70, 70, 70, 70, 70, 70}},
{0, {39, 70, 70, 70, 70, 70, 70, 70}},
{0, {40, 70, 70, 70, 70, 70, 70, 70}},
{0, {41, 70, 70, 70, 70, 70, 70, 70}},
{0, {42, 70, 70, 70, 70, 70, 70, 70}},
{0, {43, 70, 70, 70, 70, 70, 70, 70}},
{0, {44, 70, 70, 70, 70, 70, 70, 70}},
{0, {45, 70, 70, 70, 70, 70, 70, 70}},
{0, {46, 70, 70, 70, 70, 70, 70, 70}},
{0, {47, 70, 70, 70, 70, 70, 70, 70}},
{0, {32, 70, 70, 70, 70, 70, 70, 70}},
{0, {33, 70, 70, 70, 70, 70, 70, 70}},
{0, {34, 70, 70, 70, 70, 70, 70, 70}},
{0, {35, 70, 70, 70, 70, 70, 70, 70}},
{0, {36, 70, 70, 70, 70, 70, 70, 70}},
{0, {37, 70, 70, 70, 70, 70, 70, 70}},
{0, {38, 70, 70, 70, 70, 70, 70, 70}},
{0, {39, 70, 70, 70, 70, 70, 70, 70}},
{0, {40, 70, 70, 70, 70, 70, 70, 70}},
{0, {41, 70, 70, 70, 71, 71, 71, 71}},
{0, {42, 71, 72, 72, 72, 72, 64, 0}},
};
#endif

long long N = 0xa59068ffLL;
long long p = 39971LL, q = 69493LL;
long long e = 31337;
long long phi = 2777595240;
long long d = 3467628713;

long long modinv(long long e, long long phi) {
	long long d = 0, x1 = 0, x2 = 1, y1 = 1, temp_phi = phi;
	while (e > 0) {
		long long temp1 = temp_phi / e;
		long long temp2 = temp_phi - temp1 * e;
		temp_phi = e;
		e = temp2;
		long long x = x2 - temp1 * x1;
		long long y = d - temp1 * y1;
		x2 = x1;
		x1 = x;
		d = y1;
		y1 = y;
	}
	return d + phi;
}

long long modpow(long long a, long long n, long long mod) {
	if (n == 0) return 1;
	long long half = modpow(a, n/2, mod);
	half *= half;
	half %= mod;
	if (n % 2) {
		half *= a;
		half %= mod;
	}
	return half;
}


unsigned char stmp[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int which = 0;

unsigned char len = 0;
unsigned char buf[8];

void setup()
{
  delay(2000);
    Serial.begin(115200);

    while (CAN_OK != CAN.begin(CAN_100KBPS, MCP_8MHz)) {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
    
    delay(1000);
    while (1) {
      if(CAN_MSGAVAIL == CAN.checkReceive()){
        Serial.println("discard msg");
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
        delay(1000);
      }
      else { break; }
    }
    
    
    //while(1);
    
    CAN.sendMsgBuf(0x665, 0, 8, (unsigned char*)"\x10\x06\x27\x01ZZZZ");
    int cnt = 0;
    long long challenge = 0;
    while (1) {
      if(CAN_MSGAVAIL == CAN.checkReceive()){
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        unsigned int canId = CAN.getCanId();
        
        Serial.println("-----------------------------");
        Serial.print("Get data from ID: ");
        Serial.println(canId, HEX);

        for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print(buf[i], HEX);
            Serial.print(" ");
        }
        Serial.println();
        if (cnt == 0) {
           challenge |= (long long)buf[4];
           challenge |= (long long)buf[5] << 8; 
           challenge |= (long long)buf[6] << 16; 
           challenge |= (long long)buf[7] << 24; 
           cnt = 1;
        }
        else if (cnt == 1) {
           challenge |= (long long)buf[1] << 32;
           challenge |= (long long)buf[2] << 40; 
           challenge |= (long long)buf[3] << 48; 
           challenge |= (long long)buf[4] << 56; 
           cnt = 2;
           break;
        }
      }
    }
    Serial.print("Challenge: ");
    Serial.println((unsigned long)challenge, HEX);
    
    long long resp = modpow(challenge, d, N);
    Serial.print("Response: ");
    Serial.println((unsigned long)resp, HEX);
    
    buf[0] = 0x10;
    buf[1] = 10;
    buf[2] = 0x27;
    buf[3] = 0x00;
    buf[4] = resp & 0xff;
    buf[5] = (resp >> 8) & 0xff;
    buf[6] = (resp >> 16) & 0xff;
    buf[7] = (resp >> 24) & 0xff;
    CAN.sendMsgBuf(0x665, 0, 8, buf);
    buf[0] = 0x21;
    buf[1] = (resp >> 32) & 0xff;
    buf[2] = (resp >> 40) & 0xff;
    buf[3] = (resp >> 48) & 0xff;
    buf[4] = (resp >> 56) & 0xff;
    buf[5] = 0;
    buf[6] = 0;
    buf[7] = 0;
    CAN.sendMsgBuf(0x665, 0, 8, buf);

    while (1) {
      if(CAN_MSGAVAIL == CAN.checkReceive()){
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        unsigned int canId = CAN.getCanId();
        
        Serial.println("-----------------------------");
        Serial.print("Get data from ID: ");
        Serial.println(canId, HEX);

        for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print(buf[i], HEX);
            Serial.print(" ");
        }
        Serial.println();
        break;
      }
    }
    buf[0] = 4;
    buf[1] = 0x31;
    buf[2] = 0x01;
    buf[3] = 0x43;
    buf[4] = 0x01;
    CAN.sendMsgBuf(0x665, 0, 5, buf);
    
    while (1) {
      if(CAN_MSGAVAIL == CAN.checkReceive()){
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        unsigned int canId = CAN.getCanId();
        
        Serial.println("-----------------------------");
        Serial.print("Get data from ID: ");
        Serial.println(canId, HEX);

        for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print(buf[i], HEX);
            Serial.print(" ");
        }
        Serial.println();
        break;
      }
    }
    
    Serial.println("Reset the RHME board now.");
    delay(60000);
    Serial.println("Continuing.");
    while(1)
      f();
    
    while(1);
}

void loop(){}

void f()
{
    for (int i=0; i<8; i++) 
      stmp[i] = pgm_read_byte_near(&cans[which].data[i]);
    
    CAN.sendMsgBuf(pgm_read_word_near(&cans[which].sid), 0, 8, stmp);
    Serial.println(which);
    delay(1000);

    while(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        unsigned int canId = CAN.getCanId();
        
        Serial.println("-----------------------------");
        Serial.print("Get data from ID: ");
        Serial.println(canId, HEX);

        for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print(buf[i], HEX);
            Serial.print(" ");
        }
        Serial.println();
    }
    
    which++;
    if (which * sizeof(canx) == sizeof(cans)) which = 0;
}

// END FILE
