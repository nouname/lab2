/**
 * mwcrsr -- реализует перемещение курсора
 *
 * Copyright (c) 2018, Egor Ignatov <ignatov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"

void change_cursor_position(text txt, int new_line, int new_position);

void mwcrsr(text txt, int line, int cursor) {
  change_cursor_position(txt, line, cursor);
  getcrsr(txt);
}
