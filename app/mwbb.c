/**
 * mwbb.c -- реализует смещение позиции курсора в начало слова, если возможно
 *
 * Copyright (c) 2018, Egor Ignatov <ignatov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static void move_cursor_left(int index, char *contents, int cursor, void *data);

void mwbb(text txt) { process_forward(txt, move_cursor_left, txt); }

static void move_cursor_left(int index, char *contents, int cursor,
                             void *data) {
  assert(contents != NULL);

  UNUSED(data);

  if (cursor > 0) {
    /* Пока непробельный символ || не начало строки -> двигаем курсор влево */
    while (cursor > -1 && !isspace(contents[cursor])) {
      cursor--;
    }
    cursor++;
    /* Переставляем курсор на новую позицию */
    mwcrsr(data, index + 1, cursor + 1);
  }
}
