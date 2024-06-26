//노드를 5개 만들어서 data를 각각 1,3,5,7,9(오름차순)으로 초기화 했음
// data를 추가로 입력받아서 노드를 추가할때 오름차순을 유지해야함
//넌 일단 나가라
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void addNode(Node *a, int data) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = data;

  temp->next = a->next;
  a->next = temp;
}

int main() {
  Node *a, *b, *c, *d, *e;
  a = (Node *)malloc(sizeof(Node));
  b = (Node *)malloc(sizeof(Node));
  c = (Node *)malloc(sizeof(Node));
  d = (Node *)malloc(sizeof(Node));
  e = (Node *)malloc(sizeof(Node));

  a->data = 1;
  b->data = 3;
  c->data = 5;
  d->data = 7;
  e->data = 9;

  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = NULL;

  int data;
  printf("추가할 숫자를 입력하세요: ");
  scanf("%d", &data);

  while (1) {
    // a->data가 내가 입력한 data보다 작을때만 출력
    printf("%d ", a->data);

    if (a->data < data) {
      addNode(a, data);
      printf("%d ", a->data);
      a = a->next;
      break;
    }

    a = a->next;
  }
  //이제 오름차순 유지해야함 a->data 다음에 data 넣어주기
  while (a != NULL) {
    printf("%d ", a->data);
    a = a->next;
  }

  free(a);
  free(b);
  free(c);
  free(d);
  free(e);
}