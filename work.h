/*
work.h - C-Header für meine eigene
nützlichen Dinge wie zb. Zufalls-
funktionen oder spezielle Eingaben-
funktionen und weiteres...
*/

/* Makros und Konstanten */
#define TRUE 1                            /* pseudo Boolean erzeugen */
#define FALSE 0

#define CLS printf("\033[H\033[2J") /* Bildschrim löschen unter Linux im Terminal */
#define NL printf("\n")             /* Newline ausgeben */
#define TPL while(getchar() != '\n')  /* Newline also '\n' abfangen */

#define SIZE_INT_ARRAY_SORT 100 /* Größe kann hier verändert werden je nach Bedarf */
#define INPUT_SIZE_INT 20 /* Größe kann angepasst werden */

/* Funktionsprototypen */
int rnd(int bereich);
void seedrnd(void);
void sort_int_array(int* array, int size);
void underline(char* string, char zeichen);
int input_number(void);
char* entferneNL(char* string);
void error_message(char* string, int next);
void text_message(char* dateiname);

/* Funktion zum setzen des Zufallsgenerators mit Hilfe der Uhrzeit */
void seedrnd(void)
{
        srand((unsigned)time(NULL));
}

/* Funktion zur Erzeugung von Zufallszahlen */
int rnd(int bereich)
{
        int r;

        r = (rand() % bereich + 1);
        return r;
}

/* Funktion zur Sortierung eines int-Arrays */
void sort_int_array(int* array, int size)
{
        int a, b, temp;

        for(a = 0; a < size - 1; a++)
        {
                for(b = a + 1; b < size; b++)
                {
                        if(array[a] > array[b])
                        {
                                temp = array[b];
                                array[b] = array[a];
                                array[a] = temp;
                        }
                }
        }
}

/* Funktion die einen Textstring mit einem Zeichen unterstreicht */
void underline(char* string, char zeichen)
{
        while(*string++)
        {
                putchar(zeichen);
        }
}

/* Funkion für die Eingabe von Integer-Werten bei der
keine Fehler auftreten wenn man diese in einer Schleife
aufruft. */
int input_number(void)
{
        char input[INPUT_SIZE_INT];
        int x;

        fgets(input, INPUT_SIZE_INT, stdin);
        x = atoi(input);

        return x;
}

/* Funktion zum entfernen des Newline Zeichens in einem mit fgets eingelesenen Strings */
char* entferneNL(char* string)
{
        char* string2 = string;

        while(*string2)
        {
                if(*string2 == '\n')
                {
                        *string2 = '\0';
                }
                string2++;
        }

        return string;
}

/* Funktion zum ausgeben von Error-Nachrichten */
void error_message(char* string, int next)
{
        int i;
        char* s;

        for(i = 0; i < next; i++)
        {
                s = string;
                while(*s != '\0')
                {
                        putchar(*s);
                        s++;
                }
                NL; /* neue Zeile */
        }
}

/* Funktion zur Ausgabe von Textdateien */
void text_message(char* dateiname)
{
        FILE* stream;
        char c;

        stream = fopen(dateiname, "r");

        if(!stream)
        {
                puts("!!!Datei nicht gefunden!!!");
                exit(1);
        }

        do
        {
                c = (char)fgetc(stream);
                putchar(c);
        }while(c != EOF);

        fclose(stream);
}
