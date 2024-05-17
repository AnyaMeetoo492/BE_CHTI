
#ifndef DFT_H
#define DFT_H

extern short TabCos[64];
extern short TabSin[64];
extern short LeSignal[64];

int DFT(short * Signal, int k);

#endif
