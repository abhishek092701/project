#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct user
{
	char username[30];
	char password[30];
};

int accountExists();
int validUsername(char username[]);
int validPassword(char password[]);
void deleteAccount();
void signup();

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
void saveContacts();
int nextId=1;

int accountExists()
{
    FILE *fp;
    fp = fopen("D:\\LOQ\\login.bin1","rb");
    if(fp==NULL)
    {
        return 0;
	}
    fclose(fp);
    return 1;
}

int login()
{
    FILE *fp;
    if(!accountExists())
	{
    	printf("\n									No account found.");
		printf("Please SignUp First.\n");
		system("pause");
    	return 0;
	}
	struct user u;
	char username[30], password[30];
    fp=fopen("D:\\LOQ\\login.bin1", "rb");
	printf("\n\n									Enter Username : ");
	scanf("%s", username);
	char ch;
	int i=0;
	printf("									Enter Password : ");
	while(1)
	{
    	ch=getch();
		if(ch==13)
    	{
        	password[i]='\0';
        	break;
    	}
    	else if(ch==8)
    	{
        	if(i>0)
        	{
            	i--;
            	printf("\b \b");
        	}
    	}
    	else
    	{
        	password[i]=ch;
        	i++;
        	printf("*");
    	}
	}
	printf("\n");
	fread(&u, sizeof(struct user), 1, fp);
	fclose(fp);
	if(strcmp(username, u.username)==0 &&
   		strcmp(password, u.password)==0)
		{
    		printf("\n\n									Login Successful!\n");
    		return 1;
		}
		else
		{
    		printf("\n\n									Invalid Username or Password!\n");
    		system("pause");
			return 0;
		}
	}

int validUsername(char username[])
{
    int i;
    if(strlen(username)<4 || strlen(username)>20)
    {
        return 0;
	}
    if(!((username[0]>='A' && username[0]<='Z') ||
         (username[0]>='a' && username[0]<='z')))
         {
        	return 0;
		 }
    for(i=0; username[i]!='\0'; i++)
    {
        if(!((username[i]>='A' && username[i]<='Z') ||
             (username[i]>='a' && username[i]<='z') ||
             (username[i]>='0' && username[i]<='9') ||
             username[i]=='_'))
        {
            return 0;
        }
    }
    return 1;
}

int validPassword(char password[])
{
    int i;
    int upper=0, lower=0, digit=0, special=0;
    if(strlen(password)<8)
    {
        return 0;
	}
    for(i=0; password[i]!='\0'; i++)
    {
        if(password[i]>='A' && password[i]<='Z')
        {
            upper=1;
		}
        else if(password[i]>='a' && password[i]<='z')
        {
            lower=1;
		}
        else if(password[i]>='0' && password[i]<='9')
        {
            digit=1;
		}
        else
        {
            special=1;
		}
    }
    if(upper && lower && digit && special)
    {
        return 1;
	}
    return 0;
}

void deleteAccount()
{
	int i;
	if(!accountExists())
    {
        printf("\n									No account found!\n");
        system("pause");
        return;
    }
    do
    {
    	char choice;
    	printf("\n								Are you sure you want to delete your account? (Y/N): ");
    	scanf(" %c",&choice);
    	if(choice=='Y' || choice=='y')
    	{
        	if(remove("D:\\LOQ\\login.bin1")==0)
        	{
            	printf("\n								Account Deleted Successfully!\n");
        	}
        	else
        	{
            	printf("\n								Unable to delete account!\n");
        	}
        	system("pause");
        	return;
    	}
    	else if(choice=='N' || choice=='n')
    	{
        	printf("\n									Account Deletion Cancelled.\n");
        	system("pause");
        	return;
    	}
    	else
    	{
        	printf("\n								Invalid Choice!\n");
    	}
	}while(1);
    system("pause");
}

