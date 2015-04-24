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
    drumkitKick     ( 1,1,"x---x---x---x---",(char *) 0);
}


void
shuffleDrums(int measures)
{
        spot = getLocation();
        drumkitHHClosed ( measures,1,"f--gf--gf--gf--g",(char *) 0); setLocation(spot);
        drumkitSnare    ( measures,1,"----xg------xg--",(char *) 0); setLocation(spot);
        drumkitKick     ( measures,1,"x-------x-------",(char *) 0);
}

void
slowDrum(int measures)
{
        spot = getLocation();
        drumkitHHClosed ( measures,1,"f--------------g",(char *) 0); setLocation(spot);
        drumkitSnare    ( measures,1,"--------x-------",(char *) 0); setLocation(spot);
        drumkitKick     ( measures,1,"X---------------",(char *) 0);
}

void
drumCrash()
{
    spot = getLocation();
    drumkitCrash    ( 1,1,"X",(char *) 0); setLocation(spot);
    drumkitSnare    ( 1,1,"X",(char *) 0); setLocation(spot);
    drumkitKick     ( 1,1,"X",(char *) 0);

}


void
slowDrum2(int measures)
{
    spot = getLocation();
    drumkitCrash    ( measures,1,"f---",(char *) 0); setLocation(spot);
    drumkitSnare    ( measures,1,"--x-",(char *) 0); setLocation(spot);
    drumkitKick     ( measures,1,"--x-",(char *) 0);
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
//goto here;
    shuffleDrumIntro();
    shuffleDrums(12);
    shuffleDrums(13);
    rest(W);

    here:;
setAmplitude(0.3);
    crazydrum:;
    drumCrash();
    rest(W);
    drumCrash();
    drumCrash();
    drumCrash();
    rest(W);
    drumCrash();
    rest(W);
    drumCrash();
    rest(W);
    drumCrash();
    drumCrash();
    rest(W);
    setAmplitude(0.7);
    slowDrum(14);
    //rest(W);
    shuffleDrums(12);
    here2:;
    shuffleDrums(12);
    here3:;
    //shuffleDrums(12);
    closeOutput();

    return 0;
    }
