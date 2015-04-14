#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "guitar-electric/clean_"
#define base2 "mandolin/sample_"

/*

 _____           _         _            _____
|     |_ _ ___ _| |___ ___|_|_ _ ___   |     |___ ___ ___ ___
|  |  | | | .'| . | .'|  _| | | |_ -|  | | | | . | . |  _| -_|
|__  _|___|__,|___|__,|_| |_|___|___|  |_|_|_|___|___|_| |___|
   |__|
*/


/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "song";
char *PROGRAM_VERSION = "0.01";

static int last = 0;
int spot;

static
bar(int instrument, int octave, int chord){
    c(chord,I,instrument,octave);
    c(chord,I,instrument,octave);
    c(chord,I,instrument,octave);
    c(chord,I,instrument,octave);
    c(chord,I,instrument,octave);
    c(chord,I,instrument,octave);
    c(chord,I,instrument,octave);
    c(chord,S,instrument,octave);c(chord,S,instrument,octave);
}

static
barLast(int instrument, int octave, int chord){
    c(chord,Q,instrument,octave);
    c(chord,Q,instrument,octave);
    c(chord,Q,instrument,octave);
    c(chord,Q,instrument,octave);
    if(last) setSustain(0.999999);
    c(chord,Q,instrument,octave);
}

static
twelveBars(int instrument,int octave){

    bar(instrument,octave,1);
    bar(instrument,octave,4);
    bar(instrument,octave,1);
    bar(instrument,octave,1);//4
    bar(instrument,octave,4);
    bar(instrument,octave,4);
    bar(instrument,octave,1);
    bar(instrument,octave,1);//8
    bar(instrument,octave,5);
    bar(instrument,octave,4);
    if(last){ barLast(instrument,octave,1);}
    else{
        bar(instrument,octave,1);
        bar(instrument,octave,1);
        bar(instrument,octave,5);}

}

static
experimentalBar(int instrument, int octave){

    rest(W);
    c(1,W,instrument,octave);
    c(4,W,instrument,octave);
    c(4,W,instrument,octave);
    c(1,W,instrument,octave);
    c(5,W,instrument,octave);
    c(4,W,instrument,octave);
    c(1,W,instrument,octave);
}

static
ex2(int instrument, int octave)
{
    rest(H);
    rest(W);
    c(1,W,instrument,octave);
    c(4,W,instrument,octave);
    c(4,W,instrument,octave);
    c(1,W,instrument,octave);
    c(5,W,instrument,octave);
    c(4,W,instrument,octave);
    c(1,H,instrument,octave);
}

int
main()
    {
    int instrument;
    int instrument2;
    int octave = 2;

    songInit();

    instrument = readScale(dir,base);
    instrument2 = readScale(dir,base2);


    setKey(A);
    setTempo(120);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.3);

    openOutput("song.rra",0,0);

    experimentalBar(instrument, octave);
    experimentalBar(instrument, octave);

    spot = getLocation();
    experimentalBar(instrument, octave); setLocation(spot);
    ex2(instrument2, octave);

    spot = getLocation();
    experimentalBar(instrument, octave); setLocation(spot);
    ex2(instrument2, octave);
    spot = getLocation();
    experimentalBar(instrument, octave); setLocation(spot);
    ex2(instrument2, octave);
    spot = getLocation();
    experimentalBar(instrument, octave); setLocation(spot);
    ex2(instrument2, octave);
    
    spot = getLocation();
    experimentalBar(instrument, octave); setLocation(spot);
    ex2(instrument2, octave);
    spot = getLocation();
    experimentalBar(instrument, octave); setLocation(spot);
    ex2(instrument2, octave);
    spot = getLocation();
    experimentalBar(instrument, octave); setLocation(spot);
    ex2(instrument2, octave);
    
    closeOutput();

    return 0;
    }
