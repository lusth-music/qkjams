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
    shuffleDrums()
    {
        spot = getLocation();
        drumkitCrash    ( 1,1,"X---------------",(char *) 0); setLocation(spot);
        drumkitHHOpen   ( 1,1,"----x---x---x---",(char *) 0); setLocation(spot);
        drumkitSnare    ( 1,1,"--------X-------",(char *) 0); setLocation(spot);
        drumkitKick     ( 1,1,"x---x---x---x---",(char *) 0); setLocation(spot);

        spot = getLocation();
        drumkitHHClosed ( 24,1,"f--gf--gf--gf--g",(char *) 0); setLocation(spot);
        drumkitSnare    ( 24,1,"----X-------X---",(char *) 0); setLocation(spot);
        drumkitKick     ( 24,1,"X-------X-------",(char *) 0);
        setAmplitude(0.9);
        //drumkitKick   ( 12,1,"rxxrxxrxxrxxrxx-",(char *) 0); //setLocation(spot);
    }

void
dressIntro()
{
    spot = getLocation();
    drumkitCrash    ( 1,1,"----------------",(char *) 0); setLocation(spot);
    drumkitHHOpen   ( 1,1,"----x---x---x---",(char *) 0); setLocation(spot);
    drumkitSnare    ( 1,1,"------------X---",(char *) 0); setLocation(spot);
    drumkitKick     ( 1,1,"X---------------",(char *) 0); //setLocation(spot);
}

void
dress()
{
    spot = getLocation();
    drumkitCrash    ( 1,1,"----------------",(char *) 0); setLocation(spot);
    drumkitHHOpen   ( 1,1,"xxxxxxxxxxxxxxxx",(char *) 0); setLocation(spot);
    drumkitSnare    ( 1,1,"X-X-X-X-X-X-X-X-",(char *) 0); setLocation(spot);
    drumkitKick     ( 1,1,"x-x-x-x-x-x-x-x-",(char *) 0); //setLocation(spot);
    // spot = getLocation();
    // drumkitCrash    ( 1,1,"----------------",(char *) 0); setLocation(spot);
    // drumkitHHOpen   ( 1,1,"x---x---x---x---",(char *) 0); setLocation(spot);
    // drumkitSnare    ( 1,1,"----------------",(char *) 0); setLocation(spot);
    // drumkitKick     ( 1,1,"--------X-------",(char *) 0); //setLocation(spot);
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
    setAmplitude(0.999);

    openOutput("drums.rra",0,0);

    //drumkitStick(1,1,"xxxx",(char *) 0); //intro

    //spot = getLocation();
    shuffleDrums();
    //spot = getLocation();
    //mess();
    //mess();

    // spot = getLocation();
    // rest(W);
    // rest(W);
    // rest(W);
    // rest(W);
    // mess();
    // drumkitKick   (10,1,"XxX-XxX-XxX-XxX-",(char *) 0); setLocation(spot);
    // drumkitSnare  (10,1,"---X---X---X---X",(char *) 0); setLocation(spot);
    // drumkitHHPedal(10,1,"--x---x---x---x-",(char *) 0); setLocation(spot);
    // drumkitRim    (10,1,"x--xx--x--xx--x-",(char *) 0); setLocation(spot);
    // drumkitTomHi  (10,1,"x---x-----x---x-",(char *) 0); setLocation(spot);
    // drumkitTom    (10,1,"-X-X-X-x-X-X-X-x",(char *) 0); setLocation(spot);
    // drumkitTomLo  (10,1,"X-x-X-x-X-x-X-x-",(char *) 0);

    closeOutput();

    return 0;
    }
