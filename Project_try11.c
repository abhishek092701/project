#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct contact
{
	int id;
	char name[50];
	char phone[50];
	char email[50];
	char address[50];
};

struct contact *C=NULL;
int count=0;
int nextId=1;

void addContact()
{

	int valids,i;
    C=(struct contact *)realloc(C,(count+1)*sizeof(struct contact));
    C[count].id=nextId++;
    do
    {
    	valids=1;
    	fflush(stdin);
    	printf("\n								Enter Name    : ");
    	gets(C[count].name);
    	if(strlen(C[count].name)==0)
    	{
    		valids=0;
		}
		for(i=0; C[count].name[i] != '\0'; i++)
		{
			if(!((C[count].name[i] >= 'A' && C[count].name[i] <= 'Z') ||
			(C[count].name[i] >= 'a' && C[count].name[i] <= 'z') ||
			C[count].name[i]== ' '))
			{
				valids=0;
				break;
			}
		}
		if(!valids)
		{
			printf("\n						Invalid Name! Use only alphabets and spaces.\n\n");
		}
	}while(!valids);

    fflush(stdin);
	int len,valid;
	do
	{
    	valid=1;
    	printf("								Enter Phone   : ");
    	scanf("%s", C[count].phone);
    	len=strlen(C[count].phone);
    	if(len!=10)
    	{
        	valid=0;
    	}
    	for(i=0; i<len; i++)
    	{
        	if(C[count].phone[i] < '0' || C[count].phone[i] > '9')
        	{
        		valid=0;
            	break;
        	}
    	}
    	if(valid)
    	{
        	if(!((C[count].phone[0] == '9') && (C[count].phone[1] == '8' || C[count].phone[1] == '7')))
        	{
            	valid=0;
        	}
    	}
    	if(!valid)
    	{
        	printf("						Invalid phone number! Enter a valid 10-digit number starting with 98 or 97.\n\n");
    	}
	} while(!valid);

    fflush(stdin);
	int Valid;
	do
	{
    	Valid=1;
    	printf("								Enter Email   : ");
    	scanf("%s", C[count].email);
    	if(strstr(C[count].email, "@gmail.com") == NULL)
    	{
        	Valid=0;
    	}
    	if(C[count].email[0] == '@')
    	{
        	Valid=0;
    	}
    	if(!((C[count].email[0] >= 'a' && C[count].email[0] <= 'z')))
		{
    		Valid=0;
		}
		for(i=0; C[count].email[i] != '\0' && C[count].email[i] != '@'; i++)
		{
    		if(!((C[count].email[i] >= 'a' && C[count].email[i] <= 'z') ||
         		(C[count].email[i] >= '0' && C[count].email[i] <= '9')))
    			{
        			Valid=0;
        			break;
    			}
		}
    	if(!Valid)
    	{
        	printf("\n						Invalid Email! Enter like username@gmail.com\n\n");
    	}
	}while(!Valid);

    fflush(stdin);
    int Valids,comma=0;
    do
    {
    	Valids=1;
    	comma=0;
    	fflush(stdin);
    	printf("								Enter Address : ");
    	gets(C[count].address);
    	if(strlen(C[count].address)==0)
    	{
    		Valids=0;
		}
		for(i=0; C[count].address[i] != '\0'; i++)
		{
			if(C[count].address[i] == ',')
        	{
            	comma++;
        	}
			if(!((C[count].address[i] >= 'A' && C[count].address[i] <= 'Z') ||
			(C[count].address[i] >= 'a' && C[count].address[i] <= 'z') ||
			C[count].address[i]== ' ' || C[count].address[i] == ','))
			{
				Valids=0;
				break;
			}
		}
		if(comma!= 1)
    	{
        	Valids=0;
    	}
    	if(C[count].address[0] == ',')
    	{
        	Valids=0;
    	}
    	if(C[count].address[strlen(C[count].address)-1] == ',')
    	{
        	Valids=0;
    	}
    	if(!Valids)
    	{
        	printf("\n						Invalid Address! Use like(City/Country/District, District/Country/City)\n\n");
    	}
	}while(!Valids);

    fflush(stdin);
    count++;
    printf("\n								Contact Added Successfully!\n\n");
}

void displayContacts()
{
    int i;
    if(count==0)
    {
        printf("\n								No Contacts Available!\n\n");
        return;
    }
    printf("\n        								CONTACT LIST        \n");
    for(i=0; i<count; i++)
    {
        printf("\n								Contact %d\n", i+1);
        printf("								ID      : %d\n", C[i].id);
        printf("								Name    : %s\n", C[i].name);
        printf("								Phone   : %s\n", C[i].phone);
        printf("								Email   : %s\n", C[i].email);
        printf("								Address : %s\n", C[i].address);
    }
}
void searchContact()
{
    int choice,i,found=0;
    int searchId;
    if(count==0)
    {
        printf("\n								No Contacts Available!\n\n");
        return;
    }
    printf("\n								Enter SearchId Number: ");
    scanf("%d",&searchId);
    for(i=0; i<count; i++)
    {
        if(C[i].id==searchId)
        {
            printf("\n								Contact Found!\n\n");
            printf("								ID      : %d\n", C[i].id);
            printf("								Name    : %s\n", C[i].name);
            printf("								Phone   : %s\n", C[i].phone);
            printf("								Email   : %s\n", C[i].email);
            printf("								Address : %s\n", C[i].address);
            found=1;
            break;
        }
    }
    if(!found)
    {
        printf("\n								Contact Not Found!\n\n");
    }
}

