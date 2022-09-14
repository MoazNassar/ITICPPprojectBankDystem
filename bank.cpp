
/**************************************************** Library Inclusions *************************************************************/

#include<iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

#include"STD_TYPES.h"

/************************************************** Self Files Inclusions ************************************************************/
#include"linkedlist.h"
#include"bank.h"  


/*Variable To Store That The Admin Password is Valid.*/
uint16 Global_uint8bankCheck = 0;		

void bankSystem_VoidAdminCheck()
{
	/*Variable to count down the username and Password Entering trials*/
	static uint16 Local_uint8bankTrials = 0;
	/*Variable to scan in it the username and Password entered by the admin*/
	uint16 Local_uint16bankAdminPassword = 0;
	uint8 Local_uint8bankAdminUsername [100] ;
	/*Clearing the Password Validity Flag*/
	Global_uint8bankCheck = 0;
	/*Reset the Number of the Password trials*/
	Local_uint8bankTrials = BANK_SYSTEM_MAX_TRIALS;
	 
	 
	while((Local_uint8bankTrials !=0 ) && (Global_uint8bankCheck == 0))
	{
		/*Scaning from the Admin the username*/
		 cout<<"Please Enter The Admin Username : "<<endl ;
		 cin >> Local_uint8bankAdminUsername;
		/*Scaning from the Admin the Password*/
		 cout<<"Please Enter The Admin Password : "<<endl ;
		 cin >> Local_uint16bankAdminPassword;
		 
		/*Checking if the username and Password valid or not*/
		if( (BANK_SYSTEM_ADMIN_PASSWORD == Local_uint16bankAdminPassword) )
		{
			/*Firing a Flag that the password Checked successfully and valid*/
			Global_uint8bankCheck = BANK_SYSTEM_VALID;
		}
		else
		{
		 	/*Printing an Error message that the password entered is incorrect*/
			cout <<"The Password or username is incorrect, Please Try Again."<<endl ;
		}
		/*Decrement the number of password Entering Trials*/		
		 Local_uint8bankTrials--;
	}
}

