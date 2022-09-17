#include "student_manager.h"

int print_select() {
  int num = -1;
  printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━┓ \n");
  printf(" ┃      学生管理系统     ┃ \n");
  printf(" ┣━━━━━━━━━━━━━━━━━━━━━━━┫ \n");
  printf(" ┃      1. 增加学生      ┃ \n");
  printf(" ┃      2. 查找学生      ┃ \n");
  printf(" ┃      3. 输出学生      ┃ \n");
  printf(" ┃      4. 修改学生      ┃ \n");
  printf(" ┃      5. 删除学生      ┃ \n");
  printf(" ┃      6. 退出系统      ┃ \n");
  printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━┛\n");
  printf("请选择：");
  scanf("%d", &num);
  return num;
}

int main() {
  while (!login_status) {
    login_in();
  }

  linknode_t *head = create_empty_linklist();

  while (1) {
    int num = print_select();
    switch (num) {
      case ADD_STUDENT:
        insert_student(head);
        break;
      case FIND_STUDENT:
        find_student(head);
        break;
      case PRINT_STUDENT:
        display_student(head);
        break;
      case MODIFY_STUDENT:
        update_student(head);
        break;
      case DELETE_STUDENT:
        delete_student(head);
        break;
      case EXIT_SYSTEM:
        exit(EXIT_SUCCESS);
      default:
        break;
    }
  }
  clean_up_linklist(head);
  return 0;
}
