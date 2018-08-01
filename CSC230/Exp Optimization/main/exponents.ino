// inverted exp function and progressive
FPTYPE exp_1(FPTYPE x) {
  int i = 1;
  FPTYPE retval = 1.0 + x; // First two terms, which is always x^0/0! + x^1/1!
  FPTYPE nextTerm;
  
  do {
    i++;
    nextTerm = pow_1(x, i)/fact(i);
    retval += nextTerm;
  } while (nextTerm > 1.0e-10);

  return retval;
}


FPTYPE exp_2(FPTYPE x) {
  int i = 1;
  FPTYPE retval = 1.0 + x; // First two terms, which is always x^0/0! + x^1/1!
  FPTYPE nextTerm;
  
  
  do {
    i++;
    nextTerm=pow_1(x,i)/factTable[i];
    retval += nextTerm;
#if (USE_DOUBLE)
  } while ((i < 79) && (nextTerm > 1.0e-30));
#else
  } while ((i < 33) && (nextTerm > 1.0e-10));
#endif

  return retval;
}

FPTYPE exp_3(FPTYPE x) {
  int i = 1;
  FPTYPE retval = 1.0 + x; // First two terms, which is always x^0/0! + x^1/1!
  FPTYPE nextTerm;
  
  do {
    i++;
    nextTerm=pow_1(x,i)*factTable_3[i];
    retval += nextTerm;
    #if (USE_DOUBLE)
  } while ((i < 79) && (nextTerm > 1.0e-30));
#else
  } while ((i < 33) && (nextTerm > 1.0e-10));
#endif

  return retval;
}
  /*} while ((i < 79) && (nextTerm > 1.0e-30));

  return retval;*/


// Version 4: Turn power into iterative loop here in the exponent function
FPTYPE exp_4(FPTYPE x) {
  int i = 1;
  FPTYPE retval = 1.0 + x;
  FPTYPE powVal = x; // Initially x^1, since we've done that term now
  FPTYPE nextTerm;
  
  do {
    i++;
    powVal*=x;
    nextTerm=powVal*factTable_3[i];
    //Ask question!!!!
    retval += nextTerm;
#if (USE_DOUBLE)
   } while (i < 79);
#else
  } while (i < 33);
#endif

  return retval;
}


