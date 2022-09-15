static int fps()
{
    static int fps = 0;
    static int frame = 0;
    static uint64_t fpsLastTime = micros();

    uint64_t time = micros();
    frame++;
    if (time - fpsLastTime >= 1000000)
    {
        fpsLastTime = time;
        fps = frame;
        frame = 0;
    }
    return fps;
}