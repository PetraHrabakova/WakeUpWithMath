#include "GFX4d.h"                                            // include library for the screen
//#include <SoftwareSerial.h>                                 // software serial library

GFX4d gfx = GFX4d();                                          // Create object for the screen
//SoftwareSerial serialArduino(2, 3);                         // Create object for software serial

class button {                    // Creating class for button
  public:                         // Access modifier to make all members public
    int hndl;                     // Attributes that the class has (only blue print, not the data)
    int x;                        // All the variables needed to create a button
    int y;
    int w;
    int h;
    int buttonColour;
    String text;
    int fontID;
    int txtColour;

    // Constructor "button" that passes all the needed variables for creation as parameters
    button(int hndl, int x, int y, int w, int h, int buttonColour, String text, int fontID, int txtColour)
    {
      this-> hndl = hndl;
      this-> x = x;
      this-> y = y;
      this-> w = w;
      this-> h = h;
      this-> buttonColour = buttonColour;
      this-> text = text;
      this-> fontID = fontID;
      this-> txtColour = txtColour;
    }

    // Class method init() to create the button
    void init() {
      gfx.Buttonx(hndl, x, y, w, h, buttonColour, text, fontID, txtColour);
    }
};


// Bellow I create all the button objects used in the program using "button" constructor created above in the class
// Main screen
button button12 = button(12, 120, 30, 90, 40, GREEN, "SET ALARM", 2, BLACK);        // SET ALARM
button button13 = button(13, 120, 130, 90, 40, GREEN, "SEE DATE", 2, BLACK);        // SEE DATE
button button14 = button(14, 120, 80, 90, 40, GREEN, "SEE TIME", 2, BLACK);         // SEE TIME
button button16 = button(16, 120, 180, 90, 40, GREEN, "SEE ALARM", 2, BLACK);       // SEE ALARM
button button19 = button(19, 20, 185, 80, 30, RED, "DELETE ALARM", 1, BLACK);       // DELETE ALARM

// Keyboard used to set timer
button button1 = button(1, 100, 80, 40, 40, WHITE, "1", 2, BLACK);
button button2 = button(2, 140, 80, 40, 40, WHITE, "2", 2, BLACK);
button button3 = button(3, 180, 80, 40, 40, WHITE, "3", 2, BLACK);
button button4 = button(4, 100, 120, 40, 40, WHITE, "4", 2, BLACK);
button button5 = button(5, 140, 120, 40, 40, WHITE, "5", 2, BLACK);
button button6 = button(6, 180, 120, 40, 40, WHITE, "6", 2, BLACK);
button button7 = button(7, 100, 160, 40, 40, WHITE, "7", 2, BLACK);
button button8 = button(8, 140, 160, 40, 40, WHITE, "8", 2, BLACK);
button button9 = button(9, 180, 160, 40, 40, WHITE, "9", 2, BLACK);
button button10 = button(10, 140, 200, 40, 40, WHITE, "0", 2, BLACK);
button button11 = button (11, 230, 80, 70, 30, GRAY, "DELETE", 2, BLACK);           // DELETE KEY
button button15 = button (15, 230, 180, 70, 30, GREEN, "SUBMIT", 2, BLACK);         // SUBMIT ALARM TIME
button button17 = button(17, 230, 20, 70, 30, RED, "BACK", 2, BLACK);               // BACK TO MAIN SCREEN

// Morning screen
button button18 = button(18, 200, 20, 100, 40, RED, "START MATH", 2, BLACK);        // START MATH button on morning screen

// Keyboard used when solving math problems
button button31 = button(31, 100, 80, 40, 40, WHITE, "1", 2, BLACK);
button button32 = button(32, 140, 80, 40, 40, WHITE, "2", 2, BLACK);
button button33 = button(33, 180, 80, 40, 40, WHITE, "3", 2, BLACK);
button button34 = button(34, 100, 120, 40, 40, WHITE, "4", 2, BLACK);
button button35 = button(35, 140, 120, 40, 40, WHITE, "5", 2, BLACK);
button button36 = button(36, 180, 120, 40, 40, WHITE, "6", 2, BLACK);
button button37 = button(37, 100, 160, 40, 40, WHITE, "7", 2, BLACK);
button button38 = button(38, 140, 160, 40, 40, WHITE, "8", 2, BLACK);
button button39 = button(39, 180, 160, 40, 40, WHITE, "9", 2, BLACK);
button button40 = button(40, 140, 200, 40, 40, WHITE, "0", 2, BLACK);
button button41 = button (41, 230, 80, 70, 30, GRAY, "DELETE", 2, BLACK);           // DELETE KEY
button button45 = button (45, 230, 180, 70, 30, GREEN, "SUBMIT", 2, BLACK);         // SUBMIT ANSWER


