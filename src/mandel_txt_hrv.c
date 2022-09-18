#include "mandel_txt.h"


void print_image_line (struct_txt_image* image,unsigned iy)
{
char text_color[8] = {'.','-','=','!','^','(','@','%'};
unsigned ix;
unsigned dot;
long long scratch;
unsigned char *ptr;

  //scratch = BASE_OUTPUT_BUFFER + iy*image->pixels_per_side;
  //ptr = (unsigned char *) scratch;
  for (ix=0; ix<image->pixels_per_side; ix++) {
    dot=image->image[ix][iy];
    dot=(dot % 8);
    printf("%c", text_color[dot]);
  }
  printf("\n");
}