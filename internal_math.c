int greatest_common_divisor(int integer1 , int integer2)
{
  int gcd;
  for(int i=1; i<=integer1 && i<=integer2; i++)
  {
    if(integer1%i==0 && integer2%i==0)
    {
      gcd = i;
    }
  }
  return gcd;
}