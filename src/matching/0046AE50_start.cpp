class Path {
public:
    virtual ~Path();
    char field_4[1];
    char* start();
};

char* Path::start() { return this->field_4; }