void bankSystem_VoidAdminAddNewAccountRecord()
 {
	/************************************ Scaning the new Account ID and check its validity *****************************************/
	/*Local Variable to gnerate the account ID */
	 static uint64  Local_uint8bankSystemNewID = 1000000000;
	/*Printing a bank account id*/
	cout<<" bank account ID is : "<< Local_uint8bankSystemNewID << endl;
	
	 /*Local Variable to gnerate the password*/
	 uint16  Local_uint8bankSystemNewIDPass = rand();
	 cout<<" bank account PASSWORD is : "<<Local_uint8bankSystemNewIDPass<<endl;
	 //uint8  Local_uint8bankSystemstatus[50] = "active";
	/***************************************** Storing the data of the new account *************************************************/
	
	/*New Dynamic Allocation Struct to store the New account Record*/
	 Node * Local_PStructNewclient = (Node*)malloc(sizeof(Node));
	
	/*Storing the client ID*/
	 Local_PStructNewclient -> uint8BankAccountID = Local_uint8bankSystemNewID;
	 /*Storing the client password*/
	 Local_PStructNewclient -> uint8clientPassword = Local_uint8bankSystemNewIDPass;
	/*Storing the client Full Name*/
	cout<<"Please Enter client Full Name :" ;
    fflush(stdin);
	cin >> Local_PStructNewclient-> uint8clientFullName ;
	fflush(stdin);
	/*Storing the client Full Address*/
	cout<<"Please Enter client FullAddress :" ;
	//getline(cin, Local_PStructNewclient-> uint8clientFullAddress);
	cin >> Local_PStructNewclient-> uint8clientFullAddress ;
	fflush(stdin);
	/*Storing the client Age*/
	cout<<"Please Enter client Age :" ;
	cin >> Local_PStructNewclient-> uint8clientAge ;

	 /*Storing the client National ID*/
	cout<<"Please Enter client National ID :" ;
	cin >> Local_PStructNewclient-> uint8nationalID ;
	 /*Storing the client Balance */
	cout<<"Please Enter client balance :" ;
	cin >> Local_PStructNewclient->uint8clientBalance ;
	cout<<" client balance :"<<Local_PStructNewclient->uint8clientBalance<<endl ;
	
	 /*Storing the client status*/
	cout<<"Please Enter active by default to the status of account :" ;
	cin >> Local_PStructNewclient-> uint8AccountStatus ;
	
	 /*Storing the Guardian client National ID*/
	if ((Local_PStructNewclient->uint8clientAge) < 21 )
	{
	cout<<"Please Enter Guardian client National ID :";
	cin>>Local_PStructNewclient-> uint8GuardianNationalID; 	
	}
	/*Inserting the New account Record in the bank List*/
	 LinkedList_InsertNodeHead(Local_PStructNewclient);
	 
	/******************************************************************************************************************************/
	/*Printing Confirmation message that the client new account Record Added*/
	cout<<"account Records Added successfully."<<endl;
	Local_uint8bankSystemNewID +=1;
 }
 
 
 void bankSystem_VoiduserCheck()
{
	/*Pointer to struct to store the account Address needed to edit*/
	static Node * Local_PStructEditedstatus = NULL;
	/*Variable to scan in it the username and Password entered by the admin*/
	uint16 Local_uint8bankAdminPassword = 0;
	uint32 Local_uint8bankaccountid     = 0;
	/*Clearing the Password Validity Flag*/
	Global_uint8bankCheck = 0;
	 
	while(Global_uint8bankCheck == 0)
	{
		/*Scaning from the user the bank account id*/
		 cout<< "Please Enter The user bank account id : " <<endl ;
		 cin >> Local_uint8bankaccountid;
		/*Scaning from the user the Password*/
		 cout<< "Please Enter The user bank account Password : " <<endl ;
		 cin >> Local_uint8bankAdminPassword;
		 
		/*Checking if the accound id and Password valid or not*/
		if(  (LinkedList_ID_Search(Local_uint8bankaccountid))  ) 
		{
			Local_PStructEditedstatus = LinkedList_ID_Search(Local_uint8bankaccountid);
			if(Local_PStructEditedstatus->uint8clientPassword == Local_uint8bankAdminPassword)
			{
			/*Firing a Flag that the password Checked successfully and valid*/
			Global_uint8bankCheck = BANK_SYSTEM_VALID;
			}
			else {cout<<"The Password is incorrect, Please Try Again. " << endl; }
		}
		else
		{
		 	/*Printing an Error message that the password entered is incorrect*/
			cout<<"The Password or username is incorrect, Please Try Again."<< endl ;
		}
	}
}


void bank_id()
{
	/*Pointer to struct to store the account Address needed to edit*/
	static Node * Local_PStructEditedstatus = NULL;
	/*Variable to scan in it the username and Password entered by the admin*/
	uint64 Local_uint8bankaccountid     = 0;
	/*Clearing the Password Validity Flag*/
	Global_uint8bankCheck = 0;
	 
	while(Global_uint8bankCheck == 0)
	{
		/*Scaning from the user the bank account id*/
		cout<<"Please Enter The user bank account id : "<<endl;
		cin>>Local_uint8bankaccountid;
		
		 
		/*Checking if the accound id and Password valid or not*/
		if(  (LinkedList_ID_Search(Local_uint8bankaccountid))  ) 
		{
			Local_PStructEditedstatus = LinkedList_ID_Search(Local_uint8bankaccountid);
			Global_uint8bankCheck = BANK_SYSTEM_VALID;
			
		}
		else
		{
		 	/*Printing an Error message that the password entered is incorrect*/
			cout<<"The id is incorrect, Please Try Again."<<endl;
		}
	}
}



