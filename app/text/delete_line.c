/**
 * delete_line.c -- Функция удаления строки
 *
 * Copyright (c) 2018, Hristoforov Egor <hristofo@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
void change_cursor_position(text txt, int new_line, int new_position);

void delete_line(text txt, int line_num) {
  node *p = txt->begin;
  int i;
  for (i = 1; i < line_num; i++) {
    p = p->next;
  }
  if (txt->cursor->line == p && line_num != (int)txt->length) {
    change_cursor_position(txt, i + 1, txt->cursor->position + 1);
  }
  if (line_num == 1) {
    if (txt->length == 1 || txt->length == 0) {
      txt->length = 0;
      txt->begin = NULL;
      txt->end = NULL;
      return;
    }
    p = p->next;
    p->previous = NULL;
    txt->begin = p;
  } else if (line_num == (int)txt->length) {
    change_cursor_position(txt, line_num -1, txt->cursor->position + 1);
    p = p->previous;
    p->next = NULL;
    txt->end = p;
  } else if (line_num < (int)txt->length) {
    p->previous->next = p->next;
    p->next->previous = p->previous;
  }
  txt->length--;
}
