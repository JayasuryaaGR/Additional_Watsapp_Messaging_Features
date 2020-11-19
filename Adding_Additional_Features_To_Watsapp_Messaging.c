#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Name: JAYASURYAA G R
// Roll No: 19L118
// DSA Assignment Presentation
// Date: 19/11/2020

struct Node
{
    char message[100];
    struct Node *next;
}*start = NULL;

int createMessage();
int deleteMessage();
int deleteLast();
int deleteFirst();
int deleteTyped();
int deleteNumbered();
int modifyMessage();
int modifyLast();
int modifyFirst();
int modifyTyped();
int modifyNumbered();
int displayMessage();

int modifyNumbered()
{
    int messageNumber, count = 1;
    char typeModified[100];

    typeMessageNumber:
    printf("\nType the Message Number\n");
    fflush(stdin);
    scanf("%d",&messageNumber);

    if(messageNumber < 1)
    {
        printf("\nType a valid Number\n");
        goto typeMessageNumber;
    }

    struct Node* temp = start;

    while(temp->next != NULL)
    {
        if(messageNumber == count)
        {
            printf("\nType the Modified Message\n");
            fflush(stdin);
            gets(typeModified);

            strcpy(temp->message, typeModified);
            printf("\nThe Message is Modified Successfully\n");
            return 0;
        }
        temp = temp->next;
        count++;
    }
    if(messageNumber == count)
        {
            printf("\nType the Modified Message\n");
            fflush(stdin);
            gets(typeModified);

            strcpy(temp->message, typeModified);
            printf("\nThe Message is Modified Successfully\n");
            return 0;
        }
    printf("\nYour Number is too large. Type the correct Number\n");
    temp = start;
    count = 1;
    goto typeMessageNumber;
}

int modifyTyped()
{
    char typedModify[100],typeUnmodified[100];
    printf("\nType the Unmodified Message\n");
    fflush(stdin);
    gets(typeUnmodified);

    struct Node* temp = start;

    while(strcmp(temp->message,typeUnmodified) != 0)
    {
        if(temp->next == NULL)
        {
            printf("\nYou may have Typo Error (or) This Message is Not Available\n");
            return 0;
        }
        temp = temp->next;
    }
    printf("\nType the Modified Message\n");
    fflush(stdin);
    gets(typedModify);
    strcpy(temp->message,typedModify);
    printf("\nThe Messsage is Modified Successfully\n");
    return 0;
}

int modifyFirst()
{
    char firstModify[100];
    printf("\nType the Modified Message\n");
    fflush(stdin);
    gets(firstModify);

    strcpy(start->message,firstModify);
    printf("\nThe Message is Modified Successfully\n");
    return 0;
}

int modifyLast()
{
    char lastModify[100];
    printf("\nType the Modified Message\n");
    fflush(stdin);
    gets(lastModify);

    struct Node* temp = start;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    strcpy(temp->message,lastModify);
    printf("\nThe Message is Modified Successfully\n");
    return 0;
}

int modifyMessage()
{
    if(start == NULL)
    {
        printf("\nNothing is Available to Modify\n");
        return 0;
    }
    int modifyNumber;
    printf("\nEnter the Choice:\n1.Modify the Recent Message\n2.Modify the Very First Message\n3.Type and Show the Errored Message\n4.Type the Message Number\n\n");
    fflush(stdin);
    scanf("%d",&modifyNumber);

    switch(modifyNumber)
    {
    case 1:
        modifyLast();
        break;
    case 2:
        modifyFirst();
        break;
    case 3:
        modifyTyped();
        break;
    case 4:
        modifyNumbered();
        break;
    default:
        printf("\nInvalid Choice\n");
        break;
    }
    return 0;
}

int displayMessage()
{
    struct Node* temp = start;
    int count = 1;

    if(start == NULL)
    {
        printf("\nNothing to Display");
        return 0;
    }

    printf("\nThe Messages are\n");

    while(1)
    {
        printf("%d.",count);
        count++;
        puts(temp->message);

        if(temp->next == NULL)
            return 0;
        temp = temp->next;
    }
}

int createMessage()
{
    char createMessage[100];
    struct Node* temp;

    printf("\nEnter the Message:\n");
    fflush(stdin);
    gets(createMessage);

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->message,createMessage);
    newNode->next = NULL;

    if(start == NULL)
    {
        start = newNode;
    }
    else
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
    temp->next = newNode;
    }
    return 0;
}

