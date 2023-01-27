#include <stdio.h>
#include <string.h>

typedef struct LinkItem_t LinkItem_t;
struct LinkItem_t {
  char key[10];
  float cost; 
  LinkItem_t * next;
};

#define MAX_ITEM 0x10
LinkItem_t datapool[MAX_ITEM];
LinkItem_t *dataFree;
LinkItem_t *dataLink;

/* useful printing functions */
void printItem(LinkItem_t * ip) {
  printf("%p [%-10s] %10.2f -> %p\n", ip, ip->key, ip->cost, ip->next);
}
void printLink(LinkItem_t * ip) {
  while (ip) {
    printItem(ip); 
    ip = ip->next;
  }
}
void printDataLink() {
  printf("\nDataLink     %p\n", dataLink);
  printLink(dataLink);
}
void printDataFree() {
  printf("\nDataFreeLink %p\n", dataFree);
  printLink(dataFree);
}

/* data link allocation */
LinkItem_t * allocItem() {
  LinkItem_t * ip;
  ip = dataFree;
  if (ip) {
    dataFree = dataFree->next;
  }
  return ip;
}
void freeItem(LinkItem_t *ip) {
  if (ip) {
    ip->next = dataFree;
    dataFree = ip;
  }
}

/* addItem
*/
LinkItem_t * addItem(char * name, float cost) {
  LinkItem_t *ip;
  /* alloc a dataLink */
  ip = allocItem();
  strncpy(ip->key, name, sizeof ip->key);
  ip->cost = cost;
  /* save the dataLink */
  ip->next = dataLink;
  dataLink = ip;
  return ip;
}

/* initialize the dataLink and dataFree from datapool */
void initData() {
    /* initialize data to zero */
  memset(datapool, 0, sizeof datapool);
  dataFree = 0;
  dataLink = 0;

  LinkItem_t* ip;
  int i;
  for (i = 0, ip = datapool; i < MAX_ITEM; i++, ip++) {
    ip->next = dataFree;
    dataFree = ip;   
  }
}

/* init test dataa */
void initTestData() {
  addItem("apple", .5);
  addItem("watch", 200.10);
  addItem("shoe", 24.8);
}

int main(int ac, char *av[]) {
  initData();
  initTestData();
  printDataLink();
  printDataFree();
}

