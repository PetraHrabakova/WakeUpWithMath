void display_time() {               // Displays time
  gfx.TextSize(8);
  gfx.FontStyle(DOTMATRIXLED);
  gfx.TextColor(ORANGE, BLACK);
  gfx.MoveTo(40, 90);
  gfx.print(hours);
  gfx.print(":");
  gfx.print(minutes);

  delay(2000);
  gfx.Cls();
}
