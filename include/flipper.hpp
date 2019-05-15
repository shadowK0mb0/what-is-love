#ifndef _FLIPPER_H_
#define _FLIPPER_H_

void flip();
void flipperOp();

bool flipperTooHigh();
void flip(int vel);

bool flipperDown();
void setFlipperAsync(int sp);

void flipperUpAsync();

void flipperDownAsync();

void flipperTask(void* parameter);

#endif
