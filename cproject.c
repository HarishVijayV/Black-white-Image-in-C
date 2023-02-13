#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare image variables
    int width, height, max_color,i;
    float new;
    unsigned char *image;
    char str[100];
    printf("Enter the name of the file (with .ppm) :");
    gets(str);
    // Read image from file
    FILE *in_file = fopen(str, "rb");
    fscanf(in_file, "P6\n%d %d\n%d\n", &width, &height, &max_color);
    image = (unsigned char *) malloc(width * height * 3);
    fread(image, 1, width * height * 3, in_file);
    fclose(in_file);
    // Convert to black and white
        for (int i = 0; i < width * height * 3; i += 3) {
        float new = (0.299*image[i] + 0.587*image[i + 1] + 0.114*image[i + 2]);
    
        if (new>128.00)
        {
            image[i]=255;
            image[i+1]=255;
            image[i+2]=255;
        }
        else{
            image[i]=0;
            image[i+1]=0;
            image[i+2]=0;
        }
        }
    //
    FILE *out_file = fopen("output_withB.ppm", "wb");
    fprintf(out_file, "P6\n%d %d\n%d\n", width, height, max_color);
    fwrite(image, 1, width * height * 3, out_file);
    fclose(out_file);
    free(image);
    return 0;
}