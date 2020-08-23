struct NamedPoint;
struct NamedPoint *makeNamedPoint(double, double, char *);
void setName(struct NamedPoint *, char *);
char *getName(struct NamedPoint *);