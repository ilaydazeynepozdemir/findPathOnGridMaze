/*##################################################################*/
/*HW07_<IlaydaZeynep>_<Ozdemir>_<131044022>_part1.c                 */
/*_____________________________________                             */
/*Written by Ilayda Ozdemir                                         */
/*Input:                                                            */
/*  -string that into wish_to_find                                  */ 
/*  -word that find                                                 */
/*Output:                                                           */
/*  -Total number of word in string                                 */
/*##################################################################*/

#include <stdio.h>
#include <string.h>

int find_size(const char *string);
int char_number(const char *string, const char *wish_to_find);

/***************************************************************/
/*                       MAIN                                  */
/***************************************************************/

int main(void)
{
    int size_str,
        size_str_2,/*'\n' olmadigindaki boyutunu bulmak icin*/
        size_find_word,
        how_many_times;
    char str[100];
    char str_find[20];



    printf("\nEnter the words or sentence »\n");
    fgets(str,100,stdin);
/*fgets fonksiyonu '\n' i de aldigi icin onun yerine null koyuyorum*/     
    size_str=find_size(str);
    str[size_str-1]='\0';
/*******************************************************************/    
    size_str_2=find_size(str);  
    printf("«««size of string %d»»»\n",size_str);
    
    
    printf("\nEnter the word that wish find »\n");
    fgets(str_find,20,stdin);
/*fgets fonksiyonu '\n' i de aldigi icin onun yerine null koyuyorum*/    
    size_find_word=find_size(str_find);
    str_find[size_find_word-1]='\0';
/*******************************************************************/     
    how_many_times=char_number(str,str_find);
 
    printf("«««String has '%s' %d times»»»\n\n",str_find,how_many_times);
    
    return 0;
}

/********************************************************/
/*  this function find size like a strlen function      */
/********************************************************/
/*recursive*/
int find_size(const char *string)
{
    int size;
    if(string[0]=='\0')/*durdurucu unsur NULL*/
        size=0;
        
    else
    {
        size=find_size(&string[1]);
        ++size; 
    }
    
         
return size;
}

/********************************************************/
/*this function find how many times a given string is   */
/*used in a given string                                */
/********************************************************/
/*iterative*/
int char_number(const char *string, const char *wish_to_find)
{
int size_word=find_size(wish_to_find);
int n=0,i=0,k=0,count=0;
char temp[20];


    while(string[i] !='\0')/*string sonuna kadar dongu doner*/
    {
        
        if(string[i] ==' ' || string[i+1]=='\0' ||  string[i] =='.')
        {
            /*if » son kelimeden sonra bosluk olursa diye*/
            if((string[i] ==' ' && string[i+1]=='\0') || (string[i] =='.' && string[i+1]=='\0'));
            /*else if » string[i+1]=='\0' bu kosul son kelimeyi kontrol etmek icin*/
            else if(string[i+1]=='\0')/*n ile yaptigim donguyu i'ye baglı kurdugum icin*/
                i=i+1;           /*i'yi burada i+1'e esitledim*/
                

            k=0;
            for(n=i-size_word; n<i; ++n)
            {
                temp[k]=string[n];
                ++k;
            }

            if(strcmp(temp,wish_to_find) == 0)/*cumle icindeki kelimeler ile aradıgımız kelimeyi karsılastırdım*/
                ++count;  /*kac defa oldugunu tutan count*/
       }   
    
    ++i;
    }
return count;
}


/*##################################################################*/
/*    End of HW07_<IlaydaZeynep>_<Ozdemir>_<131044022>_part1.c      */
/*##################################################################*/
