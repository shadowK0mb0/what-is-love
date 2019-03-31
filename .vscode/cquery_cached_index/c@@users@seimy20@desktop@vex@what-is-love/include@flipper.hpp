#ifndef _FLIPPER_H_
#define _FLIPPER_H_

void flip();
void flipperOp();

bool flipperTooHigh();

void flipperUpAsync();

void flipperDownAsync();

void flipperTask(void* parameter);

#endif
