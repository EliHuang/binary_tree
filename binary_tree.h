#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "assert.h"

#define TRUE 1
#define FALSE 0
#define NULL 0
typedef int BOOL;

typedef struct binary_tree_node {
   int data;
   struct binary_tree_node* parent;
   struct binary_tree_node* l_child;
   struct binary_tree_node* r_child;
} tBT_NODE, *pBT_NODE;

tBT_NODE* bt_Create(int value);
tBT_NODE* bt_FindData(const pBT_NODE pnode, int value);
tBT_NODE* bt_FindMaxData(const pBT_NODE pnode);
int bt_Count(const pBT_NODE pnode);
void bt_PrintAll(const pBT_NODE pnode);
int bt_CalHeight(const pBT_NODE pnode);
BOOL bt_Insert(pBT_NODE* ppnode, int value);
BOOL bt_Delete(pBT_NODE* ppnode, int value);
#endif
