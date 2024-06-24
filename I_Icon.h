class Icon
{
    public:
    float speed, glow, energy;
    int x, y;
    virtual void move() = 0;
    virtual void flair() = 0;
};
