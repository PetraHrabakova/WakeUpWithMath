void show_alarm() {            // SHOW ALARM button in main menu
  if (alarm_hours >= 0 && alarm_minutes >= 0 && alarm_seconds > 0) {     // If there is an alarm set, display the alarm
    gfx.TextSize(2);
    gfx.MoveTo(20, 20);
    gfx.print("Your alarm is set to ");
    gfx.TextSize(3);
    gfx.MoveTo(20, 60);
    gfx.print(alarm_hours);
    gfx.print(":");
    gfx.print(alarm_minutes);
    delay(2000);
  }
  else                              // If there is no alarm, show a message
  {
    gfx.TextSize(2);
    gfx.MoveTo(20, 20);
    gfx.print("There is no alarm set");
    delay(2000);
  }
}
