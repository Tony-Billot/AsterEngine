#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../renderer/framebuffer.h"


struct Picture {
    int width;
    int height;
    unsigned char *data;
};

struct Picture* loadPicture(const char* filename)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
        return NULL;

    unsigned char header[54];

    if (fread(header, 1, 54, file) != 54)
    {
        fclose(file);
        return NULL;
    }

    if (header[0] != 'B' || header[1] != 'M')
    {
        fclose(file);
        return NULL;
    }

    uint32_t dataOffset = *(uint32_t*)&header[10];
    int32_t width = *(int32_t*)&header[18];
    int32_t height = *(int32_t*)&header[22];
    uint16_t bitsPerPixel = *(uint16_t*)&header[28];
    uint32_t compression = *(uint32_t*)&header[30];

    if (bitsPerPixel != 24 || compression != 0)
    {
        fclose(file);
        return NULL;
    }

    struct Picture *pic = malloc(sizeof(struct Picture));
    if (!pic)
    {
        fclose(file);
        return NULL;
    }

    pic->width = width;
    pic->height = height;

    pic->data = malloc(width * height * 4);
    if (!pic->data)
    {
        free(pic);
        fclose(file);
        return NULL;
    }

    fseek(file, dataOffset, SEEK_SET);

    int padding = (4 - ((width * 3) % 4)) % 4;

    for (int y = height - 1; y >= 0; y--)
    {
        for (int x = 0; x < width; x++)
        {
            unsigned char b = fgetc(file);
            unsigned char g = fgetc(file);
            unsigned char r = fgetc(file);

            int index = (y * width + x) * 4;

            pic->data[index + 0] = r;
            pic->data[index + 1] = g;
            pic->data[index + 2] = b;
            pic->data[index + 3] = 255;
        }

        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);
    return pic;
}

void freePicture(struct Picture *pic)
{
    if (!pic)
        return;

    free(pic->data);
    free(pic);
}

void drawPicture(struct Framebuffer *fb, const struct Picture *picture, Point position)
{
    if (fb == NULL || picture == NULL || picture->data == NULL)
        return;

    for (int y = 0; y < picture->height; y++)
    {
        for (int x = 0; x < picture->width; x++)
        {
            int index = (y * picture->width + x) * 4;

            Color color;
            color.r = picture->data[index + 0];
            color.g = picture->data[index + 1];
            color.b = picture->data[index + 2];
            color.a = picture->data[index + 3];

            Point p;
            p.x = position.x + x;
            p.y = position.y + y;

            putPixel(fb, p, color);
        }
    }
}