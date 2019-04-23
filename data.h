/**
 * data.h -- содержит структуру данных для корректной работы с курсором
 *
 * Copyright (c) 2018, Darya Madrakhimova <madrahim@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef DATA_H
#define DATA_H

#include "text/text.h"

typedef struct _dat {
  int line;
  int cursor;
  text txt;
} dat;

#endif
