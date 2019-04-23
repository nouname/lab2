/**
 * change_cursor_position -- реализует перемещение курсора
 *
 * Copyright (c) 2018, Egor Ignatov <ignatov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include "text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Устанавливает курсор в заданную позицию
 *
 * @param txt текст
 * @param new_line номер строки
 * @param new_position позиция курсора в строке
 * @returns none
 */
void change_cursor_position(text txt, int new_line, int new_position) {
  if (txt == NULL || txt->length == 0) {
    return;
  }
  new_line--;
  new_position--;
  if (new_line < 0 || new_line >= (int)txt->length)
    new_line = 0;
  node *p;
  p = txt->begin;
  for (int i = 0; i < new_line; i++)
    p = p->next;
  if (new_position >= (int)strlen(p->contents) || new_position < 0)
    new_position = 0;
  txt->cursor->position = new_position;
  txt->cursor->line = p;
}
