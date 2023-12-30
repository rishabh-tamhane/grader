/*report.c functions*/
void reportparams(FILE *fd,char *fn, Course *c);
void reportfreqs(FILE *fd, Stats *s);
void reportquantilesummaries(FILE *fd,Stats *s);
void reportquantiles(FILE *fd, Stats *s);
void reportmoments(FILE *fd,Stats *s);
void reportscores(FILE *fd,Course *c, int nm);
void reportcomposites(FILE *fd,Course *c,int nm);
void reporthistos(FILE *fd,Course *c,Stats *s,int nm);
void reporttabs(FILE *fd, Course *c);