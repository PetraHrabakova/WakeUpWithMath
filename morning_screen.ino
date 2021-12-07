void morning_screen() {          // Displays message after user solved all math problems
  gfx.Cls(BLACK);
  gfx.TextSize(5);
  gfx.FontStyle(DOTMATRIXLED);
  gfx.TextColor(ORANGE, BLACK);
  gfx.MoveTo(20, 90);
  gfx.print("Well done!");
  gfx.TextSize(3);
  gfx.MoveTo(20, 150);
  gfx.print("Have a beautiful day!");
  delay(2000);
  gfx.Cls();
}
