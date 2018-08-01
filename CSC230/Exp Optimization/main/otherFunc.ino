FPTYPE pow_1(FPTYPE x, uint32_t y) {
  if (y == 0) return 1.0;

  if (y == 1) return x;

  if (y & 1) return x * pow_1(x, y-1);

  FPTYPE temp = pow_1(x, y >> 1);
  return temp * temp;
}

FPTYPE fact(uint32_t x) {
  if (x <= 1) return 1.0;

  return x * fact(x-1);
}

void calcExponent(String type, ExpFunc_t expFunc, FPTYPE x) {
  int32_t startTime = _CP0_GET_COUNT();
  int32_t stopTime;
  FPTYPE result = expFunc(x);
  stopTime = _CP0_GET_COUNT();
  Serial.print(type + " version: e^" + String(x) + " = ");
#if (USE_DOUBLE)
  Serial.print(result, 14);
#else
  Serial.print(result, 7);
#endif
  Serial.print(", ");
  Serial.print((stopTime - startTime) << 1, DEC);
  Serial.println(" CPU cycles");
}

