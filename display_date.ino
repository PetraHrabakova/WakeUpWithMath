void display_date() {               // Displays date
  gfx.TextSize(8);
  gfx.FontStyle(DOTMATRIXLED);
  gfx.TextColor(ORANGE, BLACK);
  gfx.MoveTo(60, 90);
  gfx.print(days);
  gfx.print("/");
  gfx.print(months);

  delay(2000);
  gfx.Cls();
}
