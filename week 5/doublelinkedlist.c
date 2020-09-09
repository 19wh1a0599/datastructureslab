#include<stdio.h>
#include<stdlib.h>
struct node
{
     float data;
     struct node *prev;
     struct node *next;
};

struct node *head = NULL,*tail = NULL,*cur,*t1,*t2;
void create()
{
     int n;
     printf("enter no of nodes : \n");
     scanf("%d",&n);
     for(int i=0 ; i<n ; i++)
     {
         cur = (struct node*)malloc(sizeof(struct node));
         printf("enter cur node data    \n");
         scanf("%f",&(cur -> data));
     cur -> prev = NULL;
     cur -> next = NULL;
     if(head == NULL)
             head = tail = cur;
     else
     {
          tail -> next = cur;
          cur -> prev = tail;
          tail = cur;
     }
     }
}

void insert_at_begin()
{
      cur = (struct node*)malloc(sizeof(struct node));
      printf("enter current node data    \n");
      scanf("%f",&(cur -> data));
      cur -> prev = NULL;
      cur -> next = head;
      head -> prev = cur;
      head = cur;
}

void insert_at_end()
{
    cur = (struct node*)malloc(sizeof(struct node));
    printf("enter current data   \n");
    scanf("%f",&(cur -> data));
    cur -> next = NULL;
    cur -> prev = tail;
    tail -> next = cur;
    tail = cur;
}

void insert_at_position()
{
    int c=1,pos;
    cur = (struct node*)malloc(sizeof(struct node));
    printf("enter current data   \n");
    scanf("%f", &(cur -> data));
    printf("enter position");
    scanf("%d",&pos);
    t1 = head;
    while(c < pos && t1 != NULL)
    {
        t2 = t1;
        t1 = t1 -> next;
        c++;
    }    
    cur -> prev = t2;
    t2 -> next = cur;
    t1 -> prev = cur;
    cur -> next = t1;
}

void insert_before_node()
{
     float value;
     cur = (struct node*)malloc(sizeof(struct node));
    printf("enter current data   \n");
    scanf("%f", &(cur -> data));
    printf("enter the data before which node we need to insert  \n");
    scanf("%f",&value);
    t1 = head;
    while(t1 != NULL && t1 -> data != value)
    {
          t2 = t1;
          t1 = t1 -> next;
    }
    t2 -> next = cur;
    cur -> prev = t2;
    t1 -> prev = cur;
    cur -> next = t1;
}    

void insert_after_node()
{
    float value;
    cur = (struct node*)malloc(sizeof(struct node));
    printf("enter current data   \n");
    scanf("%f", &(cur -> data));
    printf("enter the data after which node we need to insert  \n");
    scanf("%f",&value);
    t1 = head;
    while(t1 != NULL && t1 -> data != value)
    {
          t1 = t1 -> next;
    }
    cur -> next = t1 -> next;
    t1 -> next -> prev = cur;
    t1 -> next = cur;
    cur -> prev = t1;
}

void delete_begin()
{
     cur = head;
     head = head -> next;
     head -> prev = NULL;
     printf("Deleted element %f",cur -> data);
     cur -> prev = NULL;
     free(cur);
}  

void delete_end()
{
     cur = tail;
     tail = tail -> prev;
     tail -> next = NULL;
     cur -> prev = NULL;
     printf("deleted element %f",cur -> data);
     free(cur);
}

void delete_at_position()
{
     int pos , c=1;
     printf("enter the position of deletion\n");
     scanf("%d",&pos);
     t1 = head;
     while(c<pos)
     {
            t2 = t1;
            t1 = t1 -> next;
            c++;
     }
     t2 -> next = t1 -> next;
     t1 -> prev = NULL;
     t1 -> next -> prev = t2;
     t1 -> next = NULL;
     printf("deleted data is %f ",t1 -> data);
     free(t1);
}

void delete_before_node()
{
       float value;
       t1 = head;
       printf("enter the data of node to perform delete before");
       scanf("%f", &value);
       while(t1 -> next -> data != value && t1 -> next != NULL)
      {
             t2 = t1;
             t1 = t1 -> next;
      }
             printf("deleted element %f",(t1 -> data));
             t2 -> next = t1 -> next;
             (t1 -> next) -> prev = t1 -> prev;
             t1 -> next = NULL;
             t1 -> prev = NULL;
             free(t1);
}   
void delete_after_node()
{
       float value;
       printf("enter the data of node to perform delete after");
       scanf("%f", &value);
       t1 = head;
       while(t1 -> data != value && t1 != NULL)
       {
             t1 = t1 -> next;
       }
             t2 = t1 -> next;
             t1 -> next = t2 -> next;
             (t2 -> next) -> prev = t1;
             printf("deleted element %f",t2 -> data);
             t2 -> prev = NULL;
             t2 -> next = NULL;
             free(t2);
       
}

void display()
{
      if(head == NULL)
      printf(" douuble linked list is empty ");
      else
      {
           cur = head;
           printf("elements of double linked list are\n");
           while(cur != NULL)
           {
                printf("%f <->",cur -> data);
                cur = cur -> next;
           }
      }
}

void display_reverse()
{
      if(head == NULL)
      printf(" double linked list is empty ");
      else
      {
           cur = tail;
           printf("elements of double linked list\n");
           while(cur != NULL)
           {
                printf("<-> %f ",cur -> data);
                cur = cur -> prev;
           }
      }
}

void sorting()
{
      struct node *p1, *p2, *last = NULL;
      int c,t;
      do
      {
             c = 0;
             p1 = head;
             while(p1 -> next != last)
             {
                   if(p1 -> data > p1->next->data)
                   {
                         t = p1 -> data;
                         p1 -> data = p1 -> next -> data;
                         p1 -> next -> data = t;
                         c = 1;
                   }
              p1 = p1 -> next;
              }
              last = p1;
       }while(c);
}

void search()
{
      float value ;
      int flag = 0, c=0;
      printf("enter the element to be searched:   \n");
      scanf("%f",&value);
      t1 = head;
      while(t1 != NULL)
      {
           if(t1 -> data == value)
           {      
                flag = 1;
                break;
           }
           t1 = t1 -> next;
           c++;
     } 
     if(flag == 1)
             printf("at postion = %d \n",c);
     else
             printf("element not present  \n");
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
            printf("7.delete at begining \n");
            printf("8.delete at end \n");
            printf("9.delete at position \n");
            printf("10.delete before node \n");
            printf("11.delete after node \n");
            printf("12.display \n");
            printf("13.display reverse \n");
            printf("14.sorting the linked list \n");
            printf("15.searching the linked list \n");
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
                  case 4: insert_at_position();
                  break;
                  case 5: insert_before_node();
                  break;
                  case 6: insert_after_node();
                  break;
                  case 7: delete_begin();
                  break;
                  case 8: delete_end();
                  break;
                  case 9: delete_at_position();
                  break;
                  case 10: delete_before_node();
                  break;
                  case 11: delete_after_node();
                  break;
                  case 12: display();
                  break;
                  case 13: display_reverse();
                  break;
                  case 14: sorting();
                  break;
                  case 15: search();
                  break;
                  case 16: exit(0);
            }
      }
      return 0;
}

  