void delete_alarm() {           // Action taken after pressing DELETE ALARM button
  if (alarm_hours >= 0 && alarm_minutes >= 0 && alarm_seconds > 0) {     // If the alarm is actually set
    gfx.TextSize(2);
    gfx.MoveTo(20, 20);
    gfx.println("Your alarm has been ");      // Display a message
    gfx.println("   succesfully deleted");
    delay(2000);
    gfx.Cls();
    alarm_hours = 0;                          // Set alarm values to 0
    alarm_minutes = 0;                        // Set alarm values to 0
    alarm_seconds = 0;                        // Set alarm values to 0
  }
  else {                                      // If there is no alarm
    gfx.TextSize(2);
    gfx.MoveTo(20, 20);
    gfx.println("There is no alarm ");        // Show a message
    gfx.println("   to be deleted");
    delay(2000);
    gfx.Cls();
  }
}
