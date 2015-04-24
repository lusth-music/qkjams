#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "guitar-electric/clean_"
#define base2 "mandolin/sample_"
#define base3 "harmonica/pocket_"

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
    c(chord,Q,instrument,octave);
    c(chord,Q,instrument,octave);
    c(chord,Q,instrument,octave);
    //if(last) setSustain(0.999999);
    c(chord,Q,instrument,octave);
}

static
bar2(int instrument, int octave, int chord){
    c(chord,Q,instrument,octave);
    c(chord,Q,instrument,octave);
    c(chord+1,I,instrument,octave);
    c(chord,I,instrument,octave);
    //if(last) setSustain(0.999999);
    c(chord,Q,instrument,octave);
}

static
bar3(int instrument, int octave, int chord){
    c(chord,I,instrument,octave);

    rest(I+Q);
    //c(chord,Q,instrument,octave);
    //c(chord,Q,instrument,octave);
    c(chord+1,I,instrument,octave);
    c(chord,I,instrument,octave);
    //if(last) setSustain(0.999999);
    c(chord,Q,instrument,octave);
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

    c(1,W,instrument,octave);
    c(4,W,instrument,octave);
    c(1,W,instrument,octave);
    c(1,W,instrument,octave);
    c(4,W,instrument,octave);
    c(4,W,instrument,octave);
    c(1,W,instrument,octave);
    c(1,W,instrument,octave);
    c(5,W,instrument,octave);
    c(4,W,instrument,octave);
    c(1,W,instrument,octave);
    c(5,W,instrument,octave);
}

static
twelveBar2s(int instrument,int octave){

    bar2(instrument,octave,1);
    bar2(instrument,octave,4);
    bar2(instrument,octave,1);
    bar2(instrument,octave,1);//4
    bar2(instrument,octave,4);
    bar2(instrument,octave,4);
    bar2(instrument,octave,1);
    bar2(instrument,octave,1);//8
    bar2(instrument,octave,5);
    bar2(instrument,octave,4);
    bar2(instrument,octave,1);
    if (last) {bar2(instrument,octave,1);}//12
    else{bar2(instrument,octave,5);}
//    bar(instrument,octave,5);

}

static
twelveBar3s(int instrument,int octave){

    bar3(instrument,octave,1);
    bar3(instrument,octave,4);
    bar3(instrument,octave,1);
    bar3(instrument,octave,1);//4
    bar2(instrument,octave,4);
    bar2(instrument,octave,4);
    bar3(instrument,octave,1);
    bar3(instrument,octave,1);//8
    bar(instrument,octave,5);
    bar(instrument,octave,4);
    bar3(instrument,octave,1);
    if (last)
    {
        setSustain(0.999999);
        c(1,W, instrument,octave);
    }//12
    else{bar3(instrument,octave,5);}
//    bar(instrument,octave,5);

}

static
experimental7Bar(int instrument, int octave){

    rest(W);
    c(1,W*2,instrument,octave);
    c(4,W*2,instrument,octave);
    c(4,W*2,instrument,octave);
    c(1,W*2,instrument,octave);
    c(5,W*2,instrument,octave);
    c(4,W*2,instrument,octave);
    c(1,W*2,instrument,octave);
}

static
blues7Bar(int instrument, int octave)
{
    c(2,W, instrument, octave);
    c(5,W, instrument, octave);
    c(1,W, instrument, octave);
}

static
ex72(int instrument, int octave)
{
    rest(W);
    rest(H);
    c(1,W,instrument,octave);
    c(1,W,instrument,octave);
    c(4,W,instrument,octave);
    c(4,W,instrument,octave);
    c(4,W,instrument,octave);
    c(4,W,instrument,octave);
    c(1,W,instrument,octave);
    c(1,W,instrument,octave);
    c(5,W,instrument,octave);
    c(5,W,instrument,octave);
    c(4,W,instrument,octave);
    c(4,W,instrument,octave);
    c(1,H,instrument,octave);
}

int
main()
    {
    int instrument;
    int instrument2;
    int hmonica;
    int octave = 1;

    songInit();

    instrument = readScale(dir,base);
    instrument2 = readScale(dir,base2);
    hmonica = readScale(dir, base3);


    setKey(A);
    setTempo(120);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.95);
    setAmplitude(0.3);

    openOutput("song.rra",0,0);
//goto here;
    rest(W);
    twelveBar2s(instrument, octave);
    twelveBar3s(instrument, octave);
    c(1,W,instrument,octave);
    rest(W);
here:;
//bluesBar(instrument, octave);
    
    //rest(W*3);
    spot = getLocation();
    twelveBars(hmonica, octave); setLocation(spot);
    twelveBar2s(instrument2, octave);

    spot = getLocation();
    experimental7Bar(instrument, octave); setLocation(spot);
    ex72(instrument2, octave);
    here2:;
    rest(W);
    twelveBar2s(instrument, octave);
    last = 1;
here3:;
    twelveBar3s(instrument, octave);

    closeOutput();

    return 0;
    }
