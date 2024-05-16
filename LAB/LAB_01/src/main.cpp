#include <Arduino.h>

// กำหนด strcture หรือ customs type
// Books คือ structure tag เอาไว้สำหรับ reuse กับ variable อื่นๆ หากไม่ระบุจะเอาไปใช้กับอย่างอื่นไม่ได้
struct Books
{
  int id;
  char *title;
  char *auther;
  int page_count; // เพิ่ม parameter
} book, y;

// x จะมี structure แบบเดียวกับ Books เพราะเรานำ tag Books มาใช้งาน
struct Books x;

// ประกาศ function prototype
void my_print(struct Books e);
void gen_id(struct Books *e);

void setup()
{
  Serial.begin(115200);
  delay(1000);
  book.id = 1;
  book.title = "title";
  book.auther = "test";
  book.page_count = 45;
  my_print(book);

  gen_id(&x);
  x.title = "title2";
  x.auther = "test2";
  x.page_count = 1;
  my_print(x);

  y.id = 2;
  y.title = "title3";
  y.auther = "test3";
  y.page_count = 3;
  my_print(y);

  // c struct pointer
  struct Books *book_p = (struct Books *)malloc(sizeof(struct Books));
  gen_id(book_p);
  book_p->title = "title4";
  book_p->auther = "auther4";
  book_p->page_count = 100;
  // Parameter ใน fuction my_print ยังไม่ใช่ pointer เลยต้องใส่ * เพื่อบอกว่าเป็น pointer
  my_print(*book_p);
  free(book_p);

  // c++ struct pointer
  struct Books *book_cpp = new Books();
  gen_id(book_cpp);
  book_cpp->title = "title5";
  book_cpp->auther = "auther5";
  book_cpp->page_count = 19;
  my_print(*book_cpp);
  delete book_cpp;
}

void loop()
{
}

void gen_id(struct Books *e)
{
  e->id = random(10, 100);
}

void my_print(struct Books e)
{
  Serial.printf("ID: %d\n", e.id);
  Serial.printf("TITLE: %s\n", e.title);
  Serial.printf("AUTHER: %s\n", e.auther);
  Serial.printf("COUNT: %d\n", e.page_count); // เพิ่ม parameter
}