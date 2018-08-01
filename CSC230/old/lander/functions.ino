
void spaceShip::startTime()
{
   int32_t startTime = _CP0_GET_COUNT();
   _startTime=startTime;
}
void spaceShip::stopTime()
{
   int32_t stopTime = _CP0_GET_COUNT();
   _stopTime=stopTime;
}
int32_t spaceShip::getTime()
{
  spaceShip s;
  int32_t Time;
  if(_stopTime<=_startTime)
  {
    s.stopTime();
  }
  Time=_stopTime-_startTime;
  return Time;
  
}
void spaceShip::timer_activ_getBurnRate()
{
  spaceShip t;
  int32_t eightMillion=8000000;
  int32_t stopTime;
  t.stopTime();
  //want _stopTime-_startTime=8 milion
  while(_stopTime>(eightMillion+_startTime))
  {
    t.stopTime();
  }
  getBurnRate();
}
double spaceShip::getBurnRate()
{
    return 1.009;
}
//want _stopTime-_startTime=8 milion