void bankSystem_VoidAdminEditAccountstatus()
 {	
	/*Pointer to struct to store the account Address needed to edit*/
	 static Node * Local_PStructEditedstatus = NULL;
	/*Variable to store the ID of the account needed to Edit*/
	 uint64  Local_uint8bankSystemNewID = 0;

	/************************************ Scaning the  account ID and check its validity *****************************************/
	/*Printing a message to the admin to enter the account ID*/
	 cout<<"Please Enter bank account ID Needed to Edit:";
	/*Scaning from the Admin the ID of the account needed to edit*/
	 cin>>Local_uint8bankSystemNewID;
	
	/*Checking if the ID Exist or Not*/
	 if(!LinkedList_ID_Search(Local_uint8bankSystemNewID))
	 {
		/*Printing a message to the admin that account ID not found*/
		 cout<<"Sorry This ID is not Found Be sure of the ID \n"<<endl;
		/*Printing a message to the admin to enter the account ID*/
		cout<<"Please Enter bank account ID Needed to Edit:";
		cin>>Local_uint8bankSystemNewID;
	 }
	
	/******************************************** Editing account status Partition **************************************************/
	/*Storing the adresses of the wanted account to edit in a variable after found it*/
	 Local_PStructEditedstatus = LinkedList_ID_Search(Local_uint8bankSystemNewID);
	/*Printing a message to the admin to enter the New account status*/
	cout<<"Please Enter account New status :";
	cin>>Local_PStructEditedstatus-> uint8AccountStatus;
	/*Confirmation message that the account status changed*/
	cout<<"account status Changed Successfully.\n";
 }
 
 
 
 
 void bankSystem_VoidAdmingetcash()
 {	
	/*Pointer to struct to store the account of client Address needed to edit*/
	static Node * Local_PStructEditedbalance = NULL;
	/*Variable to store the ID of the bank account needed to Edit*/
	 uint64   Local_uint8bankSystemNewID=0 ;
	 uint32  Local_uint8getcash = 0;
	/************************************ Scaning the  account ID and check its validity *****************************************/
	/*Printing a message to the admin to enter the bank account ID*/
	 cout<<"Please Enter bank account ID Needed to Edit:";
	/*Scaning from the Admin the ID of the bank account needed to edit*/
	 cin>>Local_uint8bankSystemNewID;
	
	/*Checking if the ID Exist or Not*/
	 if(!LinkedList_ID_Search(Local_uint8bankSystemNewID))
	 {
		/*Printing a message to the admin that bank account ID not found*/
		cout<<"Sorry This ID is not Found Be sure of the ID \n"<<endl;
		/*Printing a message to the admin to enter the bank account ID*/
		cout<<"Please Enter bank account ID Needed to Edit:";
		/*Scaning from the Admin the ID of the bank account needed to edit*/
		cin>>Local_uint8bankSystemNewID;
	 }
	/******************************************** get cash Partition **************************************************/
	/*Storing the adresses of the wanted bank account to edit in a variable after found it*/
	 Local_PStructEditedbalance = LinkedList_ID_Search(Local_uint8bankSystemNewID);
	
	char local[2]="a";
	char local1[2];
	uint16 Local_uint8NameLoopCounter = 0;
	
	
	for(Local_uint8NameLoopCounter = 0; Local_uint8NameLoopCounter < 2; Local_uint8NameLoopCounter++)
	{
		local1[Local_uint8NameLoopCounter] = Local_PStructEditedbalance->uint8AccountStatus[Local_uint8NameLoopCounter];
	}
	
	if (!strcmp(local1, local))
	{
	cout<<"cash is : \n"<<endl<<Local_PStructEditedbalance->uint8clientBalance;
	cout<<"Please Enter amount of cash you wanted to get :";
	cin>> Local_uint8getcash;
	
		if ( (Local_PStructEditedbalance->uint8clientBalance) > Local_uint8getcash  )
		{
		Local_PStructEditedbalance->uint8clientBalance -= Local_uint8getcash;
		
		cout<<"here is your cash and account balance Changed Successfully  ."<<Local_PStructEditedbalance->uint8clientBalance<<endl;
		}
		else{
		cout<<"Please enter amount below than you current balance";
		}
	}
	else
		{
		cout<<"The acount status is not active , please activate it first "<<endl;
		}
 }
 
 void bankSystem_VoidAdmindeposit()
 {	
	/*Pointer to struct to store the account of account Address needed to edit*/
	static Node * Local_PStructEditedbalance = NULL;
	
	/*Variable to store the ID of the bank account needed to Edit*/
	 uint64  Local_uint8bankSystemNewID = 0;
	 uint32  Local_uint8deposit = 0;
	/************************************ Scaning the  account ID and check its validity *****************************************/
	/*Printing a message to the admin to enter the bank account ID*/
	 cout<<"Please Enter bank account ID Needed to Edit:";
	/*Scaning from the Admin the ID of the bank account needed to edit*/
	cin>>Local_uint8bankSystemNewID;
	
	/*Checking if the ID Exist or Not*/
	 if(!LinkedList_ID_Search(Local_uint8bankSystemNewID))
	 {
		/*Printing a message to the admin that bank account ID not found*/
		cout<<"Sorry This ID is not Found Be sure of the ID \n"<<endl;
		/*Printing a message to the admin to enter the bank account ID*/
		cout<<"Please Enter bank account ID Needed to Edit:";
		/*Scaning from the Admin the ID of the bank account needed to edit*/
		cin>>Local_uint8bankSystemNewID;
	 }
	
	/******************************************** deposit Partition **************************************************/
	/*Storing the adresses of the wanted bank account to edit in a variable after found it*/
	 Local_PStructEditedbalance = LinkedList_ID_Search(Local_uint8bankSystemNewID);
	 
	char local[2]="a";
	char local1[2];
	uint16 Local_uint8NameLoopCounter = 0;
	
	
	for(Local_uint8NameLoopCounter = 0; Local_uint8NameLoopCounter < 2; Local_uint8NameLoopCounter++)
	{
		local1[Local_uint8NameLoopCounter] = Local_PStructEditedbalance->uint8AccountStatus[Local_uint8NameLoopCounter];
	}
	
	if (!strcmp(local1, local))
		{
		/*Printing a message to the admin to enter the amount her want to deposit*/
		cout<<"cash is : \n"<<Local_PStructEditedbalance->uint8clientBalance<<endl;
		cout<<"Please Enter amount of cash you wanted to deposit :";
		/*Scaning from the Admin the amount he want to deposit*/
		cin>> Local_uint8deposit;
		Local_PStructEditedbalance->uint8clientBalance += Local_uint8deposit;
	
		/*Confirmation message that the action is done*/
		cout<<"Your account balance Changed Successfully.\n"<<Local_PStructEditedbalance->uint8clientBalance<<endl;
		}
	else
		{
		cout<<"The acount status is not active , please activate it first "<<endl;
		}
 }
 
 
