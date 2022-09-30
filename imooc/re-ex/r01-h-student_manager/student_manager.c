//
// Created by SlybootsLion on 2022/9/30.
//

#include "student_manager.h"

bool login_status = false;

void login_in() {
  char username[30] = {0};
  char password[30] = {0};

  printf("=========== 登录 ============\n");
  printf("账户：");
  fgets(username, sizeof(username), stdin);
  username[strlen(username) - 1] = '\0';
  printf("密码：");
  fgets(password, sizeof(password), stdin);
  password[strlen(password) - 1] = '\0';

  if (strcmp(username, "root") == 0 && strcmp(password, "root") == 0) {
    login_status = true;
    printf("登录成功\n");
  } else {
    login_status = false;
    printf("密码错误\n");
  }
}

void insert_student(linknode_t *head) {
  s_t st = {0};
  bool is_id_exist = true;

  printf("---------\n");
  printf("请输入学生的信息【学号 姓名 性别 年龄 分数】:");
  scanf("%d%s%s%d%lf", &(st.id), st.name, st.sex, &(st.age), &(st.score));
  while (getchar() != '\n');

  linknode_t *p = head;
  while (p->next != NULL) {
    if (p->next->data.id == st.id) {
      is_id_exist = false;
      printf("已经存在id = %d号学生，请重新输入！\n", st.id);
      break;
    }
    p = p->next;
  }

  if (is_id_exist == true) {
    insert_tail_linklist(head, st);
    printf("插入成功!\n");
  }
}

void print_tb_head() {
  printf("===========================学生信息表==========================\n");
  printf("---------------------------------------------------------------\n");
  printf("|学号\t| 姓名\t| 性别\t| 年龄\t| 分数\t|\n");
}

void print_st(linknode_t *st) {
  printf("|%d\t|%s\t|%s\t|%d\t|%.1f\t|\n", st->data.id, st->data.name,
         st->data.sex, st->data.age, st->data.score);
}

void display_student(linknode_t *head) {
  linknode_t *p = head;
  print_tb_head();
  while (p->next != NULL) {
    print_st(p->next);
    p = p->next;
  }
  printf("---------------------------------------------------------------\n");
}

void find_student(linknode_t *head) {
  linknode_t *p = head;
  int id;
  printf("请输入要查找学生编号：");
  scanf("%d", &id);

  while (p->next != NULL) {
    if (p->next->data.id == id) {
      print_tb_head();
      print_st(p->next);
      printf("---------------------------------------------------------------\n");
      return;
    }
    p = p->next;
  }

  if (p->next == NULL) {
    printf("---------------------------------------------------------------\n");
    printf("编号输入错误");
    printf("---------------------------------------------------------------\n");
  }
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

void user_change_data(linknode_t *temp, int id) {
  char user_data[100] = {0};
  printf("输入需要修改新的数据：");
  scanf("%s", user_data);
  int new_id, new_age, new_score;
  switch (id) {
    case 1:
      new_id = atoi(user_data);
      if (new_id > 0)
        temp->data.id = new_id;
      break;
    case 2:
      memset(temp->data.name, 0, sizeof(temp->data.name));
      strcpy(temp->data.name, user_data);
      break;
    case 3:
      memset(temp->data.sex, 0, sizeof(temp->data.sex));
      strcpy(temp->data.sex, user_data);
      break;
    case 4:
      new_age = atoi(user_data);
      if (new_age > 0)
        temp->data.age = new_age;
      break;
    case 5:
      new_score = atof(user_data);
      if (new_score > 0)
        temp->data.score = new_score;
      break;
    case 6:
      printf("退出");
      break;
    default:
      break;
  }
  printf("修改成功");
}

void update_student_info(linknode_t *temp) {
  int num = -1;
  display_update_info();
  loop:
  printf("请输入你要修改的学生信息编号：");
  scanf("%d", &num);

  while (getchar() != '\n');

  if (!(num >= 1 && num <= 6)) {
    printf("信息输入错误，请重试\n");
    goto loop;
  }

  user_change_data(temp, num);
}

void update_student(linknode_t *head) {
  linknode_t *p = head;
  int id = 0, num = 0;
  printf("请输入要修改的学生编号：");
  scanf("%d", &id);

  while (p->next != NULL) {
    if (p->next->data.id == id) {
      update_student_info(p->next);
      break;
    }
    p = p->next;
  }

  if (p->next == NULL) {
    printf("---------------------------------------------------------------\n");
    printf("编号输入错误！\n");
    printf("---------------------------------------------------------------\n");
  }
}

void delete_student(linknode_t *head) {
  int id;

  loop:
  printf("输入要删除的学生编号：");
  scanf("%d", &id);

  int ret = delete_data_linklist(head, id);
  if (ret == -1)
    printf("数据为空，删除无效\n");
  else if (ret == -2) {
    printf("数据不存在，重新输入\n");
    goto loop;
  } else
    printf("删除id = %d学生信息成功\n", id);
}
