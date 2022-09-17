//
// Created by SlybootsLion on 2022/9/17.
//
#include "student_manager.h"

bool login_status = false;

void printlnf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  printf("\n");
  va_end(args);
}

void print_table_head() {
  printlnf("|学号\t| 姓名\t| 性别\t| 年龄\t| 分数\t|\n");
}

void print_table(linknode_t *head) {
  print_table_head();
  linknode_t *p = head;
  while (p->next != NULL) {
    printlnf("|%d\t| %s\t| %s\t| %d\t| %.2f\t|\n", p->next->data.id, p->next->data.name, \
    p->next->data.sex, p->next->data.age, p->next->data.score);
    p = p->next;
  }
}

void login_in() {
  char username[30] = {0};
  char password[30] = {0};

  printf("===登录===\n");

  printf("账户：");
  fgets(username, sizeof(username), stdin);
  username[strlen(username) - 1] = '\0';

  printf("密码：");
  fgets(password, sizeof(password), stdin);
  password[strlen(password) - 1] = '\0';

  if ((strcmp(username, "root") == 0) && (strcmp(password, "root") == 0)) {
    login_status = true;
    printlnf("登录成功");
  } else {
    login_status = false;
    printlnf("密码错误");
  }
}

void insert_student(linknode_t *head) {
  s_t st = {0};
  linknode_t *p = NULL;
  bool is_id_exist = false;

  printlnf("============================");
  printf("输入学生信息：[学号 姓名 性别 年龄 分数]：");
  scanf("%d%s%s%d%lf", &st.id, st.name, st.sex, &st.age, &st.score);

  p = head;
  while (p->next != NULL) {
    if (p->next->data.id == st.id) {
      is_id_exist = true;
      printlnf("已经存在id = %d号学生，请重新输入", st.id);
      break;
    }
    p = p->next;
  }
  if (is_id_exist == false) {
    insert_tail_linklist(head, st);
    printlnf("插入成功！\n");
  }
}

void display_student(linknode_t *head) {
  linknode_t *p = head;
  printlnf("======学生信息表======");
  printlnf("--------------------");
  print_table(head);
  printlnf("--------------------");
}

void find_student(linknode_t *head) {
  int id;
  printf("输入要查找学生编号：");
  scanf("%d", &id);

  linknode_t *p = head;
  while (p->next != NULL) {
    if (p->next->data.id == id) {
      linknode_t *st = create_empty_linklist();
      insert_tail_linklist(st, p->next->data);
      printlnf("--------------------");
      print_table(st);
      printlnf("--------------------");
      clean_up_linklist(st);
      return;
    }
    p = p->next;
  }

  if (p->next == NULL) {
    printlnf("--------------------");
    printlnf("编号输入错误");
    printlnf("--------------------");
  }
}

void delete_student(linknode_t *head) {
  int ret = 0;
  int id = 0;

  loop:
  printf("输入要删除的学生编号：");
  scanf("%d", &id);

  ret = delete_data_linklist(head, id);
  if (ret == -1)
    printlnf("数据为空，删除无效");
  else if (ret == -2) {
    printlnf("数据不存在，重新输入");
    goto loop;
  } else
    printlnf("删除id = %d学生信息成功", id);
}

void display_update_info() {
  printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━┓ \n");
  printf(" ┃        学生信息       ┃ \n");
  printf(" ┣━━━━━━━━━━━━━━━━━━━━━━━┫ \n");
  printf(" ┃      1. 修改学号      ┃ \n");
  printf(" ┃      2. 修改姓名      ┃ \n");
  printf(" ┃      3. 修改性别      ┃ \n");
  printf(" ┃      4. 修改年龄      ┃ \n");
  printf(" ┃      5. 修改分数      ┃ \n");
  printf(" ┃      6. 退出          ┃ \n");
  printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void user_change_data(linknode_t *head, int num) {
  char user_data[100] = {0};
  int new_id, new_age;
  double new_score;
  printf("请输入需要修改新的数据");
  scanf("%s", user_data);

  switch (num) {
    case 1:
      new_id = atoi(user_data);
      if (new_id > 0)
        head->data.id = new_id;
      break;
    case 2:
      memset(head->data.name, 0, sizeof(head->data.name));
      strcpy(head->data.name, user_data);
      break;
    case 3:
      memset(head->data.sex, 0, sizeof(head->data.sex));
      strcpy(head->data.sex, user_data);
    case 4:
      new_age = atoi(user_data);
      if (new_age > 0)
        head->data.age = new_age;
      break;
    case 5:
      new_score = atof(user_data);
      if (new_score > 0)
        head->data.score = new_score;
      break;
    case 6:
      printf("退出!\n");
      return;
    default:
      break;
  }

  printlnf("修改成功");
}

void update_student_info(linknode_t *head) {
  int num = -1;
  display_update_info();

  loop:
  printf("输入要修改的学生信息编号：");
  scanf("%d", &num);

  while (getchar() != '\n');

  if (!(num >= 1 && num <= 6)) {
    printlnf("信息输入有误，请重试");
    goto loop;
  }

  user_change_data(head, num);
}

void update_student(linknode_t *head) {
  linknode_t *p = head;
  int id;
  printf("输入要修改的学生编号:");
  scanf("%d", &id);

  while (p->next != NULL) {
    if (p->next->data.id == id) {
      update_student_info(p->next);
      break;
    }
    p = p->next;
  }

  if (p->next == NULL) {
    printlnf("--------------------");
    printlnf("编号输入错误！");
    printlnf("--------------------");

  }
}
