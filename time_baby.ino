/* The code below I have not written myself - found online */
void time_baby() {
  timeNow = millis() / 1000; // the number of milliseconds that have passed since boot
  seconds = timeNow - timeLast;//the number of seconds that have passed since the last time 60 seconds was reached.

  if (seconds == 60) {
    timeLast = timeNow;
    minutes = minutes + 1;
  }

  // If one minute has passed, start counting milliseconds from zero again and add one minute to the clock.
  if (minutes == 60) {
    minutes = 0;
    hours = hours + 1;
  }

  // If one hour has passed, start counting minutes from zero and add one hour to the clock
  if (hours == 24) {
    hours = 0;
    days = days + 1;
  }

  if ((months == 1) or (months == 3) or (months == 5) or (months == 7) or (months == 9) or (months == 11)) {
    if (days == 31) {
      days = 0;
      months = months + 1;
    }
  }

  if ((months == 4) or (months == 6) or (months == 8) or (months == 10) or (months == 12)) {
    if (days == 30) {
      days = 0;
      months = months + 1;
    }
  }

  if (months == 2) {
    if (days == 28) {
      days = 0;
      months = months + 1;
    }
  }

  if (months == 12) {
    months = 0;
  }

  // If 24 hours have passed , add one day
  if (hours == (24 - startingHour) && correctedToday == 0) {
    delay(dailyErrorFast);
    seconds = seconds + dailyErrorBehind;
    correctedToday = 1;
  }

  // Every time 24 hours have passed since the initial starting time and it has not been reset this day before, add milliseconds or delay the program with some milliseconds.
  // Change these variables according to the error of your board.
  // The only way to find out how far off your boards internal clock is, is by uploading this sketch at exactly the same time as the real time, letting it run for a few days
  // And then determine how many seconds slow/fast your boards internal clo ck is on a daily average. (24 hours).

  if (hours == 24 - startingHour + 2) {
    correctedToday = 0;
  }

  // Let the sketch know that a new day has started for what concerns correction, if this line was not here the arduino
  // Would continue to correct for an entire hour that is 24 - startingHour.
}
/* The code above I have not written myself - found online */
