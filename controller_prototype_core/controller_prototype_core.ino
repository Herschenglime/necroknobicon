#include <Control_Surface.h>

/*
Final iteration of pins, at least on breadboard
- may need to tinker with midi channels to be more convenient for vcv and such
*/

USBMIDI_Interface midi;

//example for single pot
/*
CCPotentiometer potentiometer{
  A1,  // pin number
  {
    MIDI_CC::Channel_Volume,  // MIDI address
    Channel_1                 // channel number
  }
};
*/
// CLUSTER 1
// bank on breadboard in line with teensy
CCPotentiometer potCluster1[]{
  { A0, { 0x01, Channel_1 } },
  { A1, { 0x02, Channel_1 } },
  { A2, { 0x03, Channel_1 } }

};
CCRotaryEncoder enc1{
  { 33, 34 },    // pins
  { 0x04, Channel_1 },  // MIDI address (CC number + optional channel)
  2,             // optional multiplier if the control isn't fast enough
};
// Instantiate a CCButton object
CCButton button1{
  // Push button on pin 32:
  32,
  // General Purpose Controller #1 on MIDI channel 1:
  { 0x05, Channel_1 },
};

// CLUSTER 2
// bank in bottom left corner
CCPotentiometer potCluster2[]{
  { A3, { 0x06, Channel_1 } },
  { A4, { 0x07, Channel_1 } },
  { A5, { 0x08, Channel_1 } }

};
CCRotaryEncoder enc2{
  { 35, 36 },    // pins
  { 0x09, Channel_1 },  // MIDI address (CC number + optional channel)
  2,             // optional multiplier if the control isn't fast enough
};
// Instantiate a CCButton object
CCButton button2{
  // Push button on pin 31:
  31,
  { 0x0A, Channel_1 },
};

// CLUSTER 3
// bank in bottom right corner
CCPotentiometer potCluster3[]{
  { A15, { 0x0B, Channel_1 } },
  { A16, { 0x0C, Channel_1 } },
  { A17, { 0x0D, Channel_1 } }

};
CCRotaryEncoder enc3{
  { 37, 32 },    // pins
  { 0x0E, Channel_1 },  // MIDI address (CC number + optional channel)
  2,             // optional multiplier if the control isn't fast enough
};
CCButton button3{
  30,
  { 0x0F, Channel_1 },
};

// CLUSTER 4
// bank in top left corner
CCPotentiometer potCluster4[]{
  { A13, { 0x10, Channel_1 } },
  { A12, { 0x11, Channel_1 } },
  { A11, { 0x12, Channel_1 } }

};
CCRotaryEncoder enc4{
  { 29, 28 },    // pins
  { 0x13, Channel_1 },  // MIDI address (CC number + optional channel)
  2,             // optional multiplier if the control isn't fast enough
};
CCButton button4{
  12,
  { 0x14, Channel_1 },
};

// CLUSTER 5
// bank in top left corner
CCPotentiometer potCluster5[]{
  { A14, { 0x15, Channel_1 } },
  { A9, { 0x16, Channel_1 } },
  { A10, { 0x17, Channel_1 } }

};
CCRotaryEncoder enc5{
  { 10, 9 },    // pins
  { 0x18, Channel_1 },  // MIDI address (CC number + optional channel)
  2,             // optional multiplier if the control isn't fast enough
};
CCButton button5{
  11,
  { 0x19, Channel_1 },
};

// CLUSTER 6
// auxilliary bank -- too annoying to deal with, so removed for now
// CCPotentiometer potCluster6[]{
//   { A6, { 0x1A, Channel_6 } },
//   { A7, { 0x1B, Channel_6 } },
//   { A8, { 0x1C, Channel_6 } }

// };
// CCRotaryEncoder enc6{
//   { 2, 1 },    // pins
//   { 0x1D, Channel_6 },  // MIDI address (CC number + optional channel)
//   2,             // optional multiplier if the control isn't fast enough
// };
// CCButton button6{
//   0,
//   { 0x1E, Channel_6 },
// };



void setup() {
  // optionally set relative cc mode if the existing one doesn't work
  Control_Surface.begin();  // Initialize Control Surface
}

void loop() {
  Control_Surface.loop();  // Update the Control Surface
}
