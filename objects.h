//objects.h

//defines the structures of the flow meter in memory for calculations

typedef struct Path{
    double TUp;
    double TDn;
    double DeltaT;
} path_t;

typedef struct {
    double MassFlow;
    double VolumeFlow;
} result_t;

