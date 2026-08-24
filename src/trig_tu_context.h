#ifndef AOE1_TRIG_TU_CONTEXT_H
#define AOE1_TRIG_TU_CONTEXT_H

// Authentic trig.cpp class surface.  The two restriction helpers are private
// in the shipped class; the table accessors and constructor are public.
class TRIGONOMETRY {
private:
    int RestrictAngle(int param_1);
    int RestrictAngle360(int param_1);

public:
    float sines[4096];
    float cose[4096];
    float tane[4096];
    float atane[4096];

    float sine360[360];
    float cose360[360];
    float tane360[360];
    float atane360[360];

    TRIGONOMETRY();
    float sine(int param_1);
    float cosine(int param_1);
    float tangent(int param_1);
    float atangent(int param_1);
    float sin360(int param_1);
    float cos360(int param_1);
    float tan360(int param_1);
    float atan360(int param_1);
};

#endif
