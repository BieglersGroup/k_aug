//
// Created by dav0 on 9/17/18.
//

#include <memory.h>
#include <stdio.h>
#include "compute_glagrangian.h"

void compute_glagrangian(nlp_info *nlp_info1, nlp_pd *nlp_pd1) {
    int i, j;
    FILE *myfile;
    memset(nlp_pd1->grad_L, 0, sizeof(double) * (nlp_info1->n_orig + nlp_info1->n_slack));
    myfile = fopen("grad_L", "w");
    for (i = 0; i < (nlp_info1->n_orig + nlp_info1->n_slack); i++) {
        nlp_pd1->grad_L[i] += nlp_pd1->grad_f[i] + nlp_pd1->grad_c_y[i] + nlp_pd1->z[i];
        fprintf(myfile, "%f\n", nlp_pd1->grad_L[i]);
    }
    fclose(myfile);
}