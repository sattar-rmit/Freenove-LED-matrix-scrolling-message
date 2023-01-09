/*/////////////
Code by Abdul Sattar, RMIT.
Includes all ABC characters.
Simply write your msg in short_msg[], all the rest will be displayed automatically.
Display scrolls.
More details here on Youtube: https://www.youtube.com/c/hotresistorblog
Github: https://github.com/sattar-rmit
Website: hotresistor.blogspot.com
////////////////////*/

int latchPin = 12;  // Pin connected to ST_CP of 74HC595（Pin12）
int clockPin = 13;  // Pin connected to SH_CP of 74HC595（Pin11）
int dataPin = 11;   // Pin connected to DS of 74HC595（Pin14）

// Define the pattern data for a smiling face
const int smilingFace[] = {
  0x1C, 0x22, 0x51, 0x45, 0x45, 0x51, 0x22, 0x1C
};


// Define the data of numbers and letters, and save them in flash area
const int data[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // " "
  0x00, 0x00, 0x21, 0x7F, 0x01, 0x00, 0x00, 0x00, // "1"
  0x00, 0x00, 0x23, 0x45, 0x49, 0x31, 0x00, 0x00, // "2"
  0x00, 0x00, 0x22, 0x49, 0x49, 0x36, 0x00, 0x00, // "3"
  0x00, 0x00, 0x0E, 0x32, 0x7F, 0x02, 0x00, 0x00, // "4"
  0x00, 0x00, 0x79, 0x49, 0x49, 0x46, 0x00, 0x00, // "5"
  0x00, 0x00, 0x3E, 0x49, 0x49, 0x26, 0x00, 0x00, // "6"
  0x00, 0x00, 0x60, 0x47, 0x48, 0x70, 0x00, 0x00, // "7"
  0x00, 0x00, 0x36, 0x49, 0x49, 0x36, 0x00, 0x00, // "8"
  0x00, 0x00, 0x32, 0x49, 0x49, 0x3E, 0x00, 0x00, // "9"
  0x00, 0x00, 0x3E, 0x41, 0x41, 0x3E, 0x00, 0x00, // "0"
  0x00, 0x00, 0x3F, 0x44, 0x44, 0x3F, 0x00, 0x00, // "A"
  0x00, 0x00, 0x7F, 0x49, 0x49, 0x36, 0x00, 0x00, // "B"
  0x00, 0x00, 0x3E, 0x41, 0x41, 0x22, 0x00, 0x00, // "C"
  0x00, 0x00, 0x7F, 0x41, 0x41, 0x3E, 0x00, 0x00, // "D"
  0x00, 0x00, 0x7F, 0x49, 0x49, 0x41, 0x00, 0x00, // "E"
  0x00, 0x00, 0x7F, 0x48, 0x48, 0x40, 0x00, 0x00,  // "F"
  B00000000, B00000000, B00111110, B01000001, B01001001, B00101110, B00000000, B00000000, //G
  B00000000, B00000000, B01111111, B00001000, B00001000, B01111111, B00000000, B00000000, //H
  B00000000, B00000000, B00000000, B01000001, B01111111, B01000001, B00000000, B00000000, //I
  B00000000, B00000000, B00000110, B00000001, B01000001, B01111110, B01000000, B00000000, //J
  B00000000, B00000000, B01111111, B00001000, B00010100, B00100010, B01000001, B00000000, //K
  B00000000, B00000000, B01111111, B00000001, B00000001, B00000001, B00000000, B00000000, //L
  B00000000, B00000000, B01111111, B00010000, B00001000, B00010000, B01111111, B00000000, //M
  B00000000, B00000000, B01111111, B00010000, B00001100, B00000010, B01111111, B00000000,//N
  B00000000, B00000000, B00111110, B01000001, B01000001, B00111110, B00000000, B00000000,//O
  B00000000, B00000000, B01111111, B01001000, B01001000, B00110000, B00000000, B00000000, //P
  B00000000, B00000000, B00111110, B01000001, B01000001, B00111111, B00000001, B00000000, //Q
  B00000000, B00000000, B01111111, B01001000, B01001100, B00110010, B00000001, B00000000, //R
  B00000000, B00000000, B00110010, B01001001, B01001001, B00100110, B00000000, B00000000, //S
  B00000000, B00000000, B01000000, B01000000, B01111111, B01000000, B01000000, B00000000, //T
  B00000000, B00000000, B01111110, B00000001, B00000001, B00000001, B01111110, B00000000, //U
  B00000000, B00000000, B01111100, B00000010, B00000001, B00000010, B01111100, B00000000, //V
  B00000000, B00000000, B01111111, B00000010, B00001100, B00000010, B01111111, B00000000, //W
  B00000000, B01000001, B00100010, B00010100, B00001000, B00010100, B00100010, B01000001, //X
  B00000000, B00000000, B01100000, B00010000, B00001111, B00010000, B01100000, B00000000, //Y
  B00000000, B00000000, B01100011, B01000101, B01001001, B01010001, B01100011, B00000000, //Z
  B00000000, B00000000, B00000000, B00000011, B00000011, B00000000, B00000000, B00000000,  // . OR PERIOD
  B00000000, B00000000, B00000000, B00000000, B00001101, B00001110, B00000000, B00000000,   // , COMMA
  B00000000, B00000000, B00000000, B01111101, B01111101, B00000000, B00000000, B00000000, // !
  B00000000, B00000000, B00110000, B01000000, B01000101, B01001000, B00110000, B00000000 // ?
};


//char short_msg[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";   // TEST ABC COMPLETE STRING // UNCOMMENT TO TEST ABC..Z

char short_msg[] = "WRITE YOUR MSG HERE"; // MUST BE ALL CAPS FOR SEARCH INDEX TO WORK

int number_char_in_msg = 19;  /// MUST UPDATE EVERYTIME AS PER CHARACTERS IN short_msg[] var; INCLUDE 'SPACES'

int Display_array_index[100];

int Display_array_data[8];




void setup() {

  Serial.begin(115200);



  // set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

 
////////////////////////////////////////////////////
  search_array_index(short_msg); // must be run once to find index of characters from short_msg[]
////////////////////////////////////////////////////



  
}// end void setup






void loop() {



/// Sattar's Display Array

//  number_char_in_msg = updated in global variables

  for (int char_counter = 0; char_counter < number_char_in_msg; char_counter++) {


        for (int read_8bytes = 0; read_8bytes < 8; read_8bytes++) {

          Display_array_data[0] = pgm_read_byte(&data[Display_array_index[char_counter]+read_8bytes]);

          
          refresh_display();

         
          }
          
    }


}  /// end loop






void matrix(byte row_value, byte col_value) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, row_value); // original
//   shiftOut(dataPin, clockPin, MSBFIRST, row_value);
   shiftOut(dataPin, clockPin, LSBFIRST, ~col_value);
//  shiftOut(dataPin, clockPin, MSBFIRST, ~col_value); // original
  digitalWrite(latchPin, HIGH);
}
