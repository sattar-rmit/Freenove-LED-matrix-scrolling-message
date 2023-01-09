
void  refresh_display(){

              
                   int hh= map(analogRead(A1),0,1023,1,200);
              
 
                    for (int k = 0; k < hh; k++) {      // hh= repeat image of each frame 10 or 20 times.// can replace with fixed value
                    hh= map(analogRead(A1),0,1023,1,200);
                                  
                    int cols = 0x01;      // Assign binary 00000001. Means the first column is selected.
                   
                    for (int j = 0; j < 8; j++) { // display image of each frame
                          matrix(Display_array_data[j],cols);
                          cols <<= 1;                 // shift"cols" 1 bit left to select the next column
                          delay(map(analogRead(A2),0,1023,1,100));  // or replace with delay(1);
                                
                              }                                            
                          
                        }

                       //// Scroll display!!
                       //// using for loop
                      for(int p=7; p>0; p--){ // it is important to fill arrays from 7<--6, 6<--5, etc for scrolling
                              Display_array_data[p] = Display_array_data[p-1];
                //              Serial.println(p); 
                              }

}// end function
