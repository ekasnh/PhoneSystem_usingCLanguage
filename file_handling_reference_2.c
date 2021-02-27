#include<stdio.h>
#include<conio.h>
#include<string.h>

struct data
{
    int id;
    char name[20];
    char address[30];
}
s;

void strt();
void add();
void search();
void del();
void disp();
void update();
void multiple_add();
void addn();
void main()
{
    strt();
    getch();
}

void strt()
{
      int c;
    printf("\n\n");
    printf("\n\t------Select One Of The Choices------\n");
    printf("(1)\tAdd Contact\n");
    printf("(2)\tAdd Multiple Contact\n");
    printf("(3)\tView All Contact\n");
    printf("(4)\tSearch contact\n");
    printf("(5)\tDelete A contact\n");
    printf("(6)\tUpdate A contact\n");
    printf("(7)\tExit\n\n\t\t");
    scanf("%d",&c);
    switch(c)
    {
         case 1:
        add();
        break;
     case 2:
    multiple_add();
    break;
     case 3:
    disp();
    break;
     case 4:
    search();
    break;
     case 5:
    del();
    break;
     case 6:
    update();
    break;
     case 7:
    exit(0);
    break;
     default:
    printf("Wrong Choice...Please Try Again");
    main();

      }
    }
    void add()
    {
    FILE *fp;
    fp = fopen("Record.csv","a");
    printf("\n\n\t\tEnter The contact id: ");
    scanf("%d",&s.id);
    printf("\n\t\tEnter The contact Name: ");
    scanf("%s",&s.name);
    printf("\n\t\tEnter The contact phone number: ");
    scanf("%s",&s.address);
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("\n\n\t\tData Added Sucessfully");
    strt();

    }

void disp()
{
    FILE *fp1;
    fp1 = fopen("Record.xlsx","r");
    printf("\n\tRoll_No\t\tName\t\tAddress\n\n\n");
    while (fread(&s, sizeof(s), 1, fp1))
    {
        printf("\t%d\t\t%s\t\t%s\n",s.id,s.name,s.address);
    }
    fclose(fp1);
    strt();

}

void search()
{
    FILE *fp3;
    FILE *fp4;
    int r,q,avl;
    printf("\n\n\t\tEnter The ID You Want To Search: ");
    scanf("%d",&r);

    fp3 = fopen("Record.xlsx","r");
    while (fread(&s, sizeof(s), 1, fp3))
    {
        q = s.id;
        if(q==r)
        {
            printf("\n\t\tID: %d",s.id);

            printf("\n\t\tName: %s",s.name);
            printf("\n\t\tAddress: %s",s.address);
        }
    }
    fclose(fp3);

}
void del()
{
FILE *fpo;
FILE *fpt;
int r,avl;
int x;
char c;
printf("\n\n\t\t\tEnter The ID You Want To Delete: ");
scanf("%d",&r);

    fpo=fopen("Record.xlsx","r");
    fpt=fopen("tempfile","w");
    while (fread(&s, sizeof(s), 1, fpo))
    {
        x = s.id;
        if(x!=r)
        {
            fwrite(&s, sizeof(s), 1, fpt);
        }
    }
    fclose(fpo);
    fclose(fpt);
    fpo=fopen("Record.xlsx","w");
    fpt=fopen("tempfile","r");
    while (fread(&s, sizeof(s), 1, fpt))
        fwrite(&s, sizeof(s), 1, fpo);
    printf("\n\n\t\tRecord Deleted Sucessfully.\n\tBYE");



 }

    void multiple_add()
    {
    int a,i=1;
    printf("\n\n\t\tEnter The Number Of contact You Want To Add: ");
    scanf("%d",&a);
    while(i<=a)
{
    addn();
    i++;
}
strt();

}
void addn()
{
FILE *fp;
fp = fopen("Record.xlsx","a");
printf("\n\n\t\tEnter The Contact ID: ");
scanf("%d",&s.id);
printf("\n\t\tEnter The contact Name: ");
scanf("%s",&s.name);
printf("\n\t\tEnter The contact number: ");
scanf("%s",&s.address);
fwrite(&s, sizeof(s), 1, fp);
fclose(fp);
printf("\n\n\t\tData Added Sucessfully");
}
 void update()
    {
    FILE *fpt;
    FILE *fpo;
    int x,r,ch;
    printf("Enter The ID Which You Want To Update: ");
    scanf("%d",&r);
    fpo = fopen("Record.xlsx","r");
    fpt = fopen("TempFile","w");
    while (fread(&s, sizeof(s), 1, fpo))
    {
        x = s.id;
        if(x!=r)
            fwrite(&s, sizeof(s), 1, fpt);
        else
        {
            printf("\n\n\t\t(1)\tUpdate Name Of ID %d.",r);
            printf("\n\n\t\t(2)\tUpdate number Of ID %d.",r);
            printf("\n\n\t\t(3)\tUpdate Name and number Of ID %d.",r);
            printf("Enter Your Choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                printf("Enter Name: ");
                scanf("%s",&s.name);
                break;
            case 2:
                printf("Enter number: ");
                scanf("%s",&s.address);
                break;
            case 3:
                printf("Enter Name: ");
                scanf("%s",&s.name);
                printf("Enter number: ");
                scanf("%s",&s.address);
                break;
            default:
                printf("Invalid Selection");
                break;
            }
            fwrite(&s, sizeof(s), 1, fpt);

        }
    }
    fclose(fpo);
    fclose(fpt);
    fpo = fopen("Record.xlsx","w");
    fpt = fopen("TempFile","r");
    while (fread(&s, sizeof(s), 1, fpt))
    {
    fwrite(&s, sizeof(s), 1, fpo);
    }
    fclose(fpo);
    fclose(fpt);
    printf("\n\n\t\tRECORD UPDATED\n");

    }
