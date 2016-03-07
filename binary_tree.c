#include "binary_tree.h"
#include "malloc.h"
#include "stdio.h"
#include "string.h"

tBT_NODE* bt_Create(int value)
{
   pBT_NODE pnode = NULL;
   pnode = (tBT_NODE*) malloc(sizeof(tBT_NODE));
   assert(NULL != pnode);
   memset(pnode, 0, sizeof(tBT_NODE));
   pnode->data = value;
   return pnode;
}

tBT_NODE* bt_FindData(const pBT_NODE pnode, int value)
{
   if (NULL == pnode)
      return NULL;

   if (value == pnode->data)
      return pnode;
   else if (value > pnode->data)
      return bt_FindData(pnode->r_child, value);
   else
      return bt_FindData(pnode->l_child, value);
}

tBT_NODE* bt_FindMaxData(const pBT_NODE pnode)
{
   if (NULL == pnode)
      return NULL;

   if(NULL == pnode->r_child)
      return pnode;

   return bt_FindMaxData(pnode->r_child);
}

int bt_Count(const pBT_NODE pnode)
{
   if (NULL == pnode)
      return 0;

   return 1 + bt_Count(pnode->l_child) + bt_Count(pnode->r_child);
}

void bt_PrintAll(const pBT_NODE pnode)
{
   if (pnode)
   {
      bt_PrintAll(pnode->l_child);
      printf("%d ", pnode->data);
      bt_PrintAll(pnode->r_child);
   }
}

int bt_CalHeight(const pBT_NODE pnode)
{
   if (NULL == pnode)
      return 0;

   int left = bt_CalHeight(pnode->l_child);
   int right = bt_CalHeight(pnode->r_child);

   return (left > right) ? (left + 1) : (right + 1);
}

BOOL _bt_insert(pBT_NODE* ppnode, int value, pBT_NODE pparent)
{
   if(NULL == *ppnode)
   {
      *ppnode = bt_Create(value);
      assert(NULL != *ppnode);
      (*ppnode)->parent = pparent;
      return TRUE;
   }

   if (value > (*ppnode)->data)
      return _bt_insert(&(*ppnode)->r_child, value, *ppnode);
   else
      return _bt_insert(&(*ppnode)->l_child, value, *ppnode);
}

BOOL bt_Insert(pBT_NODE* ppnode, int value)
{
   if (NULL == ppnode)
      return FALSE;

   if (NULL == *ppnode)
   {
      *ppnode = bt_Create(value);
      assert(NULL != *ppnode);
      return TRUE;
   }

   return _bt_insert(ppnode, value, NULL);
}

BOOL _bt_delete(pBT_NODE dnode)
{
   if (NULL == dnode->l_child && NULL == dnode->r_child)
   {
      if (dnode == dnode->parent->l_child)
         dnode->parent->l_child = NULL;
      else
         dnode->parent->r_child = NULL;
   }
   else if (NULL != dnode->l_child && NULL == dnode->r_child)
   {
      dnode->l_child->parent = dnode->l_child;
      if (dnode == dnode->parent->l_child)
         dnode->parent->l_child = dnode->l_child;
      else
         dnode->parent->r_child = dnode->l_child;
   }
   else if (NULL == dnode->l_child && NULL != dnode->r_child)
   {
      dnode->r_child->parent = dnode->r_child;
      if (dnode == dnode->parent->l_child)
         dnode->parent->l_child = dnode->r_child;
      else
         dnode->parent->r_child = dnode->r_child;
   }
#if 1
   else
   {
      pBT_NODE pLeftMax = bt_FindMaxData(dnode->l_child);
      if (dnode->l_child == pLeftMax)
      {
         if ( dnode == dnode->parent->l_child)
            dnode->parent->l_child = dnode->l_child;
         else
            dnode->parent->r_child = dnode->l_child;

         dnode->l_child->parent = dnode->parent;
         dnode->l_child->r_child = dnode->r_child;
         dnode->r_child->parent = dnode->l_child;
      }
      else
      {
         /* exchange the data and then free the temple max node*/
         printf("left child max element: %d\n",pLeftMax->data);
         dnode->data = pLeftMax->data;
         pLeftMax->parent->r_child = pLeftMax->l_child;
         if (pLeftMax->l_child != NULL)
            pLeftMax->l_child->parent = pLeftMax->parent;
         dnode = pLeftMax;
      }
   }
#endif
   free(dnode);
   return TRUE;
}

BOOL bt_Delete(pBT_NODE* ppnode, int value)
{
   pBT_NODE dnode = NULL;

   if (NULL == ppnode || NULL == *ppnode)
      return FALSE;

   dnode = bt_FindData(*ppnode, value);
   if(NULL == dnode)
      return FALSE;

   /* delete the head element */
   if (*ppnode == dnode)
   {
      if (NULL == dnode->r_child && NULL == dnode->l_child)
      {
         *ppnode = NULL;
      }
      else if( NULL == dnode->r_child && NULL != dnode->l_child)
      {
         //*ppnode = (*ppnode)->l_child;
         *ppnode = dnode->l_child;
         dnode->l_child->parent = NULL;
      }
      else if(NULL != dnode->r_child && NULL == dnode->l_child)
      {
         *ppnode = dnode->r_child;
         dnode->r_child->parent = NULL;
      }
      else if(NULL != dnode->r_child && NULL != dnode->l_child)
      {  
         pBT_NODE pLeftMax = bt_FindMaxData(dnode->l_child);
         printf("pLeftMax data: %d\n", pLeftMax->data);
         if (pLeftMax == dnode->l_child)
         {
            *ppnode = dnode->l_child;
            (*ppnode)->r_child = dnode->r_child;
            (*ppnode)->r_child->parent = *ppnode;
            (*ppnode)->parent = NULL;
         }
         else
         {
            dnode->data = pLeftMax->data;
            pLeftMax->parent->r_child = NULL;
            dnode = pLeftMax;
         }
      }
      free(dnode);
      return TRUE;
   }

   return _bt_delete(dnode);
}