// Variables for checking if button is pressed
int reading;
int last_reading;
int but;

// Varibles to keep the numbers for alarm clock
int fillSize = 0;               // Size of the array
int time_array[4];

// Variables for array that holds user's answers to the math problems
int Size = 0;
int result_array[3];

// Variables for alarm
int alarm_minutes;
int alarm_hours;
int alarm_seconds;
int seconds_array[0];

// Arrays to keep the result and user's answer
int user_answer[1];

// Pointer to math_problems function
int *result;

// Variables to turn on and off the speaker without delay
int alarmState = LOW;
unsigned long previousMillis = 0;
const long interval = 200;


/* THE SECTION BELOW I DID NOT MAKE MYSELF - FOUND ONLINE */
// Variables for time
unsigned long timeNow = 0;
unsigned long timeLast = 0;

// Time start setting
int startingHour = 10;        // Set starting hour, not below at int hour. This ensures accurate daily correction of time

int seconds = 0;
int minutes = 23;             // Change these numbers to the time when you are uploading the program
int hours = startingHour;
int days = 14;                // Change these numbers to the date when you are uploading the program
int months = 6;               // Change these numbers to the date when you are uploading the program

// Accuracy settings
int dailyErrorFast = 0;       // Set the average number of milliseconds your microcontroller's time is fast on a daily basis
int dailyErrorBehind = 1;     // Set the average number of milliseconds your microcontroller's time is behind on a daily basis

int correctedToday = 1;       // Do not change this variable, one means that the time has already been corrected today for the error in your boards crystal
// This is true for the first day because you just set the time when you uploaded the sketch
/* THE SECTION ABOVE I DID NOT MAKE MYSELF - FOUND ONLINE */



void setup() {
  //  serialArduino.begin(115200);        // Serial communication with Arduino

  pinMode(16, OUTPUT);                    // Making a pin 16 output for the speaker

  gfx.begin();                            // Initial settings for the screen
  gfx.Cls();                              // Initial settings for the screen
  gfx.ScrollEnable(false);                // Initial settings for the screen
  gfx.BacklightOn(true);                  // Initial settings for the screen
  gfx.Orientation(LANDSCAPE);             // Initial settings for the screen
  gfx.touch_Set(TOUCH_ENABLE);            // Initial settings for the screen


  button12.init();                        // Initialize the main menu buttons
  button13.init();                        // Initialize the main menu buttons
  button14.init();                        // Initialize the main menu buttons
  button16.init();                        // Initialize the main menu buttons
  button19.init();                        // Initialize the main menu buttons
}


