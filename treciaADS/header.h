#ifndef header
    #define header
    
typedef struct {
    char *skaicius;
    int ilgis;
    int zenklas;
} BigInt;

typedef struct plane {
    BigInt *timeOfAppearance;
    BigInt *maneouverTime;
    short int takeOff; // 1 = true, 0 = false
    int id;
} Plane;

#endif