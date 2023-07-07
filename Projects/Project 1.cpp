#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
struct phoneBookContact { // phoneBookContact definition
	long int ID;// define integer ID
    char firstName[21];//define string for firstName
    char lastName[21];//define string for lastName
    long long int mobileNumber;
	//define long (integer can hold a maximum of 10 digits + sign ) for mobileNumber
}Contacts, temporary;//end struct phoneBookContact
//struct phoneBookContact Contacts;//new type name for phoneBookContact
//struct phoneBookContacts temporary;//new type name for phoneBookContact
FILE *fPtr;// global declaration for a file pointer
/*typedef struct
{
	int ID;
	char *firstName;
	char *lastName;
	long int phoneNumber;
} Contacts;*/
void startOfProgram();//welcome + change CMD back/foreground
void menuBox();//print a menu box containing options
void menuCategories();//receive charcter to continue
void contactsList();//view full list of contacts
void contactEntry();//add contacts
void contactRevision();//revise(edit) contacts
void deleteContacts();// delete contact information
void searchNumber();//search through contacts
void deleteContact();//delete individual contacts
void deleteEntireFile();//delete entire file
int main ( void )
{
	system("color 70");/*system("color 10f")/("help"); shows a list of prompts for screen
	& font color this call can be made to anywhere in the program to change the colors
	of every page of the program which can improve the programs visual features.*/
	startOfProgram();//start program execution
}//end function main
void startOfProgram()
{
	char choice;//initialize choice as a character
	printf("%s%s","Hello. Welcome to this program.\n",
		   "press the RETURN key to enter menu.\n" );
		/*in c to print strings of characters you can use one statement for %s
		and other corresponding statements will precede in order inside double
		quotation marks: this can impact coding in a great way*/
		switch( choice = getch() ){
		  case'\r':
            Sleep( 3000 );
			system("cls");
			menuBox();
			break;
	      default:
            Sleep( 3000 );
			system("cls");
			printf( "%s\a\a", strerror( 1 ) ) ;
			Sleep( 3000 );
			system("cls");
			startOfProgram();
		}//end switch cases
}//end function startOfProgram
void menuBox()
{
	system("cls");
	int i, j;/*counter-->since we are working with an array size_t(which is equivalent to
	unsigned int and the same conversion specifier %u) is better suited.*/
	//declare a pointer to a string for which the statements are constant and cannot change
	const char *mainmenu[] = {"View Contacts List","Add a Contact", "Edit a Contact",
	"Delete a Contact", "Search Contacts by Number","Exit"};
	/*for the characters below ASCII codes can be used along side Run:<charmap>	once its
	opened characters could be chosen for printing by using th key strokes or through
	changing from character set unicode to dos and converting hexadecimal to decimal.*/
	printf("\t\t\t%c", 201 );//upper left corner
	for( i = 0; i < 36; ++i ) {// menu header
		printf("%c", 205 );
	}//end for
	printf("%c\n", 187 );//upper right corner
	for( j = 0; j < 6; ++j ) { 
		printf("\t\t\t%c%6d.%-29s%c\n", 186, j + 1, mainmenu[ j ], 186 );
	}//end for
	for( i = 0; i < 5; ++i ) {// side lines
		printf("\t\t\t%c\t",186 );
		printf("\t\t\t     %c\t\t\n", 186 );
	}//end for
	printf("\t\t\t%c", 200 );//lower left corner
	for( i = 0; i < 36; ++i ) {
		printf("%c", 205 );
	}
	printf("%c\n", 188 );//lower right corner
	time_t t;// not a primitive datatype
    time(&t);// special pre-determined function call to time header
    printf("\n\t\t\t\t%s", ctime(&t)); // print string consistent of time & date
    puts("");// skip a line ==> printf("\n");
    menuCategories();
}
void menuCategories()
{
	int mainMenu;
	char choice;
	switch( choice = getchar() ) {
		case'1':
			contactsList();
			break;
		case'2':
			contactEntry();
			break;
		case'3':
			contactRevision();
			break;
		case'4':
			deleteContacts();
			break;
		case'5':
			searchNumber();
			break;
		case'6':
			exit(1);// exit returns value 1
		default:
			menuCategories();//go back to the begining of previous category
			break;// for the default case break is optional.
	}//end switch                                                       
}// end function menuCategories
void contactEntry()
{
	system("cls");
	//FILE *fPtr;
	//struct phoneBookContact Contacts;
	srand( time( NULL ) );
	long int ID = 1 + rand() % 100000000;//generate a random number between [1 - 100000000]
	Contacts.ID = ID;//store randomly generated ID as a characteristic of Contacts.ID
	if ( ( fPtr = fopen( "Contacts.txt", "a+" ) ) == NULL ) {
		puts("File could not be opened");
	}//end if
	else {
		puts("Enter First Name, Last Name and Phone Number respectively.");
		puts("Enter Return key to end input:");
		scanf("%20s%20s%011lld", &Contacts.firstName, &Contacts.lastName, 
			&Contacts.mobileNumber);//scan data to be put into file sequentially 
		fprintf( fPtr , "%s\t%s\t%011lld\t%ld\n", Contacts.firstName,
			Contacts.lastName, Contacts.mobileNumber , Contacts.ID);/*print every 
		argument scanned by scanf into *fPtr's address*/  
        fclose( fPtr );// close txt file of type fPtr 
	}//end else
	Sleep( 2000 );
	system("cls");
	puts("Enter B to go back to Add more contacts or M for Menu:");
	char option;
	while( option = getchar() ) {
		switch( option ) {
			case'B':
			case'b':
				contactEntry();
				break;
			case'M':
			case'm':
				menuBox();
				break;
		}//end switch
	}//end while
}//end function contactEntry
void contactsList()
{
	//FILE *fPtr;
	//struct phoneBookContact Contacts;
   	char ch;
   	if ( ( fPtr = fopen( "Contacts.txt", "r" ) ) == NULL) {/*the file is opened to be read from*/
    	  puts("File could not be opened / File does not exist.");
   	}//end if
   	else {
   		printf("%s %s\t%s\t%s\n","F.Name"," L.Name", "Phone Number", "ID");
   		while( ( ch = fgetc ( fPtr ) ) != EOF ) {
   			printf("%c", ch);
		}// end while
		fclose( fPtr );// close txt file of type fPtr
   }// end else
   Sleep( 15000 );
   system("cls");
   char option;
   puts("Enter M for Menu:");
	while( option = getchar() ) {
		switch( option ) {
			case'M':
			case'm':
				menuBox();
				break;
		}//end switch
	}//end while
}// end function contactsList
void contactRevision()
{
	//int ID;
	char fName[21], firstName[21], lastName[21], choice;	
	//struct phoneBookContact Contacts;
	//struct phoneBookContact temp;
	FILE *newFile;
	newFile = fopen("temp.txt","a");
	if ( (fPtr = fopen("Contacts.txt", "r+") ) == NULL ) {
		puts("No file could be found!");
		exit(1);
	}//end if
	else{
		puts("Enter Name of the contact you wish to edit:\n"
			"(Keep in mind that the maximum length of characters cannot exceed 20.)");
		scanf("%20s", &fName );
		while( fscanf( fPtr ,"%20s\t%20s\t%011lld\t%ld\n", &Contacts.firstName, &Contacts.lastName,
				 &Contacts.mobileNumber , &Contacts.ID ) != EOF ) {
			if( strcmpi( Contacts.firstName, fName ) == 0 ) {
				printf("%s%s%s","To edit information enter\n1-for First Name, ",
						"2-for Last Name & ", "3-for Phone Number\n");
				choice = getch();
				switch( choice ) {
				case'1':
					Sleep(2000);
					system("cls");
					puts("Enter new FirstName:");
					scanf("%20s", &temporary.firstName );
					fprintf( newFile ,"%s\t%s\t%011lld\t%ld\n", temporary.firstName, Contacts.lastName,
					Contacts.mobileNumber, Contacts.ID );
					system("cls");
					printf("Changes saved successfully!");
					break;
				case'2':
					Sleep(2000);
					system("cls");
					puts("Enter new LastName:");
					scanf("%20s", &temporary.lastName );
					fprintf( newFile ,"%s\t%s\t%011lld\t%d\n", Contacts.firstName, temporary.lastName,
					Contacts.mobileNumber, Contacts.ID );
					system("cls");
					printf("Changes saved successfully!");
					break;
				case'3':
					Sleep(2000);
					system("cls");
					puts("Enter new PhoneNumber:");
					scanf("%011lld", &temporary.mobileNumber );
					fprintf( newFile ,"%s\t%s\t%011lld\t%d\n", Contacts.firstName,
					Contacts.lastName, temporary.mobileNumber, Contacts.ID );
					system("cls");
					printf("Changes saved successfully!");
					break;
				}//end switch
			}//end if
			else{
				fprintf( newFile ,"%s\t%s\t%011lld\t%d\n", Contacts.firstName, 
					Contacts.lastName, Contacts.mobileNumber, Contacts.ID );
			}//end else
		}//end while
	fclose(fPtr);
	fclose(newFile);
	remove("Contacts.txt");
	rename("temp.txt","Contacts.txt");
	}//end else
	Sleep( 2000 );
	system("cls");
	puts("Enter B to go back to Update other contacts or M for Menu:");
	char option;
	while( option = getchar() ) {
		switch( option ) {
			case'B':
			case'b':
				system("cls");
				contactRevision();
				break;
			case'M':
			case'm':
				menuBox();
				break;
		}//end switch
	}//end while
}//end function contactRevision
void deleteContacts()
{
	char choice;//initialize a character for menu or options
	//FILE *fPtr;// *fPtr is a file pointer
	printf("To delete an individuals information enter 1 and to delete entire phone book enter 2:\n");
	while( ( choice = getchar() ) != EOF ) {
		switch ( choice ) {
			case'1':
				Sleep(1000);
				system("cls");
				deleteContact();
				break;
			case'2':
				Sleep(2000);
				system("cls");
				deleteEntireFile();		
		}//end switch
	}//end while
}//end function deleteContacts
void searchNumber()
{
	int i;
	long long int phoneNumber;
	system("cls");
	//FILE *fPtr;// *fPtr is a file pointer
	//struct phoneBookContact Contacts;
	if( ( fPtr = fopen( "Contacts.txt", "r" ) ) == NULL ) {/*the file is opened for reading*/
		puts("Can't find a file to search in.");
	}//end if
	else {
		puts("Enter PhoneNumber");
		scanf("%011lld", &phoneNumber );
		system("cls");
		printf("\n\n\t\t\t\tPlease wait until the search is completed!\n\t\t\t\t\t\t");
		for( i = 0; i < 10; ++i ) {
			printf("%c", 219 );
			Sleep( 1000 );
		}// end for
		Sleep(500);//this one is only for the sake of coding convenience
		system("cls");
		while( fscanf( fPtr, "%s\t%s\t%011lld\t%d\n", &Contacts.firstName, &Contacts.lastName,
				&Contacts.mobileNumber, &Contacts.ID ) != EOF ) {
			if( Contacts.mobileNumber == phoneNumber  ) {
				printf("FirstName: %s\nLastName: %s\nPhoneNumber: %011lld\n", 
					Contacts.firstName, Contacts.lastName, Contacts.mobileNumber );
				Sleep(7500);
			}//end if
		}//end while
	fclose( fPtr );// close txt file of type fPtr
	}//end else
	Sleep( 2000 );
	system("cls");
	puts("Enter B to go back to Search for another contact or M for Menu:");
	char option;
	while( option = getchar() ) {
		switch( option ) {
			case'B':
			case'b':
				searchNumber();
				break;
			case'M':
			case'm':
				menuBox();
				break;
		}//end switch
	}//end while
}//end function searchNumber
/*void searchNumber()
{
	int i;
	char name[21];
	system("cls");
	//FILE *fPtr;// *fPtr is a file pointer
	//struct phoneBookContact Contacts;
	if( ( fPtr = fopen( "Contacts.txt", "r" ) ) == NULL ) {//the file is opened for reading
		puts("Can't find a file to search in.");
	}//end if
	else {
		puts("Enter First name");
		scanf("%s", &name );
		system("cls");
		printf("\n\n\t\t\t\tPlease wait until the search is completed!\n\t\t\t\t\t\t");
		for( i = 0; i < 10; ++i ) {
			printf("%c", 219 );
			Sleep( 1000 );
		}// end for
		Sleep(500);//this one is only for the sake of coding convenience
		system("cls");
		while( fscanf( fPtr, "%20s\t%20s\t%011lld\t%d\n", &Contacts.firstName, &Contacts.lastName,
				&Contacts.mobileNumber, &Contacts.ID ) != EOF ) {
			if( strcmpi( Contacts.firstName, name ) == 0 ) {
				printf("FirstName: %s\nLastName: %s\nPhoneNumber: %011lld\nID: %d", 
					Contacts.firstName, Contacts.lastName, Contacts.mobileNumber, Contacts.ID);
				Sleep(7500);
			}//end if
		}//end while
	fclose( fPtr );// close txt file of type fPtr
	}//end else
	Sleep( 2000 );
	system("cls");
	puts("Enter B to go back to Search for another contact or M for Menu:");
	char option;
	while( option = getchar() ) {
		switch( option ) {
			case'B':
			case'b':
				searchNumber();
				break;
			case'M':
			case'm':
				menuBox();
				break;
		}//end switch
	}//end while
}//end function searchNumber*/
void deleteContact()
{
	char option, fName[21] ; //declare option character
	//FILE *fPtr;
	FILE *newFile;//declare a new file for editing
	fPtr = fopen("Contacts.txt", "r");
	//struct phoneBookContact temp;
		if( fPtr == NULL ) {//the file is opened for reading
			puts("No data exists in file!");
			Sleep(1000);
			exit(1);
		}//end if
		else {
			newFile = fopen("temp.txt", "w");
			if( newFile == NULL) {/*Items are written to the 
			file and if file does not exist a new file is created*/
				puts("Error opening file");
				exit(1);
			}//end if/*not neccesary*/
			else{
				puts("Enter the Name of the contact you wish to delete:");
				scanf("%20s", &fName );
				while( fscanf( fPtr, "%20s\t%20s\t%011lld\t%d\n", &Contacts.firstName, 
				&Contacts.lastName, &Contacts.mobileNumber, &Contacts.ID ) != EOF ) {
					if( strcmpi( fName , Contacts.firstName ) != 0 ) {
						fprintf( newFile,"%s\t%s\t%011lld\t%d\n", Contacts.firstName,
							Contacts.lastName, Contacts.mobileNumber, Contacts.ID );
					}//end if
				}//end while
			}//end else
		fclose(fPtr);//closes original file
		fclose(newFile);//closes new file
		remove("Contacts.txt");//removes original file
		rename("temp.txt","Contacts.txt");//in rename("","") the first part shows the current
		//path and the second is your desired destination and name		
		}//end else
	Sleep( 4000 );
	system("cls");
	puts("Enter B to go back to Delete more contacts or M for Menu:");
	while( option = getchar() ) {
		switch( option ) {
			case'B':
			case'b':
				system("cls");
				deleteContacts();
				break;
			case'M':
			case'm':
				menuBox();
				break;
		}//end switch
	}//end while
}//end function deleteContact
void deleteEntireFile()
{
	char choice;// character for optional choosing
	Sleep(2000);
	system("cls");
	puts("Are you sure you want to delete the entire file?\a ""(Y for yes and N for no: )");
	fclose( fPtr );//before deleting the file it must first be closed.
	while ( choice = getchar() ) {
		switch( choice ) {
			case'Y':
			case'y':
				Sleep(2000);
				remove("Contacts.txt");
				system("cls");
				puts("Entire file deleted!");
				Sleep(2000);
				system("cls");
				Sleep(2000);
				menuBox();
				break;
			case'N':
			case'n':
				deleteContacts();	
				break;
		}//end switch
	}//end while
}//end function deleteEntireFile
/*
void sortAscending()
{

}//end function sortAscending
void sortDescending()
{

}//end function sortDescending
void sortAlphaAscending()
{

}//end function sortAlphaAscending()
void void sortAlphaDescending()
{

}//end function sortAlphaDescending()
*/
/*This program was developed by ©I-am-Programming-the-World*/