void loop() {
  time_baby();                            // Start time

  reading = gfx.CheckButtons();                     // Check buttons state
  if (reading != last_reading && reading > 0) {     // A massive if statement that checks if any of the buttons are being pressed
    but = reading;

    if (but == 14) {              // SEE TIME
      delete_menu();              // Deletes menu buttons
      display_time();             // Displays time
      menu();                     // Initializes menu buttons again
    }

    if (but == 13) {              // DISPLAY DATE
      delete_menu();              // Deletes menu
      display_date();             // Displays date
      menu();                     // Initializes menu buttons again
    }

    if (but == 12) {              // SET ALARM
      delete_menu();              // Deletes menu
      keyboard();                 // Initializes keyboard buttons
    }

    if (but == 16) {              // SEE ALARM
      delete_menu();              // Deletes menu
      show_alarm();               // If there is an alarm set, it shows the alarm, if there is no alarm, it say "there is no alarm set"
      menu();                     // Initializes manu again
    }

    if (but == 19) {              // DELETE ALARM
      delete_menu();              // Deletes menu
      delete_alarm();             // Deletes alarm and shows message
      menu();                     // Shows menu again
    }

    if (but == 1) {
      print_whatever("1");            // Little function that takes a string as a parameter and prints it woohooo
      time_array[fillSize++] = 1;     // If you press this button it puts 1 on the next position in the time_array

    }
    if (but == 2) {
      print_whatever("2");            // Prints 2 on the screen
      time_array[fillSize++] = 2;     // If you press this button it puts 2 on the next position in the time_array
    }
    if (but == 3) {
      print_whatever("3");            // Prints 3 on the screen
      time_array[fillSize++] = 3;     // If you press this button it puts 3 on the next position in the time_array
    }
    if (but == 4) {
      print_whatever("4");            // Prints 4 on the screen
      time_array[fillSize++] = 4;     // If you press this button it puts 4 on the next position in the time_array
    }
    if (but == 5) {
      print_whatever("5");            // Prints 5 on the screen
      time_array[fillSize++] = 5;     // If you press this button it puts 5 on the next position in the time_array
    }
    if (but == 6) {
      print_whatever("6");            // Prints 6 on the screen
      time_array[fillSize++] = 6;     // If you press this button it puts 6 on the next position in the time_array
    }
    if (but == 7) {
      print_whatever("7");            // Prints 7 on the screen
      time_array[fillSize++] = 7;     // If you press this button it puts 7 on the next position in the time_array
    }
    if (but == 8) {
      print_whatever("8");            // Prints 8 on the screen
      time_array[fillSize++] = 8;     // If you press this button it puts 8 on the next position in the time_array
    }
    if (but == 9) {
      print_whatever("9");            // Prints 9 on the screen
      time_array[fillSize++] = 9;     // If you press this button it puts 9 on the next position in the time_array
    }
    if (but == 10) {
      print_whatever("0");            // Prints 0 on the screen
      time_array[fillSize++] = 0;     // If you press this button it puts 0 on the next position in the time_array
    }
    if (but == 11) {                  // DELETE
      alarm_hours = 0;                          // Set alarm values to 0
      alarm_minutes = 0;                        // Set alarm values to 0
      alarm_seconds = 0;                         // Set alarm values to 0
      keyboard();                     // Display the keyboard button again


    }
    if (but == 15) {                  // SUBMIT ALARM
      alarm_seconds = 1;              // Whenever alarm_second is more than 0, it means there is an alarm set, so whenever the user hits SUBMIT, the program knows there is an alarm set
      print_whatever("Alarm ");
      gfx.print(alarm_hours);
      gfx.print(":");
      gfx.print(alarm_minutes);
    }

    if (but == 17) {                  // BACK
      delete_keyboard1();             // Back to main screen from setting the alarm
      menu();                         // Initializes menu
    }

    if (but == 18) {
      //      serialArduino.write('2');       // If the button is pressed, send "2" via UART and the speaker turns off

      alarm_hours = 0;                    // Set these variables to 0 so the program knows there is no alarm now, since the user just turned it off by starting the math problems
      alarm_minutes = 0;                  // Set these variables to 0 so the program knows there is no alarm now, since the user just turned it off by starting the math problems
      alarm_seconds = 0;                  // Set these variables to 0 so the program knows there is no alarm now, since the user just turned it off by starting the math problems
      digitalWrite(16, LOW);              // Turn off the speaker
      delete_menu();                      // Delete the main screen button
      keyboard2();                        // Initialize second keypad for math problems
      result = math_problem(random(1, 5));      // Give out first math problem ranndomly picked out
    }

    // The following 10 if statements are regarding the keys that user hits when answering the math problems
    // Result array holds the user's answer at the very first position - whenever user hits a key
    // The current value gets multiplied by 10 and the value of the key is added - isn't it just genius?

    if (but == 31) {
      print_whatever("1");
      result_array[0] = (result_array[0] * 10 + 1);         // Multiplies value at first position of result_array by 10 and adds 1
    }
    if (but == 32) {
      print_whatever("2");
      result_array[0] = (result_array[0] * 10 + 2);         // Multiplies value at first position of result_array by 10 and adds 2
    }
    if (but == 33) {
      print_whatever("3");
      result_array[0] = (result_array[0] * 10 + 3);         // Multiplies value at first position of result_array by 10 and adds 3
    }
    if (but == 34) {
      print_whatever("4");
      result_array[0] = (result_array[0] * 10 + 4);         // Multiplies value at first position of result_array by 10 and adds 4
    }
    if (but == 35) {
      print_whatever("5");
      result_array[0] = (result_array[0] * 10 + 5);         // Multiplies value at first position of result_array by 10 and adds 5
    }
    if (but == 36) {
      print_whatever("6");
      result_array[0] = (result_array[0] * 10 + 6);         // Multiplies value at first position of result_array by 10 and adds 6
    }
    if (but == 37) {
      print_whatever("7");
      result_array[0] = (result_array[0] * 10 + 7);         // Multiplies value at first position of result_array by 10 and adds 7
    }
    if (but == 38) {
      print_whatever("8");
      result_array[0] = (result_array[0] * 10 + 8);         // Multiplies value at first position of result_array by 10 and adds 8
    }
    if (but == 39) {
      print_whatever("9");
      result_array[0] = (result_array[0] * 10 + 9);         // Multiplies value at first position of result_array by 10 and adds 9
    }
    if (but == 40) {
      print_whatever("0");
      result_array[0] = (result_array[0] * 10);             // Multiplies value at first position of result_array by 10
    }
    if (but == 41) {                                // DELETE
      gfx.Cls();
      keyboard2();                                  // Shows keyboard
      result = math_problem(random(1, 5));          // And generates new math problem
    }

    if (but == 45) {                                // SUBMIT button for math problems
      if ((*(result) + 0) == result_array[0] && user_answer[0] < 5) {      // Checks the first position in the result array and if it's smaller than 5, it means the user hasn't finished his morning math yet
        gfx.Cls(GREEN);                                                    // Correct answer = green screen
        user_answer[0] += 1;                                               // Adds 1 to array position which holds the number of correct answers
        result_array[0] = 0;                                               // Wipes out array position where user's answer is stored
        keyboard2();                                                       // Shows keyboard 2 again
        result = math_problem(random(1, 5));                               // And generates new math problem
      }
      
      else {
        gfx.Cls(RED);                                                       // Wrong answer = red screen
        result_array[0] = 0;                                                // Wipes out array position where user's answer is stored
        user_answer[0] = 0;                                                 // Restarts the count of correct answers
        keyboard2();                                                        // Shows keyboard 2 again
        result = math_problem(random(1, 5));                                // And generates new math problem
      }
    }


    else {
      but = 0;
    }
    last_reading = reading;
  }

  alarm_convert();            // Function that returns alarm_minutes and alarm_hours by checking time_array

  // As described above, whenever there is alarm set, the alarm_seconds = 1, which means that as soon as the user sets an alarm (no matter the values), this if statement will be true
  if (alarm_hours >= 0 && alarm_minutes >= 0 && alarm_seconds > 0)
  {
    if (minutes == alarm_minutes && hours == alarm_hours)       // Alarm time must equal the time
    {
      //      serialArduino.write('1');           // Sends 1 to Arduino via UART (it turns on the speaker)
      gfx.Cls(GREEN);                             // Screen starts flashing green
      alarm_screen();                             // Displays the alarm screen

      // Speaker beeps without delay - genious
      unsigned long currentMillis = millis();     // Captures current amount of milliseconds since the program started
      if (currentMillis - previousMillis >= interval) {   // The interval is set to 200 ms so if the captured time minus previous captured time is larger or same, it flips the value for the speaker
        if (alarmState == LOW) {                          // That's how the delay is created
          alarmState = 700;                               // PWM of 700
        } else {
          alarmState = LOW;                               // If it was high before, it makes it LOW
        }
        previousMillis = currentMillis;
        analogWrite(16, alarmState);
      }
    }
  }
  if (user_answer[0] == 5) {       // If the user answered five times correctly
    delete_keyboard2();            // Deletes keyboard
    morning_screen();              // Good morning
    result_array[0] = 0;           // Clear array where user's answer is stored
    user_answer[0] = 0;            // Clears array thta keeps count of the correct answers
    menu();                        // Shows menu again
  }

  yield();                         // This is for the ESP8266
}
