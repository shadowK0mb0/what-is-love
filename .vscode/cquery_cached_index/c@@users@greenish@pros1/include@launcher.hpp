#ifndef _LAUNCHER_H_
#define _LAUNCHER_H_

void launcher(int vel);

bool isFired();

void shootAsync();
void ratchetAsync();
void cataLoadAsync();
void cataThrowAsync();
void shoot();
void ratchet();

void launcherTask(void* parameter);

bool cataThrow();
bool cataSet(int dist);

void launcherOp();

#endif
