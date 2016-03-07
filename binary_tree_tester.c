#include "binary_tree.h"

static void test1()
{
   printf("test1: \n");
   pBT_NODE pnode = NULL;
   assert(TRUE == bt_Insert(&pnode, 99));
   assert(99 == pnode->data);
   free(pnode);
}

static void test2()
{
   printf("test2: \n");
   pBT_NODE pnode = NULL;
   assert(TRUE == bt_Insert(&pnode, 9));
   assert(TRUE == bt_Insert(&pnode, 8));
   assert(TRUE == bt_Insert(&pnode, 10));
   assert(TRUE == bt_Insert(&pnode, 7));
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(9 == pnode->data);
   assert(8 == pnode->l_child->data);
   assert(10 == pnode->r_child->data);
   assert(7 == pnode->l_child->l_child->data);

   free(pnode->l_child);
   free(pnode->r_child);
   free(pnode);
}
/*
*     99
*    /  \    ====> NULL
*  NULL NULL
*  
*/
static void test3()
{
   printf("test3: \n");
   pBT_NODE pnode = NULL;
   pnode = bt_Create(99);
   assert(TRUE == bt_Delete(&pnode, 99)); 
   assert(NULL == pnode);
}

/*
*       99
*      /  \            88
*     88 NULL  ====>  /  \
*    /               77  NULL
*   77
*/
static void test4()
{
   printf("test4: \n");
   pBT_NODE pnode = NULL;
   pnode = bt_Create(99);
   assert(TRUE == bt_Insert(&pnode, 88));
   assert(TRUE == bt_Insert(&pnode, 77));
   assert(TRUE == bt_Delete(&pnode, 99)); 
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(88 == pnode->data);
   assert(NULL == pnode->parent);
   free(pnode->l_child);
   free(pnode);
}

/*
*       99
*      /  \            111
*    NULL 111  ====>   /  \
*           \        NULL  222
*           222
*/
static void test5()
{
   printf("test5: \n");
   pBT_NODE pnode = NULL;
   pnode = bt_Create(99);
   assert(TRUE == bt_Insert(&pnode, 111));
   assert(TRUE == bt_Insert(&pnode, 222));
   assert(TRUE == bt_Delete(&pnode, 99)); 
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(111 == pnode->data);
   assert(NULL == pnode->parent);
   free(pnode->r_child);
   free(pnode);
}

/*
*       10
*      /  \            6
*     6   14  ====>   / \
*    /               4  14
*   4
*/
static void test6()
{
   printf("test6: \n");
   pBT_NODE pnode = NULL;
   pnode = bt_Create(10);
   assert(TRUE == bt_Insert(&pnode, 6));
   assert(TRUE == bt_Insert(&pnode, 4));
   assert(TRUE == bt_Insert(&pnode, 14));
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(TRUE == bt_Delete(&pnode, 10)); 
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(6 == pnode->data);
   assert(NULL == pnode->parent);
   assert(pnode == pnode->r_child->parent);
   free(pnode->l_child);
   free(pnode->r_child);
   free(pnode);
}

/*
*       10
*      /  \            8
*     6   14  ====>   / \
*      \             6  14
*       8
*/
static void test7()
{
   printf("test7: \n");
   pBT_NODE pnode = NULL;
   pnode = bt_Create(10);
   assert(TRUE == bt_Insert(&pnode, 6));
   assert(TRUE == bt_Insert(&pnode, 8));
   assert(TRUE == bt_Insert(&pnode, 14));
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(TRUE == bt_Delete(&pnode, 10)); 
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(8 == pnode->data);
   assert(NULL == pnode->parent);
   assert(pnode == pnode->r_child->parent);
   free(pnode->l_child);
   free(pnode->r_child);
   free(pnode);
}

/*
*                   10
*                     \
*    10               15
*   /  \     ====>  10
*  6   15          /
*                 6
*/
static void test8()
{
   printf("test8: \n");
   pBT_NODE pnode = NULL;
   pnode =bt_Create(10);
   assert(TRUE == bt_Insert(&pnode, 6));
   assert(TRUE == bt_Insert(&pnode, 15));
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(TRUE == bt_Delete(&pnode, 6));
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(TRUE == bt_Insert(&pnode, 6));
   assert(TRUE == bt_Delete(&pnode, 15));
   bt_PrintAll(pnode);
   printf(".\n"); 
   free(pnode->l_child);
   free(pnode->r_child);
   free(pnode);
}

