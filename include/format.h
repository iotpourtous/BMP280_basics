#ifndef format_h
#define format_h

String formatFloat(float value)
{
  char retour[] = "--";
  if (!isnan(value))
  {
    sprintf(retour, "%.1f", value);
  }
  return String(retour);
}


int roundedFloat(float value)
{
  return (int)round(value);
}

#endif