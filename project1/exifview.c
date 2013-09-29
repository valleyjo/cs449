//Created By: Alex Vallejo
//Date: 9/17/2013
//Project: Rock, Paper, Scissors and EXIF Viewer
//Class: CS 447

#include <stdio.h>

/* Struct for the image header */
typedef struct{
  unsigned short start_marker;
  unsigned short app_marker;
  unsigned short app_marker_length;
  char exif[4];
  unsigned short nul_marker;
  char endinness[2];
  unsigned short version;
  unsigned int offset;
} Header;

/* Struct for tiff tags */
typedef struct{
  unsigned short id;
  unsigned short type;
  unsigned int num_items;
  char value[4];
  unsigned int offset;
} Tag;

int main(int argc, char *argv[]){

  //Variable declerations
  int count;

  // Verify the program was executed correctly
  if (argc < 2 || argc > 2){
    printf("Usage: ./exifview img.jpg\nTry again!\n\n");
    return 0; 
  }

  // Variable decleration
  FILE * file;
  Header head;

  file = fopen(argv[1], "rb");
  fread(&head, sizeof(head), 1, file);

  printf("%s",head.endinness);
  
  //Verify the files are properly formatted!
  if (head.app_marker != 0xE1FF){ //verify no app0 marker is present
    printf("The file is improperly formatted!\nFile contains an APP0 marker.\n\n");
    return 0;
  }

  if (0 != strcmp(head.endinness, "II*")){
    printf("Sorry, but we do not support big endinness!");
    return 0;
  }

  if (0 != strcmp(head.exif, "Exif")){
    printf("Your fine does not contain EXIF data!");
    return 0;
  }

  

  printf("End of the program.");
}