int validName(int index)
{
	int valids,i;
	fflush(stdin);
    do
    {
    	valids=1;
    	fflush(stdin);
    	printf("\n								Current Name      : %s\n", C[index].name);
    	printf("\n								Enter New Name    : ");
    	gets(C[index].name);
    	fflush(stdin);
    	if(strlen(C[index].name)==0)
    	{
    		valids=0;
		}
		for(i=0; C[index].name[i] != '\0'; i++)
		{
			if(!((C[index].name[i] >= 'A' && C[index].name[i] <= 'Z') || (C[index].name[i] >= 'a' && C[index].name[i] <= 'z') || C[index].name[i]== ' '))
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
	return 1;	
}

int validPhone(int index)
{
	int len,valid,i;
	fflush(stdin);
	do
	{
    	valid=1;
    	fflush(stdin);
    	printf("\n								Current Phone     : %s\n", C[index].phone);    	
    	printf("\n								Enter New Phone   : ");
    	scanf("%s", C[index].phone);
    	fflush(stdin);
    	len=strlen(C[index].phone);
    	if(len!=10)
    	{
        	valid=0;
    	}
    	for(i=0; i<len; i++)
    	{
        	if(C[index].phone[i] < '0' || C[index].phone[i] > '9')
        	{
        		valid=0;
            	break;
        	}
    	}
    	if(valid)
    	{
        	if(!((C[index].phone[0] == '9') && (C[index].phone[1] == '8' || C[index].phone[1] == '7')))
        	{
            	valid=0;
        	}
    	}
        /*if(valid)
		{
    		for(i=0; i<count; i++)
    		{
        		if(strcmp(C[index].phone, C[i].phone) == 0)
        		{
            		valid=0;
            		printf("\n\n								Phone number already exists!\n\n");
            		break;
        		}
    		}
		}
    	if(!valid)
    	{
        	printf("						Invalid phone number! Enter a valid 10-digit number starting with 98 or 97.\n\n");
    	}*/
	} while(!valid);
	return 1;
}

int validEmail(int index)
{
	int Valid,i;
	int atCount;
	int atPos;
	int lastDot;
	int leng;
	fflush(stdin);
	do
	{
    	Valid=1;
    	atCount=0;
    	atPos=-1;
    	lastDot=-1;
    	fflush(stdin);
    	printf("\n								Current Email     : %s\n",C[index].email);
    	printf("\n								Enter New Email   : ");
    	scanf("%s", C[index].email);
    	fflush(stdin);
    	leng=strlen(C[index].email);
    	if(!(C[index].email[0]>= 'a' && C[index].email[0]<= 'z'))
    	{
        	Valid=0;
    	}
    	for(i=0; i<leng; i++)
    	{
        	char ch=C[index].email[i];
        	if(ch == '@')
        	{
            	atCount++;
            	atPos=i;
        	}
        	if(ch=='.')
        	{
            	lastDot=i;
        	}
        	if(ch== ' ')
        	{
            	Valid=0;
            	break;
    		}
        	if(!((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '@' || ch == '.' || ch == '_' || ch == '-'))
        	{
            	Valid=0;
            	break;
        	}
        	if(i<leng-1 && ch == '.' && C[count].email[i+1] == '.')
        	{
            	Valid=0;
            	break;
        	}
    	}
    	if(atCount!=1)
    	{
        	Valid=0;
    	}
    	if(atPos<=0 || atPos==leng-1)
    	{
        	Valid=0;
    	}
    	if(atPos>0)
    	{
        	char prev=C[index].email[atPos-1];
        	if(prev == '.' || prev == '_' || prev == '-')
        	{
            	Valid=0;
        	}
    	}
    	if(atPos+1<leng)
    	{
        	char next=C[index].email[atPos+1];
        	if(next=='.' || next=='-')
        	{
            	Valid=0;
        	}
    	}
    	int dotFound=0;
    	for(i=atPos+1; i<leng; i++)
    	{
        	if(C[index].email[i] == '.')
        	{
            	dotFound=1;
            	if(i==atPos+1)
            	{
                	Valid=0;
                	break;
            	}
            	if(leng-i-1<2)
            	{
                	Valid=0;
                	break;
            	}
        	}
    	}
    	if(!dotFound)
    	{
        	Valid=0;
    	}
    	if(C[index].email[leng-1] == '.')
    	{
        	Valid=0;
    	}
    	if(strstr(C[index].email, "@@")!=NULL)
    	{
        	Valid=0;
    	}
    	if(strstr(C[index].email, ".@")!=NULL)
    	{
        	Valid=0;
    	}
    	if(strstr(C[index].email, "@.")!= NULL)
    	{
        	Valid=0;
    	}
    	/*if(Valid)
    	{
        	for(i=0; i<count; i++)
        	{
            	if(strcmp(C[index].email, C[i].email)==0)
            	{
                	Valid=0;
                	printf("\n								Email already exists!\n\n");
                	break;
            	}
       	 	}
    	}
    	if(!Valid)
    	{
        	printf("\n								Invalid Email Format!\n");
        	printf("								Examples:\n");
        	printf("									-abc@gmail.com\n");
        	printf("									-ram123@yahoo.com\n");
        	printf("									-ram.shrestha@college.edu.np\n\n");
    	}*/
	} while(!Valid);
	return 1;
}

int validAddress(int index)
{
    int Valids,comma=0,i;
    fflush(stdin);
    do
    {
    	Valids=1;
    	comma=0;
    	fflush(stdin);
    	printf("\n								Current Address   : %s\n", C[index].address);
    	printf("\n								Enter New Address : ");
    	gets(C[index].address);
    	fflush(stdin);
    	if(strlen(C[index].address)==0)
    	{
    		Valids=0;
		}
		for(i=0; C[index].address[i] != '\0'; i++)
		{
			if(C[index].address[i] == ',')
        	{
            	comma++;
        	}
			if(!((C[index].address[i] >= 'A' && C[index].address[i] <= 'Z') || (C[index].address[i] >= 'a' && C[index].address[i] <= 'z') || C[index].address[i]== ' ' || C[index].address[i] == ','))
			{
				Valids=0;
				break;
			}
		}
		if(comma!= 1)
    	{
        	Valids=0;
    	}
    	if(C[index].address[0] == ',')
    	{
        	Valids=0;
    	}
    	if(C[index].address[strlen(C[index].address)-1] == ',')
    	{
        	Valids=0;
    	}
    	if(!Valids)
    	{
        	printf("\n						Invalid Address! Use like(City/Country/District, District/Country/City)\n\n");
    	}
	}while(!Valids);
	return 1;
}

void signup()
{
    struct user u;
    FILE *fp;
	if(accountExists())
	{
    	printf("\n										An account already exists.\n");
    	printf("								Please login or delete the existing account first.\n");
    	system("pause");
    	return;
	}
	fp=fopen("D:\\LOQ\\login.bin1","wb");
	do
	{
    	printf("\n\n									Enter Username : ");
    	scanf("%s",u.username);
    	if(!validUsername(u.username))
    	{
        	printf("\n\n									Invalid Username!\n");
			printf("									Please Enter following Category:\n");
        	printf("										- 4 to 20 characters\n");
        	printf("										- First character must be a letter\n");
        	printf("										- Only letters, numbers and underscore (_) are allowed\n\n");
		}
	}while(!validUsername(u.username));
	do
	{
    	printf("									Enter Password : ");
    	scanf("%s",u.password);
		if(!validPassword(u.password))
		{
        	printf("\n\n									Invalid Password!\n\n");
			printf("									Please Enter following Category:\n");
        	printf("										- Minimum 8 characters\n");
        	printf("										- At least one uppercase letter\n");
        	printf("										- At least one lowercase letter\n");
        	printf("										- At least one number\n");
        	printf("										- At least one special character\n\n");
		}
	}while(!validPassword(u.password));
	fwrite(&u, sizeof(struct user), 1, fp);
	fclose(fp);
	printf("\n									Account Created Successfully!\n");
	printf("\n									Please Login from the Login Menu.\n");
	system("pause");
}

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
    	fflush(stdin);
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
    	fflush(stdin);
    	printf("								Enter Phone   : ");
    	scanf("%s", C[count].phone);
    	fflush(stdin);
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
        if(valid)
		{
    		for(i=0; i<count; i++)
    		{
        		if(strcmp(C[count].phone, C[i].phone) == 0)
        		{
            		valid=0;
            		printf("\n\n								Phone number already exists!\n\n");
            		break;
        		}
    		}
		}
    	if(!valid)
    	{
        	printf("						Invalid phone number! Enter a valid 10-digit number starting with 98 or 97.\n\n");
    	}
	} while(!valid);

	fflush(stdin);
	int Valid;
	int atCount;
	int atPos;
	int lastDot;
	int leng;
	do
	{
    	Valid=1;
    	atCount=0;
    	atPos=-1;
    	lastDot=-1;
    	printf("								Enter Email   : ");
    	scanf("%s", C[count].email);
    	leng=strlen(C[count].email);
    	if(!(C[count].email[0]>= 'a' && C[count].email[0]<= 'z'))
    	{
        	Valid=0;
    	}
    	for(i=0; i<leng; i++)
    	{
        	char ch=C[count].email[i];
        	if(ch == '@')
        	{
            	atCount++;
            	atPos=i;
        	}
        	if(ch=='.')
        	{
            	lastDot=i;
        	}
        	if(ch== ' ')
        	{
            	Valid=0;
            	break;
    		}
        	if(!((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '@' || ch == '.' || ch == '_' || ch == '-'))
        	{
            	Valid=0;
            	break;
        	}
        	if(i<leng-1 && ch == '.' && C[count].email[i+1] == '.')
        	{
            	Valid=0;
            	break;
        	}
    	}
    	if(atCount!=1)
    	{
        	Valid=0;
    	}
    	if(atPos<=0 || atPos==leng-1)
    	{
        	Valid=0;
    	}
    	if(atPos>0)
    	{
        	char prev=C[count].email[atPos-1];
        	if(prev == '.' || prev == '_' || prev == '-')
        	{
            	Valid=0;
        	}
    	}
    	if(atPos+1<leng)
    	{
        	char next=C[count].email[atPos+1];
        	if(next=='.' || next=='-')
        	{
            	Valid=0;
        	}
    	}
    	int dotFound=0;
    	for(i=atPos+1; i<leng; i++)
    	{
        	if(C[count].email[i] == '.')
        	{
            	dotFound=1;
            	if(i==atPos+1)
            	{
                	Valid=0;
                	break;
            	}
            	if(leng-i-1<2)
            	{
                	Valid=0;
                	break;
            	}
        	}
    	}
    	if(!dotFound)
    	{
        	Valid=0;
    	}
    	if(C[count].email[leng-1] == '.')
    	{
        	Valid=0;
    	}
    	if(strstr(C[count].email, "@@")!=NULL)
    	{
        	Valid=0;
    	}
    	if(strstr(C[count].email, ".@")!=NULL)
    	{
        	Valid=0;
    	}
    	if(strstr(C[count].email, "@.")!= NULL)
    	{
        	Valid=0;
    	}
    	if(Valid)
    	{
        	for(i=0; i<count; i++)
        	{
            	if(strcmp(C[count].email, C[i].email)==0)
            	{
                	Valid=0;
                	printf("\n								Email already exists!\n\n");
                	break;
            	}
       	 	}
    	}
    	if(!Valid)
    	{
        	printf("\n								Invalid Email Format!\n");
        	printf("								Examples:\n");
        	printf("									-abc@gmail.com\n");
        	printf("									-ram123@yahoo.com\n");
        	printf("									-ram.shrestha@college.edu.np\n\n");
    	}
	} while(!Valid);

    fflush(stdin);
    int Valids,comma=0;
    do
    {
    	Valids=1;
    	comma=0;
    	fflush(stdin);
    	printf("								Enter Address : ");
    	gets(C[count].address);
    	fflush(stdin);
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
    saveContacts();
}

void displayContacts()
{
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int i;
    if(count==0)
    {
        printf("\n								No Contacts Available!\n\n");
        return;
    }
    SetConsoleTextAttribute(h,BACKGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY);
    printf("\n\n\n        								CONTACT LISTS        \n");
    SetConsoleTextAttribute(h,BACKGROUND_GREEN);
    printf("\n					%-6s %-25s %-15s %-35s %-30s\n","ID", "NAME", "PHONE", "EMAIL", "ADDRESS\n");
    for(i=0; i<count; i++)
    {
        printf("					%-6d %-25s %-15s %-35s %-30s\n",C[i].id,C[i].name,C[i].phone,C[i].email,C[i].address);
    }
}

void searchContact()
{
    int choice,i,found=0;
    int searchId;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
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
        	SetConsoleTextAttribute(h, BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            printf("\n\n									Contact Found!\n\n");
            SetConsoleTextAttribute(h, BACKGROUND_GREEN);
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
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int searchId;
    int valids,i;
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
			int check,ch;
    		SetConsoleTextAttribute(h,BACKGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY);
			printf("\n\n								Contact Found!\n\n");
			SetConsoleTextAttribute(h,BACKGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);
			printf("\n					%-6s %-25s %-15s %-35s %-30s\n","ID", "NAME", "PHONE", "EMAIL", "ADDRESS\n");
			SetConsoleTextAttribute(h,BACKGROUND_GREEN);
        	printf("					%-6d %-25s %-15s %-35s %-30s\n",C[i].id,C[i].name,C[i].phone,C[i].email,C[i].address);
			printf("\n								1.Edit Name\n");
			printf("								2.Edit Phone\n");
			printf("								3.Edit Email\n");
			printf("								4.Edit Address\n");
			printf("								5.Cancel\n");
			do
			{
				fflush(stdin);
    			printf("\n								Enter Choice : ");
				check=scanf("%d", &ch);
				if(check!=1)
    			{
        			printf("\n							Invalid Input! Please enter numbers only.\n");
					while(getchar()!='\n');
    			}
    			else if(ch<1 || ch>5)
    			{
        			printf("\n							Invalid Choice! Please enter between 1 and 5.\n");
    			}
			}while(check!=1 || ch<1 || ch>5);
			switch(ch)
			{
				case 1:
					fflush(stdin);
					validName(i);				
					saveContacts();
    				printf("								Name Updated Successfully!\n");
    				return;
					break;
				case 2:
					fflush(stdin);
					validPhone(i);
					saveContacts();
    				printf("								Phone Updated Successfully!\n");
    				return;
    				break;
				case 3:
					fflush(stdin);
					validEmail(i);
					saveContacts();
    				printf("								Email Updated Successfully!\n");
    				return;
    				break;
				case 4:
					fflush(stdin);
					validAddress(i);
					saveContacts();
    				printf("								Address Updated Successfully!\n");
    				return;
    				break;
				case 5:
					fflush(stdin);
					printf("\n								Edit Cancelled!\n");
					break;
					return;
        		default:
					printf("\n								Invalid Choice!\n");
        			return;
			}
        }
    }
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
    		char confirm;
    		printf("\n");
    		printf("                                			Are you sure you want to delete this contact? (Y/N): ");
    		scanf(" %c", &confirm);
    		if(confirm=='Y' || confirm=='y')
    		{
        		for(j=i; j<count-1; j++)
        		{
            		C[j]=C[j+1];
        		}
				count--;
				C=(struct contact *)realloc(C, count*sizeof(struct contact));
				printf("\n                                				Contact Deleted Successfully!\n\n");
    		}
    		else
    		{
        		printf("\n                                				Deletion Cancelled!\n\n");
    		}
    		saveContacts();
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
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int choice;
    int loging=0;
	while(!loging)
	{
    	int ch;
    	system("color 0F");
    	system("cls");
    	SetConsoleTextAttribute(h, 1);
    	printf("\n									LOGIN SYSTEM				\n\n");
    	SetConsoleTextAttribute(h, 15);
    	printf("									1. Login\n");
    	printf("									2. Sign Up\n");
    	printf("									3. Delete Account\n");
    	printf("									4. Exit\n");
		int check;
		do
		{
    		printf("\n									Enter Choice : ");
			check=scanf("%d", &ch);
			if(check!=1)
    		{
        		printf("\n							Invalid Input! Please enter numbers only.\n");
				while(getchar()!='\n');
    		}
    		else if(ch<1 || ch>4)
    		{
        		printf("\n							Invalid Choice! Please enter between 1 and 4.\n");
    		}
		}while(check!=1 || ch<1 || ch>4);
    	switch(ch)
    	{
        	case 1:
            	loging=login();
            	break;

        	case 2:
            	signup();
            	break;

            case 3:
            	deleteAccount();
            	break;

        	case 4:
           		exit(0);

        	default:
            	printf("\n\n							Invalid Choice!\n");
            	system("pause");
    	}
	}
    system("color 2F");
    loadContacts();
    do
    {
    	system("cls");
		SetConsoleTextAttribute(h,BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("\n      							DYNAMIC PHONE BOOK / CONTACT MANAGER     \n\n");
        SetConsoleTextAttribute(h, BACKGROUND_GREEN);
        printf("								1.Add Contact\n");
        printf("								2.Display Contacts\n");
        printf("								3.Search Contact (By ID)\n");
        printf("								4.Edit Contact\n");
        printf("								5.Delete Contact\n");
        printf("								6.Sort Contacts\n");
        printf("								7.Exit\n\n");
		int valid;
		do
		{
    		valid=1;
			printf("								Enter Choice : ");
			if(scanf("%d", &choice)!= 1)
    		{
        		valid=0;
				printf("\n\n							Invalid Input! Please enter numbers only.\n");
				while(getchar()!='\n');
    		}
    		else if(choice<1 || choice>7)
    		{
        		valid=0;
				printf("\n								Invalid Choice! Please enter between 1 and 7.\n");
    		}
		}while(!valid);
        switch(choice)
        {
            case 1:
                addContact();
                system("pause");
                break;

            case 2:
                displayContacts();
                system("pause");
                break;

            case 3:
                searchContact();
                system("pause");
                break;

            case 4:
                editContact();
                system("pause");
                break;

            case 5:
                deleteContact();
                system("pause");
                break;

            case 6:
                sortContacts();
                system("pause");
                break;

            case 7:
                freeMemory();
                system("pause");
                printf("\n								Thank You for Using Phone Book!\n\n");
                exit(0);
                break;
            default:
                printf("\n								Invalid Choice!\n\n");
        }
    }
	while(choice!=8);
    return 0;
}