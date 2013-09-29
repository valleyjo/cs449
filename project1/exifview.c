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
  unsigned int offset;
} Tag;

int verify(Header head){

  if (0xE1FF != head.app_marker){ //verify no app0 marker is present
    printf("The file is improperly formatted!\nFile contains an APP0 marker.\n\n");
    return 0;
  }

  if (0 != strcmp(head.endinness, "II*")){
    printf("Sorry, but we do not support big endinness!");
    return 0;
  }

  if (0 != strcmp(head.exif, "Exif")){
    printf("Your file does not contain EXIF data!");
    return 0;
  }
  return 1;
}

void print_sub_tags(FILE *file, int tag_count){
  int i;
  unsigned short WIDTH = 0xa02;
  unsigned short HEIGHT = 0xa03;
  unsigned short ISO_SPEED = 0x8827;
  Tag tag;
  unsigned int tmp_ptr_loc;

  for (i = 0; i < tag_count; i++){
    fread(&tag, sizeof(tag), 1, file);

    tmp_ptr_loc = ftell(file);
  }
}

int main(int argc, char *argv[]){

  //Variable declerations
  unsigned short count, sub_block_count, MAN_STR = 0x010f,
                 MODEL_STR = 0x0110, SUB_BLOCK_INDICATOR = 0x8769;
  unsigned int block_address, tmp_ptr_loc, i;
  char value_str[100];
  FILE * file;
  Header head;
  Tag tag;

  // Verify the program was executed correctly
  if (argc < 2 || argc > 2){
    printf("Usage: ./exifview img.jpg\nTry again!\n\n");
    return 0;
  }

  file = fopen(argv[1], "rb");
  fread(&head, sizeof(head), 1, file);

  //Verify the files are properly formatted!
  verify(head);

  fread(&count, sizeof(count), 1, file);

  /*Debug print statements
  printf("endinness => %s\n",head.endinness);
  printf("count => %u\n", count);
  printf("ftell() => %d\n", ftell(file));
  */

  for (i = 0; i < count; i++){
    fread(&tag, sizeof(tag), 1, file);

    tmp_ptr_loc = ftell(file);

    if (tag.id == MAN_STR){
      fseek(file, tag.offset + 12, SEEK_SET);
      fread(&value_str, sizeof(value_str[0]), tag.num_items, file);
      printf("%-15s %s\n", "Manufacturer:", value_str);
    }

    else if (tag.id == MODEL_STR){
      fseek(file, tag.offset + 12, SEEK_SET);
      fread(&value_str, sizeof(value_str[0]), tag.num_items, file);
      printf("%-15s %s\n", "Model:", value_str);
    }

    else if (tag.id == SUB_BLOCK_INDICATOR){
      fseek(file, tag.offset + 12, SEEK_SET);
      fread(&sub_block_count, sizeof(sub_block_count), 1, file);
      print_sub_tags(file, sub_block_count);
    }

    fseek(file, tmp_ptr_loc, SEEK_SET);
  }
}
