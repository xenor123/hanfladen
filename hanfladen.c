/* Hanfladen textbasiertes Wirtschaftsimulationsgame in C */
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "work.h"

/* Konstanten und Makros */
#define START_KAPITAL 100

/* Anzahl der verschiedenen Drogen etc. */
#define DRUG_COUNT 7
#define EVENT_COUNT 9
#define LOCATION_COUNT 6

/* Meldungen */
#define NOT_IMPLEMENTED "Nicht implementiert!"
#define ERROR_MESSAGE "Oaschloch!"
#define EXIT_MESSAGE "Schade :-("

/* globale Variablen etc... */
int ende = 0;

/* Strukturen */
struct drug_struct
{
	char name[32];
	int stock;
	int Preis_Dealer;
	int Preis_Verkauf;
	int Beliebtheit;
	int normal_price;
};

struct event_struct
{
	char name[32];
	int frequency;
};

struct location_struct
{
	char name[32];
};

char *location_name[] =
{
	"Bahnhof",
	"Skatepark",
	"Spielplatz",
	"Polizeipräsidium",
	"Hauptschule",
	"Zedernstraße",
};

char *drug_name[] =
{
	"Cannabis",
	"LSD",
	"Ecstasy",
	"Heroin",
	"Kokain",
	"Viagra",
	"Crystal Meth"
};

int drug_normal_price[] =
{
	10,
	20,
	15,
	25,
	35,
	10,
	25
};

char *event_name[] =
{
	"Nichts Besonderes",
	"Loveparade",
	"Museldemo",
	"Goa-Festival",
	"Metal-Konzert",
	"Hip-Hop-Konzert",
	"Christopher-Street-Day",
	"Schulferien",
	"Straßenfest"
};

char *text_menu[] =
{
	"*********",
	"Hanfladen",
	"*********",
	"",
	"[1] Neues Spiel",
	"[2] Spiel laden",
	"[3] Spiel speichern",
	"[4] Beenden", 
	"",
	"Bitte auswählen: "
};

/* Funktionsprototypen */
int game();
int hauptmenu();
int dealmenu(int *Geld, int Ereignis, int Tag, struct drug_struct *Droge);
int auswahl_ort();
int show_event();
void ausgabe_text(char *text[], int x);
void show_msg(char *msg);

/* Hanfladen.c */
int main(int argc, char *args[])
{
   do
	{
		ausgabe_text(text_menu, 10);
		switch (input_number())
		{
			case 1:
				game();
				break;
	
			case 2:
				puts(NOT_IMPLEMENTED);
				break;
			
			case 3:
				puts(NOT_IMPLEMENTED);
				break;
		
			case 4:
				puts(EXIT_MESSAGE);
				ende = 1;
				break;

			default:
				puts(ERROR_MESSAGE);
	
		}
	} while(ende == 0);
	return 0;
}

int game()
{
	int i;
	int cash = START_KAPITAL;
	int event_today;
	int day = 0;
	struct drug_struct 		drug[DRUG_COUNT];
	struct event_struct 		event[EVENT_COUNT];
	struct location_struct 	location[LOCATION_COUNT];
	
	// Initialisierung der Startbedingungen
	
	for(i = 0; i < DRUG_COUNT; i++)
	{
		strcpy(drug[i].name, drug_name[i]);
		drug[i].stock = 0;
		drug[i].normal_price = drug_normal_price[i];
	}
	
	for(i = 0; i < EVENT_COUNT; i++)
	{
		strcpy(event[i].name, event_name[i]);
	}
	
	for(i = 0; i < LOCATION_COUNT; i++)
	{
		strcpy(location[i].name, location_name[i]);
	}

	
	//Game-Schleife	
	
	do 
	{
			event_today = show_event(day, event);
			day++;
	} while (1);
}

int dealmenu(int *Geld, int Ereignis, int Tag, struct drug_struct *Droge)
{
	//int Preis_Cannabis = 10
	//int Preis_LSD = 20
	//int Preis_Ecstasy = 15
	//int Preis_Heroin = 25
	//int Preis_Kokain = 35
	//int Preis_Viagra = 15
	//int Preis_Meth = 25
	
	do
	{
		CLS;
		printf("Beim Dealer:"); NL;
		NL;
	} while(1);
}

int auswahl_ort()
{
	int i;
	int eingabe;
    
	do
	{
		printf("An welchem Ort möchtest du verkaufen?\n");
		for (i = 0 ; i < LOCATION_COUNT ; i++) // Gibt die Ortsnamen aus
		{
			printf("[%i] %s\n", i, location_name[i]);
		}
		eingabe = input_number();
		
	} while((eingabe < 1) || (eingabe > LOCATION_COUNT));
	
	return eingabe;
}

int show_event(int day, struct event_struct *event)
{
	int event_today;
	event_today = rand() % EVENT_COUNT;
	printf("Tag %i\n", day);
	printf("Heute: %s\n",event[event_today].name);
	usleep(1000000);
	return event_today;
}

void ausgabe_text(char *text[], int x)
{
	// int a, b;
	int i;
	x--;

	for(i = 0; i <= x; i++)
	{
		printf("%s\n", text[i]);
	}
}

void show_msg(char *msg)
{
	printf("%s\n",msg);
}
