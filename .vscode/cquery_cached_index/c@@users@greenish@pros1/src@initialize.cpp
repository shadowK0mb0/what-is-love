#include "main.h"

int auton = 0; // keeps track of what auton is selected
bool mirror = false;



void initialize() {

  FILE* usd_file_read = fopen("/usd/auton.txt", "r");
  char buf[20]; // This just needs to be larger than the contents of the file
  fread(buf, 1, 20, usd_file_read); // passing 1 because a `char` is 1 byte, and 50 b/c it's the length of buf
  auton = buf[0] - '0';
  //auton = fgetc(usd_file_read);
  // Should print "Example text" to the terminal
  fclose(usd_file_read); // always close files when you're done with them

  gui();
}

void disabled() {}

void competition_initialize() {}