int deleteLast()
{
    struct Node* temp1, *temp2;
    temp1 = start;
    temp2 = temp1;

    if(temp1->next == NULL)
    {
        start = NULL;
        free(temp1);
        printf("\nMessage Deleted Successfully\n");
        return 0;
    }

    while(temp1->next != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = NULL;
    free(temp1);
    printf("\nMessage Deleted Successfully\n");
    return 0;
}

int deleteFirst()
{
    struct Node *temp = start;
    start = start->next;
    free(temp);
    printf("\nMessage Deleted Successfully\n");
    return 0;
}

int deleteTyped()
{
    char deleteTypedMessage[100];

    printf("\nType the Message\n");
    fflush(stdin);
    gets(deleteTypedMessage);

    struct Node *temp1, *temp2;
    temp1 = start;
    temp2 = temp1;

    while(strcmp(temp1->message, deleteTypedMessage) != 0)
    {
        if(temp1->next == NULL)
        {
            printf("\nYou may have Typo Error (or) The Message is not available\n");
            return 0;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if(temp1->next == NULL && temp1 == start)
    {
        start = NULL;
        free(temp1);
        printf("\nMessage Deleted Successfully\n");
        return 0;
    }
    else if(temp1->next != NULL && temp1 == start)
    {
        start = temp1->next;
        free(temp1);
    }
    else if(temp1->next == NULL)
    {
        temp2->next = NULL;
        free(temp1);
        printf("\nMessage Deleted Successfully\n");
        return 0;
    }
    else
    {
        temp2->next = temp1->next;
        free(temp1);
        printf("\nMessage Deleted Successfully\n");
        return 0;
    }
}

int deleteNumbered()
{
    int messageNumber, count;

    reEnter:
    printf("\nType the Message Number\n");
    fflush(stdin);
    scanf("%d",&messageNumber);
    count = 1;

    if(messageNumber < 1)
    {
        printf("\nYour Number is Invalid\n");
        goto reEnter;
    }

    struct Node* temp1 = start;
    struct Node* temp2 = temp1;


    while(1)
    {
        if(messageNumber > count && temp1->next == NULL)
        {
            printf("\nYour number is too large. Type the correct Number\n");
            goto reEnter;
        }
        else if(count == messageNumber && temp1 == start)
        {
            start = start->next;
            free(temp1);
            printf("\nThe Message is Deleted Successfully\n");
            return 0;
        }
        else if(count == messageNumber && temp1->next == NULL)
        {
            temp2->next = NULL;
            free(temp1);
            printf("\nThe Message is Deleted Successsfully\n");
            return 0;
        }
        else if(count == messageNumber && temp1->next != NULL)
        {
            temp2->next = temp1->next;
            free(temp1);
            printf("\nThe Message is Deleted Successfully\n");
            return 0;
        }

        temp2 = temp1;
        temp1 = temp1->next;
        count++;
    }
}

int deleteMessage()
{
    int delOption;

    if(start == NULL)
    {
        printf("\nNo Message is Present to Delete\n");
        return 0;
    }
    printf("\nEnter the Choice:\n1.Delete the very Recent Message\n2.Delete the very First Message\n3.Type and show the message\n4.Type the Message Number\n\n");
    scanf("%d",&delOption);

    switch(delOption)
    {
    case 1:
        deleteLast();
        break;
    case 2:
        deleteFirst();
        break;
    case 3:
        deleteTyped();
        break;
    case 4:
        deleteNumbered();
        break;
    default:
        printf("\nInvalid Choice\n");
        break;
    }
    return 0;
}

void main()
{
    int mainOption;
    char typedMessage[100], yesOrNo;

    mainprint:
    printf("\nChoose the Option:\n1.Post a message\n2.Delete a message\n3.Modify a message\n4.Display the messages\n5.Exit\n\n");
    fflush(stdin);
    scanf("%d",&mainOption);

    switch(mainOption)
    {
    case 1:
        createMessage();
        break;
    case 2:
        deleteMessage();
        break;
    case 3:
        modifyMessage();
        break;
    case 4:
        displayMessage();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("\nInvalid Choice\n\n");
        break;
    }

    printf("\nDo You Want to Continue? (Y/N)\n");
    fflush(stdin);
    scanf("%c",&yesOrNo);

    if(yesOrNo == 'Y' || yesOrNo == 'y')
    {
        goto mainprint;
    }
}