void editContact()
{
    int searchId;
    int i;
    if(count==0)
    {
        printf("\n								No Contacts Available!\n\n");
        return;
    }
    fflush(stdin);
    printf("\n								Enter ID to Edit: ");
    scanf("%d",&searchId);
    for(i=0; i<count; i++)
    {
        if(C[i].id==searchId)
        {
        	fflush(stdin);
        	printf("								Enter New Name    : ");
			gets(C[i].name);
        	fflush(stdin);
            printf("								Enter New Phone   : ");
            gets(C[i].phone);
            fflush(stdin);
            printf("								Enter New Email   : ");
            gets(C[i].email);
            fflush(stdin);
            printf("								Enter New Address : ");
    		gets(C[i].address);
			fflush(stdin);
            printf("\n								Contact Updated Successfully!\n\n");
            return;
        }
    }
    printf("\n								Contact Not Found!\n\n");
}

void deleteContact()
{
    int searchId;
    int i,j;
    if(count==0)
    {
        printf("\n								No Contacts Available!\n\n");
        return;
    }
    printf("\n								Enter ID to Delete: ");
    scanf("%d",&searchId);
    for(i=0; i<count; i++)
    {
        if(C[i].id==searchId)
        {
            for(j=i; j<count-1; j++)
            {
                C[j]=C[j+1];
            }
            count--;
            C=(struct contact *)realloc(C,count*sizeof(struct contact));
            printf("\n								Contact Deleted Successfully!\n\n");
            return;
        }
    }
    printf("\n								Contact Not Found!\n\n");
}

void sortContacts()
{
    int i,j;
    struct contact temp;
    if(count==0)
    {
        printf("\n								No Contacts Available!\n\n");
        return;
    }
    for(i=0; i<count-1; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if(strcmp(C[i].name,C[j].name)>0)
            {
                temp=C[i];
                C[i]=C[j];
                C[j]=temp;
            }
        }
    }
    for(i=0; i<count; i++)
    {
        C[i].id=i+1;
    }
    nextId=count+1;
    printf("\n								Contacts Sorted Alphabetically!\n\n");
}

void saveContacts()
{
    FILE *fp;
    int i;
	fp=fopen("D:\\LOQ\\project_try-11.bin","wb");
	if(fp==NULL)
	{
		return;
	}
	fwrite(&count, sizeof(int), 1, fp);
	fwrite(C, sizeof(struct contact),count,fp);
    fclose(fp);
    printf("\n								Contacts Saved Successfully!\n\n");
}

void loadContacts()
{
    FILE *fp;
    int i;
	fp=fopen("D:\\LOQ\\project_try-11.bin","rb");
    if(fp==NULL)
    {
        return;
    }
	fread(&count, sizeof(int),1,fp);
	if(count > 0)
    {
        C=(struct contact *)malloc(count*sizeof(struct contact));
        fread(C, sizeof(struct contact), count, fp);
        nextId=1;
        for(i=0; i<count; i++)
        {
            if(C[i].id>=nextId)
            {
                nextId=C[i].id+1;
            }
        }
    }
    else
    {
        C=NULL;
    }
    fclose(fp);
}

void freeMemory()
{
    free(C);
    C=NULL;
}
int main()
{
	system("color 4e");
	system("cls");
    int choice;
    loadContacts();
    do
    {
        printf("\n      									PHONE BOOK     \n\n");
        printf("								1.Add Contact\n");
        printf("								2.Display Contacts\n");
        printf("								3.Search Contact (By ID)\n");
        printf("								4.Edit Contact\n");
        printf("								5.Delete Contact\n");
        printf("								6.Sort Contacts\n");
        printf("								7.Save Contacts\n");
        printf("								8.Exit\n\n");
        printf("								Enter Your Choice: ");
        scanf("%d", &choice);
        system("cls");
        switch(choice)
        {
            case 1:
                addContact();
                system("pause");
                system("cls");
                break;

            case 2:
                displayContacts();
                system("pause");
                system("cls");
                break;

            case 3:
                searchContact();
                system("pause");
                system("cls");
                break;

            case 4:
                editContact();
                system("pause");
                system("cls");
                break;

            case 5:
                deleteContact();
                system("pause");
                system("cls");
                break;

            case 6:
                sortContacts();
                system("pause");
                system("cls");
                break;

            case 7:
                saveContacts();
                system("pause");
                system("cls");
                break;

            case 8:
                saveContacts();
                system("pause");
                system("cls");
                freeMemory();
                printf("\n								Thank You for Using Phone Book!\n\n");
                break;

            default:
                printf("\n								Invalid Choice!\n\n");
        }
    }
	while(choice!=8);
    return 0;
}