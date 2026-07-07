typedef struct Picture
{
    int width;
    int height;
    unsigned char *data;
} Picture;

Picture* loadPicture(const char* filename);
void freePicture(Picture* picture);
void drawPicture(Framebuffer* fb, const Picture* picture, Point position);