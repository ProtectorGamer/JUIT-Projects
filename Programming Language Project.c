#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void person(char*);
void loginpage(void);
void loginsystem(void);
void account(void);
void accountcreate(void);
void afterlogin(void);
void logout(void);
void balance(char*);
void tfmoney(void);
void displayinfo(char*);

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

struct storage
{
    char username[50];
    int date, month, year;
    char phonenumber[20];
    char aadharnumber[20];
    char firstname[50];
    char lastname[50];
    char fathername[50];
    char mothername[50];
    char address[50];
    char accounttype[50];
};

struct moneytransfer
{
    char usernameto[50];
    char userpersonfrom[50];
    long int moneytransfer;
};

struct userpassword
{
    char password[50];
};

int main()
{
    int a, b, c, choice;
    int password;

    gotoxy( 20, 3);

    printf("Welcome to Bank Account System\n\n");
    gotoxy( 18, 5);

    printf("----------------------------------");
    gotoxy( 25, 7);

    printf("Developers Info : Vansh Thakur | Prajwal Chauhan");
    gotoxy( 20, 10);

    printf("Option 1. Create Bank Account");
    gotoxy( 20, 12);
    
    printf("Option 2. Sign In To Bank Account");
    gotoxy( 20, 14);

    printf("Option 3. Exit the Bank System\n\n");

    printf("Please Input your Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
                {
                    clearScreen;
                    printf("\n\n Username Max Character Limit : 50");
                    printf("\n\n Password Max Character Limit : 50");
                    account();
                    break;
                }
        case 2:
                {
                    loginpage();
                    break;
                }
        case 3:
                {
                    exit(0);
                    break;
                }
        default:
                {
                    printf("Invalid choice! Please enter a valid option.\n");
                    getchar();
                }
    }

}

void account(void)
{
    char password[50];
    int passwordstrength, i, check = 0;

    char ch;

    FILE *fp, *fu;
    struct storage user1;
    struct userpassword person1;
    struct userpassword user2;

    fp = fopen ("username.txt", "ab");

    clearScreen;
    printf("\n\nAccount Creation has been Started");

    printf("\n First Name : ");
    scanf("%s", &user1.firstname);

    printf("\n Last Name : ");
    scanf("%s", &user1.lastname);

    printf("\n Father's Name : ");
    scanf("%s", &user1.fathername);

    printf("\n Mother's Name : ");
    scanf("%s", &user1.mothername);

    printf("\n Address : ");
    scanf("%s", &user1.address);

    printf("\n Date Of Birth : ");
    printf("\nDate : ");
    scanf("%d", &user1.date);
    printf("\nMonth : ");
    scanf("%d", &user1.month);
    printf("\nYear : ");
    scanf("%d", &user1.year);

    printf("\n Aadhar Number : ");
    scanf("%s", &user1.aadharnumber);

    printf("\n Phone Number : ");
    scanf("%s", &user1.phonenumber);

    printf("\n Username(for login) : ");
    scanf("%s", &user1.username);

    printf("\nPassword (for login): ");
    
    for(i = 0; i < 50; i++) {
        ch = getchar(); 
        
        if(ch == '\n' || ch == 13) {
            break;
        }

        password[i] = ch;
        printf("*");
    }

    password[i] = '\0';
    fwrite(password, sizeof(password), 1, fp);
    fclose(fp);
    printf("\nAccount has been Created Successfully\n");
}
void accountcreate(void)
{
    int i;
    char ch;

    clearScreen;

    printf("Kindly Wait\n Your Data is getting verified\n");
    for(i = 0; i < 2000000000; i++)
    {
        i++;
        i--;
    }

    gotoxy(30, 10);

    printf("Account has been Created Successfully");
    gotoxy(0, 20);

    printf("Press *Enter* to Login");

    getchar();
    loginpage();

}

void loginpage(void)
{
    clearScreen;

    char username[50];
    char password[50];

    int i, j ,k;
    char ch;
    FILE *fp, *fu;
    struct storage user1;
    struct userpassword user2;

    fp = fopen("username.txt", "rb");

    if(fp == NULL)
    {
        printf("User Doesn't Exist or Error in File");
    }

    gotoxy(34, 2);

    printf("Account Login");
    gotoxy(7, 5);

    printf("-------------------------------------------");
    gotoxy(35,10);

    printf("LOG IN");

    gotoxy(35, 12);
    printf("Username : ");
    scanf("%s", &username);

    gotoxy(35, 14);
    printf("Password : ");

    for( i = 0; i < 50; i++)
    {
        ch = getchar();
        if( ch != 13)
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
        {
            break;
        }
    }

    while( fread ( &user1, sizeof(user1), 1, fp))
    {
        if(strcmp( username, user1.username) == 0)
        {
            loginsystem();
            display(username);
        }
    }
    fclose(fp);
}

void loginsystem(void)
{
    int i;
    FILE* fp;
    struct userpassword user1;
    clearScreen;

    printf("Fetching Account Details. Please Wait\n");

    for( i = 0; i < 20000; i++)
    {
        i++;
        i--;
    }

    gotoxy(30, 10);
    printf("Login has been successfully");
    
    gotoxy(0, 20);
    printf("Press *Enter* to continue");

    getchar();
}

