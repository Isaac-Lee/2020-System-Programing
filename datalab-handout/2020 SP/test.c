#include <limits.h>
#include <stdio.h>
int isGreater(int x, int y) {
  /* 
   * x가 양수고 y가 음수라면 수가 무조건 x가 크다.
   * x와 y가 값이 값을 경우를 생각해서 x > y이면 1을 갖는 값을 만들어준다.
   * 단순하게 뺄셈을 해서 부호를 
   */
  int Xsign = (x >> 31) & 1;
  int Ysign = (y >> 31) & 1;
  int XYsign = !((x+(~y+1)) >> 31);

  return (!Xsign & Ysign) | (XYsign) & !(Xsign ^ Ysign) & (x^y) | (Xsign ^ Ysign) & !(Xsign & !Ysign);
}

int		main(void)
{
	int ans = isGreater(INT_MAX, 1);
	printf("%d\n", ans);
	return 0;
}
