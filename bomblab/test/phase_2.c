#include <stdio.h>

void phase_2() {
  rax = 0
  rsi = rsp[0]
  read_six_numbers()
  if (rsp <= 0) {
    boom!
  }
  rbx = 1
  rbp = rsp[0]
  while(rbx < 6) {
    rax = rbx
    rax += rbx*4 + rbp - 4
    if (rax != rbx*4 + rbp) {
      boom!
    }
    rbx++
  }
  return 0;
}

int main(int argc, char const *argv[])
{
  rax = fs:0x28
  rsp[0x18] = rax
  rax = 0
  rsi = rsp[0]
  read_six_numbers()
  if (rsp <= 0) {
    boom!
  }
  rbx = 1
  rbp = rsp[0]
  while(rbx < 6) {
    rax = rbx
    rax += rbx*4 + rbp - 4
    if (rax != rbx*4 + rbp) {
      boom!
    }
    rbx++
  }
  return 0;
}
