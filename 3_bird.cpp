typedef struct Bird {
  char name[30];  // 이름
  int age;        // 나이

  int health;  // 체력
  int food;    // 배부른 정도
  int clean;   // 깨끗한 정도

  // 여기까지는 Animal 과 동일하다.
  int height;  // 나는 고도

} Bird;

typedef struct Fish {
  char name[30];  // 이름
  int age;        // 나이

  int health;  // 체력
  int food;    // 배부른 정도
  int clean;   // 깨끗한 정도

  // 여기까지는 Animal 과 동일하다.
  int deep;  // 현재 깊이

} Fish;
