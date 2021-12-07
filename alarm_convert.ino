int alarm_convert() {       // Creates the alarm time
  // time_array saves the values of the buttons that the user pressed when setting alarm
  alarm_hours = time_array[0] * 10 + time_array[1];     // First position of the array gets multiplied by 10 and then second position is added, together it is the value for alarm_hours
  alarm_minutes = time_array[2] * 10 + time_array[3];   // Third position of the array gets multiplied by 10 and then fourth position is added, together it is the value for alarm_minutes

  return alarm_hours;
  return alarm_minutes;
}
