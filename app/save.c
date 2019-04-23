/**
 * save.c -- реализует команду сохранения текста
 *
 * Copyright (c) 2018, Darya Madrakhimova <madrahim@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void save_line(int index, char *contents, int cursor, void *data);

/**
 * Сохраняет текст в указанный файл
 */
void save(text txt, char *filename) {
  FILE *f;
  /* Открываем файл для записи, контролируя ошибки */
  if ((f = fopen(filename, "w")) == NULL) {
    printf("The file %s cannot be opened\n", filename);
    return;
  }
  process_forward(txt, save_line, f);
  fclose(f);
}

static void save_line(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(cursor);

  /* Записываем строку в файл */
  fprintf((FILE *)data, "%s", contents);
  if (contents[strlen(contents) - 1] != '\n')
    fprintf((FILE *)data, "\n");
  fflush((FILE *)data);
}
