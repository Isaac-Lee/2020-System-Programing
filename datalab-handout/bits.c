/* 
 * CS:APP Data Lab 
 * 
 * NAME: 이예성
 * NUMBER: 201902727
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /*
   * 드모르간 법칙을 이용해서 해결
   */
  return ~((~x) | (~y));
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  /*
   * 드모르간 법칙을 이용해서 해결
   */
  return (~x) & (~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* 
   * 원하는 인덱스를 LSB의 위치로 bitshift 해주고
   * 해당하는 인덱스 값외 나머지값은 0과 and 연산으로 제거
   */
  return (x >> (n << 3)) & 0x000000ff;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  /* 
   * 바이트를 바꾸기 위해서 각 위치에 값을 복사하기 위한 Nnum, Mnum를 준비하고
   * 각 위치의 값을 복사해서 바꿔주는 위치로 bitshift를 한다.
   * Nbyte와 Mbyte를 이용해서 바꿔줄 위치의 값을 0으로 만들어 준다.
   * 그리고 다시 바꾼 값을 or연산으로 넣어준다.
   */

  int Nbyte = 0x000000ff << (n << 3);
  int Mbyte = 0x000000ff << (m << 3);

  int Nindex = n << 3;
  int Mindex = m << 3;

  int Nnum = ((x >> Nindex) & 0x000000ff) << Mindex;
  int Mnum = ((x >> Mindex) & 0x000000ff) << Nindex;

  x = x&(~(Nbyte|Mbyte));
  x = x|(Nnum|Mnum);

  return x;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  /* 
   * x, y 그리고 합의 부호를 구한다.
   * x, y의 부호가 다르면, overflow가 나지 않는다.
   * x, y의 부호가 같고, 합의 부호도 같다면, overflow가 나지 않는다.
   * return 에서 not을 할 때 bit로 하는지 logic으로 하는지가 다른데,
   * 이는 괄호 안에서 연산한 값으 0과 -1이 나오기 때문이다.
   */

  int sum = x + y;

  int Xsign = x >> 31;
  int Ysign = y >> 31;
  int Ssign = sum >> 31;

  return !(~(Xsign ^ Ysign) & (Ysign ^ Ssign));
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /* 
   * x가 양수고 y가 음수라면 무조건 x가 크다.
   * x와 y가 값이 같지 않고, x와 y의 부호가 같다면 두 수의 차의 부호와 같다.
   * x가 음수 y가 양수라면 y가 무조건 크다.
   */
  int Xsign = x >> 31;
  int Ysign = y >> 31;
  int XYsign = !((x+(~y+1)) >> 31);

  return (!Xsign & Ysign) | ((XYsign) & !(Xsign ^ Ysign) & !!(x^y));
}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
  /* 
   * x의 부로, 2배한 값의 부호, 3배한 값의 부호를 구한다.
   * 2, 3배를 하는동안 overflow가 난다면 overflow가 1이 된다.
   * x의 부호에 따라 overflow가 났을때 어떤 값을 가져야하는지 구한다.
   * overflow가 나면 x가 양수라면 정수 최대값, 음수라면 정수 최소값을 반환한다.
   * overflow가 나오지 않았다면 3배한 값을 그대로 반환한다.
   */
  int Xsign = x >> 31;
  int mul2 = x + x;
  int mul2Sign = mul2 >> 31;
  int mul3 = mul2 + x;
  int mul3Sign = mul3 >> 31;

  int overflow = ((Xsign ^ mul2Sign) | (mul2Sign ^ mul3Sign));

  int minMax = (~Xsign ^ (1 << 31)); // x가 양수면 정수 최대값, 음수면 정수 최소값

  return (overflow & minMax) | (~overflow & mul3);
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  /* 
   * 부호를 구해서 만약 음수라면 2의 보수에 1을 더해 양수를 구하고,
   * 양수인 경우에는 0을 구해서 저장한다.
   * x값에 구한값을 2번 더해준다.
   */
  int sign = x >> 31;
	int flip = (((~x) + 1) & sign);

	return x + flip + flip;
}