void display(char username1[])
{
    clearScreen;

    FILE* fp;
    int choice, i;

    fp = fopen("username.txt", "rb");
    struct storage user1;

    if (fp == NULL)
    {
        printf("User Doesn't exist or Error in File");
        return;
    }

    while (fread(&user1, sizeof(user1), 1, fp))
    {
        if (strcmp(username1, user1.username) == 0)
        {
            gotoxy(30, 1);
            printf("Welcome %s %s", user1.firstname, user1.lastname);
            gotoxy(28, 2);
            printf("---------------------------------------");

            gotoxy(55, 6);
            printf("Your Account Information");

            gotoxy(55, 8);
            printf("----------------------------------------");

            gotoxy(55, 10);
            printf("Name : %s %s", user1.firstname, user1.lastname);

            gotoxy(55, 12);
            printf("Father's Name : %s", user1.fathername);

            gotoxy(55, 14);
            printf("Mother's Name : %s", user1.mothername);

            gotoxy(55, 16);
            printf("Aadhar Number : %s", user1.aadharnumber);

            gotoxy(55, 18);
            printf("Mobile Number : %s", user1.phonenumber);

            gotoxy(55, 20);
            printf("Date Of Birth : %d-%d-%d", user1.date, user1.month, user1.year);

            gotoxy(55, 22);
            printf("Address : %s", user1.address);

            gotoxy(55, 24);
            printf("Account Type : %s", user1.accounttype);
        }
    }

    fclose(fp);

    gotoxy(0, 6);
    printf("Home");
    gotoxy(0, 7);
    printf("--------");
    gotoxy(0, 9);
    printf("1. Check Account Balance");
    gotoxy(0, 11);
    printf("2. Transfer Money");
    gotoxy(0, 13);
    printf("3. Session out\n\n");
    gotoxy(0, 15);
    printf("4. Exit\n\n");

    printf("Please Input your Choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
                {
                    checkbalance(username1);
                    break;
                }
        case 2:
                {
                    transfermoney();
                    break;
                }
        case 3:
                {
                    logout();
                    login();
                    break;
                }
        case 4:
                {
                    exit(0);
                    break;
                }
        default:
                {
                    printf("Invalid choice! Please enter a valid option.\n");
                    getchar(); 
                    display(username1);
                    break;
                }
    }
}


void transfermoney(void)
{
    int i, j;
    FILE *fm, *fp;

    struct storage user1;
    struct moneytransfer money1;

    char usernameto[50];
    char usernameperson[50];
    clearScreen;

    fp = fopen("username.txt", "rb");
    fm = fopen("mon.txt", "ab");

    gotoxy(33, 4);
    printf(" Transfer Money");
    gotoxy(33, 5);
    printf("-----------------");

    gotoxy(33, 11);
    printf("From User : ");
    scanf("%s", usernameto);

    gotoxy(33, 13);
    printf("To User : ");
    scanf("%s", usernameperson);

    while(fread(&user1, sizeof(user1), 1, fp))
    {
        if(strcmp(usernameperson, user1.username) == 0)
        {
            strcpy(money1.usernameto, user1.username);
            strcpy(money1.userpersonfrom, usernameto);
        }
    }

    gotoxy(33, 16);
    printf("Enter the Amount for Transfer : ");
    scanf("%ld", &money1.moneytransfer);

    fwrite(&money1, sizeof(money1), 1, fm);

    gotoxy(0, 26);
    printf("-----------------------");
    gotoxy(0, 28);
    printf("Transferring Amount, Please Wait");

    for(i = 0; i < 70; i++)
    {
        for(j = 0; j < 1200000; j++)
        {
            j++;
            j--;
        }
        printf("*");
    }

    gotoxy(33, 40);
    printf("Amount has been transferred successfully");
    getchar();

    fclose(fp);
    fclose(fm);

    display(usernameto);
}

void checkbalance(char username2[])
{
    clearScreen;
    FILE* fm;

    struct moneytransfer money1;
    char ch;
    int i = 1, summoney = 0;

    fm = fopen("mon.txt", "rb");

    int k = 5, l = 10;
    int m = 30, n = 10;
    int u = 60, v = 10;

    gotoxy(30, 2);
    printf("Balance Dashboard : ");
    gotoxy(30, 3);
    printf("-----------------------");
    gotoxy(k, l);
    printf("S. No. : ");
    gotoxy(m, n);
    printf("Transaction ID : ");
    gotoxy(u, v);
    printf("Amount : ");

    while(fread(&money1, sizeof(money1), 1, fm))
    {
        if(strcmp(username2, money1.usernameto) == 0)
        {
            gotoxy(k, ++l);
            printf("%d", i);
            i++;
            gotoxy(m, ++n);
            printf("%s", money1.userpersonfrom);
            gotoxy(u, ++v);
            printf("%ld", money1.moneytransfer);

            summoney = summoney + money1.moneytransfer;
        }
    }

    gotoxy(80, 10);
    printf("Total Amount : ");
    gotoxy(80, 12);
    printf("%d", summoney);

    getchar();

    fclose(fm);

    display(username2);
}


void logout(void)
{
    int i, j;
    clearScreen;
    printf("Please wait, Logging Out");

    for( i = 0; i < 10; i++)
    {
        for( j = 0; j < 25000000; j++)
        {
            i++;
            i--;
        }
        printf(".");
    }

    gotoxy(30, 10);
    printf("Signed Out Successfully\n");

    gotoxy(0,20);
    printf("Press *Any Key* to Continue");

    getchar();
}
