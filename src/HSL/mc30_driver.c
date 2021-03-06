/* @source mc30_driver.c
**
** April 10th, 2017
** @author: David Thierry (dmolinat@andrew.cmu) dav0@lb2016-1

******************************************************************************

@mc30driver ********************************************
**
** Calculates scaling factors exp(s[i])
** To solve the linear system, Ax=b
** (D1^-1) A (D2) y = (D1^-1)  b
** and set x = D2 y
** (D1^-1) = exp(s[i])_{ii}
** (D2) = exp(s[i])_{ii}
** pls check Golub & Van Loan 4ed pp 138
** @param [r] nr row number
** @param [r] nz number of nz
** @@
*******************************************************************************/

/*#include <stdlib.h> */
#include "mc30_driver.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int mc30driver(fint n, fint nz, real *a, fint *irn, fint *icn, real *s){
	
	real *w;
	fint ifail, lp;
	int i;
	/* working array */
	w = (real *)malloc(sizeof(real) * n * 4);

	memset(w, 0, n * 4 * sizeof(real));
	memset(s, 0, n * sizeof(real));
	
	ifail = 0;
	lp = 6;

	/* call mc30ad */
	mc30ad_(&n, &nz, a, irn, icn, s, w, &lp, &ifail);
	
	assert(ifail == 0);
	
	free(w);


	return 0;
}