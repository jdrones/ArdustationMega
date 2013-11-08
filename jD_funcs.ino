//#define VER "v1.1"


void init_ASM() {

    
    GLCD.ClearScreen();
    delay(50);
    Splash();
    delay(1000);

    GLCD.CursorTo(0,5);
    GLCD.println("Initialize");
    Splash();
    delay(1000);

    GLCD.CursorTo(0,6);
    GLCD.println(" Servos...");
    Splash();
    delay(1000);

    GLCD.CursorTo(0,6);
    GLCD.println(" SD Card..");
    Splash();
    delay(1000);

    GLCD.CursorTo(0,6);
    GLCD.println(" BattADC..");
    Splash();
    delay(1000);

    GLCD.CursorTo(0,6);
    GLCD.println(" Serial...");
    Splash();
    delay(1000);

//    delay(3000);
    GLCD.ClearScreen();

}


void Splash(){
 int a = 73;
 int b = -5;

 GLCD.SelectFont(System5x7, BLACK); // font for the default text area

// GLCD.ClearScreen();
 GLCD.CursorTo(0,1);
 GLCD.println("jDrones ASM");
 GLCD.print("    ");
 GLCD.println(VER);
 GLCD.DrawHLine(2, 25, 60, BLACK);

// GLCD.CursorTo(0,5);
// GLCD.println(" Press C to");
// GLCD.println("   start");
 GLCD.DrawRoundRect(GLCD.CenterX + 5, 0, GLCD.CenterX -6, GLCD.Bottom, 5);  // rounded rectangle around text area 
 
 //  YLA, VASEn, YLA, VASEN
  
  // Box 
  GLCD.DrawLine(a + 5, b + 56, a + 25, b + 56, BLACK); 
  GLCD.DrawLine(a + 25, b + 56, a + 25, b + 42, BLACK); 
  GLCD.DrawLine(a + 25, b + 42, a + 20, b + 37, BLACK); 
  GLCD.DrawLine(a + 20, b + 37, a + 10, b + 37, BLACK); 
  GLCD.DrawLine(a + 10, b + 37, a + 5, b + 42, BLACK); 
  GLCD.DrawLine(a + 5, b + 42, a + 5, b + 56, BLACK); 
  // Box hole
  GLCD.DrawCircle(a + 15, b + 44, 2, BLACK);

  //Yagi frame
  GLCD.DrawLine(a + 24, b + 40, a + 44, b + 20, BLACK); 
  GLCD.DrawLine(a + 44, b + 20, a + 44, b + 17, BLACK); 
  GLCD.DrawLine(a + 44, b + 17, a + 23, b + 38, BLACK); 
  // Yagi segments
  GLCD.DrawLine(a + 25, b + 30, a + 33, b + 38, BLACK); 
  GLCD.DrawLine(a + 27, b + 28, a + 35, b + 36, BLACK); 
  GLCD.DrawLine(a + 29, b + 26, a + 37, b + 34, BLACK); 
  GLCD.DrawLine(a + 31, b + 24, a + 39, b + 32, BLACK); 
  GLCD.DrawLine(a + 33, b + 22, a + 41, b + 30, BLACK); 
  GLCD.DrawLine(a + 36, b + 21, a + 41, b + 26, BLACK); 
  GLCD.DrawLine(a + 39, b + 20, a + 43, b + 23, BLACK); 

  // Patch Antenna
  GLCD.DrawLine(a + 24, b + 36, a + 12, b + 24, BLACK); 
  GLCD.DrawLine(a + 12, b + 24, a + 16, b + 24, BLACK); 
  GLCD.DrawLine(a + 16, b + 24, a + 22, b + 30, BLACK); 
  GLCD.DrawLine(a + 22, b + 30, a + 22, b + 34, BLACK); 

  // Legs
  GLCD.DrawLine(a + 7, b + 61, a + 11, b + 57, BLACK); 
  GLCD.DrawLine(a + 7, b + 61, a + 11, b + 57, BLACK); 
  GLCD.DrawLine(a + 15, b + 61, a + 15, b + 57, BLACK); 
  GLCD.DrawLine(a + 23, b + 61, a + 19, b + 57, BLACK); 
  GLCD.DrawLine(a + 6, b + 62, a + 8, b + 62, BLACK); 
  GLCD.DrawLine(a + 14, b + 62, a + 16, b + 62, BLACK); 
  GLCD.DrawLine(a + 22, b + 62, a + 24, b + 62, BLACK); 
  
 
}


int Kbd() {
    byte x;
    Wire.requestFrom(32,1); 
    if(Wire.available())     //If the request is available
    {
        x=Wire.read();       //Receive the data
    }
    if(x<255)                     //If the data is less than 255
    {
      
      if(x == 239) return 1;
      
//        GLCD.CursorToXY(15,10);

//        if (x==251) GLCD.println("A"); //P1
//        if (x==247) GLCD.println("B"); //P1
//        if (x==239) GLCD.println("C"); //P1
//        if (x==127) GLCD.println("D"); //P1
//        if (x==223) GLCD.println("E"); //P1
//        if (x==191) GLCD.println("F"); //P1
//        GLCD.CursorToXY(25,10);
//        GLCD.println(x, DEC);
    }

    Wire.endTransmission();            //End the Transmission
    return 0;
}  


/*
byte KbdRead() {
  byte _data;
  Wire.requestFrom(expander, 1);
  if(Wire.available()) {
    _data = Wire.read();
  }
  return _data;
}


*/


