#define USE_DOUBLE  0
#if (USE_DOUBLE)
typedef double FPTYPE;
#else
typedef float FPTYPE;
#endif

typedef FPTYPE (*ExpFunc_t)(FPTYPE);

constexpr FPTYPE fact_2(uint32_t n)
{
  return n <= 1 ? 1.0 : n * fact_2(n-1);
}

static const FPTYPE factTable[34] = {
  fact_2(0), 
  fact_2(1),
  fact_2(2),
  fact_2(3),
  fact_2(4),
  fact_2(5),
  fact_2(6),
  fact_2(7),
  fact_2(8),
  fact_2(9),
  fact_2(10),
  fact_2(11),
  fact_2(12),
  fact_2(13),
  fact_2(14),
  fact_2(15),
  fact_2(16),
  fact_2(17),
  fact_2(18),
  fact_2(19),
  fact_2(20),
  fact_2(21),
  fact_2(22),
  fact_2(23),
  fact_2(24),
  fact_2(25),
  fact_2(26),
  fact_2(27),
  fact_2(28),
  fact_2(29),
  fact_2(30),
  fact_2(31),
  fact_2(32),
  fact_2(33)
};
// Test 3: Invert the factorial table (1/x!) and multiply.
const FPTYPE factTable_3[34] = {
  1.0/factTable[0],
  1.0/factTable[1],
  1.0/factTable[2],
  1.0/factTable[3],
  1.0/factTable[4],
  1.0/factTable[5],
  1.0/factTable[6],
  1.0/factTable[7],
  1.0/factTable[8],
  1.0/factTable[9],
  1.0/factTable[10],
  1.0/factTable[11],
  1.0/factTable[12],
  1.0/factTable[13],
  1.0/factTable[14],
  1.0/factTable[15],
  1.0/factTable[16],
  1.0/factTable[17],
  1.0/factTable[18],
  1.0/factTable[19],
  1.0/factTable[20],
  1.0/factTable[21],
  1.0/factTable[22],
  1.0/factTable[23],
  1.0/factTable[24],
  1.0/factTable[25],
  1.0/factTable[26],
  1.0/factTable[27],
  1.0/factTable[28],
  1.0/factTable[29],
  1.0/factTable[30],
  1.0/factTable[31],
  1.0/factTable[32],
  1.0/factTable[33]
};
/*const FPTYPE factTable_3[34] = {
  1.0/fact_2(0), 
  1.0/fact_2(1),
  1.0/fact_2(2),
  1.0/fact_2(3),
  1.0/fact_2(4),
  1.0/fact_2(5),
  1.0/fact_2(6),
  1.0/fact_2(7),
  1.0/fact_2(8),
  1.0/fact_2(9),
  1.0/fact_2(10),
  1.0/fact_2(11),
  1.0/fact_2(12),
  1.0/fact_2(13),
  1.0/fact_2(14),
  1.0/fact_2(15),
  1.0/fact_2(16),
  1.0/fact_2(17),
  1.0/fact_2(18),
  1.0/fact_2(19),
  1.0/fact_2(20),
  1.0/fact_2(21),
  1.0/fact_2(22),
  1.0/fact_2(23),
  1.0/fact_2(24),
  1.0/fact_2(25),
  1.0/fact_2(26),
  1.0/fact_2(27),
  1.0/fact_2(28),
  1.0/fact_2(29),
  1.0/fact_2(30),
  1.0/fact_2(31),
  1.0/fact_2(32),
  1.0/fact_2(33)
};*/
void setup() {
  uint32_t i;
  uint32_t *int_p;
  // put your setup code here, to run once:
  Serial.begin(9600);

  while (!Serial.available());
  Serial.flush();

  Serial.println("Welcome to exponent calculator!");

}

static FPTYPE myX = 10.5;
static int testNum = 0;

//String outPut(FPTYPE myX) {
void loop(){
  // put your main code here, to run repeatedly;

    switch (testNum) {
      case 0 :
        calcExponent("Normal", exp_1, myX);
        testNum++;
        break;
      case 1 :
        calcExponent("Factorial Table", exp_2, myX);
        testNum++;
        break;
      case 2 :
        calcExponent("Inverted Factorial Table", exp_3, myX);
        testNum++;
        break;
      case 3 :
        calcExponent("Progressive Power", exp_4, myX);
        testNum++;
        break;
      default :
      
        break;
    }
     

}

/*void loop(){
  while(myX<20)
  {
    outPut(myX);
    myX++;
  }
}*/
    