/*
*     10                   10
*    /              10       \         10
*   6       ====>  /         15 ====>    \
*  /              4         /            12
* 4                       12
*/
static void test9()
{
   printf("test9: \n");
   pBT_NODE pnode = NULL;
   pnode =bt_Create(10);
   assert(TRUE == bt_Insert(&pnode, 6));
   assert(TRUE == bt_Insert(&pnode, 4));
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(TRUE == bt_Delete(&pnode, 6));
   bt_PrintAll(pnode);
   printf(".\n"); 
   free(pnode->l_child);
   free(pnode->r_child);
   free(pnode);

   pBT_NODE qnode = NULL;
   qnode =bt_Create(10);
   assert(TRUE == bt_Insert(&qnode, 15));
   assert(TRUE == bt_Insert(&qnode, 12));
   bt_PrintAll(qnode);
   printf(".\n"); 
   assert(TRUE == bt_Delete(&qnode, 15));
   bt_PrintAll(qnode);
   printf(".\n"); 
   free(qnode->l_child);
   free(qnode->r_child);
   free(qnode);
}

/*
*     10                   10
*    /              10       \         10
*   6       ====>  /         15 ====>    \
*    \            8           \          18
*     8                       18
*/
static void test10()
{
   printf("test10: \n");
   pBT_NODE pnode = NULL;
   pnode =bt_Create(10);
   assert(TRUE == bt_Insert(&pnode, 6));
   assert(TRUE == bt_Insert(&pnode, 8));
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(TRUE == bt_Delete(&pnode, 6));
   bt_PrintAll(pnode);
   printf(".\n"); 
   free(pnode->l_child);
   free(pnode->r_child);
   free(pnode);

   pBT_NODE qnode = NULL;
   qnode =bt_Create(10);
   assert(TRUE == bt_Insert(&qnode, 15));
   assert(TRUE == bt_Insert(&qnode, 18));
   bt_PrintAll(qnode);
   printf(".\n"); 
   assert(TRUE == bt_Delete(&qnode, 15));
   bt_PrintAll(qnode);
   printf(".\n"); 
   free(qnode->l_child);
   free(qnode->r_child);
   free(qnode);
}
/*
*     10            10        10          10
*    /              /        /           /
*   6       ====>  5        5    ====>  4
*  / \              \      / \         / \
* 5   8              8    2   6       2   6
*                          \
*                           4
*  10                  10   
*   \                    \
*    14    =====>        11
*   /  \                  \
*  11  16                  16
*/
static void test11()
{
   printf("test11: \n");
   pBT_NODE pnode = NULL;
   pnode =bt_Create(10);
   assert(TRUE == bt_Insert(&pnode, 6));
   assert(TRUE == bt_Insert(&pnode, 5));
   assert(TRUE == bt_Insert(&pnode, 8));
   bt_PrintAll(pnode);
   printf(".\n"); 
   assert(TRUE == bt_Delete(&pnode, 6));
   bt_PrintAll(pnode);
   printf(".\n"); 
   free(pnode->l_child);
   free(pnode->r_child);
   free(pnode);

   pBT_NODE qnode = NULL;
   qnode =bt_Create(10);
   assert(TRUE == bt_Insert(&qnode, 5));
   assert(TRUE == bt_Insert(&qnode, 2));
   //assert(TRUE == bt_Insert(&qnode, 6));
   assert(TRUE == bt_Insert(&qnode, 4));
   assert(TRUE == bt_Insert(&qnode, 6));
   assert(4 == qnode->l_child->l_child->r_child->data);
   bt_PrintAll(qnode);
   printf(".\n"); 
   assert(TRUE == bt_Delete(&qnode, 5));
   assert(4 == qnode->l_child->data);
   bt_PrintAll(qnode);
   printf(".\n"); 
   free(qnode->l_child);
   free(qnode->r_child);
   free(qnode);
}

int main(int argc, char* argv[])
{
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();
  test11();
}
