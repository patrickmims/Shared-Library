#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "zlib.h"

int pack(FILE *, FILE *);

#endif
