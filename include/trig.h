#ifndef AOE1_TRIG_H
#define AOE1_TRIG_H

class TRIGONOMETRY {
  private:
    int RestrictAngle(int angle);
    int RestrictAngle360(int angle);

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
    float sine(int angle);
    float cosine(int angle);
    float tangent(int angle);
    float atangent(int angle);
    float sin360(int angle);
    float cos360(int angle);
    float tan360(int angle);
    float atan360(int angle);
};

#endif // AOE1_TRIG_H