void bankSystem_VoidAdminChangePassword()
  {
	  /*Pointer to struct to store the account Address needed to edit*/
	 static Node * Local_PStructEditedstatus = NULL;
	/*Variable to store the ID of the acount needed to Edit*/
	 uint64  Local_uint8bankSystemNewID = 0;

	/************************************ Scaning the  account ID and check its validity *****************************************/
	/*Printing a message to the admin to enter the account ID*/
	 cout<<"Please Enter bank account ID Needed to Edit:";
	/*Scaning from the Admin the ID of the account needed to edit*/
	 cin>>Local_uint8bankSystemNewID;
	
	/*Checking if the ID Exist or Not*/
	 if(!LinkedList_ID_Search(Local_uint8bankSystemNewID))
	 {
		/*Printing a message to the admin that account id not found*/
		 cout<<"Sorry This ID is not Found Be sure of the ID \n"<<endl;
		 /*Printing a message to the admin to enter the account id*/
		cout<<"Please Enter bank account ID Needed to Edit:";
		/*Scaning from the Admin the ID of the account needed to edit*/
		cin>>Local_uint8bankSystemNewID;
	 }
	
	/******************************************** Editing account password Partition **************************************************/
	
	/*Storing the adresses of the wanted account to edit in a variable after found it*/
	 Local_PStructEditedstatus = LinkedList_ID_Search(Local_uint8bankSystemNewID);
	/*Printing a message to the admin to enter the account New password*/
	cout<<"Please Enter account New password :";
	/*Scaning from the Admin the  the account New password*/
	cin>>Local_PStructEditedstatus-> uint8clientPassword;
				 
	/*Confirmation message that the account password changed*/
	cout<<"account password Changed Successfully.\n"<<endl;
 }


