/***************************************************************************
 *   Copyright (C) $2023$ by $Koskela Jaakko$   *
 *   $koskela63z@gmail.com$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
     files version 2.0

 2.  DESCRIPTION
     simple program with updates from C-course

 3.  VERSIONS
       Original:
         1.0.2023 / jaakko koskela

       Version history:
        1.0 not released
**********************************************************************/

/*-------------------------------------------------------------------*
 *    HEADER FILES                                                    *
 *--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*-------------------------------------------------------------------*
 *    GLOBAL VARIABLES AND CONSTANTS                                  *
 *--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define MAX 100

/* Global variables */

/* Global structures */

/*-------------------------------------------------------------------*
 *    FUNCTION PROTOTYPES                                             *
 *--------------------------------------------------------------------*/
void display_menu(void);
char ask_command(void);
char read_string(char s[]);
void print_string(char s[]);
int count_vowels(char s[]);
int count_consonants(char s[]);
char to_lower(char s[]);
char to_upper(char s[]);
void read_file(char s[]);
void write_file(char s[]);
/*********************************************************************
 *    MAIN PROGRAM                                                      *
 **********************************************************************/
int main()
{
    {
    char* banner = "   _____                       _      \n"
                   "  / ____|                     (_)     \n"
                   " | (___  _ __   __ _ _ __ ___ _  ___ \n"
                   "  \\___ \\| '_ \\ / _` | '__/ __| |/ _ \\\n"
                   "  ____) | |_) | (_| | | | (__| |  __/\n"
                   " |_____/| .__/ \\__,_|_|  \\___|_|\\___|\n"
                   "        | |                           \n"
                   "        |_|                           ";

    printf("%s\n", banner);
    printf("\n");
    }
    char string[100] = "testi";
    char statement;
    display_menu();
    statement = ask_command();

    while (statement != 'X' && statement != 'x')
    {

        switch (statement)
        {
        case 'A':
        case 'a':
            printf("Number of vocals: %d\n", count_vowels(string));
            printf("Give next command:\n ");
            break;
        case 'B':
        case 'b':
            printf("Number of consonants: %d\n", count_consonants(string));
            printf("Give next command:\n ");
            break;
        case 'C':
        case 'c':
            to_upper(string);
            printf("Converted String into uppercase: %d \n", to_upper(string));
            printf("Give next command: \n");
            break;
        case 'D':
        case 'd':
            to_lower(string);
            printf("Converted String into lowercase: %d \n", to_lower(string));
            printf("Give next command:\n ");
            break;
        case 'E':
        case 'e':
            print_string(string);
            printf("Give next command:\n ");
            break;
        case 'F':
        case 'f':
            read_string(string);
            printf("Give next command:\n ");
            break;
        case 'G':
        case 'g':
            read_file(string);
            printf("Give next command:\n ");
            break;
        case 'H':
        case 'h':
            write_file(string);
            printf("Give next command:\n ");
            break;
        case 'M':
        case 'm':
            display_menu();
            break;
        default:
            printf("\n");
            printf("Give right command from menu. \n");
            break;
        
        }
        statement = ask_command();
    }
    return 0;
}
/* end of main */

/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: display_menu
 DESCRIPTION: shows menu of program
    Input:no inputs
    Output: used for call other functions.
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void display_menu(void)
{
    printf(" A) Count the number of vowels in string \n");
    printf(" B) Count the number of consonants in the string \n");
    printf(" C) Convert the string to uppercase \n");
    printf(" D) Convert the string to lowercase \n");
    printf(" E) Display the current string \n");
    printf(" F) Enter a another string \n");
    printf(" G) Read string from file \n");
    printf(" H) Write string to file \n");
    printf("\n");
    printf(" M) Dispaly this menu \n");
    printf(" X) Exit program\n ");
    printf("\n");
    printf("Give some command from menu\n ");
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: ask_command
 DESCRIPTION: asks command from the user
    Input: max value of string which is defined already
    Output:No output in traditional meaning. 
  Used global variables: max value 100
 REMARKS when using this function: test users command inside
*********************************************************************/
char ask_command(void)
{
    char str[MAX];

    fgets(str, MAX, stdin);
    
    int temp_character = to_upper(str);
    
    if(str[0] == 'A' || str[0] == 'B' || str[0] == 'C' || str[0] == 'D'|| 
       str[0] == 'E' || str[0] == 'F' || str[0] == 'G' || str[0] == 'H'|| 
       str[0] == 'M' || str[0] == 'X')
    {
       return str[0];
    }   
      
    
    else
    {
        display_menu();
    }
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: read_string
 DESCRIPTION: asks string
    Input: differents chars, which is word and string in this program
    Output:does not print anything, but it saves words as a string
  Used global variables: MAX value 100.
 REMARKS when using this function:tests users command inside.
*********************************************************************/
char read_string(char s[])
{
    printf("Give String: ");
    fgets(s, MAX, stdin);
    s[strcspn(s, "\n")] = '\0';
    
    int temp_character = to_upper(s);
    
    if (s[0] >= 'A' && s[0] <= 'Z')
    {
        return s[0];
    }
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: print_string
 DESCRIPTION: prints string
    Input: string, which have been saved into program
    Output:prints string for the user to see.
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void print_string(char s[])
{
    printf("%s\n", s);
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:  count_vowels
 DESCRIPTION: counts vowels in string
    Input:  string you wrote
    Output: number of vowels in string
  Used global variables:
 REMARKS when using this function:vovewls; a,e,i,o,u,y
*********************************************************************/
int count_vowels(char s[])
{
    int count = 0;
    int i;
    int temp_character = to_lower(s);

    for (i = 0; s[i] != '\0'; i++)
    {
        int k = s[i];
        if (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u' || k == 'y')
        {
            count++;
        }
    }

    return count;
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:  count_consonants
 DESCRIPTION: counts consonants in string
    Input:  string you wrote
    Output: number of consonants in string
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
int count_consonants(char s[])
{
    int count = 0;
    int j;
    int temp_character = to_lower(s);
    for (j = 0; s[j] != '\0'; j++)
    {
        int c = s[j];
        if (c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'h' ||
            c == 'j' || c == 'm' || c == 'n' || c == 'l' || c == 'p' || 
            c == 'r' || c == 's' || c == 'g' || c == 't' || c == 'q' || 
            c == 'v' || c == 'x' || c == 'z')
        {
            count++;
        }
    }
    return count;
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:  to_lower
 DESCRIPTION: makes letters small letters
    Input:  string you wrote
    Output: string as STRING
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
char to_lower(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        s[i] = tolower(s[i]);
    }
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:  to_upper
 DESCRIPTION: makes letters big letters
    Input:  string you wrote
    Output: STRING as string
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
char to_upper(char s[])
{
    int j;
    for (j = 0; s[j] != '\0'; j++)
    {
        s[j] = toupper(s[j]);
    }
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:  read_file
 DESCRIPTION: reads file
    Input:  string you have saved
    Output: string from file
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void read_file(char s[])
{
    FILE *fPointer;
    char filename[] = "example.txt";

    fPointer = fopen(filename, "r");
    if (fPointer == NULL)
    {
        printf("Failed to open file %s\n", filename);
        return;
    }
    (fgets(s, 1000, fPointer));

    fclose(fPointer);
}
/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:  write_file
 DESCRIPTION: writes string into file
    Input:  string you have given for program
    Output: string you saved into
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void write_file(char s[])
{

    FILE *fPointer;
    fPointer = fopen("example.txt", "w");
    if (fPointer == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    fprintf(fPointer, "%s", s);
    fclose(fPointer);
}

