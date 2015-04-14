#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples"
#define base "drum"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "drums";
char *PROGRAM_VERSION = "0.01";

//static int last = 0;
    int spot;
void
intro()
{
    spot = getLocation();

    drumkitCrash  ( 1,1,"x---x---x---x---",(char *) 0);
}

void
shuffleDrumIntro()
{
        spot = getLocation();
        drumkitCrash    ( 1,1,"X---------------",(char *) 0); setLocation(spot);
        drumkitHHOpen   ( 1,1,"----x---x---x---",(char *) 0); setLocation(spot);
        drumkitSnare    ( 1,1,"--------X-------",(char *) 0); setLocation(spot);
        drumkitKick     ( 1,1,"x---x---x---x---",(char *) 0); setLocation(spot);
}


void 
shuffleDrums()
{
        spot = getLocation();
        drumkitHHClosed ( 24,1,"f--gf--gf--gf--g",(char *) 0); setLocation(spot);
        drumkitSnare    ( 24,1,"----X-------X---",(char *) 0); setLocation(spot);
        drumkitKick     ( 24,1,"X-------X-------",(char *) 0);
}

int
main()
    {
    //int instrument;
    //int octave = 1;
    songInit();

    //instrument = readScale(dir,base);

    //setKey(A);
    setTempo(120);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.7);

    openOutput("drums.rra",0,0);

    shuffleDrumIntro();
    shuffleDrums();
    shuffleDrums();

    rest(W);
    shuffleDrums();
    closeOutput();

    return 0;
    }