void bankSystem_VoidAdminTransaction()
 {	
	/*Pointer to struct to store the account of client Address needed to transfare money from*/
	static Node * Local_PStructTransactionFrom = NULL;
	/*Variable to store the ID of the bank account needed to transfare money from and to*/
	 uint64   Local_uint8bankSystemFromID = 0;
	 uint32  Local_uint8getcash = 0;
	/************************************ Scaning the  account ID and check its validity *****************************************/
	/*Printing a message to the admin to enter the bank account ID*/
	cout<<"Please Enter bank account ID Needed to transfare money from:";
	/*Scaning from the Admin the ID of the bank account needed to edit*/
	 cin>>Local_uint8bankSystemFromID;
	/*Checking if the ID Exist or Not*/
	 while(!LinkedList_ID_Search(Local_uint8bankSystemFromID) )
	 {
		/*Printing a message to the admin that bank account ID not found*/
		cout<<"Sorry This ID is not Found Be sure of the ID \n"<<endl;
		cout<<"Please Enter bank account ID Needed to transfare money from:";
	
		cin>>Local_uint8bankSystemFromID;
	 }
	/******************************************** get cash Partition **************************************************/
	/*Storing the adresses of the wanted bank account to edit in a variable after found it*/
	Local_PStructTransactionFrom = LinkedList_ID_Search(Local_uint8bankSystemFromID);
	char local[2]="a";
	char local1[2];
	char local2[2];
	uint16 Local_uint8NameLoopCounter = 0;
	for(Local_uint8NameLoopCounter = 0; Local_uint8NameLoopCounter < 2; Local_uint8NameLoopCounter++)
	{
		local1[Local_uint8NameLoopCounter] = Local_PStructTransactionFrom->uint8AccountStatus[Local_uint8NameLoopCounter];
	}
	
	if (!strcmp(local1, local))
	{
		cout<<"Please Enter amount of money you wanted to transfare :";
		cin>> Local_uint8getcash;
		if ( (Local_PStructTransactionFrom->uint8clientBalance) > Local_uint8getcash  )
		{
			Local_PStructTransactionFrom->uint8clientBalance -= Local_uint8getcash;
			cout<<"Ok you can make this transaction and your balance will be : ."<<Local_PStructTransactionFrom->uint8clientBalance;
			cout<<endl;
		}
		else{
			cout<<"Please enter amount below than you current balance";
			goto label;
		}
		/*Printing a message to the admin to enter the bank account ID*/
		cout<<"Please Enter bank account ID Needed to transfare money to:";
		/*Scaning from the Admin the ID of the bank account needed to edit*/
		cin>>Local_uint8bankSystemFromID;
		if(!LinkedList_ID_Search(Local_uint8bankSystemFromID) )
		{
		/*Printing a message to the admin that bank account ID not found*/
			cout<<"Sorry This ID is not Found Be sure of the ID \n"<<endl;
			goto label;
		}
		Local_PStructTransactionFrom = LinkedList_ID_Search(Local_uint8bankSystemFromID);
		for(Local_uint8NameLoopCounter = 0; Local_uint8NameLoopCounter < 2; Local_uint8NameLoopCounter++)
		{
			local2[Local_uint8NameLoopCounter] = Local_PStructTransactionFrom->uint8AccountStatus[Local_uint8NameLoopCounter];
		}
		if (!strcmp(local2, local))
		{
			Local_PStructTransactionFrom->uint8clientBalance += Local_uint8getcash;
			cout<<"Transaction is done Successfully %d .\n"<<Local_PStructTransactionFrom->uint8clientBalance <<endl;
		}
		else
		{
			cout<<"The acount status is not active , please activate it first "<<endl;
		}
	}
	else
	{
	cout<<"The acount status is not active , please activate it first "<<endl;
	label:
	{
	printf("Transaction can not be done\n");
	}
	}
	
 }