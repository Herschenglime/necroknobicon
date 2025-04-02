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
  { A0, { MIDI_CC::Effects_1, Channel_1 } },
  { A1, { MIDI_CC::Effects_2, Channel_1 } },
  { A2, { MIDI_CC::Effects_3, Channel_1 } }

};
CCRotaryEncoder enc1{
  { 33, 34 },    // pins
  {MIDI_CC::Effects_4, Channel_1},  // MIDI address (CC number + optional channel)
  2,             // optional multiplier if the control isn't fast enough
};
// Instantiate a CCButton object
CCButton button1{
  // Push button on pin 32:
  32,
  // General Purpose Controller #1 on MIDI channel 1:
  { MIDI_CC::General_Purpose_Controller_1, Channel_1 },
};

// CLUSTER 2
// bank in bottom left corner
CCPotentiometer potCluster2[]{
  { A3, { MIDI_CC::Effects_1, Channel_2 } },
  { A4, { MIDI_CC::Effects_2, Channel_2 } },
  { A5, { MIDI_CC::Effects_3, Channel_2 } }

};
CCRotaryEncoder enc2{
  { 35, 36 },    // pins
  {MIDI_CC::Effects_4, Channel_2},  // MIDI address (CC number + optional channel)
  2,             // optional multiplier if the control isn't fast enough
};
// Instantiate a CCButton object
CCButton button2{
  // Push button on pin 31:
  31,
  { MIDI_CC::General_Purpose_Controller_1, Channel_2 },
};

// CLUSTER 3
// bank in bottom right corner
CCPotentiometer potCluster3[]{
  { A15, { MIDI_CC::Effects_1, Channel_3 } },
  { A16, { MIDI_CC::Effects_2, Channel_3 } },
  { A17, { MIDI_CC::Effects_3, Channel_3 } }

};
CCRotaryEncoder enc3{
  { 37, 32 },    // pins
  {MIDI_CC::Effects_4, Channel_3},  // MIDI address (CC number + optional channel)
  2,             // optional multiplier if the control isn't fast enough
};
CCButton button3{
  30,
  { MIDI_CC::General_Purpose_Controller_1, Channel_3 },
};

// CLUSTER 4
// bank in top left corner
CCPotentiometer potCluster4[]{
  { A13, { MIDI_CC::Effects_1, Channel_4 } },
  { A12, { MIDI_CC::Effects_2, Channel_4 } },
  { A11, { MIDI_CC::Effects_3, Channel_4 } }

};
CCRotaryEncoder enc4{
  { 29, 28 },    // pins
  {MIDI_CC::Effects_4, Channel_4},  // MIDI address (CC number + optional channel)
  2,             // optional multiplier if the control isn't fast enough
};
CCButton button4{
  12,
  { MIDI_CC::General_Purpose_Controller_1, Channel_4 },
};

// CLUSTER 5
// bank in top left corner
CCPotentiometer potCluster5[]{
  { A14, { MIDI_CC::Effects_1, Channel_5 } },
  { A9, { MIDI_CC::Effects_2, Channel_5 } },
  { A10, { MIDI_CC::Effects_3, Channel_5 } }

};
CCRotaryEncoder enc5{
  { 10, 9 },    // pins
  {MIDI_CC::Effects_4, Channel_5},  // MIDI address (CC number + optional channel)
  2,             // optional multiplier if the control isn't fast enough
};
CCButton button5{
  11,
  { MIDI_CC::General_Purpose_Controller_1, Channel_5 },
};

// CLUSTER 6
// auxilliary bank -- too annoying to deal with, so removed for now
// CCPotentiometer potCluster6[]{
//   { A6, { MIDI_CC::Effects_1, Channel_6 } },
//   { A7, { MIDI_CC::Effects_2, Channel_6 } },
//   { A8, { MIDI_CC::Effects_3, Channel_6 } }

// };
// CCRotaryEncoder enc6{
//   { 2, 1 },    // pins
//   {MIDI_CC::Effects_4, Channel_6},  // MIDI address (CC number + optional channel)
//   2,             // optional multiplier if the control isn't fast enough
// };
// CCButton button6{
//   0,
//   { MIDI_CC::General_Purpose_Controller_1, Channel_6 },
// };



void setup() {
  // optionally set relative cc mode if the existing one doesn't work
  Control_Surface.begin();  // Initialize Control Surface
}

void loop() {
  Control_Surface.loop();  // Update the Control Surface
}
