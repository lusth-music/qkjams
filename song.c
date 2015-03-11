#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "guitar-electric/clean_"

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

static
bar(int instrument, int octave, int chord){
    c(chord,I,instrument,octave);
    c(chord,I,instrument,octave);
    c(chord,I,instrument,octave);
    c(chord,I,instrument,octave);
    //if(last) setSustain(0.999999);
    c(chord,I,instrument,octave);
    c(chord,I,instrument,octave);
    c(chord,I,instrument,octave);
    c(chord,S,instrument,octave);c(chord,S,instrument,octave);
    // c(chord,Q,instrument,octave);
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

int
main()
    {
    int instrument;
    int octave = 1;

    songInit();

    instrument = readScale(dir,base);

    setKey(A);
    setTempo(72);
    setTime(6,8);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.3);

    openOutput("song.rra",0,0);

    rest(W);
    //softer(4);
    twelveBars(instrument,octave);
    last = 1;
    twelveBars(instrument,octave);

    closeOutput();

    return 0;
    }
