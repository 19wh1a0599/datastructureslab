#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *link;
};
struct node *head=NULL,*tail=NULL,*cur,*prev,*next;
void create()
{
       int n;
       printf("enter the no of nodes for linked list:   \n");
       scanf("%d", &n);
       for(int i =0;i<n;i++)      
       {
             cur=(struct node *)malloc(sizeof(struct node));
             printf("enter current node data");
             scanf("%d",&(cur -> data));
             cur->link=NULL;
             if(head == NULL)
                   head = tail = cur;
             else
             {
                   tail->link=cur;
                   tail=cur;
             }
       }
}

void insert_at_begin()
{
     cur = (struct node *)malloc (sizeof(struct node));
     printf("enter new begining node data: \n");
     scanf("%d",&(cur->data));
     cur -> link = head;
     head = cur;
}

void insert_at_end()
{
      cur=(struct node *)malloc(sizeof(struct node));
      printf("enter new ending nod edata:  \n");
      scanf("%d",&(cur->data));
      cur -> link = NULL;
      tail -> link = cur;
      tail = cur;
}

void insert_at_pos()
{
      int pos,c=1;
      cur = (struct node *)malloc(sizeof(struct node));
      printf("enter new data to be sorted:   \n");
      scanf("%d",&(cur->data));
      printf("enter the position:    \n");
      scanf("%d",&pos);
      next = head;
      while(c<pos)
      {
            prev = next;
            next = next -> link;
            c++;
      }
      prev -> link = cur;
      cur -> link = next;
}

void insert_before_node()
{
      int value;
      cur = (struct node *)malloc(sizeof(struct node));
      printf("enter new node data:   \n");
      scanf("%d",&(cur->data));
      printf("enter node data before which node should be added:    \n");
      scanf("%d",&value);
      next = head;
      while(next -> data != value && next != NULL)
      {
            prev = next;
            next = next -> link;
      }
      prev -> link = cur;
      cur -> link = next;
}

void insert_after_node()
{
      int value;
      cur = (struct node *)malloc(sizeof(struct node));
      printf("enter new node data:   \n");
      scanf("%d",&(cur->data));
      printf("enter node after data where new node should be added    \n");
      scanf("%d",&value);
      next = head;
      while(next -> data != value && next != NULL)
      {
            next = next -> link;
      }
      cur -> link = next -> link;
      next -> link = cur;
}

void traversal()
{
       if(head == NULL) 
        printf("list is empty\n");
       else
       {
          next = head;
          while(next!=NULL)
          {
           printf("%d->",next->data);
           next = next->link;
          }
       }
}

void delete_at_begin()
{
     cur = head;
     head = cur -> link;
     cur ->link = NULL;
     printf("deleted data:  %d \n",cur->data);
     free(cur);
}

void delete_at_end()
{
     cur = head;
     while(cur -> link != tail)
     cur = cur -> link;
     cur -> link = NULL;
     next = tail;
     printf("deleted data: %d \n",next->data);
     free(next);
     tail=cur;
}

void delete_at_pos()
{
      int pos,c=1;
      printf("enter position of deletion:    \n");
      scanf("%d",&pos);
      next = head;
      while(c<pos)
      {
            prev=next;
            next = next -> link;
            c++;
      }
      prev -> link = next -> link;
      printf("deleted data  %d \n",next->data);
      next -> link = NULL;
      free(next);
}

void delete_before_node()
{
     printf("enter before which node we need to delete:   \n");
     int value;
     scanf("%d",&value);
     next = head;
     while(next -> link -> data != value)
     {
           prev = next;
           next = next -> link;
     }
     prev -> link = next -> link;
     next -> link = NULL;
     printf("deleted element:  %d \n",next->data);
     free(next);
}

void delete_after_node()
{
     printf("enter after which node we need to delete:   \n");
     int value;
     scanf("%d",&value);
     next = head;
     while(next -> data != value)
     {
           prev = next;
           next = next -> link;
     }
     prev = next -> link;
     next -> link = prev -> link;
     printf("deleted data:  %d \n",prev->data);
     prev -> link = NULL;
     free(prev);
}

void search()
{
      int value ,flag = 0, c=0;
      printf("enter the element to be searched:   \n");
      scanf("%d",&value);
      next = head;
      while(next != NULL)
      {
           if(next -> data == value)
           {      
                flag = 1;
                break;
           }
           next = next -> link;
           c++;
     } 
     if(flag == 1)
             printf("at postion = %d \n",c);
     else
             printf("element not present  \n");
}

void reverse(struct node *head)
{
       if(head != NULL)
       {
              reverse(head -> link);
              printf(" <- %d",head -> data);
       }
       else
              printf("NULL");
} 

void sorting()
{
      struct node *p1, *p2, *last = NULL;
      int c,t;
      do
      {
             c = 0;
             p1 = head;
             while(p1 -> link != last)
             {
                   if(p1 -> data > p1->link->data)
                   {
                         t = p1 -> data;
                         p1 -> data = p1 -> link -> data;
                         p1 -> link -> data = t;
                         c = 1;
                   }
              p1 = p1 -> link;
              }
              last = p1;
       }while(c);
}  
int main()
{
      int ch;
      while(1)
      {
            printf("PROGRAM FOR SINGLE LINKED LIST\n");
            printf("---------------------------------\n");
            printf("1.create \n");
            printf("2.Insert at begining \n");
            printf("3.Insert at end \n"); 
            printf("4.Insert at position \n");
            printf("5.insert before node \n");
            printf("6.Insert after node \n");
            printf("7.traversal \n");
            printf("8.delete at begining \n");
            printf("9.delete at end \n");
            printf("10.delete at position \n");
            printf("11.delete before node \n");
            printf("12.delete after node \n");
            printf("13.search for element \n");
            printf("14.reversing the linked list \n");
            printf("15.sorting the linked list \n");
            printf("16.exit \n");
            printf("---------------------------------\n");
            scanf("%d",&ch);
            switch(ch)
            {
                  case 1: create();
                  break;
                  case 2: insert_at_begin();
                  break;
                  case 3: insert_at_end();
                  break;
                  case 4: insert_at_pos();
                  break;
                  case 5: insert_before_node();
                  break;
                  case 6: insert_after_node();
                  break;
                  case 7: traversal();
                  break;
                  case 8: delete_at_begin();
                  break;
                  case 9: delete_at_end();
                  break;
                  case 10: delete_at_pos();
                  break;
                  case 11: delete_before_node();
                  break;
                  case 12: delete_after_node();
                  break;
                  case 13: search();
                  break;
                  case 14: reverse(head);
                  break;
                  case 15: sorting();
                  break;
                  case 16: exit(0);
            }
      }
      return 0;
}
