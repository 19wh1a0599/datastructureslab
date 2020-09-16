#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node*link;
};
struct node*top = NULL, *cur, *temp;

int isempty()
{
	if(top == NULL)
	return 1;
	else
	return 0;
}

void push()
{
        cur = (struct node*)malloc(sizeof(struct node));
        printf("enter data to be pushed \n");
        scanf("%d",&(cur -> data));
        cur -> link = top;
	top = cur;
}
void pop()
{
        cur = top;
        top = cur -> link;
        cur -> link = NULL;
        printf("popped data is : %d\n",cur -> data);
	free(cur);
}

void display()
{
	temp = top;
        while(temp != NULL)
        {
             printf("%d \n",temp -> data);
             temp = temp -> link;
        }
}

int peek()
{
	return(top -> data);
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n1-push\n2-pop\n3-display\n4-peek\n5-exit\n");
		printf("enter ur choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
                case 1: push();
			break;
		case 2: if(isempty())
			printf("stack is empty\n");
			else
			    {
	                         pop();
			    }
			break;
		case 3: if(isempty())
                        printf("stack is empty \n");
                        else
                             {
                                 display();
                             }
			break;
		case 4: if(isempty())
                        printf("stack is empty \n");
                        else
                             {
                                 x = peek();
                             }
                             printf("top most element on the stack is %d\n", peek());
			break;
		case 5: exit(0);
		}
        }      
}
