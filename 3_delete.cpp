/* 지역 변수 delete 하기 */
#include <iostream>

int main() {
  int a = 5;

  delete &a;

  return 0;
}
/* heap 아닌 공간 제외 에러 */