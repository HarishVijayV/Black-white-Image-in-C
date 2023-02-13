#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare image variables
    int width, height, max_color,n;
    unsigned char *image;
    char str[100];//creating a character matrix with name str
    printf("Enter the name of the file (with .ppm) :");//getting the input image 
    gets(str);//storing the ppm form input image in str array
    // Read image from file
    FILE *in_file = fopen(str, "rb");//now *in file open the image (rb=read binary)
    fscanf(in_file, "P6\n%d %d\n%d\n", &width, &height, &max_color);//from in file(input image.ppm) scan the values
    image = (unsigned char *) malloc(width * height * 3);//(allocate)create same(dimensional) space in new array 'image'
    fread(image, 1, width * height * 3, in_file);//now store(read) all the values from infile to image including p6\n width,height\n max colour
    fclose(in_file);//close the opened(input image .ppm) file
    // Convert to black and white
    printf("1 for black and white image\n \n");
    scanf("d",&n);

    
    for (int i = 0; i < width * height * 3; i += 3) {
        int new = (0.299*image[i] + 0.587*image[i + 1] + 0.114*image[i + 2]);
        if (new>128){
        image[i] = 255;
        image[i + 1] = 255;
        image[i + 2] = 255;

        }
        else{
             image[i] = 0;
        image[i + 1] = 0;
        image[i + 2] = 0;

        }
       
    }
    // Write Gray Level Sliced image to file
    FILE *out_file = fopen("output_withB.ppm", "wb");//open an output file
    fprintf(out_file, "P6\n%d %d\n%d\n", width, height, max_color);//print the first three line values
    fwrite(image, 1, width * height * 3, out_file);//write the above (if,else) crossed image value in out_file
    fclose(out_file);//close out file
    free(image);//free out images memoryallocation.
    return 0;
}