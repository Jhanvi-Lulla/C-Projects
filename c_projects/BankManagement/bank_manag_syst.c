#include<stdio.h>
#include<string.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

const char* ACCOUNT_FILE= "account.dat";

struct Account    // typedef struct 
{
char name[50];
int acc_no;
float balance;
};

int main()
{
int choice;
while(1)
{
printf("\n\n *********** Bank Management System ***********");
printf("\n1. Create Account");
printf("\n2. Deposit Money");
printf("\n3. Withdraw Money");
printf("\n4. Check Balance");
printf("\n5. Exit");
printf("\nEnter your choice: ");
scanf("%d", &choice);

switch (choice)
{
case 1:
create_account();
break;

case 2:
deposit_money();
break;

case 3:
withdraw_money();
break;

case 4:
check_balance();
break;

case 5:
printf("\nClosing the Bank. Thanks for your visit !!\n");
break;

default:
printf("\nInvalid Choice!!");
break;

}
}
return 0;
}

// -------- Defining Functions ---------
void clear_stdin_buffer()
{
while(getchar()!='\n');
}

void create_account()
{
printf("\n------ Creating Account ------\n");

struct Account acc, tmp;    // Account acc;

FILE *file = fopen(ACCOUNT_FILE, "ab+");
if (file == NULL)
{
printf("\nUnable to open file!!");
return;
}
// ------------- Taking name from user --------------
printf("Enter your Name: ");
clear_stdin_buffer();
scanf("%[^\n]",acc.name);

if(strlen(acc.name)==0)
{
printf("Name required\n");
return;
}


// --------------- Taking Account number ---------------
printf("Enter Your Account number: ");
scanf("%d",&acc.acc_no);
acc.balance = 0;

fwrite(&acc, sizeof(acc), 1, file);
fclose(file);
printf("\nAccount created successfully!!");
}
void deposit_money()
{
printf("\n------ Depositing Money ------\n");
FILE *file = fopen(ACCOUNT_FILE, "rb+");
if (file == NULL)
{
printf("\nUnable to open file!!");
return;
}
struct Account acc_r;
int acc_no;
float money;
printf("Enter your account number: ");
scanf("%d", &acc_no);
printf("Enter amount to deposit: ");
scanf("%f", &money);
while(fread(&acc_r, sizeof(acc_r), 1, file))
{
if (acc_r.acc_no == acc_no)
{
acc_r.balance += money;
fseek(file, -sizeof(acc_r), SEEK_CUR); // overwrite karne ke liye cursor move 
fwrite(&acc_r, sizeof(acc_r), 1, file);
fclose(file);
printf("Successfully deposited Rs. %.2f . New Balance is Rs. %.2f", money, acc_r.balance);
return;
} // if close
} //while close
fclose(file);
printf("Money could not be deposited as Account no. %d was not found in records.", acc_no);


}

void withdraw_money()
{
printf("\n------- Withdrawing Money -------\n");
FILE *file= fopen(ACCOUNT_FILE, "rb+");
if (file == NULL)
{
printf("\nUnable to open the account file!!");
return;
} // if close
int acc_no;
float money;
struct Account acc_r;
printf("Enter your account number: ");
scanf("%d", &acc_no);
printf("Enter the amount you wish to withdraw: ");
scanf("%f", &money);

while(fread(&acc_r, sizeof(acc_r),1 , file))
{
if (acc_r.acc_no == acc_no)
{
if (acc_r.balance >= money)
{
acc_r.balance -= money;
fseek(file, -sizeof(acc_r), SEEK_CUR);
fwrite(&acc_r, sizeof(acc_r), 1, file);
printf("Successfully withdrawn Rs. %.2f . Remaining balance is Rs. %.2f .", money,acc_r.balance);
}
else
{
printf("Insufficient balance!");
}
fclose(file);
return;
} //1st if
} //while close
} //void

void check_balance()
{
printf("\n------- Check Balance -------\n");
FILE *file = fopen(ACCOUNT_FILE, "rb");
if (file == NULL)
{
printf("\nUnable to open file!!");
return;
}

struct Account acc_read;
int acc_no;
printf("Enter your account number: ");
scanf("%d", &acc_no);
while(fread(&acc_read, sizeof(acc_read), 1, file))
{
if (acc_read.acc_no==acc_no)
{
printf("\n Your current balance is Rs. %.2f", acc_read.balance);
fclose(file);
return;
}
} //while end
fclose(file);
printf("\nAccount No: %d was not found.\n", acc_no);

}


