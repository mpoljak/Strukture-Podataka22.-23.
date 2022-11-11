#ifndef structPolynomaial_h
#define structPolynomaial_h

typedef struct polynomaial* Position;

struct polynomaial {
	int coeff;
	int power;
	Position next;
};

#endif