/**
 * common.h -- прототипы функций реализации команд редактора
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "data.h"
#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Выводит текст с капитализацией символов, которым предшествует пробел
 */
void showupfirst(text txt);

/**
 * Удаляет первую непустую строку 
 */
void r1ne(text txt);

/**
 * Перемещает курсор в конец строки
 */
void mle(text txt);

/**
 * Сохраняет текст в указанный файл
 */
void save(text txt, char *filename);

/**
 * Переводит в верхний регистр
 */
void showupper(text txt);

/**
 * Удаляет первую пустую строку
 */
void remove_first_entry_line(text txt);

/**
 * Выводит содержимое с нумерацией строк
 */
void shownum(text txt);

/**
 * Выводит строки, в которых содержатся цифры
 */
void showlineswithdigits(text txt);

/**
 * Выводит содержимое непустых строк
 */
void shownonempty(text txt);

/**
 * Заменяет непробельные символы на символ '*' звезды
 */
void showclassified(text txt);

/**
 * Перемещает курсор в указанную позицию
 */
void mwcrsr(text txt, int line, int position);

/**
 * Перемещает курсор в начало текущего слова, если это возможно
 */
void mwbb(text txt);

/**
 * Возвращает текущую позицию курсора
 */
void getcrsr(text txt);

/**
 * Удаляет текущю строку
 */
void remove_current_line(text txt);

/**
 * Организует вывод первого слова из строки
 */
void showfirstwords(text txt);

/**
 * Перемещает первую строку в конец текста
 */
void c1n(text txt);

void printpos(dat val);

/**
 * Перемещает курсор в начало строки
 */
void cursor_to_begin(text txt);

/**
 *  Выводит на экран часть строки от начала до курсора
 */
void plb(text txt);

/**
 *  Разделяет строку на две по позиции курсора
 */
void s(text txt);

/**
 *  Выводит столбец длин строк текста
 */
void showlengths(text txt);

/**
 *  Перемещает курсор в начало следующего слова, если это возможно
 */
void mnwbf(text txt);

/**
 *  Удаляет строку перед текущей
 */
void rp(text txt);

/**
 *  Обмен содержимого текущей строки до и после курсора
 */
void ch(text txt);

/**
 *  Перемещает курсор на один символ вправо, если это возможно
 */
void mcf(text txt);

/**
 * Удаляет первую строку
 */
void rh(text txt);

/**
 * Удаляет строку после текущей
 */
void rn(text txt);

/**
 * Заменяет пробелы символом подчеркивания
 */
void showunderscores(text txt);

/**
 *  Перемещает курсор в конец предыдущего слова, если это возможно
 */
void mpweb(text txt);

/**
 * Выводит содержимое в обратном порядке
 */
void showrev(text txt);

/**
 * Выводит часть строки от курсора до конца строки
 */
void ple(text txt);

/**
 * Выводит текст, опуская небуквенные символы
 */
void showalphaonly(text txt);

#endif
