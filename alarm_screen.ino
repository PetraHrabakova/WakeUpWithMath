void alarm_screen() {             // Displays alarm screen
  gfx.Cls(BLACK);
  gfx.TextSize(8);
  gfx.FontStyle(DOTMATRIXLED);
  gfx.TextColor(ORANGE, BLACK);
  gfx.MoveTo(40, 90);
  gfx.print(hours);
  gfx.print(":");
  gfx.print(minutes);

  gfx.TextSize(4);
  gfx.MoveTo(30, 150);
  gfx.print("WAKEY WAKEY");
  button18.init();
}
