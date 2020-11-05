#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define Alphabet ((C >= 97 && C <= 122 )|| (C >= 65 && C <= 90))
#define notAlpabet !Alphabet
#define whitespace 32
#define dash 45
#define backspace 8
#define enter 13
#define MAXCHAR 20
//global variable
char Global_CharArr[MAXCHAR];

const char CharacterToReturn(int i, int j,char string[]);
const char* stringToReturn(char* string);

const char CharacterToReturn(int i, int j, char string[]){//Sub function for checking input
    char UpperCase[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    char LowerCase[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    char C;

    C = getch();

    if(C == dash || C == whitespace){//checks if input is whitespace or dash
        if(string[j-1] == dash || string[j-1] == whitespace )//restrict the dash or whitespace to one to avoid multipe input of dash and and whitespace
            return 0;
        else if(Alphabet)//for lowering the first char if double space and dash
            return C ;
    }

    else if(C == enter)//check if input is enter
        return 1;

    else if(C == backspace)//check if input is backspace
        return -1;

    else if(notAlpabet && (C != whitespace || C != enter))//Checks if input is symbols
        return 0;

    else if(Alphabet){//Auto upercase and lowercase characters
        if(i == 0){
            for(int x = 0; x < 27; x++){
                if(C == LowerCase[x])
                    C = UpperCase[x];
                else if(C == UpperCase[x])
                    continue;
            }
        }
        else if( i != 0){
            for(int x = 0; x < 27; x++){
                if(C == UpperCase[x])
                    C = LowerCase[x];
            }
        }
    }
    return C;
}

const char* stringToReturn(char* string){//Main function
    int temp, Capital_indicator, flag;

    for(int x = 0; x < MAXCHAR; x++){
        Capital_indicator = x;

        if(flag == 0)
            Capital_indicator = flag;

        temp = CharacterToReturn(Capital_indicator, x, string);//Checks the input

        if(temp == whitespace || temp == dash){//Sets whitespace or dash to print/add to string
            flag = 0;
        }
        else{//Reinitialize white space and dash
            flag = 1;
        }
        if(temp == 1){//Exit the function
            string[x] = '\0';
            break;
        }
        if(temp == 0 && x >= 0){//Ignores symbols
            if( x >= 0){
                printf("%c", whitespace);
                printf("%c", backspace);
                x--;
            }
        }
        else if(temp == -1){//Delete char
            if(x == 0){
                x--;
            }
            if(x >= 0){
                x--;
                string[x] = '\0';
                printf("%c", backspace);
                printf("%c", whitespace);
                printf("%c", backspace);
                x--;
            }
        }
        else{//copy the temp char to char arry
            string[x] = temp;
            printf("%c", string[x]);
        }
    }
    string[MAXCHAR] = '\0';
    return 0;
}
int main(){
    char CharArr[MAXCHAR] = "";

    system("cls");
    printf("Double space( ) or dash(-) for lowercase\n");
    printf("e.g., Name-Name = Name-name\n\n");
    printf("Input: ");
    stringToReturn(CharArr);// Good for function return/local variable
    strcpy(Global_CharArr, CharArr);// Good for Global variable
    printf("\nlocal  - %s", CharArr);
    printf("\nGlobal - %s", Global_CharArr);
    printf("\nOutput - ");
    for(int x =  0 ; CharArr[x] != '\0'; x++){//Too make sure that the deleted character is NULL
        printf("%c", CharArr[x]);
    }
    getch();
}
