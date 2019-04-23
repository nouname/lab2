/**
 * mle.c -- функция перевода курсора в конец текущей строки
 *
 * Copyright (c) 2018, Minenko Danil <minenko@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void mlee(int index, char *contents, int cursor, void *data);

/**
 * Переводит курсор в конец текущей строки
 */
void mle(text txt) {
    /* Применяем функцию mle к каждой строке текста */
    process_forward(txt, mlee, txt);
}

static void mlee(int index, char *contents, int cursor, void *data) {
    assert(contents != NULL);

    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    if (cursor != -1) {
    mwcrsr((text)data, index + 1, strlen(contents));

    }
}
