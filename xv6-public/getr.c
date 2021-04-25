/**************************************************************/
/*CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi      	*/
/*Tekijä: Akseli Törrönen					*/
/*Opiskelijanumero: 0542794					*/
/*Harjoitustyö: Kernel hacking: getr.c			*/
/**************************************************************/
/*modified files include but are not limited to usys.S, syscall.c, syscall.h, sysproc.c, Makefile, user.h and proc.h*/

#include "types.h"
#include "user.h"
#include "stat.h"
#include <stddef.h>
int
main(int argc, char *argv[])
{
	int rc, fd=0;
	void *buf=NULL;
	size_t count=0;
	char buffer[2];
	printf(1, "\nHACK INITIATED!\n");
	read(fd, buf, count); //calling read with 0 and NULL values just for the hell of it
	rc = getreadcount(); //getting read count (sysproc.c)
	//you have to choice to reset the read count to zero
	printf(1, "current count: %d\n\nDo you want to reset the counter? [y]\n",rc);
	//using gets() to read answer
	gets(buffer, 2);
	if(strcmp(buffer,"y")==0){rc = resetread();printf(1, "Read count has been reset.\n");}
	rc = getreadcount(); //getting read count (sysproc.c)
	printf(1, "read count currently: %d\n",rc);
	exit();
}
