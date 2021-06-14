#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int data;
    char str[10];
    struct node *next;
}*head=NULL,*p=NULL,*last=NULL;
int pin=0,flag=1,choice=0,n=0,amount=0,hund=0,five=0,thou=0,bno=0,send=0;

int menu(int pin){
    int choice=0;
    if(pin)
    {   printf("               Enter 1 to Know your Account Balance \n");
        printf("               Enter 2 to Do a cash Withdrawal\n");
        printf("               Enter 3 to Know your Previous Records\n");
        printf("               Enter 4 to do a Money Transfer\n");
        printf("                        Enter 10 to exit");
    }
    scanf("%d",&choice);
    return choice;
}
int main()
{
	printf("				****WELCOME TO THE ATM MACHINE****\n\n\n");
	printf("                   Please Enter Your pin number\n");
    scanf("%d",&pin);
    choice=menu(pin);

    while(flag)
    {
    switch(choice)
    {
    case 1:     n = rand() % 10000 + 1;
                if(n<2000){n=2000;}
                printf("%d\n", n);
                choice=menu(choice);
                printf("\n\n\n");
                break;


   case 2:      printf("               Enter the amount you want to withdraw \n");
                printf("              You can only withdraw in multiples of 100 \n");
                scanf("%d",&amount);
                printf("               Enter the number of Rs100 notes you want\n");
                scanf("%d",&hund);
                printf("               Enter the number of Rs500 notes you want\n");
                scanf("%d",&five);
                printf("               Enter the number of Rs1000 notes you want\n");
                scanf("%d",&thou);
                if(hund*100+five*500+thou*1000!=amount)
                {
                    printf("               Enter the details again\n");
                }
                else{
                    printf("               You can collect your cash....!\n\n\n");

                    if(head==NULL){
                    head=(struct node *)malloc(sizeof(struct node));
                    head->data=amount;
                    head->next=NULL;
                    strcpy(head->str,"Withdrawal");
                    last=head;
                    }
                    else{
                        p=(struct node *)malloc(sizeof(struct node));
                        p->data=amount;
                        strcpy(p->str,"Withdrawal");
                        p->next=NULL;
                        last->next=p;
                        last=p;
                    }
                }

                choice=menu(choice);
                break;


    case 3:     if(head==NULL)
                    {
                        printf("               There is no transaction history...!\n\n\n");
                    }
                    else{
                            p=head;
                            while(p!=NULL)
                            {
                                printf("              %d-",p->data);
                                printf("              %s\n",p->str);
                                p=p->next;
                            }
                    }
                    choice=menu(choice);
                    break;
    case 4:       printf("              Enter the Bank account Number-...!\n\n\n");
                  scanf("%d",&bno);
                  printf("              Enter the Amount you want to send-...!\n\n\n");
                  scanf("%d",&send);
                  printf("              Your transaction has been done-...!\n\n\n");
                  if(head==NULL){
                    head=(struct node *)malloc(sizeof(struct node));
                    head->data=amount;
                    strcpy(head->str,"Withdrawal");
                    head->next=NULL;
                    last=head;
                    }
                    else{
                        p=(struct node *)malloc(sizeof(struct node));
                        p->data=send;
                        strcpy(p->str,"Transferred");
                        p->next=NULL;
                        last->next=p;
                        last=p;
                    }
                     choice=menu(choice);
                  break;

    case 10:    printf("               Thank you...!!!!\n");
                flag=0;
                break;
    }
    }
	return 0;
}

