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

static int last = 0;

int
main()
    {
    //int instrument;
    //int octave = 1;
    int spot;
    songInit();

	void
	mess()
	{
		spot = getLocation();

		drumkitCrash  ( 1,1,"x---x---x---x---",(char *) 0);
        spot = getLocation();
		drumkitCrash  ( 1,1,"X---------------",(char *) 0); setLocation(spot);
        drumkitHHOpen ( 1,1,"----x---x---x---",(char *) 0); setLocation(spot);
        drumkitSnare  ( 1,1,"--------X-------",(char *) 0); setLocation(spot);
        drumkitKick   ( 1,1,"rxxrxxrxxrxxrxxr",(char *) 0); setLocation(spot);

        spot = getLocation();
        drumkitHHOpen ( 7,1,"x---x---x---x---",(char *) 0); setLocation(spot);
        drumkitSnare  ( 7,1,"--------X-------",(char *) 0); setLocation(spot);
        drumkitKick   ( 1,1,"xxrxxrxxrxxrxxrx",(char *) 0); spot = getLocation(); //setLocation(spot);
        drumkitKick   ( 1,1,"xrxxrxxrxxrxxrxx",(char *) 0); spot = getLocation(); //setLocation(spot);
        drumkitKick   ( 1,1,"rxxrxxrxxrxxrxxr",(char *) 0); spot = getLocation(); //setLocation(spot);
        drumkitKick   ( 1,1,"xxrxxrxxrxxrxxrx",(char *) 0); spot = getLocation(); //setLocation(spot);
        drumkitKick   ( 1,1,"xrxxrxxrxxrxxrxx",(char *) 0); spot = getLocation(); //setLocation(spot);
        drumkitKick   ( 1,1,"rxxxrxxrxxrxxrxx",(char *) 0); spot = getLocation(); //setLocation(spot);
        drumkitKick   ( 1,1,"rxxrxxrxxrxxrxxr",(char *) 0); spot = getLocation(); //setLocation(spot);
  //    drumkitKick   (10,1,"XxX-XxX-XxX-XxX-",(char *) 0); setLocation(spot);
  //   	drumkitKick   (10,1,"XxX-XxX-XxX-XxX-",(char *) 0); setLocation(spot);
  //   	drumkitSnare  (10,1,"---X---X---X---X",(char *) 0); setLocation(spot);
  //   	drumkitHHPedal(10,1,"--x---x---x---x-",(char *) 0); setLocation(spot);
  //   	drumkitRim    (10,1,"x--xx--x--xx--x-",(char *) 0); setLocation(spot);
  //   	drumkitTomHi  (10,1,"x---x-----x---x-",(char *) 0); setLocation(spot);
  //   	drumkitTom    (10,1,"-X-X-X-x-X-X-X-x",(char *) 0); setLocation(spot);
  //   	drumkitTomLo  (10,1,"X-x-X-x-X-x-X-x-",(char *) 0); 
	}
    //instrument = readScale(dir,base);

    // setKey(A);
    setTempo(115);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.3);

    openOutput("drums.rra",0,0);

    //drumkitStick(1,1,"xxxx",(char *) 0); //intro

    spot = getLocation();
    mess();
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
